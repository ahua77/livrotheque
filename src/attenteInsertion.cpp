// Class automatically generated by Dev-C++ New Class wizard

// header local
#include "attenteInsertion.h" // class's header file

// header standards
#include <wx/log.h>

// header du projet
#include "mabase.h"
#include "divers.h"
#include "ParamManager.h"

int g_nbInstances = 0;

// class constructor
attenteInsertion::attenteInsertion(long rowid)
{
    g_nbInstances++;
    wxLogMessage("attenteInsertion : constructeur - %d", g_nbInstances);
	m_rowid = rowid;
}

// class destructor
attenteInsertion::~attenteInsertion()
{
    g_nbInstances--;
    wxLogMessage("attenteInsertion : destructeur - %d", g_nbInstances);
}

// insert ou update en base ; retourne le rowid suite � l'insertion/mise � jour
int attenteInsertion::writeDB(ma_base* db)
{
    if (m_rowid == -1) {
        // ins�rer le nouvel enregistrement en base
        wxString rq;
        rq.Printf("INSERT INTO attenteInsertion (isbn, titre, auteur, commentaire) "
                  "VALUES ('%s', '%s', '%s', '%s')",
                  gestion_quote2(m_isbn).c_str(), 
                  gestion_quote2(m_titre).c_str(), 
                  gestion_quote2(m_auteur).c_str(), 
                  gestion_quote2(m_commentaire).c_str());
        wxLogMessage("attenteInsertion::writeDB() : [%s]", rq.c_str());

        // ex�cuter en base
        db->exec_rapide(rq);
        
        // mettre � jour m_rowid
        m_rowid = db->last_insert();
    } else {
        // mettre � jour un enregistrement existant
        wxString rq;
        rq.Printf("UPDATE attenteInsertion SET "
                  "isbn = '%s', "
                  "titre = '%s', "
                  "auteur = '%s', "
                  "commentaire = '%s' "
                  "WHERE rowid = %ld",
                  gestion_quote2(m_isbn).c_str(), 
                  gestion_quote2(m_titre).c_str(), 
                  gestion_quote2(m_auteur).c_str(), 
                  gestion_quote2(m_commentaire).c_str(),
                  m_rowid);
                  
        // ex�cuter en base
        db->exec_rapide(rq);
    }
    
    return m_rowid;
}

// relit � partir de la base
void attenteInsertion::readDB(ma_base* db)
{
    if (m_rowid == -1)
        return;
    
    wxString rq;
    rq.Printf("SELECT isbn, titre, auteur, commentaire FROM attenteInsertion WHERE rowid = %ld", m_rowid);
    int ret = db->transac_prepare(rq);
    if (ret < 0) {
        wxString mess;
        db->get_erreur(mess);
        wxMessageBox("probleme avec la requete " + rq + "\nmessage : " + mess);
    }
    if (ret >= 0) {
        ret = db->transac_step();
        if (ret == SQLITE_ROW) {
            // il ne doit y avoir qu'une ligne avec typeParam / nomParam --> on ne prend que la premiere trouv�e
            int taille;
            db->get_value_char(0, m_isbn, taille);
            db->get_value_char(1, m_titre, taille);
            db->get_value_char(2, m_auteur, taille);
            db->get_value_char(3, m_commentaire, taille);
        }
        db->transac_fin();
    }
}

/* static */ void attenteInsertion::verifieFormatBase(ma_base* db)
{
    static bool formatOk = false;
    if (!formatOk) {
        ParamManager* param = ParamManager::GetInstance("livre");
        if (param == NULL)
            param = new ParamManager(*db, "livre");
        long formatBase = 0;
        param->GetOrSet("config", "BASE", "FormatAttenteInsertion", formatBase);
        if (formatBase == 0) {
            wxString rq = "CREATE TABLE attenteInsertion "
                          "(isbn TEXT, titre TEXT, auteur TEXT, commentaire TEXT)";
            db->exec_rapide(rq);
            
            formatBase = 1;
            param->Set("config", "BASE", "FormatAttenteInsertion", formatBase, 0);
        }
        
        formatOk = true; // pour ne pas refaire la v�rification dans la m�me ex�cution du programme
    }
}

/* static */ void attenteInsertion::readDB(ma_base* db, mapAttenteInsertion& mapItem, const wxString& filtre)
{
    wxString query = "SELECT rowid, isbn, titre, auteur, commentaire FROM attenteInsertion";
    if (filtre != "")
        query += "WHERE " + filtre;

    if (db->transac_prepare(query) < 0) {
        wxString mess;
        db->get_erreur(mess);
        wxMessageBox("attenteInsertion::readDB() " + mess, "probleme", wxOK | wxICON_EXCLAMATION);
        return;
    }    

    while (db->transac_step() == SQLITE_ROW) {
        int id, taille;
        wxString texte;

        db->get_value_int(0, id);
        attenteInsertion* item = new attenteInsertion(id);
        db->get_value_char(1, texte, taille);
        item->isbn(texte);
        db->get_value_char(2, texte, taille);
        item->titre(texte);
        db->get_value_char(3, texte, taille);
        item->auteur(texte);
        db->get_value_char(4, texte, taille);
        item->commentaire(texte);

        mapItem[id] = item;
    }    

    db->transac_fin();
}  

