///-----------------------------------------------------------------
///
/// @file      listeAttenteInsertionDlg.cpp
/// @author    cubbiste
/// Created:   12/06/2011 07:46:57
/// @section   DESCRIPTION
///            listeAttenteInsertionDlg class implementation
///
///------------------------------------------------------------------

// header local
#include "listeAttenteInsertionDlg.h"

// header standards
#include <wx/textfile.h>
#include <wx/tokenzr.h>

// header du projet
#include "attenteInsertion.h"
#include "mabase.h"
#include "Nouv_livre.h"
#include "attenteInsertionDlg.h"

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

// définition des colonnes
#define NUM_COLUMNS_attenteInsertion 5

// enum E_Col {COL_COMPTE, COL_MONTANT_COURANT, COL_MONTANT_FINAL};

static wxString _gszColumnLabel[NUM_COLUMNS_attenteInsertion] = {
	_T("id"), _T("isbn"), _T("titre"), _T("auteur"), _T("commentaire")
};

static int _gnColumnFmt[NUM_COLUMNS_attenteInsertion] = {
	wxLIST_FORMAT_RIGHT, wxLIST_FORMAT_LEFT, wxLIST_FORMAT_LEFT, wxLIST_FORMAT_LEFT, wxLIST_FORMAT_LEFT
};

static int _gnColumnWidth[NUM_COLUMNS_attenteInsertion] = {
	30, 100, 350, 200, 400
};

//----------------------------------------------------------------------------
// listeAttenteInsertionDlg
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(listeAttenteInsertionDlg,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(listeAttenteInsertionDlg::OnClose)
	EVT_BUTTON(ID_WXBTN_SUPPRIMER_LIGNES_SELECTIONNEES,listeAttenteInsertionDlg::OnSupprimerLignesSelectionnees)
	EVT_BUTTON(ID_WXBTN_AJOUTER_LIGNE,listeAttenteInsertionDlg::OnAjouterLigne)
	EVT_BUTTON(ID_WXBTN_INSERER_LIGNE_SELECTIONNEE,listeAttenteInsertionDlg::OnImporterLigneSelectionnee)
	EVT_BUTTON(ID_WXBTN_IMPORTER_LISTE,listeAttenteInsertionDlg::OnImporterListe)
	
	EVT_LIST_ITEM_ACTIVATED(ID_WXLC_LIVRES,listeAttenteInsertionDlg::OnItemActivated)
END_EVENT_TABLE()
////Event Table End

listeAttenteInsertionDlg::listeAttenteInsertionDlg(wxWindow *parent, ma_base* db, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
    m_db = db;

	CreateGUIControls();
	
	rafraichit();
}

listeAttenteInsertionDlg::~listeAttenteInsertionDlg()
{
} 

void listeAttenteInsertionDlg::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	m_sizerV_general = new wxBoxSizer(wxVERTICAL);
	this->SetSizer(m_sizerV_general);
	this->SetAutoLayout(true);

	WxLC_livres = new wxListCtrl(this, ID_WXLC_LIVRES, wxPoint(92, 5), wxSize(250, 150), wxLC_REPORT | wxLC_HRULES | wxLC_VRULES, wxDefaultValidator, wxT("WxLC_livres"));
	m_sizerV_general->Add(WxLC_livres,1,wxALIGN_CENTER | wxEXPAND | wxALL,5);

	m_sizerH_boutons = new wxBoxSizer(wxHORIZONTAL);
	m_sizerV_general->Add(m_sizerH_boutons, 0, wxALIGN_CENTER | wxEXPAND | wxALL, 5);

	WxButton_importerListe = new wxButton(this, ID_WXBTN_IMPORTER_LISTE, wxT("Importer une liste"), wxPoint(5, 5), wxSize(75, 25), 0, wxDefaultValidator, wxT("WxButton_importerListe"));
	m_sizerH_boutons->Add(WxButton_importerListe,1,wxALIGN_CENTER | wxALL,5);

	WxButton_insererLigneSelectionnee = new wxButton(this, ID_WXBTN_INSERER_LIGNE_SELECTIONNEE, wxT("Insérer la ligne sélectionnée"), wxPoint(90, 5), wxSize(75, 25), 0, wxDefaultValidator, wxT("WxButton_insererLigneSelectionnee"));
	m_sizerH_boutons->Add(WxButton_insererLigneSelectionnee,1,wxALIGN_CENTER | wxALL,5);

	WxButton_ajouterLigne = new wxButton(this, ID_WXBTN_AJOUTER_LIGNE, wxT("Ajouter une ligne"), wxPoint(175, 5), wxSize(75, 25), 0, wxDefaultValidator, wxT("WxButton_ajouterLigne"));
	m_sizerH_boutons->Add(WxButton_ajouterLigne,1,wxALIGN_CENTER | wxALL,5);

	WxButton_supprimerLignesSelectionnees = new wxButton(this, ID_WXBTN_SUPPRIMER_LIGNES_SELECTIONNEES, wxT("Supprimer les lignes sélectionnées"), wxPoint(260, 5), wxSize(75, 25), 0, wxDefaultValidator, wxT("WxButton_supprimerLignesSelectionnees"));
	m_sizerH_boutons->Add(WxButton_supprimerLignesSelectionnees,1,wxALIGN_CENTER | wxALL,5);

	WxButton_fermer = new wxButton(this, wxID_OK, wxT("Fermer"), wxPoint(345, 5), wxSize(75, 25), 0, wxDefaultValidator, wxT("WxButton_fermer"));
	m_sizerH_boutons->Add(WxButton_fermer,1,wxALIGN_CENTER | wxALL,5);

	SetTitle(wxT("Livres en attente d'insertion"));
	SetIcon(wxNullIcon);
	
	GetSizer()->Layout();
	GetSizer()->Fit(this);
	GetSizer()->SetSizeHints(this);
	Center();
	
	////GUI Items Creation End

	// construction des colonnes des listCtrl
	for(int iCol = 0; iCol<NUM_COLUMNS_attenteInsertion; iCol++) {
        wxListItem itemCol;
        itemCol.m_mask = wxLIST_MASK_TEXT | wxLIST_MASK_WIDTH | wxLIST_MASK_FORMAT /* | wxLIST_MASK_DATA */;
        itemCol.m_text = _gszColumnLabel[iCol];
        itemCol.m_width = _gnColumnWidth[iCol];
        itemCol.m_format = _gnColumnFmt[iCol];
        WxLC_livres->InsertColumn(iCol, itemCol);
	}

	
	// forcer la taille, puisque la taille définie dans le wxform n'est pas prise en compte ...
	SetSize(1150, 400);
	Center();
}

