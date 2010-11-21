#ifndef VERSIONXML_H
#define VERSIONXML_H

#include <wx/string.h>
#include <wx/datetime.h>
#include <wx/xml/xml.h>

class VersionXml {
public:
    VersionXml(wxString url, wxString tempDir, wxString version, bool preprod=false);
    ~VersionXml();
    
    /** return true si le fichier a été correctement récupéré et parsé */
    bool ok() const {return m_ok;}
    bool aJour() const;
    wxString message() const {return m_message;}
    bool afficherMessage() const;
    wxString versionCourante() const {return m_versionCourante;}
    wxString idVersion() const {return m_idVersion;}
    wxString urlDownload() const {return m_urlDownload;}
    wxXmlDocument& xmlDoc() {return m_xmlDoc;}

    /** return 0 si v1=v2; <0 si v1<v2; >0 si v1>v2 */
    static int compareVersions(wxString v1, wxString v2);
    
    /** return true si la version passée est entre la version courante et la dernière version dispo (bornes comprises) */
    bool afficherVersion(wxString version);
    
private:
    void analyseFichier();

    wxString m_message;
    wxDateTime m_messageDateMini;
    wxDateTime m_messageDateMaxi;
    wxString m_idVersion;       /** dernière version disponible */
    wxString m_versionCourante; /** version en cours d'exécution */
    wxString m_fichierVersion;
    bool m_preprod;
    bool m_ok;
    wxXmlDocument m_xmlDoc;
    wxString m_urlDownload;
};

#endif
