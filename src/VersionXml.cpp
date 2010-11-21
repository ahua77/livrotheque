#include "VersionXml.h"

#include <wx/filename.h>
#include <wx/log.h>
#include <wx/tokenzr.h>

#include "curl_util.h"

/**
 * @param url : url du fichier version.xml à récupérer
 * @param tmpDir : répertoire à utiliser pour les fichiers temporaires
 * @param version : version courante, utilisée pour comparer et déterminer si c'est la dernière
 * @param preprod : si true, utiliser la dernière version de preprod - sinon la dernière version de prod (cas normal)
 */
VersionXml::VersionXml(wxString url, wxString tmpDir, wxString version, bool preprod)
{
    m_ok = false; // le fichier n'a pas encore été récupéré et parsé
    m_versionCourante = version;
    m_preprod = preprod;
    // récupérer le fichier de version sur le serveur de référence
    m_fichierVersion = tmpDir + wxFileName::GetPathSeparators() + wxT("version.xml");
    curl_util* curl = curl_util::GetInstance();
    if (curl) {
        int retRecup = curl->GetFile(url, m_fichierVersion, tmpDir);
        if (retRecup == 0) {
            wxLogMessage("récupération de %s OK", url.c_str());
            analyseFichier();
        } else {
            wxLogMessage("récupération de %s KO - retRecup = %d", url.c_str(), retRecup);
        }
    }
    
}

VersionXml::~VersionXml()
{
}

bool VersionXml::aJour() const
{
    bool ret = true;
    // wxLogMessage("VersionXml::aJour() : version courante : %s - derniereVersion : %s", m_versionCourante.c_str(), m_idVersion.c_str());

//    if (m_versionCourante < m_idVersion)
    if (compareVersions(m_versionCourante, m_idVersion) < 0)
        ret = false;

    return ret;
}

bool VersionXml::afficherMessage() const
{
    bool ret = false;
    wxDateTime maintenant = wxDateTime::Now();
    if (m_message.IsEmpty() == false && maintenant >= m_messageDateMini && maintenant <= m_messageDateMaxi)
        ret = true;
    return ret;
}

/**
 * analyse initiale du fichier version.xml, pour lecture des noeuds <message> et <derniereVersion>
 */
void VersionXml::analyseFichier()
{
    // wxXmlDocument doc;
    bool ok = m_xmlDoc.Load(m_fichierVersion, wxT("ISO-8859-1"));
    if (ok ) {
        ok = m_xmlDoc.IsOk();
    }

    if (ok) {
        wxXmlNode* root = m_xmlDoc.GetRoot();
        if (root && root->GetName() == "descriptionVersions") {
        } else {
            ok = false;
        }
    }
    
    if (ok) {
        wxXmlNode* child = m_xmlDoc.GetRoot()->GetChildren();
        while (child) {
            
            if (child->GetName() == "message") {
                // lecture bloc <message> : message à afficher au lancement
                wxXmlNode* messageChild = child->GetChildren();
                while (messageChild) {
                    if (messageChild->GetName() == "dateMini") {
                        wxString dateMini = messageChild->GetPropVal("value", "");
                        m_messageDateMini.ParseFormat(dateMini, "%d/%m/%Y");
                        // wxLogMessage("dateMini = " + dateMini);
                    } else if (messageChild->GetName() == "dateMaxi") {
                        wxString dateMaxi = messageChild->GetPropVal("value", "");
                        m_messageDateMaxi.ParseFormat(dateMaxi, "%d/%m/%Y");
                    } else if (messageChild->GetName() == "contenu") {
                        wxString ligne = messageChild->GetPropVal("value", "");
                        m_message += ligne + "\n";
                    }
                    messageChild = messageChild->GetNext();
                }
            } else if (child->GetName() == "derniereVersion") {
                // lecture bloc <derniereVersion> : dernières versions disponibles
                wxXmlNode* versionChild = child->GetChildren();
                while (versionChild) {
                    if (versionChild->GetName() == "idVersion" && m_preprod == false) {
                        m_idVersion = versionChild->GetPropVal("value", "");
                        m_urlDownload = versionChild->GetPropVal("lien", "");
                    } else if (versionChild->GetName() == "idVersionPreprod" && m_preprod == true) {
                        m_idVersion = versionChild->GetPropVal("value", "");
                        m_urlDownload = versionChild->GetPropVal("lien", "");
                    }
                    versionChild = versionChild->GetNext();
                }
            }

            child = child->GetNext();
        }
    }
    
    // wxLogMessage("message : [%s] à afficher entre le %s et le %s ", 
    //              m_message.c_str(), m_messageDateMini.FormatDate().c_str(), m_messageDateMaxi.FormatDate().c_str());
    // wxLogMessage("idVersion : %s", m_idVersion.c_str());

    if (ok)
        m_ok = true;
}

/**
 * compare 2 chaines de versions, de la forme a.b.c.d
 * les chaines peuvent contenir autant de champs que nécessaires, séparés par des points (.) et numériques
 * @return 0 si v1=v2; <0 si v1<v2; >0 si v1>v2
 */
int VersionXml::compareVersions(wxString v1, wxString v2)
{
    // wxLogMessage("compareVersions(%s, %s)", v1.c_str(), v2.c_str());
    int ret = 0;
    wxStringTokenizer tkz1 (v1, ".");
    wxStringTokenizer tkz2 (v2, ".");
    while (ret == 0 && tkz1.HasMoreTokens()) {
        wxString tk1 = tkz1.GetNextToken();
        wxString tk2 = "";
        if (tkz2.HasMoreTokens())
            tk2 = tkz2.GetNextToken();
        // wxLogMessage("   tk1 = %s, tk2 = %s", tk1.c_str(), tk2.c_str());
        long n1 = 0, n2 = 0;
        if (tk1.IsNumber())
            tk1.ToLong(&n1);
        if (tk2.IsNumber())
            tk2.ToLong(&n2);
          
        ret = n1-n2;
    }

    // wxLogMessage("compareVersions(%s, %s) --> %d", v1.c_str(), v2.c_str(), ret);
    return ret;
}

/** 
 * @return true si la version passée est entre la version courante et la dernière version dispo (bornes comprises)
*/
bool VersionXml::afficherVersion(wxString version)
{
    bool ret = false;
    if (compareVersions(version, m_versionCourante) >= 0 && compareVersions(version, m_idVersion) <=0)
        ret = true;
        
    return ret;
}
