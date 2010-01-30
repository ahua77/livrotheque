///-----------------------------------------------------------------
///
/// @file      FusionDlg.cpp
/// @author    cubbiste
/// Created:   10/12/2009 00:38:40
/// @section   DESCRIPTION
///            FusionDlg class implementation
//
//Ce logiciel est un programme informatique servant à [rappeler les
//caractéristiques techniques de votre logiciel]. 
//
//Ce logiciel est régi par la licence CeCILL soumise au droit français et
//respectant les principes de diffusion des logiciels libres. Vous pouvez
//utiliser, modifier et/ou redistribuer ce programme sous les conditions
//de la licence CeCILL telle que diffusée par le CEA, le CNRS et l'INRIA 
//sur le site "http://www.cecill.info".
//
//En contrepartie de l'accessibilité au code source et des droits de copie,
//de modification et de redistribution accordés par cette licence, il n'est
//offert aux utilisateurs qu'une garantie limitée.  Pour les mêmes raisons,
//seule une responsabilité restreinte pèse sur l'auteur du programme,  le
//titulaire des droits patrimoniaux et les concédants successifs.
//
//A cet égard  l'attention de l'utilisateur est attirée sur les risques
//associés au chargement,  à l'utilisation,  à la modification et/ou au
//développement et à la reproduction du logiciel par l'utilisateur étant 
//donné sa spécificité de logiciel libre, qui peut le rendre complexe à 
//manipuler et qui le réserve donc à des développeurs et des professionnels
//avertis possédant  des  connaissances  informatiques approfondies.  Les
//utilisateurs sont donc invités à charger  et  tester  l'adéquation  du
//logiciel à leurs besoins dans des conditions permettant d'assurer la
//sécurité de leurs systèmes et ou de leurs données et, plus généralement, 
//à l'utiliser et l'exploiter dans les mêmes conditions de sécurité. 
//
//Le fait que vous puissiez accéder à cet en-tête signifie que vous avez 
//pris connaissance de la licence CeCILL, et que vous en avez accepté les
//termes.
//
///
///------------------------------------------------------------------

#include "FusionDlg.h"

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// FusionDlg
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(FusionDlg,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(FusionDlg::OnClose)
	EVT_INIT_DIALOG(FusionDlg::FusionDlgInitDialog)
	EVT_COMBOBOX(ID_CB_TYPE_GROUPE,FusionDlg::CB_typeGroupeSelected)
	EVT_COMBOBOX(ID_CB_TYPE_TRI,FusionDlg::CB_typeTriSelected)
	EVT_COMBOBOX(ID_WXCOMBOBOX1,FusionDlg::CB_listeGroupes1Selected)
	EVT_COMBOBOX(ID_WXCOMBOBOX2,FusionDlg::CB_listeGroupes2Selected)
	EVT_BUTTON(ID_WXBUTTON1,FusionDlg::BN_FusionnerClick)
	EVT_BUTTON(ID_WXBUTTON2,FusionDlg::BN_AnnulerClick)
END_EVENT_TABLE()
////Event Table End

FusionDlg::FusionDlg(wxWindow *parent, ma_base& p_baseLivre, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style), baseLivre(p_baseLivre)
{
	CreateGUIControls();
}

FusionDlg::~FusionDlg()
{
} 

void FusionDlg::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	wxArrayString arrayStringFor_CB_typeGroupe;
	CB_typeGroupe = new wxComboBox(this, ID_CB_TYPE_GROUPE, wxT("CB_typeGroupe"), wxPoint(136, 6), wxSize(145, 23), arrayStringFor_CB_typeGroupe, wxCB_READONLY, wxDefaultValidator, wxT("CB_typeGroupe"));

	wxArrayString arrayStringFor_CB_typeTri;
	CB_typeTri = new wxComboBox(this, ID_CB_TYPE_TRI, wxT("CB_typeTri"), wxPoint(368, 6), wxSize(241, 23), arrayStringFor_CB_typeTri, wxCB_READONLY, wxDefaultValidator, wxT("CB_typeTri"));

	wxArrayString arrayStringFor_CB_listeGroupes1;
	CB_listeGroupes1 = new wxComboBox(this, ID_WXCOMBOBOX1, wxT("Choisir un groupe"), wxPoint(77, 57), wxSize(466, 23), arrayStringFor_CB_listeGroupes1, wxCB_READONLY, wxDefaultValidator, wxT("CB_listeGroupes1"));

	wxArrayString arrayStringFor_LB_listeLivres1;
	LB_listeLivres1 = new wxListBox(this, ID_WXLISTBOX1, wxPoint(18, 86), wxSize(527, 235), arrayStringFor_LB_listeLivres1, wxLB_SINGLE);

	wxArrayString arrayStringFor_CB_listeGroupes2;
	CB_listeGroupes2 = new wxComboBox(this, ID_WXCOMBOBOX2, wxT("Choisir un groupe"), wxPoint(636, 57), wxSize(466, 23), arrayStringFor_CB_listeGroupes2, wxCB_READONLY, wxDefaultValidator, wxT("CB_listeGroupes2"));

	wxArrayString arrayStringFor_LB_listeLivres2;
	LB_listeLivres2 = new wxListBox(this, ID_WXLISTBOX2, wxPoint(575, 86), wxSize(527, 235), arrayStringFor_LB_listeLivres2, wxLB_SINGLE);

	BN_Fusionner = new wxButton(this, ID_WXBUTTON1, wxT("Fusionner >>"), wxPoint(455, 329), wxSize(91, 25), 0, wxDefaultValidator, wxT("BN_Fusionner"));

	BN_Annuler = new wxButton(this, ID_WXBUTTON2, wxT("Fermer"), wxPoint(577, 329), wxSize(75, 25), 0, wxDefaultValidator, wxT("BN_Annuler"));

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, wxT("Type de groupe :"), wxPoint(24, 8), wxDefaultSize, 0, wxT("WxStaticText3"));

	WxStaticLine1 = new wxStaticLine(this, ID_WXSTATICLINE1, wxPoint(0, 40), wxSize(1118, -1), wxLI_HORIZONTAL);

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, wxT("dans :"), wxPoint(577, 59), wxDefaultSize, 0, wxT("WxStaticText2"));

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, wxT("Fusionner :"), wxPoint(14, 59), wxDefaultSize, 0, wxT("WxStaticText1"));

	SetTitle(wxT("Fusion"));
	SetIcon(wxNullIcon);
	SetSize(8,8,1135,402);
	Center();
	
	////GUI Items Creation End
}

