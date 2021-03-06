// Class automatically generated by Dev-C++ New Class wizard

#ifndef ATTENTEINSERTION_H
#define ATTENTEINSERTION_H

#include <wx/string.h>
#include <wx/hashmap.h>

class ma_base;

class attenteInsertion;
// declare map with int keys and ges_compte* values
WX_DECLARE_HASH_MAP( int, attenteInsertion*, wxIntegerHash, wxIntegerEqual, mapAttenteInsertion );


/*
 * No description
 */
class attenteInsertion
{
 public:
	// class constructor
	attenteInsertion(long rowid = -1);
	// class destructor
	~attenteInsertion();

    // getters
    long rowid() const {return m_rowid;} 
    wxString titre() const {return m_titre;}
    wxString isbn() const {return m_isbn;}
    wxString auteur() const {return m_auteur;}
    wxString commentaire() const {return m_commentaire;}
    
    // setters
    void titre(const wxString& val) {m_titre = val;}
    void isbn(const wxString& val) {m_isbn = val;}
    void auteur(const wxString& val) {m_auteur = val;}
    void commentaire(const wxString& val) {m_commentaire = val;}

    // interface BD
    int writeDB(ma_base* db);   // insert ou update en base ; retourne le rowid suite � l'insertion/mise � jour
    void readDB(ma_base* db);   // relit � partir de la base
    static void verifieFormatBase(ma_base* db);   // met la base � niveau si n�cessaire - � appeler une fois avant les autres m�thodes utilisant la base
    static void readDB(ma_base* db, mapAttenteInsertion& mapItem, const wxString& filtre);

 private:
    long m_rowid;   // rowid en base si l'element a �t� ins�r� ; -1 pour un �l�ment qui n'existe pas (encore) en base
    wxString m_titre;
    wxString m_isbn;
    wxString m_auteur;
    wxString m_commentaire;
};

#endif // ATTENTEINSERTION_H