void listeAttenteInsertionDlg::OnClose(wxCloseEvent& /*event*/)
{
	Destroy();
}

/*
 * OnImporterListe
 */
void listeAttenteInsertionDlg::OnImporterListe(wxCommandEvent& event)
{
    wxString filename = wxFileSelector("Choix du fichier à importer", "", "", "",
                                       "texte délimité (*.txt)|*.txt|texte délimité (*.csv)|*.csv|Tous (*.*)|*.*",
                                       wxOPEN|wxFILE_MUST_EXIST);

    if ( !filename.empty() ) {
        wxTextFile fichier(filename);
        fichier.Open();
        
        for (size_t iLigne = 0; iLigne < fichier.GetLineCount(); iLigne++) {
            wxString ligne = fichier[iLigne];
            if (ligne.IsEmpty()) // ignorer les lignes vides
                continue;
            if (ligne.StartsWith("#")) // ignorer les lignes de commentaire
                continue;
                
            wxLogMessage ("ligne de contenu %d : [%s]", iLigne, fichier.GetLine(iLigne).c_str());
    
            wxArrayString fields = wxStringTokenize(ligne, "\t", wxTOKEN_RET_EMPTY_ALL);

        	attenteInsertion item;
        	if (fields.GetCount() > 0) item.isbn(fields[0]);
        	if (fields.GetCount() > 1) item.titre(fields[1]);
        	if (fields.GetCount() > 2) item.auteur(fields[2]);
        	if (fields.GetCount() > 3) item.commentaire(fields[3]);
        	item.writeDB(m_db);
        }
        
        rafraichit();
    }
}

void listeAttenteInsertionDlg::rafraichit()
{
    // vider la grille
    WxLC_livres->DeleteAllItems();
    
    // récupérer la liste des items en base
    mapAttenteInsertion mapItem;
    attenteInsertion::readDB(m_db, mapItem, "");
    
    // afficher la liste dans la grille
    mapAttenteInsertion::iterator ite = mapItem.begin();
    int ii = 0;
    while (ite != mapItem.end()) {
        attenteInsertion* item = ite->second;
        
        wxListItem lvi;
        lvi.SetId(item->rowid());

        lvi.SetText(wxString::Format("%ld", item->rowid()));
        WxLC_livres->InsertItem(lvi);
        WxLC_livres->SetItem(ii, 1, (item->isbn() == "" ? " " : item->isbn()));
        WxLC_livres->SetItem(ii, 2, (item->titre() == "" ? " " : item->titre()));
        WxLC_livres->SetItem(ii, 3, (item->auteur() == "" ? " " : item->auteur()));
        WxLC_livres->SetItem(ii, 4, (item->commentaire() == "" ? " " : item->commentaire()));
        WxLC_livres->SetItemData(ii, item->rowid());



        
        ii++;
        ite++;
    }
    
    // libérer la mémoire des item de la map
    ite = mapItem.begin();
    while (ite != mapItem.end()) {
        attenteInsertion* item = ite->second;
        delete item;
        ite++;
    }
}

