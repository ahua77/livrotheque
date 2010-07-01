//---------------------------------------------------------------------------
//
// Name:        rech_internet_gen.cpp
// Author:      Epaillard
// Created:     06/07/05 16:51:43
//
//Copyright  PE Epaillard, 06/07/05 
//
//Fougny@gmail.com
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
//---------------------------------------------------------------------------

#include "rech_internet_gen.h"

#include <wx/clipbrd.h>
//Do not add custom headers.
//wx-dvcpp designer will remove them
////Header Include Start
////Header Include End

/** conservation en static de la liste des résultats d'une précédente recherche */
liste_caracteristiques rech_internet_gen::s_list_livres;
/** conservation en static de la chaîne recherchée lors d'une précédente recherche */
wxString rech_internet_gen::s_critere;
long rech_internet_gen::s_nbInstances = 0;

//----------------------------------------------------------------------------
// rech_internet_gen
//----------------------------------------------------------------------------
     //Add Custom Events only in the appropriate Block.
    // Code added in  other places will be removed by wx-dvcpp 
    ////Event Table Start
BEGIN_EVENT_TABLE(rech_internet_gen,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(rech_internet_gen::rech_internet_genClose)
	EVT_BUTTON(ID_WXBUTTON_RECHERCHE,rech_internet_gen::WxButton_rechercheClick)
	
	EVT_GRID_CELL_LEFT_DCLICK(rech_internet_gen::WxGrid_precisCellLeftDoubleClick)
	
	EVT_GRID_CELL_LEFT_DCLICK(rech_internet_gen::WxGrid_precisCellLeftDoubleClick)
	EVT_CHECKBOX(ID_WXCHECKBOX_PROXY,rech_internet_gen::WxCheckBox_proxyClick)
	EVT_BUTTON(wxID_CANCEL,rech_internet_gen::WxButton_okClick)
END_EVENT_TABLE()
    ////Event Table End



rech_internet_gen::rech_internet_gen( wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style )
    : wxDialog( parent, id, title, position, size, style)
{
    s_nbInstances++;
    wxLogMessage("rech_internet_gen::rech_internet_gen() - nbInstances = %ld", s_nbInstances);
    CreateGUIControls();
}

rech_internet_gen::~rech_internet_gen() {
    s_nbInstances--;
    wxLogMessage("rech_internet_gen::~rech_internet_gen() - nbInstances = %ld", s_nbInstances);
    sauve_config();
} 

void rech_internet_gen::CreateGUIControls(void)
{
    //Do not add custom Code here
    //wx-devcpp designer will remove them.
    //Add the custom code before or after the Blocks
    ////GUI Items Creation Start

	wxArrayString arrayStringFor_WxRadioBox_choix_recherche;
	arrayStringFor_WxRadioBox_choix_recherche.Add(wxT("Amazon (fr)"));
	arrayStringFor_WxRadioBox_choix_recherche.Add(wxT("Alapage (fr)"));
	arrayStringFor_WxRadioBox_choix_recherche.Add(wxT("Amazon (us)"));
	arrayStringFor_WxRadioBox_choix_recherche.Add(wxT("Amazon (uk)"));
	WxRadioBox_choix_recherche = new wxRadioBox(this, ID_WXRADIOBOX1, wxT("Moteur de recherche"), wxPoint(41, 4), wxSize(122, 95), arrayStringFor_WxRadioBox_choix_recherche, 1, wxRA_SPECIFY_COLS, wxDefaultValidator, wxT("WxRadioBox_choix_recherche"));
	WxRadioBox_choix_recherche->SetToolTip(wxT("Choix du moteur de recherche"));
	WxRadioBox_choix_recherche->SetSelection(0);
	WxRadioBox_choix_recherche->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxButton_recherche = new wxButton(this, ID_WXBUTTON_RECHERCHE, wxT("Rechercher"), wxPoint(594, 115), wxSize(69, 22), 0, wxDefaultValidator, wxT("WxButton_recherche"));
	WxButton_recherche->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, wxT("Double cliquez sur le livre dont vous voulez voir le détail"), wxPoint(109, 139), wxDefaultSize, 0, wxT("WxStaticText1"));
	WxStaticText1->SetFont(wxFont(12, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxGrid_general = new wxGrid(this, ID_WXGRID_GENERAL, wxPoint(13, 454), wxSize(175, 18));
	WxGrid_general->Show(false);
	WxGrid_general->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));
	WxGrid_general->SetDefaultColSize(51);
	WxGrid_general->SetDefaultRowSize(15);
	WxGrid_general->SetRowLabelSize(15);
	WxGrid_general->SetColLabelSize(0);
	WxGrid_general->CreateGrid(1,5,wxGrid::wxGridSelectRows);

	WxGrid_precis = new wxGrid(this, ID_WXGRID_PRECIS, wxPoint(14, 169), wxSize(663, 270));
	WxGrid_precis->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));
	WxGrid_precis->SetDefaultColSize(50);
	WxGrid_precis->SetDefaultRowSize(15);
	WxGrid_precis->SetRowLabelSize(15);
	WxGrid_precis->SetColLabelSize(0);
	WxGrid_precis->CreateGrid(1,5,wxGrid::wxGridSelectRows);

	WxStaticText_recherche = new wxStaticText(this, ID_WXSTATICTEXT_RECHERCHE, wxT("Texte à rechercher :"), wxPoint(7, 118), wxDefaultSize, 0, wxT("WxStaticText_recherche"));
	WxStaticText_recherche->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_recherche = new wxTextCtrl(this, ID_WXEDIT_RECHERCHE, wxT(""), wxPoint(112, 115), wxSize(481, 21), 0, wxDefaultValidator, wxT("WxEdit_recherche"));
	WxEdit_recherche->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxCheckBox_proxy = new wxCheckBox(this, ID_WXCHECKBOX_PROXY, wxT("Utiliser un proxy"), wxPoint(235, 2), wxSize(114, 21), 0, wxDefaultValidator, wxT("WxCheckBox_proxy"));
	WxCheckBox_proxy->SetToolTip(wxT("Coc"));
	WxCheckBox_proxy->SetHelpText(wxT("Cocher la case si vous voulez utiliser un proxy"));
	WxCheckBox_proxy->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_proxy_pass = new wxTextCtrl(this, ID_WXEDIT_PROXY_PASS, wxT(""), wxPoint(498, 74), wxSize(138, 21), wxTE_PASSWORD, wxDefaultValidator, wxT("WxEdit_proxy_pass"));
	WxEdit_proxy_pass->Enable(false);
	WxEdit_proxy_pass->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_proxy_pass = new wxStaticText(this, ID_WXSTATICTEXT_PROXY_PASS, wxT("Password : "), wxPoint(435, 77), wxDefaultSize, 0, wxT("WxStaticText_proxy_pass"));
	WxStaticText_proxy_pass->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_proxy_util = new wxTextCtrl(this, ID_WXEDIT_PROXY_UTIL, wxT(""), wxPoint(498, 43), wxSize(136, 21), 0, wxDefaultValidator, wxT("WxEdit_proxy_util"));
	WxEdit_proxy_util->Enable(false);
	WxEdit_proxy_util->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_proxy_util = new wxStaticText(this, ID_WXSTATICTEXT_PROXY_UTIL, wxT("Utilisateur : "), wxPoint(437, 44), wxDefaultSize, 0, wxT("WxStaticText_proxy_util"));
	WxStaticText_proxy_util->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_proxy_port = new wxTextCtrl(this, ID_WXEDIT_PROXY_PORT, wxT(""), wxPoint(284, 73), wxSize(143, 21), 0, wxDefaultValidator, wxT("WxEdit_proxy_port"));
	WxEdit_proxy_port->Enable(false);
	WxEdit_proxy_port->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_proxy_port = new wxStaticText(this, ID_WXSTATICTEXT_PROXY_PORT, wxT("Port : "), wxPoint(247, 74), wxDefaultSize, 0, wxT("WxStaticText_proxy_port"));
	WxStaticText_proxy_port->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_proxy_adr = new wxTextCtrl(this, ID_WXEDIT_PROXY_ADR, wxT(""), wxPoint(285, 42), wxSize(142, 21), 0, wxDefaultValidator, wxT("WxEdit_proxy_adr"));
	WxEdit_proxy_adr->Enable(false);
	WxEdit_proxy_adr->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_proxy_adr = new wxStaticText(this, ID_WXSTATICTEXT_PROXY_ADR, wxT("Adresse : "), wxPoint(233, 44), wxDefaultSize, 0, wxT("WxStaticText_proxy_adr"));
	WxStaticText_proxy_adr->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxButton_ok = new wxButton(this, wxID_CANCEL, wxT("Annuler"), wxPoint(262, 447), wxSize(92, 28), 0, wxDefaultValidator, wxT("WxButton_ok"));
	WxButton_ok->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticBox_proxy = new wxStaticBox(this, ID_WXSTATICBOX_PROXY, wxT("Paramètre du Proxy"), wxPoint(226, 24), wxSize(417, 81));
	WxStaticBox_proxy->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	SetTitle(wxT("Recherche Internet générale"));
	SetIcon(wxNullIcon);
	SetSize(8,8,704,519);
	Center();
	
    ////GUI Items Creation End
    init_grille(WxGrid_general);
    init_grille(WxGrid_precis);

    load_config();
    change_etat_proxy();

    // affichage de la liste conservée d'une recherche précédente
    if (s_list_livres.GetCount() == 0 ) {
        // wxMessageBox("Pas de données ramenées","probleme", wxOK | wxICON_EXCLAMATION, this);
    } else {
        rempli_grille(WxGrid_precis, &s_list_livres);
    }
    WxEdit_recherche->SetValue(s_critere);
    

}