void FusionDlg::OnClose(wxCloseEvent& /*event*/)
{
	Destroy();
}

/*
 * FusionDlgInitDialog
 */
void FusionDlg::FusionDlgInitDialog(wxInitDialogEvent& event)
{
    CB_typeGroupe->AppendString("auteur");
    CB_typeGroupe->AppendString("serie");
    CB_typeGroupe->AppendString("genre");
    CB_typeGroupe->AppendString("editeur");
    CB_typeGroupe->AppendString("format");
    CB_typeGroupe->AppendString("artiste");
    CB_typeGroupe->AppendString("etat");
    CB_typeGroupe->AppendString("localisation");
    CB_typeGroupe->AppendString("serie_o");
    CB_typeGroupe->AppendString("pays");
    CB_typeGroupe->AppendString("langue");
    CB_typeGroupe->AppendString("traducteur");
    CB_typeGroupe->Select(3);  // selection editeur par défaut
    
    CB_typeTri->AppendString("trier par nombre de titres");
    CB_typeTri->AppendString("trier par ordre alphabétique");
    CB_typeTri->Select(0);      // sélection par nombre de titres par défaut
    
    InitListeGroupes();
}

void FusionDlg::InitListeGroupes()
{
//    wxMessageBox("InitListeGroupes");
    
    // vider les deux listes
    while (!CB_listeGroupes1->IsEmpty())
        CB_listeGroupes1->Delete(0);
    while (!CB_listeGroupes2->IsEmpty())
        CB_listeGroupes2->Delete(0);
        
    // remplir les listes à partir de la base
    wxString nom_table = CB_typeGroupe->GetStringSelection();
    wxString orderBy = "nn DESC";
    if (CB_typeTri->GetSelection() == 1) {
        orderBy = "upper(a.nom) ASC"; 
    }   
	wxString query = "SELECT a.rowid, a.nom, count(l.rowid) nn from "+nom_table
          +" a, livre l where l.id_"+nom_table
          +" = a.rowid group by a.rowid order by " + orderBy;
	wxString mess;
	int ret = baseLivre.transac_prepare(query);
	if (ret<0) {
        baseLivre.get_erreur(mess);
        mess=query+"\n"+mess;
        wxMessageBox("InitListeGroupes "+mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        // baseLivre.fermer();
        return;
    }
    ret=SQLITE_ROW;
    ret=baseLivre.transac_step();
    int ii = 0;
    while(ret==SQLITE_ROW) {
        int id;
        wxString nom;
        int taille;
        int nbLivres;
        baseLivre.get_value_int(0,id);
        baseLivre.get_value_char(1,nom,taille);
        baseLivre.get_value_int(2, nbLivres);
        wxString pourListe;
        wxString format = " (%d titres)";
        if (nbLivres < 2) 
            format = " (%d titre)";
        pourListe = nom + wxString::Format(format, nbLivres);
        CB_listeGroupes1->AppendString(pourListe);
        CB_listeGroupes1->SetClientData(ii, (void*)id);
        CB_listeGroupes2->AppendString(pourListe);
        CB_listeGroupes2->SetClientData(ii, (void*)id);
        
        ii ++;
        ret=baseLivre.transac_step();
    }  
    baseLivre.transac_fin();
    
    // vider les listes de livres car aucun groupe n'est sélectionné
    remplirListeLivres(LB_listeLivres1, -1);
    remplirListeLivres(LB_listeLivres2, -1);
}

/*
 * CB_listeGroupes1Selected
 */
void FusionDlg::CB_listeGroupes1Selected(wxCommandEvent& event )
{
    int idGroupe = (int)CB_listeGroupes1->GetClientData(CB_listeGroupes1->GetSelection());
    remplirListeLivres(LB_listeLivres1, idGroupe);
}

/*
 * CB_listeGroupes2Selected
 */
void FusionDlg::CB_listeGroupes2Selected(wxCommandEvent& event )
{
    int idGroupe = (int)CB_listeGroupes2->GetClientData(CB_listeGroupes2->GetSelection());
    remplirListeLivres(LB_listeLivres2, idGroupe);
}

void FusionDlg::remplirListeLivres(wxListBox* listeLivres, int idGroupe)
{
	// vider la liste et insérer à la place la liste des livres du groupe sélectionné
    while (!listeLivres->IsEmpty())
    	listeLivres->Delete(0);
	
	// idGroupe = -1 : aucun groupe sélectionné, laisser la liste vide
    if (idGroupe != -1) {	
        wxString nom_table = CB_typeGroupe->GetStringSelection();

    	wxString query = "select l.titre, a.nom from livre l, auteur a "
                         "where id_"+nom_table+" = " + wxString::Format(_T("%d"), idGroupe) + 
                         " and l.id_auteur=a.rowid order by upper(a.nom), l.titre";
    	wxString mess;
    	int ret = baseLivre.transac_prepare(query);
    	if (ret<0) {
            baseLivre.get_erreur(mess);
            mess=query+"\n"+mess;
            wxMessageBox("FusionDlgInitDialog "+mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
            return;
        }
        ret=SQLITE_ROW;
        ret=baseLivre.transac_step();
        int ii = 0;
        while(ret==SQLITE_ROW) {
            wxString titre;
            wxString auteur;
            int taille;
            baseLivre.get_value_char(0, titre, taille);
            baseLivre.get_value_char(1, auteur, taille);
            wxString pourListe;
            pourListe = titre + " (" + auteur + ")";
            listeLivres->Append(pourListe);
            
            ii ++;
            ret=baseLivre.transac_step();
        }  
        baseLivre.transac_fin();
    }
}


/*
 * BN_AnnulerClick
 */
void FusionDlg::BN_AnnulerClick(wxCommandEvent& event)
{
	this->EndDialog(0);
}

/*
 * BN_FusionnerClick
 */
void FusionDlg::BN_FusionnerClick(wxCommandEvent& event)
{
    int idGroupeFrom = (int)CB_listeGroupes1->GetClientData(CB_listeGroupes1->GetSelection());
    int idGroupeTo = (int)CB_listeGroupes2->GetClientData(CB_listeGroupes2->GetSelection());

    if (idGroupeTo == 0 || idGroupeFrom == 0 || idGroupeTo == idGroupeFrom)
    {
        wxMessageBox("Sélectionnez deux groupes différents à fusionner");
        return;
    }

    wxString nom_table = CB_typeGroupe->GetStringSelection();
    wxString query = "update livre set id_"+nom_table+" = " + wxString::Format(_T("%d"), idGroupeTo)
                   + " where id_"+nom_table+" = " + wxString::Format(_T("%d"), idGroupeFrom);
//    wxMessageBox(query);
    
    int ret = baseLivre.exec_rapide(query);    
    if (ret < 0) {
        wxString texte;
        baseLivre.get_erreur(texte);
        wxMessageBox("problème à l'exécution de " + query + "\n" + texte);
    }
    if (ret >= 0) {
        query = "delete from " + nom_table + " where rowid=" + wxString::Format(_T("%d"), idGroupeFrom);
        ret = baseLivre.exec_rapide(query);
        if (ret < 0) {
            wxString texte;
            baseLivre.get_erreur(texte);
            wxMessageBox("problème à l'exécution de " + query + "\n" + texte);
        }
    }
    if (ret >= 0)
    {
        InitListeGroupes();
    }
}

/*
 * CB_typeGroupeSelected
 */
void FusionDlg::CB_typeGroupeSelected(wxCommandEvent& event )
{
	InitListeGroupes();
}

/*
 * CB_typeTriSelected
 */
void FusionDlg::CB_typeTriSelected(wxCommandEvent& event )
{
	InitListeGroupes();
}