wxArrayInt listeAttenteInsertionDlg::rowIdSelectionnes()
{
    wxLogMessage("listeAttenteInsertionDlg::rowIdSelectionnes()");

    wxArrayInt liste;
    long item = -1;
    for ( ;; ) {
        item = WxLC_livres->GetNextItem(item, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
        if ( item == -1 )
            break;

        long rowid = WxLC_livres->GetItemData(item);
        liste.Add(rowid);
    }

    wxLogMessage("listeAttenteInsertionDlg::rowIdSelectionnes() : liste --> %d elts", liste.GetCount());
    return liste;
}

void listeAttenteInsertionDlg::OnSupprimerLignesSelectionnees(wxCommandEvent& event)
{
    wxLogMessage("listeAttenteInsertionDlg::OnSupprimerLignesSelectionnees()");
    wxArrayInt listeId = rowIdSelectionnes();
    if (listeId.GetCount() == 0)
        return;

    wxString question;
    question.Printf("Voulez-vous supprimer toutes les lignes sélectionnées ?");
    int ret = wxMessageBox(question, "livrothèque", wxYES_NO|wxNO_DEFAULT|wxICON_EXCLAMATION, this);
    if (ret == wxYES) {
        wxString rq = "DELETE FROM attenteInsertion WHERE rowid IN (";
        for (size_t ii = 0; ii < listeId.GetCount(); ii++) {
            rq += wxString::Format("%d, ", listeId[ii]);
        }
        rq = rq.Left(rq.Len() - 2);   // supprimer le dernier ", "
        rq += ")";
        
        wxLogMessage("listeAttenteInsertionDlg::OnSupprimerLignesSelectionnees() : " + rq);
        m_db->exec_rapide(rq);
        rafraichit();
    }
}

void listeAttenteInsertionDlg::OnImporterLigneSelectionnee(wxCommandEvent& event)
{
    wxLogMessage("listeAttenteInsertionDlg::OnImporterLigneSelectionnee()");
    wxArrayInt listeId = rowIdSelectionnes();
    if (listeId.GetCount() != 1) {
        wxMessageBox("Sélectionnez une ligne unique pour utiliser cette fonction");
        return;
    }

    int rowid = listeId[0];
    attenteInsertion item(rowid);
    item.readDB(m_db);
    
    wxLogMessage("ligne sélectionnée : %s - %s - %s - %s", item.isbn().c_str(), item.titre().c_str(), item.auteur().c_str(), item.commentaire().c_str());
    
    Nouv_livre* dlg = new Nouv_livre(m_db, &item, this);
    int ret = dlg->ShowModal();
    if (ret > 0) {
        // wxMessageBox("sortie par OK --> suppression de la ligne");
        // on a validé l'insertion --> on supprime la ligne dans attenteInsertion
        wxString rq;
        rq.Printf ("DELETE FROM attenteInsertion WHERE rowid = %d", rowid);
        m_db->exec_rapide(rq);
        rafraichit();
    } else {
        // wxMessageBox("sortie sans OK --> pas de suppression de la ligne");
    }
}

/*
 * WxLC_livresItemActivated
 */
void listeAttenteInsertionDlg::OnItemActivated(wxListEvent& event)
{
    editItem(event.GetData());
}

/*
 * WxButton_ajouterLigneClick
 */
void listeAttenteInsertionDlg::OnAjouterLigne(wxCommandEvent& event)
{
    editItem(-1);
}

void listeAttenteInsertionDlg::editItem(long rowid)
{
    attenteInsertionDlg* dlg = new attenteInsertionDlg(this);
    
    attenteInsertion item(rowid);
    item.readDB(m_db);
    dlg->initDialog(&item);

    int ret = dlg->ShowModal();
    if (ret == wxID_OK) {
        dlg->updateItem(&item);
        item.writeDB(m_db);
        rafraichit();
    }
}