void rech_internet_gen::rech_internet_genClose(wxCloseEvent& event)
{
    // --> Don't use Close with a wxDialog,
    // use Destroy instead.
wxLogMessage("rech_internet_gen::rech_internet_genClose() - entrée");
    Destroy();
wxLogMessage("rech_internet_gen::rech_internet_genClose() - sortie");
}
 
void rech_internet_gen::WxCheckBox_proxyClick(wxCommandEvent& event)
{
    change_etat_proxy();
	// insert your code here
	event.Skip();
}

void rech_internet_gen::change_etat_proxy(){
    bool etat_check;
    
    etat_check=WxCheckBox_proxy->IsChecked();
    WxEdit_proxy_pass->Enable(etat_check);
    WxEdit_proxy_util->Enable(etat_check);
    WxEdit_proxy_port->Enable(etat_check);
    WxEdit_proxy_adr->Enable(etat_check);
}

void rech_internet_gen::init_grille(wxGrid *grille) {
    wxColour couleur = wxColour::wxColour(64,128,128);
	int ir = grille->GetNumberRows();
	grille->DeleteRows(0, ir);
	//   AppendRows(ir);
/*	ir = grille->GetNumberCols();
	if (ir)
		grille->DeleteCols(0, ir);*/
	grille->SetDefaultColSize(75);
	grille->SetDefaultRowSize(15);
	grille->SetColLabelSize(15);
	grille->SetDefaultCellBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_3DFACE));
	grille->SetRowLabelSize(0);
	grille->SetSelectionBackground(couleur);	
	
    grille->SetColLabelValue(0,"Titre");
    grille->SetColLabelValue(1,"Auteur");
    grille->SetColLabelValue(2,"Editeur");
    grille->SetColLabelValue(3,"Genre");
    grille->SetColLabelValue(4,"ISBN");
    
    grille->AutoSizeColumns();
    grille->AutoSizeRows();
}

void rech_internet_gen::sauve_config() {
    wxLogMessage("rech_internet_gen::sauve_config() - entrée");
    wxString fichier_conf;
    wxString query, mess;
    int ret;
    
    fichier_conf=::wxGetCwd();
    fichier_conf+="\\config";
    config.ouvrir(fichier_conf);
    if (config.existe("rech_internet") == true) {
        query = "DELETE from rech_internet where type_param='PROXY'";
        wxLogMessage(query);
        config.exec_rapide(query);
    } else {
        query="CREATE TABLE rech_internet (type_param TEXT , nom_param TEXT, val1 TEXT, val2 TEXT)";
        wxLogMessage(query);
        ret=config.exec_rapide(query);
        if (ret<0) {
            config.get_erreur(mess);
            wxMessageBox(mess,"sauvegarde de la configuration du proxy", wxOK | wxICON_EXCLAMATION, this);
            return;
        }
    }
    wxLogMessage("WxCheckBox_proxy : 0x%x", WxCheckBox_proxy);
    wxLogMessage("WxCheckBox_proxy : %d", WxCheckBox_proxy->GetValue());
    query="INSERT INTO rech_internet (type_param, nom_param, val1) VALUES ('PROXY', 'UTILISE', '"+wxString::Format("%d",WxCheckBox_proxy->GetValue())+"')";
    wxLogMessage(query);
    ret=config.exec_rapide(query);
    if (ret<0) {
        config.get_erreur(mess);
        wxMessageBox(mess,"sauvegarde de la configuration du proxy", wxOK | wxICON_EXCLAMATION, this);
        return;
    }
    query="INSERT INTO rech_internet (type_param, nom_param, val1) VALUES ('PROXY', 'ADRESSE', '"+WxEdit_proxy_adr->GetValue()+"')";
        wxLogMessage(query);
    ret=config.exec_rapide(query);
    if (ret<0) {
        config.get_erreur(mess);
        wxMessageBox(mess,"sauvegarde de la configuration du proxy", wxOK | wxICON_EXCLAMATION, this);
        return;
    }
    query="INSERT INTO rech_internet (type_param, nom_param, val1) VALUES ('PROXY', 'PORT', '"+WxEdit_proxy_port->GetValue()+"')";
        wxLogMessage(query);
    ret=config.exec_rapide(query);
    if (ret<0) {
        config.get_erreur(mess);
        wxMessageBox(mess,"sauvegarde de la configuration du proxy", wxOK | wxICON_EXCLAMATION, this);
        return;
    }
    query="INSERT INTO rech_internet (type_param, nom_param, val1) VALUES ('PROXY', 'USER', '"+WxEdit_proxy_util->GetValue()+"')";
        wxLogMessage(query);
    ret=config.exec_rapide(query);
    if (ret<0) {
        config.get_erreur(mess);
        wxMessageBox(mess,"sauvegarde de la configuration du proxy", wxOK | wxICON_EXCLAMATION, this);
        return;
    }
    query="INSERT INTO rech_internet (type_param, nom_param, val1) VALUES ('PROXY', 'PASS', '"+WxEdit_proxy_pass->GetValue()+"')";
        wxLogMessage(query);
    ret=config.exec_rapide(query);
    if (ret<0) {
        config.get_erreur(mess);
        wxMessageBox(mess,"sauvegarde de la configuration du proxy", wxOK | wxICON_EXCLAMATION, this);
        return;
    }
    query="INSERT INTO rech_internet (type_param, nom_param, val1) VALUES ('PROXY', 'MOTEUR', '"+wxString::Format("%d",WxRadioBox_choix_recherche->GetSelection())+"')";
        wxLogMessage(query);
    ret=config.exec_rapide(query);
    if (ret<0) {
        config.get_erreur(mess);
        wxMessageBox(mess,"sauvegarde de la configuration du moteur", wxOK | wxICON_EXCLAMATION, this);
        return;
    }
        wxLogMessage("avant config.fermer");
    config.fermer();
    wxLogMessage("rech_internet_gen::sauve_config() - sortie");
}    


void rech_internet_gen::load_config() {
    wxString fichier_conf, mess;
    wxString query,nom_param, valeur="";
    int ret, taille; 
    long utilise;
    
    fichier_conf=::wxGetCwd();
    fichier_conf+="\\config";
    config.ouvrir(fichier_conf);
    query = "SELECT nom_param, val1 FROM rech_internet WHERE type_param='PROXY'";
    ret=config.transac_prepare(query);

    ret=config.transac_step();

    while(ret==SQLITE_ROW ) {
        config.get_value_char(0,nom_param,taille);
        config.get_value_char(1,valeur,taille);
        if (nom_param == "UTILISE") {
            valeur.ToLong(&utilise);
            WxCheckBox_proxy->SetValue((bool)utilise);
        } else if (nom_param == "ADRESSE") {
            WxEdit_proxy_adr->SetValue(valeur);
        } else if (nom_param == "PORT") {
            WxEdit_proxy_port->SetValue(valeur);
        } else if (nom_param == "USER") {
            WxEdit_proxy_util->SetValue(valeur);
        } else if (nom_param == "PASS") {
            WxEdit_proxy_pass->SetValue(valeur);
        } else if (nom_param == "MOTEUR") {
            valeur.ToLong(&utilise);
            WxRadioBox_choix_recherche->SetSelection((int)utilise);
        }
        ret=config.transac_step();
    }  
    config.transac_fin();
    //wxMessageBox(valeur,"probleme", wxOK | wxICON_EXCLAMATION, this);
    config.fermer();

}    

void rech_internet_gen::rempli_grille(wxGrid *Grille, liste_caracteristiques *laliste) {
    caracteristiques* ccar;
	wxColour couleur = wxColour::wxColour(230,255,230);
    
    Grille->ClearGrid();
	laliste->Init_parcours();
    int nbRows=Grille->GetNumberRows();

	Grille->DeleteRows(0,nbRows);
    int i=0;
    while (ccar=laliste->Suivant())
    {
       //wxMessageBox(ccar->Affiche(),"Caracteristiques", wxOK | wxICON_EXCLAMATION);
        //ListeB->Append(ccar->Affiche());
        Grille->AppendRows(1,true);

        Grille->SetCellValue(i,0,ccar->Titre);
        Grille->SetCellBackgroundColour(i,0,couleur);
        Grille->SetCellValue(i,1,ccar->Auteur);
        Grille->SetCellBackgroundColour(i,1,couleur);
        Grille->SetCellValue(i,2,ccar->Editeur);
        Grille->SetCellBackgroundColour(i,2,couleur);
        Grille->SetCellValue(i,3,ccar->Genre);
        Grille->SetCellBackgroundColour(i,3,couleur);
        Grille->SetCellValue(i,4,ccar->Isbn);
        Grille->SetCellBackgroundColour(i,4,couleur);
        i++;
    }
    for (int j=0;j<Grille->GetNumberRows();j++)
    {
        for (int k=0;k<Grille->GetNumberCols();k++)
        {
            Grille->SetReadOnly(j,k,true);
        }
    }
    
    Grille->AutoSizeColumns();
    Grille->AutoSizeRows();
	Grille->SetSelectionMode(wxGrid::wxGridSelectRows);
}

/*
 * WxButton_okClick
 */
void rech_internet_gen::WxButton_okClick(wxCommandEvent& event)
{
    SetReturnCode(-1);
    Destroy();
	// insert your code here
	event.Skip();
}

/*
 * WxButton_rechercheClick
 */
void rech_internet_gen::WxButton_rechercheClick(wxCommandEvent& event)
{
//    liste_caracteristiques list_livres;

//    liste_caracteristiques list_caractPopu;
//    liste_caracteristiques list_caractAutre;
    LIVRE_HTML l_livre;
    wxString mess;
    //wxCursor *curseur_wait;
    
    if (WxEdit_recherche->GetValue().Length() == 0) {
        wxMessageBox("Le champ recherche doit au moins contenir du texte....","probleme", wxOK | wxICON_EXCLAMATION, this);
        return;
    }
    //list_caractPopu.Effacer();
    //list_caractAutre.Effacer();
    s_list_livres.Effacer();
     wxSetCursor(wxCursor(wxCURSOR_WAIT));
    l_livre.setproxy(WxCheckBox_proxy->GetValue(), WxEdit_proxy_adr->GetValue(), WxEdit_proxy_port->GetValue(), WxEdit_proxy_util->GetValue(), WxEdit_proxy_pass->GetValue());

    // mémorisation du critère de recherche pour le prochain affichage de la fenêtre    
    s_critere = WxEdit_recherche->GetValue();
    l_livre.chercher_texte(WxEdit_recherche->GetValue(),s_list_livres, WxRadioBox_choix_recherche->GetSelection());
//    l_livre.chercher_texte(WxEdit_recherche->GetValue(),list_caractPopu,list_caractAutre, WxRadioBox_choix_recherche->GetSelection());

    //curseur_wait = new wxCursor(wxCURSOR_WAIT);

    if (s_list_livres.GetCount() == 0 ) {
        wxMessageBox("Pas de données ramenées","probleme", wxOK | wxICON_EXCLAMATION, this);
    } else {
        rempli_grille(WxGrid_precis, &s_list_livres);
    }
/*    if (list_caractPopu.GetCount() == 0 && list_caractAutre.GetCount() == 0) {
        wxMessageBox("Pas de données ramenées","probleme", wxOK | wxICON_EXCLAMATION, this);
    } else {
        rempli_grille(WxGrid_precis, &list_caractPopu);
        rempli_grille(WxGrid_general, &list_caractAutre);
    }*/
    wxSetCursor(wxNullCursor);

	// insert your code here
	event.Skip();
}

/*
 * WxGrid_precisCellLeftDoubleClick
 */
void rech_internet_gen::WxGrid_precisCellLeftDoubleClick(wxGridEvent& event)
{
    wxGrid *lagrille;
    int ret;
    
    lagrille = (wxGrid*)event.GetEventObject();
    //wxMessageBox(lagrille->GetCellValue(event.GetRow(),4),"probleme", wxOK | wxICON_EXCLAMATION, this);
    ma_recherche=new rech_internet(lagrille->GetCellValue(event.GetRow(),4), this, WxRadioBox_choix_recherche->GetSelection());
    
   /* wxClipboard *monclip;
    monclip = new wxClipboard();
    monclip->Open();
    wxTextDataObject my_data(lagrille->GetCellValue(event.GetRow(),0));
    monclip->SetData( &my_data );
    monclip->Close();*/
    
    ret=ma_recherche->ShowModal();
    if (ret == 0) { 
        SetReturnCode(0);
        Destroy();
    } else {
        //delete(ma_recherche);
    }

	// insert your code here
	//event.Skip();

}
