//---------------------------------------------------------------------------
//
// Name:        newProgramFrame.cpp
// Author:      
// Created:     10/27/2004 12:22:10 AM04-FEV-2005 00:00:00
//
// Copyright: PE Epaillard, 10/27/2004 
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

#ifdef __GNUG__
    #pragma implementation "biblioFrame.cpp"
#endif

/* for compilers that support precompilation
   includes "wx/wx.h" */

#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

 #include "biblioFrame.h"



#include "star1.xpm" 
#include "star2.xpm"
#include "splash.xpm"
////Header Include Start
#include "Images/Self_biblioFrame_XPM.xpm"
#include "Images/biblioFrame_WxToolButton_about_XPM.xpm"
#include "Images/biblioFrame_WxToolButton_stat_XPM.xpm"
#include "Images/biblioFrame_WxToolButton_tri_XPM.xpm"
#include "Images/biblioFrame_WxToolButton_colonne_XPM.xpm"
#include "Images/biblioFrame_toolb_inserer_XPM.xpm"
#include "Images/biblioFrame_toolb_ouvrir_XPM.xpm"
#include "Images/biblioFrame_toolb_Nouv_XPM.xpm"
#include "Images/biblioFrame_toolb_quit_XPM.xpm"
#include "Images/parametrer_xpm.xpm"
#include "Images/fusionner_xpm.xpm"
// #include "Images/inserer_xpm.xpm"
#include "Images/inserer_isbn_xpm.xpm"
// #include "Images/ouvrir_base_xpm.xpm"
// #include "Images/nouvelle_base_xpm.xpm"
// #include "Images/quitter_xpm.xpm"

////Header Include End

#include "ParametreDlg.h"
#include "ParamManager.h"



#define style_dialog_choix wxSYSTEM_MENU|wxCAPTION

//----------------------------------------------------------------------------
// newProgramFrame
//----------------------------------------------------------------------------
DEFINE_EVENT_TYPE(wxEVENT_SUPPRESSION)

    ////Event Table Start
BEGIN_EVENT_TABLE(biblioFrame,wxFrame)
	////Manual Code Start
	//EVT_KEY_DOWN(biblioFrame::OnKeyDown)
	//EVT_SPLITTER_SASH_POS_CHANGED( ID_SPLITTERWINDOW, biblioFrame::OnSplitterwindowSashPosChanged )
	EVT_SPLITTER_SASH_POS_CHANGED( ID_SPLITTERWINDOW1, biblioFrame::OnSplitterwindowSashPosChanged )
	//EVT_SPLITTER_SASH_POS_CHANGED( ID_SPLITTERWINDOW2, biblioFrame::OnSplitterwindowSashPosChanged )
	EVT_SPLITTER_DCLICK( ID_SPLITTERWINDOW1, biblioFrame::OnSplitterwindowDclick )
	EVT_SPLITTER_DCLICK( ID_SPLITTERWINDOW2, biblioFrame::OnSplitterwindowDclick )
	EVT_SPLITTER_DCLICK( ID_SPLITTERWINDOW, biblioFrame::OnSplitterwindowDclick )
	EVT_GRID_CMD_CELL_LEFT_DCLICK(ID_WXGRID_GRILLE, biblioFrame::OnSelectLivre)
	EVT_GRID_CMD_CELL_RIGHT_CLICK(ID_WXGRID_GRILLE, biblioFrame::OnGrilleClickDroit)
	EVT_TREE_SEL_CHANGED(ID_TREE_ARBRE, biblioFrame::OnArbreSel)
	//EVT_GRID_CMD_CELL_LEFT_CLICK(ID_WXGRID_GRILLE, biblioFrame::OnSelectlignegrille)
	EVT_GRID_CMD_SELECT_CELL(ID_WXGRID_GRILLE, biblioFrame::OnSelectlignegrille)
	EVT_MENU(ID_EFFACELIVRE , biblioFrame::popup_effacelivre)
	EVT_COMMAND  (ID_WXGRID_GRILLE, wxEVENT_SUPPRESSION, biblioFrame::OnSuppression)
	EVT_HTML_LINK_CLICKED(ID_HTMLWINDOW,biblioFrame::image_click)
	////Manual Code End
	
	EVT_CLOSE(biblioFrame::biblioFrameClose)
	EVT_MENU(ID_MNU_OUVRIR_1022, biblioFrame::OuvrirClick)
	EVT_MENU(ID_MNU_CREERUNEBASE_1023, biblioFrame::toolb_NouvClick)
	EVT_MENU(ID_MNU_MENUITEM30_1058, biblioFrame::Mnuitem_imprimerlivre)
	EVT_MENU(ID_MNU_IMPRIMERLALISTE_1059, biblioFrame::Mnumenuitem_imprimeliste)
	EVT_MENU(ID_MNU_EXPORTHTML_1060, biblioFrame::Mnuexporthtml1060Click)
	EVT_MENU(ID_MNU_EXPORTCSV_1062, biblioFrame::Mnuexportcsv1062Click)
	EVT_MENU(ID_MNU_IMPORTERCVS_1026, biblioFrame::MnuimportercvsClick)
	EVT_MENU(ID_MNU_QUITTER_1011, biblioFrame::toolb_quitClick)
	EVT_MENU(ID_MNU_ORDREDETRI, biblioFrame::MnuordredetriClick)
	EVT_MENU(ID_MNU_PARAMETRES, biblioFrame::parametrer)
	EVT_MENU(ID_MNU_CHOIXCOLONNES_1024, biblioFrame::popup_MnuouvrirClick)
	EVT_MENU(ID_MNU_LISTE_AUTEUR, biblioFrame::Mnulistes)
	EVT_MENU(ID_MNU_LISTE_SERIE, biblioFrame::Mnulistes)
	EVT_MENU(ID_MNU_LISTE_GENRE, biblioFrame::Mnulistes)
	EVT_MENU(ID_MNU_LISTE_EDITEUR, biblioFrame::Mnulistes)
	EVT_MENU(ID_MNU_LISTE_FORMAT, biblioFrame::Mnulistes)
	EVT_MENU(ID_MNU_LISTE_ARTISTE, biblioFrame::Mnulistes)
	EVT_MENU(ID_MNU_LISTE_ETAT, biblioFrame::Mnulistes)
	EVT_MENU(ID_MNU_LISTE_LOCALISATION, biblioFrame::Mnulistes)
	EVT_MENU(ID_MNU_LISTE_PAYS, biblioFrame::Mnulistes)
	EVT_MENU(ID_MNU_LISTE_LANGUE, biblioFrame::Mnulistes)
	EVT_MENU(ID_MNU_LISTE_TRADUCTEUR, biblioFrame::Mnulistes)
	EVT_MENU(ID_MNU_LISTE_SERIE_O, biblioFrame::Mnulistes)
	EVT_MENU(ID_MNU_RECHERCHER_1045, biblioFrame::MnurechercherClick)
	EVT_MENU(ID_MNU_STATISTIQUE_1048, biblioFrame::Mnustatistique1048Click)
	EVT_MENU(ID_MNU__APROPOS_1047, biblioFrame::Mnuapropos1047Click)
	EVT_MENU(ID_MNU_OUVRIR_1015 , biblioFrame::popup_MnuouvrirClick)
	EVT_MENU(ID_WXTOOLBUTTON_ABOUT,biblioFrame::Mnuapropos1047Click)
	EVT_MENU(ID_WXTOOLBUTTON_STAT,biblioFrame::Mnustatistique1048Click)
	EVT_MENU(ID_WXTOOLBUTTON_TRI,biblioFrame::MnuordredetriClick)
	EVT_MENU(ID_WXTOOLBUTTON_COLONNE,biblioFrame::popup_MnuouvrirClick)
	EVT_MENU(ID_WXTOOLB_INSERER,biblioFrame::insererClick)
	EVT_MENU(ID_WXTOOLB_INSERER_ISBN,biblioFrame::insererClickIsbn)
	EVT_MENU(ID_WXTOOLB_FUSION_GENRE,biblioFrame::fusionGenre)
	EVT_MENU(ID_WXTOOLB_PARAM,biblioFrame::parametrer)
	EVT_MENU(ID_TOOLB_OUVRIR,biblioFrame::OuvrirClick)
	EVT_MENU(ID_TOOLB_NOUV,biblioFrame::toolb_NouvClick)
	EVT_MENU(ID_TOOLB_QUIT,biblioFrame::toolb_quitClick)
END_EVENT_TABLE()
    ////Event Table End



biblioFrame::biblioFrame( wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style )
    : wxFrame( parent, id, title, position, size, style)
{
    // creation d'un param manager pour la base config qui reste actif pendant toute la duree de vie du programme
    wxString fichier_conf;    
    fichier_conf=::wxGetCwd();
    fichier_conf+=wxFileName::GetPathSeparators()+"config";
    config.ouvrir(fichier_conf);
    ParamManager* param = new ParamManager(config, "config");

    BOOL useSplash = true;
    param->GetOrSet("config", "INIT", "USE_SPLASH", useSplash);
    
    
    // l'option -nosplash permet d'empêcher l'affichage du splash screen, essentiellement à des fins de debug en cas de pb de démarrage
    if (wxTheApp->argc >1) {
        for (int ii = 1; ii < wxTheApp->argc; ii++)
        {
            wxString arg = _T(wxTheApp->argv[ii]);
            if (arg == "-nosplash")
                useSplash = false;
        }
    }
        
    wxSplashScreen* splash = NULL;
    if (useSplash) {
        wxBitmap WxStaticBitmap_splash(splash_xpm);
        splash = new wxSplashScreen(WxStaticBitmap_splash,
           wxSPLASH_CENTRE_ON_PARENT|wxSPLASH_TIMEOUT,
           6000, NULL, -1, wxDefaultPosition, wxDefaultSize,
           wxSIMPLE_BORDER|wxSTAY_ON_TOP);
    }
    CreateGUIControls();

    load_config();
    if (useSplash && splash != NULL) {
       splash->~wxSplashScreen();
    }
}

biblioFrame::~biblioFrame()
{ 
    delete mastat;
    amoi.fermer();
} 
void biblioFrame::init_arbre() {
    wxTreeItemId root;
    wxTreeItemId branche;
    wxString query;
    wxString texte, mess;
    char c;
    int ret, taille;
    
    arbre->DeleteAllItems();
    
    root=arbre->AddRoot("tous");
   
    for (c='A';c<='Z';c++) {
        query.Printf("select nom from auteur where nom LIKE '%c%%' ORDER by nom", c);

        ret=amoi.transac_prepare(query);
        if (ret<0) {
            amoi.get_erreur(mess);
            wxMessageBox("init_arbre "+mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
            amoi.fermer();
            return;
        }    
        ret=amoi.transac_step();
        if (ret == SQLITE_ROW) {
            texte.Printf("%c",c);
            branche=arbre->AppendItem(root, texte);
        }    
        while(ret==SQLITE_ROW) {

            if (ret<0) {
                amoi.get_erreur(mess);
                wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
            }else {
                amoi.get_value_char(0,texte,taille);
                arbre->AppendItem(branche, texte);
            }     
            ret=amoi.transac_step();
        }    
        amoi.transac_fin();
    }  
    arbre->SelectItem(root);
    arbre->Expand(root);
}

void biblioFrame::init_colonnes() {
    wxString texte;
    wxString query;
    bool defaut = true;
    int ret,taille;
    
    liste_choisis.Clear();
    liste_choisis_nom.Clear();
    liste_tri.Clear();
    if (amoi.ouverte() == true) {
        // récupération des colonnes affichées
        query = "SELECT val1, val2 FROM config WHERE type_param='INIT' AND nom_param='COLONNE'";
        ret=amoi.transac_prepare(query);
        if (ret>=0) {
            ret=amoi.transac_step();
        }    
        while(ret==SQLITE_ROW) {
            amoi.get_value_int(0,ret);
            liste_choisis.Add(ret);
            amoi.get_value_char(1,texte,taille);
            //wxMessageBox(texte,"probleme", wxOK | wxICON_EXCLAMATION, this);
            liste_choisis_nom.Add(texte);
            defaut=false;
            ret=amoi.transac_step();
        }    
        amoi.transac_fin();
        // récupération du tri
        query = "SELECT val1 FROM config WHERE type_param='INIT' AND nom_param='TRI'";
        ret=amoi.transac_prepare(query);
        if (ret>=0) {
            ret=amoi.transac_step();
        }    
        while(ret==SQLITE_ROW) {
            amoi.get_value_int(0,ret);
            liste_tri.Add(ret);
            //wxMessageBox(texte,"probleme", wxOK | wxICON_EXCLAMATION, this);
            ret=amoi.transac_step();
        }    
        amoi.transac_fin();
    }    
    // choix par défaut
    
    if (defaut == true) {
        liste_choisis.Add(0);
        liste_choisis.Add(2);
        liste_choisis.Add(1);
        liste_choisis.Add(4);
        liste_choisis_nom.Add("id");
        liste_choisis_nom.Add("auteur");
        liste_choisis_nom.Add("titre");
        liste_choisis_nom.Add("serie");
        liste_tri.Add(2);
        liste_tri.Add(4);
        liste_tri.Add(5);
    }    
    
    int i=0;
    liste_a_choisir.Clear();
    liste_a_choisir.Add("rowid");
//    while(strlen(nom_token_livre[i]) > 0) {
    while(monlivre.get_nom_token(i).Length() > 0) {
        texte=monlivre.get_nom_token(i);
        if(texte.Left(6) != "image_") {
            liste_a_choisir.Add(texte);
        }    
        i++;
    }    

}    
void biblioFrame::CreateGUIControls(void)
{
	//wxMenu *ID_MNU_LISTES_1027_Mnu_Obj = new wxMenu(0);
    ////GUI Items Creation Start

	toolb_princ = new wxToolBar(this, ID_TOOLB_PRINC, wxPoint(0,0), wxSize(691,26), wxTB_DOCKABLE);

	wxBitmap toolb_quit_BITMAP (biblioFrame_toolb_quit_XPM);
//	wxBitmap toolb_quit_BITMAP (quitter_xpm);
	wxBitmap toolb_quit_DISABLE_BITMAP (wxNullBitmap);
	toolb_princ->AddTool(ID_TOOLB_QUIT, wxT(""), toolb_quit_BITMAP, toolb_quit_DISABLE_BITMAP, wxITEM_NORMAL, 
                         wxT("Quitter"), wxT("Ce bouton sert à sortir de l'application"));

	toolb_princ->AddSeparator();

	wxBitmap toolb_Nouv_BITMAP (biblioFrame_toolb_Nouv_XPM);
//	wxBitmap toolb_Nouv_BITMAP (nouvelle_base_xpm);
	wxBitmap toolb_Nouv_DISABLE_BITMAP (wxNullBitmap);
	toolb_princ->AddTool(ID_TOOLB_NOUV, wxT(""), toolb_Nouv_BITMAP, toolb_Nouv_DISABLE_BITMAP, wxITEM_NORMAL, 
                         wxT("nouvelle base"), wxT("Créer une nouvelle base"));

	wxBitmap toolb_ouvrir_BITMAP (biblioFrame_toolb_ouvrir_XPM);
//	wxBitmap toolb_ouvrir_BITMAP (ouvrir_base_xpm);
	wxBitmap toolb_ouvrir_DISABLE_BITMAP (wxNullBitmap);
	toolb_princ->AddTool(ID_TOOLB_OUVRIR, wxT(""), toolb_ouvrir_BITMAP, toolb_ouvrir_DISABLE_BITMAP, wxITEM_NORMAL, 
                         wxT("ouvrir"), wxT("ouvrir une base existante"));

	toolb_princ->AddSeparator();

	wxBitmap toolb_inserer_BITMAP (biblioFrame_toolb_inserer_XPM);
//	wxBitmap toolb_inserer_BITMAP (inserer_xpm);
	wxBitmap toolb_inserer_DISABLE_BITMAP (wxNullBitmap);
	toolb_princ->AddTool(ID_WXTOOLB_INSERER, wxT("toolb_inserer"), toolb_inserer_BITMAP, toolb_inserer_DISABLE_BITMAP, wxITEM_NORMAL, 
                         wxT("Insérer (F2)"), wxT("Insérer un livre dans la base"));

	wxBitmap toolb_inserer_isbn_BITMAP (inserer_isbn_xpm);
	wxBitmap toolb_inserer_isbn_DISABLE_BITMAP (wxNullBitmap);
	toolb_princ->AddTool(ID_WXTOOLB_INSERER_ISBN, wxT("toolb_inserer_isbn"), toolb_inserer_isbn_BITMAP, toolb_inserer_isbn_DISABLE_BITMAP, 
                         wxITEM_NORMAL, wxT("Insérer par l'ISBN (F3)"), wxT("Insérer un livre dans la base en recherchant son code barre"));

	toolb_princ->AddSeparator();

	wxBitmap WxToolButton_colonne_BITMAP (biblioFrame_WxToolButton_colonne_XPM);
	wxBitmap WxToolButton_colonne_DISABLE_BITMAP (wxNullBitmap);
	toolb_princ->AddTool(ID_WXTOOLBUTTON_COLONNE, wxT("WxToolButton_colonne"), WxToolButton_colonne_BITMAP, WxToolButton_colonne_DISABLE_BITMAP, wxITEM_NORMAL, 
                         wxT("Choix des colonnes"), wxT("Choisir les colonnes à afficher"));

	wxBitmap WxToolButton_tri_BITMAP (biblioFrame_WxToolButton_tri_XPM);
	wxBitmap WxToolButton_tri_DISABLE_BITMAP (wxNullBitmap);
	toolb_princ->AddTool(ID_WXTOOLBUTTON_TRI, wxT("WxToolButton_tri"), WxToolButton_tri_BITMAP, WxToolButton_tri_DISABLE_BITMAP, wxITEM_NORMAL, 
                         wxT("Tri"), wxT("Choix des colonnes utilisées pour le tri"));

	toolb_princ->AddSeparator();

	wxBitmap toolb_fusion_genre_BITMAP (fusionner_xpm);
	wxBitmap toolb_fusion_genre_DISABLE_BITMAP (wxNullBitmap);
	toolb_princ->AddTool(ID_WXTOOLB_FUSION_GENRE, wxT("toolb_fusion_genre"), toolb_fusion_genre_BITMAP, toolb_fusion_genre_DISABLE_BITMAP, 
                         wxITEM_NORMAL, wxT("fusionner deux genres"), wxT("Fusionner deux genres"));

	toolb_princ->AddSeparator();

	wxBitmap WxToolButton_stat_BITMAP (biblioFrame_WxToolButton_stat_XPM);
	wxBitmap WxToolButton_stat_DISABLE_BITMAP (wxNullBitmap);
	toolb_princ->AddTool(ID_WXTOOLBUTTON_STAT, wxT("WxToolButton_stat"), WxToolButton_stat_BITMAP, WxToolButton_stat_DISABLE_BITMAP, wxITEM_NORMAL, 
                         wxT("statistiques "), wxT("Affiche des statistiques sur la base"));

	toolb_princ->AddSeparator();

	wxBitmap toolb_parametres_BITMAP (parametrer_xpm);
	wxBitmap toolb_parametres_DISABLE_BITMAP (wxNullBitmap);
	toolb_princ->AddTool(ID_WXTOOLB_PARAM, wxT("toolb_parametres"), toolb_parametres_BITMAP, toolb_parametres_DISABLE_BITMAP, wxITEM_NORMAL, 
                         wxT("paramétrer l'application"), wxT("paramétrer l'application"));

	toolb_princ->AddSeparator();

	wxBitmap WxToolButton_about_BITMAP (biblioFrame_WxToolButton_about_XPM);
	wxBitmap WxToolButton_about_DISABLE_BITMAP (wxNullBitmap);
	toolb_princ->AddTool(ID_WXTOOLBUTTON_ABOUT, wxT("WxToolButton_about"), WxToolButton_about_BITMAP, WxToolButton_about_DISABLE_BITMAP, wxITEM_NORMAL, 
                         wxT("a propos"), wxT("A propos de la livrotheque"));

	barre_statut = new wxStatusBar(this, ID_BARRE_STATUT);

	WxPopupMenu_grille = new wxMenu(wxT(""));WxPopupMenu_grille->Append(ID_MNU_OUVRIR_1015, wxT("Choix des colonnes"), wxT("Permet de choisir les colonnes affichée pour chaque livre"), wxITEM_NORMAL);

	monmenu = new wxMenuBar();
	wxMenu *ID_MNU_FICHIER_QUIT_Mnu_Obj = new wxMenu(0);
	ID_MNU_FICHIER_QUIT_Mnu_Obj->Append(ID_MNU_OUVRIR_1022, wxT("Ouvrir une Base"), wxT(""), wxITEM_NORMAL);
	ID_MNU_FICHIER_QUIT_Mnu_Obj->Append(ID_MNU_CREERUNEBASE_1023, wxT("Creer une base"), wxT(""), wxITEM_NORMAL);
	ID_MNU_FICHIER_QUIT_Mnu_Obj->AppendSeparator();
	ID_MNU_FICHIER_QUIT_Mnu_Obj->Append(ID_MNU_MENUITEM30_1058, wxT("Imprimer le &livre"), wxT(""), wxITEM_NORMAL);
	ID_MNU_FICHIER_QUIT_Mnu_Obj->Append(ID_MNU_IMPRIMERLALISTE_1059, wxT("&Imprimer la liste"), wxT(""), wxITEM_NORMAL);
	ID_MNU_FICHIER_QUIT_Mnu_Obj->AppendSeparator();
	ID_MNU_FICHIER_QUIT_Mnu_Obj->Append(ID_MNU_EXPORTHTML_1060, wxT("Export HTML"), wxT("Permet d'exporter la base au format HTML"), wxITEM_NORMAL);
	ID_MNU_FICHIER_QUIT_Mnu_Obj->Append(ID_MNU_EXPORTCSV_1062, wxT("Export CSV"), wxT(""), wxITEM_NORMAL);
	ID_MNU_FICHIER_QUIT_Mnu_Obj->AppendSeparator();
	ID_MNU_FICHIER_QUIT_Mnu_Obj->Append(ID_MNU_IMPORTERCVS_1026, wxT("Import CSV"), wxT("Importer des données à partir d'un fichier au format CVS"), wxITEM_NORMAL);
	ID_MNU_FICHIER_QUIT_Mnu_Obj->AppendSeparator();
	ID_MNU_FICHIER_QUIT_Mnu_Obj->Append(ID_MNU_QUITTER_1011, wxT("Quitter"), wxT(""), wxITEM_NORMAL);
	monmenu->Append(ID_MNU_FICHIER_QUIT_Mnu_Obj, wxT("Fichier"));
	
	wxMenu *ID_MNU_OUTIL_1017_Mnu_Obj = new wxMenu(0);
	ID_MNU_OUTIL_1017_Mnu_Obj->Append(ID_MNU_PARAMETRES, wxT("Paramètres"), wxT("Configuration de l'application"), wxITEM_NORMAL);
	ID_MNU_OUTIL_1017_Mnu_Obj->Append(ID_MNU_ORDREDETRI, wxT("Ordre de tri"), wxT("Permet de Choisir les colonnes utilisées pour le tri"), wxITEM_NORMAL);
	ID_MNU_OUTIL_1017_Mnu_Obj->Append(ID_MNU_CHOIXCOLONNES_1024, wxT("Choix des colonnes affichées"), wxT(""), wxITEM_NORMAL);
	
	wxMenu *ID_MNU_LISTES_1027_Mnu_Obj = new wxMenu(0);
	ID_MNU_LISTES_1027_Mnu_Obj->Append(ID_MNU_LISTE_AUTEUR, wxT("Auteur"), wxT(""), wxITEM_NORMAL);
	ID_MNU_LISTES_1027_Mnu_Obj->Append(ID_MNU_LISTE_SERIE, wxT("Serie"), wxT(""), wxITEM_NORMAL);
	ID_MNU_LISTES_1027_Mnu_Obj->Append(ID_MNU_LISTE_GENRE, wxT("Genre"), wxT(""), wxITEM_NORMAL);
	ID_MNU_LISTES_1027_Mnu_Obj->Append(ID_MNU_LISTE_EDITEUR, wxT("Editeur"), wxT(""), wxITEM_NORMAL);
	ID_MNU_LISTES_1027_Mnu_Obj->Append(ID_MNU_LISTE_FORMAT, wxT("Format"), wxT(""), wxITEM_NORMAL);
	ID_MNU_LISTES_1027_Mnu_Obj->Append(ID_MNU_LISTE_ARTISTE, wxT("Artiste"), wxT(""), wxITEM_NORMAL);
	ID_MNU_LISTES_1027_Mnu_Obj->Append(ID_MNU_LISTE_ETAT, wxT("Etat"), wxT(""), wxITEM_NORMAL);
	ID_MNU_LISTES_1027_Mnu_Obj->Append(ID_MNU_LISTE_LOCALISATION, wxT("Localisation"), wxT(""), wxITEM_NORMAL);
	ID_MNU_LISTES_1027_Mnu_Obj->Append(ID_MNU_LISTE_PAYS, wxT("Pays"), wxT(""), wxITEM_NORMAL);
	ID_MNU_LISTES_1027_Mnu_Obj->Append(ID_MNU_LISTE_LANGUE, wxT("Langue"), wxT(""), wxITEM_NORMAL);
	ID_MNU_LISTES_1027_Mnu_Obj->Append(ID_MNU_LISTE_TRADUCTEUR, wxT("Traducteur"), wxT(""), wxITEM_NORMAL);
	ID_MNU_LISTES_1027_Mnu_Obj->Append(ID_MNU_LISTE_SERIE_O, wxT("serie originale"), wxT(""), wxITEM_NORMAL);
	ID_MNU_OUTIL_1017_Mnu_Obj->Append(ID_MNU_LISTES_1027, wxT("Listes"), ID_MNU_LISTES_1027_Mnu_Obj);
	monmenu->Append(ID_MNU_OUTIL_1017_Mnu_Obj, wxT("Option"));
	
	wxMenu *ID_MNU_EDITION_1043_Mnu_Obj = new wxMenu(0);
	ID_MNU_EDITION_1043_Mnu_Obj->Append(ID_MNU_RECHERCHER_1045, wxT("Rechercher"), wxT(""), wxITEM_NORMAL);
	ID_MNU_EDITION_1043_Mnu_Obj->Append(ID_MNU_STATISTIQUE_1048, wxT("Statistique"), wxT(""), wxITEM_NORMAL);
	monmenu->Append(ID_MNU_EDITION_1043_Mnu_Obj, wxT("Edition"));
	
	wxMenu *ID_MNU_APROPOS_1046_Mnu_Obj = new wxMenu(0);
	ID_MNU_APROPOS_1046_Mnu_Obj->Append(ID_MNU__APROPOS_1047, wxT("&A propos"), wxT(""), wxITEM_NORMAL);
	monmenu->Append(ID_MNU_APROPOS_1046_Mnu_Obj, wxT("Aide"));
	SetMenuBar(monmenu);

	SetStatusBar(barre_statut);
	toolb_princ->SetToolBitmapSize(wxSize(16,16));
	toolb_princ->SetToolSeparation(12);
	toolb_princ->Realize();
	SetToolBar(toolb_princ);
	SetTitle(wxT("Livrotheque"));
	SetIcon(Self_biblioFrame_XPM);
	SetSize(8,8,699,600);
	Center();
	
    ////GUI Items Creation End
    split_princip = new wxSplitterWindow( this, ID_SPLITTERWINDOW, wxDefaultPosition, wxSize(100, 100), wxWANTS_CHARS|wxNO_BORDER );
    split_princip->SetMinimumPaneSize(10);

    split_gauche = new wxSplitterWindow( split_princip, ID_SPLITTERWINDOW1, wxDefaultPosition, wxSize(100, 100), wxWANTS_CHARS|wxNO_BORDER );

    wxString* choix_arbreStrings = NULL;
    choix_arbre = new wxComboBox( split_gauche, ID_COMBOBOX, _T(""), wxDefaultPosition, wxDefaultSize, 0, choix_arbreStrings, wxWANTS_CHARS|wxCB_DROPDOWN );

    
    arbre = new wxTreeCtrl( split_gauche, ID_TREE_ARBRE, wxDefaultPosition, wxSize(100, 100), wxWANTS_CHARS|wxTR_DEFAULT_STYLE );

    split_gauche->SplitHorizontally(choix_arbre, arbre, 20);
    split_gauche->Unsplit(choix_arbre);
    
    split_droit = new wxSplitterWindow( split_princip, ID_SPLITTERWINDOW2, wxDefaultPosition, wxSize(100, 500), wxWANTS_CHARS|wxNO_BORDER );
    split_droit->SetMinimumPaneSize(10);
    
    grille = new bellegrille( split_droit, ID_WXGRID_GRILLE, wxDefaultPosition, wxSize(200, 150), wxWANTS_CHARS|wxSUNKEN_BORDER|wxHSCROLL|wxVSCROLL );
 
    grille->CreateGrid(0, 0);
	//grille->AppendRows(100);
	//grille->AppendCols(100);

	int ir = grille->GetNumberRows();
	grille->DeleteRows(0, ir);
	//   AppendRows(ir);
	ir = grille->GetNumberCols();
	if (ir)
		grille->DeleteCols(0, ir);
    grille->SetDefaultColSize(50);
    grille->SetDefaultRowSize(15);
    grille->SetColLabelSize(15);
    grille->SetRowLabelSize(0);
	grille->SetSelectionMode(wxGrid::wxGridSelectRows);

    visuhtml = new wxHtmlWindow( split_droit, ID_HTMLWINDOW, wxDefaultPosition, wxSize(100, 150), wxHW_SCROLLBAR_AUTO|wxSUNKEN_BORDER|wxHSCROLL|wxVSCROLL );
    visuhtml->SetBorders(0);
    split_droit->SplitHorizontally(grille, visuhtml, 200);

    split_princip->SplitVertically(split_gauche, split_droit, 120);

    split_droit-> SetSashPosition(400);
    
    //image handler
    wxImage::AddHandler( new wxBMPHandler );
    wxImage::AddHandler( new wxPNGHandler );
    wxImage::AddHandler( new wxJPEGHandler );
    wxImage::AddHandler( new wxGIFHandler );
    wxImage::AddHandler( new wxPCXHandler );
    wxImage::AddHandler( new wxPNMHandler );
    wxImage::AddHandler( new wxTIFFHandler );
    wxImage::AddHandler( new wxXPMHandler ); 	
    
    barre_statut->SetFieldsCount(2);
    
    param_modifie=false;
	mastat=new statistique(NULL);
	grille_ok=false;
	
	wxAcceleratorTable* pAccel = GetAcceleratorTable();
	if (pAccel) {
        // wxMessageBox("pAccel not null","debug", wxOK | wxICON_INFORMATION, this);
        wxAcceleratorEntry entries[3];
        entries[0].Set(wxACCEL_NORMAL, WXK_F2, ID_WXTOOLB_INSERER);
        entries[1].Set(wxACCEL_NORMAL, WXK_F3, ID_WXTOOLB_INSERER_ISBN);
        entries[2].Set(wxACCEL_NORMAL, WXK_INSERT, ID_WXTOOLB_INSERER_ISBN);
        wxAcceleratorTable table (3, entries);
        SetAcceleratorTable(table);
        /* TODO : on perd la table existante - comment la completer au lieu de l'écraser ? */
    } else {
        // wxMessageBox("pAccel null","debug", wxOK | wxICON_INFORMATION, this);
    }
}

void biblioFrame::biblioFrameClose(wxCloseEvent& event)
{
    sauve_config();
    // --> Don't use Close with a Frame,
    // use Destroy instead.
    Destroy();
}

void biblioFrame::OnSplitterwindowSashPosChanged( wxSplitterEvent& event )
{
//@begin wxEVT_COMMAND_SPLITTER_SASH_POS_CHANGING event handler for ID_SPLITTERWINDOW1 in biblioframe.
    // Before editing this code, remove the block markers.
    int pos=event.GetSashPosition();
    wxString texte;
    //texte.Printf("pouet:%d",pos);
    //wxMessageBox(texte,"tralala", wxOK | wxICON_INFORMATION, this);
    if (pos<10) {
        event.SetSashPosition(10);
    }
    split_gauche->SetSashPosition(18,false);
    //event.Skip();
//@end wxEVT_COMMAND_SPLITTER_SASH_POS_CHANGING event handler for ID_SPLITTERWINDOW1 in biblioframe. 
}

void biblioFrame::OnSplitterwindowDclick( wxSplitterEvent& event )
{
    //split_gauche->SetSashPosition(18,false);
    //wxMessageBox("POUET","tralala", wxOK | wxICON_INFORMATION, this);
    event.Veto();
}

  
/*
 * toolb_quitClick
 */
void biblioFrame::toolb_quitClick(wxCommandEvent& event)
{
    sauve_config();
    Destroy();
    //event.Skip();
}

/*
 * OuvrirClick
 */
void biblioFrame::OuvrirClick(wxCommandEvent& event)
{
    
    wxString filename = wxFileSelector("Choix de la base à ouvrir","","","","base (*.db)|*.db|Tous (*.*)|*.*",wxOPEN|wxFILE_MUST_EXIST);

    if ( !filename.empty() )
    {
        ouvrir_base(filename);
    }
  //wxMessageBox("This is a wxWidgets Hello world sample","About Hello World", wxOK | wxICON_INFORMATION, this);
	//event.Skip();
}

void biblioFrame::ouvrir_base(wxString filename) {
    wxString mess, mess2;
    if (amoi.ouverte()==true)
            amoi.fermer();
            
    int ret=amoi.ouvrir(filename);
    if (ret<0) {
        amoi.get_erreur(mess);
        mess2.Printf("probleme :%s avec la base : ",mess.mb_str());
        wxMessageBox(mess2+filename,"probleme lors de l'ouverture", wxOK | wxICON_EXCLAMATION, this);
        return;
    }
    
    init_colonnes();
    /* TODO (#1#): ajout de verification version base */
    remplir_grille("");
    init_arbre();
	this->SetTitle(_("Livrotheque : "+filename));
	mastat->definir_base(&amoi);
}    

int biblioFrame::creer_base() {
     wxString creation;
     wxString mess;
     wxString mess2;
     int ret=0;    
     int i;
    
    i=-1;
    monlivre.gen_create_tout(creation,i);
//    wxMessageBox(creation,"probleme", wxOK | wxICON_INFORMATION, this);
    ret=amoi.exec_rapide(creation);
    if (ret<0) {
        amoi.get_erreur(mess);
        mess2.Printf("probleme :%s : vous devez creer un fichier qui n'existe pas déja",mess.mb_str());
        wxMessageBox(mess2,"probleme lors de la creation", wxOK | wxICON_EXCLAMATION, this);
        return -1;
    }
    while (i>0) {
        monlivre.gen_create_tout(creation,i);
        ret=amoi.exec_rapide(creation);
        if (ret<0) {
            amoi.get_erreur(mess);
            mess2.Printf("probleme :%s : vous devez creer un fichier qui n'existe pas déja",mess.mb_str());
            wxMessageBox(mess2,"probleme lors de la creation", wxOK | wxICON_EXCLAMATION, this);
            return -1;
        }
    }    
    return 0;
}    
/*
 * toolb_NouvClick
 */
void biblioFrame::toolb_NouvClick(wxCommandEvent& event)
{
    int ret;
     //ma_base amoi;
     wxString mess;
   	
    //char file[1000];
    
    wxString filename = wxFileSelector("Creer une nouvelle base","","","db","base (*.db)|*.db|Tous (*.*)|*.*",wxSAVE);


    if ( !filename.empty() )
    {
        if (amoi.ouverte()==true)
                amoi.fermer();
                
        amoi.ouvrir(filename);
        
        ret=creer_base();
        init_colonnes();
        //remplir_grille("");
        init_arbre();
    }
    
	//event.Skip();
}

void biblioFrame::fusionGenre(wxCommandEvent& event)
{
    FusionDlg dlg(this, amoi);
    dlg.ShowModal();
}
    
void biblioFrame::insererClick(wxCommandEvent& event)
{
    insererClick_interne(event, FALSE);
}

void biblioFrame::insererClickIsbn(wxCommandEvent& event)
{
    insererClick_interne(event, TRUE);
}

void biblioFrame::parametrer(wxCommandEvent& event)
{
    ParametreDlg dlg(this);
    dlg.ShowModal();
}

/*
 * insererClick
 */
void biblioFrame::insererClick_interne(wxCommandEvent& event, BOOL isbnMode)
{
    int ret, numrow;
    long id_ins;
    wxString mess;
    
    if (amoi.ouverte()==false) {
        wxMessageBox("Vous devez ouvrir ou créer une base pour inserer un nouveau livre!","probleme", wxOK | wxICON_EXCLAMATION, this);
    } else {
        Nouv_livre insere_livre(&amoi, this, -1, "Entrée d'un nouveau livre", wxDefaultPosition, wxDefaultSize);//, style_dialog_choix);
        
    if (isbnMode) {
        insere_livre.WxEdit_isbn->SetFocus();
    } else {
        insere_livre.WxEdit_titre->SetFocus();
    }
                
        
        ret=insere_livre.ShowModal();
        //si on a insere un enregistrement un réaffiche la grille
        if(ret>0) {
            init_arbre();
            //remplir_grille("");
            id_ins=amoi.last_insert();
            mess.Printf("%d", (int) id_ins);
            //wxMessageBox( mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
            numrow=trouve_ligne(mess);
            grille->MakeCellVisible(numrow,1);
            grille->SelectRow(numrow);
            AfficheLivre(mess);
         }    
    }    
}

void biblioFrame::OnSelectLivre( wxGridEvent &event ) 
{
    int nb_ligne, ret, numrow;
    wxString id;
    wxString mess;
    
    nb_ligne=event.GetRow();
    id=grille->GetRowLabelValue(nb_ligne);
    Nouv_livre insere_livre(&amoi, id,false, this, -1, "Modification du livre", wxDefaultPosition, wxDefaultSize);//, style_dialog_choix);
    ret=insere_livre.ShowModal();
    mess.Printf("%d", ret);
        //si on a inserer un enregistrement un réaffiche la grille
        if(ret>0) {
            //wxMessageBox(mess+" "+id,"coco", wxOK | wxICON_INFORMATION, this);
            init_arbre();
            //remplir_grille("");
            numrow=trouve_ligne(id);
            grille->MakeCellVisible(numrow,1);
            grille->SelectRow(numrow);
            AfficheLivre(id);
        }    

}    

int biblioFrame::trouve_ligne(wxString Label){
    int i;
    
    for (i=0;i<grille->GetNumberRows();i++) {
        if (grille->GetLabelValue(0,i) == Label) {
            return i;
        }
    }
    return 0;        
}    

void biblioFrame::remplir_grille(wxString where)
{
    int i,j;
     int ret;
     wxString mess;
     wxString query;
     wxString texte;
     //int id;
     int taille;
     int nbcol, champ;

    grille_ok=false;
	int ir = grille->GetNumberRows();
	if (ir)
		grille->DeleteRows(0, ir);
	ir = grille->GetNumberCols();
	if (ir)
		grille->DeleteCols(0, ir);

    creation_select_livre(query,where, "order by id_auteur");
    ret=amoi.transac_prepare(query);
        //wxMessageBox(query,"test", wxOK | wxICON_EXCLAMATION, this);
    if (ret<0) {
        amoi.get_erreur(mess);
        mess=query+"\n"+mess;
        wxMessageBox("remplir_grille "+mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        amoi.fermer();
        return;
    }
    ret=SQLITE_ROW;
    ret=amoi.transac_step();
    i=j=0;
    nbcol=amoi.transac_nbcol(); 
    grille->InsertCols(0,(nbcol-1));
    while(ret==SQLITE_ROW) {

        grille->AppendRows();
        if (ret<0) {
            amoi.get_erreur(mess);
            wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        }else {
            for (champ=0; champ<nbcol;champ++) {
                amoi.get_value_char(champ,texte,taille);
                if (champ == 0) {
                    grille->SetRowLabelValue(i,texte);
                } else {    
                    //texte.Printf("%d",id);
                    grille->SetCellValue(i,champ-1,texte);
                    grille->SetReadOnly( i, champ-1, true );
                }   
            }     
        }    
        i++;
        //j=0;
          ret=amoi.transac_step();
    }  
    mess.Printf("%d livres", i);
    SetStatusText(mess,1);
    for (i=0;i<(int)liste_choisis_nom.GetCount();i++) {
        //amoi.get_nom_col(i,texte);
        grille->SetColLabelValue(i,liste_choisis_nom[i]);
    }    
    grille->SetColLabelSize(15);
    grille->SetRowLabelSize(0);
//    grille->EnableEditing(false);
    grille->AutoSizeColumns(true);
    grille->AutoSizeRows(true);
    amoi.transac_fin();
    if (grille->GetNumberRows()>0) {
        grille->SelectRow(0);
        AfficheLivre(grille->GetLabelValue(0,0));
        grille_ok=true;
    }    
}

void biblioFrame::creation_select_livre(wxString &select, wxString where, wxString order_by) {
    int i,present;
//    wxArrayInt join_list;
    wxArrayString join_list;
    wxString texte;
    wxString from;
    wxString sansid;
    wxString join=" ";
    /* TODO (#1#): select livre.rowid,livre.titre, serie.nom from livre LEFT 
                   JOIN serie ON livre.id_serie=serie.rowid  */
    if (liste_tri.GetCount() == 0)
        order_by="";
    else
        order_by="ORDER BY ";
    
    for (i=0;i<(int)liste_tri.GetCount();i++) {
        texte=liste_a_choisir[liste_tri[i]];
        if (texte.Left(3) == "id_") {
            //join_list.Add(liste_tri[i]);
            join_list.Add(texte);
            sansid=texte.Mid(3);
            order_by+=sansid+".nom"+", ";
        } else if (texte.Left(5) == "date_") {
             order_by +=  "substr("+texte+", 7,4)||'/'||substr("+texte+",4,2)||'/'||substr("+texte+", 1,2)"+", ";   
        }
        else {
            if (texte == "rowid")
                texte="livre.rowid";
            order_by+=texte+", ";
        }        
    }    
    order_by.Truncate(order_by.Length()-2);
    select="SELECT livre.rowid, ";
    from=" FROM livre ";
    // création de join_list à partir de la liste des champs selectionnés à l'affichage
    for (i=0;i<(int)liste_choisis.GetCount();i++) {
        texte=liste_a_choisir[liste_choisis[i]];
        if (texte.Left(3) == "id_") {
            sansid=texte.Mid(3);
            select+=" "+sansid+".nom, ";
            //present=join_list.Index(liste_choisis[i]);
            present=join_list.Index(liste_a_choisir[liste_choisis[i]]);
            if (present == wxNOT_FOUND ) {
                //texte.Printf("num:%d chois:%d",present,liste_choisis[i]);
                //wxMessageBox(texte,"coco", wxOK | wxICON_INFORMATION, this);
                //join_list.Add(liste_choisis[i]);
                join_list.Add(liste_a_choisir[liste_choisis[i]]);
            }
            //from +=", "+sansid;
            //join+="LEFT JOIN "+sansid+" ON livre."+texte+"="+sansid+".rowid ";
         /*   if (where.Length() == 0) 
                where += " WHERE livre."+texte+" = "+sansid + ".rowid ";
            else
                where += " AND livre."+texte+" = "+sansid+".rowid ";*/
            
        } else {    
            select+="livre."+texte;
            select += ", ";
        }    
    }    
    // Ajout dans join list de la list_from si il y a quelque chose dedans
    for (i=0;i<(int)list_from.GetCount();i++) {
        present=join_list.Index(list_from[i],false);
        if (present == wxNOT_FOUND ) {
            join_list.Add(list_from[i]);
        }
    }

    // creation du join
    for (i=0;i<(int)join_list.GetCount();i++) {
        //texte=liste_a_choisir[join_list[i]];
        texte=join_list[i];
        //wxMessageBox(texte,"coco", wxOK | wxICON_INFORMATION, this);
        if (texte.Left(3) == "id_") {
            sansid=texte.Mid(3);
            join+="LEFT JOIN "+sansid+" ON livre."+texte+"="+sansid+".rowid ";
        }
    }    
    
    select.Truncate(select.Length()-2);
    select += " "+from+" "+join+" "+where+" "+order_by;
    // wxMessageBox(select,"coco", wxOK | wxICON_INFORMATION, this);
}    

void biblioFrame::OnGrilleClickDroit( wxGridEvent& event ) {
    wxMenuItem *menu_efface;
    int nrow;
    wxString id_l;
    
    nrow=event.GetRow();
    if (amoi.ouverte() == false)
        return;
    id_l=grille->GetLabelValue(0,nrow);
    AfficheLivre(id_l);
    grille->SelectRow(nrow);
	menu_efface=WxPopupMenu_grille->Insert(0, ID_EFFACELIVRE,"effacer le livre sélectionné",_("Permet d'effacer les livres selectionnés"), wxITEM_NORMAL);
    PopupMenu(WxPopupMenu_grille);
    WxPopupMenu_grille->Delete(ID_EFFACELIVRE);
}    

void biblioFrame::OnSelectlignegrille(wxGridEvent &event)
{
    int nrow;
    wxString id_l;
    wxString mess;
    
    if (grille_ok == false || grille->GetNumberRows() == 0)
        return;
    mess.Printf("numb:%d ", grille->GetNumberRows());
    nrow=event.GetRow();
    if (amoi.ouverte() == false)
        return;
    id_l=grille->GetLabelValue(0,nrow);
    /*if (grille_ok == true) 
        wxMessageBox("OK"+mess+id_l,"coco", wxOK | wxICON_INFORMATION, this);
    else
        wxMessageBox("PAS OK"+mess+id_l,"coco", wxOK | wxICON_INFORMATION, this);*/
    AfficheLivre(id_l);
    
    grille->SelectRow(nrow);
    
    //event.Skip();    
}    

void biblioFrame::popup_effacelivre(wxCommandEvent& event){
    wxArrayInt cell_select;
    wxString query, mess, id;
    int ret;

    cell_select=grille->GetSelectedRows();
    if (cell_select.GetCount()>0) {
        ret=wxMessageBox("Etes vous sur de vouloir effacer le livre avec l'id n°"+grille->GetRowLabelValue(cell_select[0])+"?? \n(Attention cet effacement est DEFINITIF!)","Question", wxYES_NO|wxNO_DEFAULT | wxICON_EXCLAMATION, this);
        if (ret == wxYES) {
            id=grille->GetRowLabelValue(cell_select[0]);
            query="DELETE FROM livre WHERE rowid="+id;
            ret=amoi.exec_rapide(query);
            if (ret<0) {
                amoi.get_erreur(mess);
                wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
            }    
            init_arbre();
            //remplir_grille("");
            //ret=wxMessageBox("effacement de "+id,"Question", wxYES_NO|wxNO_DEFAULT |wxICON_EXCLAMATION, this);
        }    
    }    
}    

/*
 * popup_MnuouvrirClick
 */
void biblioFrame::popup_MnuouvrirClick(wxCommandEvent& event)
{
    int ret;
    wxArrayInt liste_choisis_p;
    wxArrayString liste_choisis_nom_p;
    //wxString mess;

    liste_choisis_p=liste_choisis;
    liste_choisis_nom_p=liste_choisis_nom;
    //choix_colonnes choisir(liste_a_choisir, &liste_choisis, &liste_choisis_nom, this, -1, "choix du tri", wxDefaultPosition, wxDefaultSize, wxSYSTEM_MENU|wxCAPTION);
    choix_colonnes choisir(liste_a_choisir, &liste_choisis_p, &liste_choisis_nom_p, this, -1, "choix des colonnes à afficher", wxDefaultPosition, wxDefaultSize, style_dialog_choix);
    ret=choisir.ShowModal();
    if (ret==0) {
        //mess.Printf("ret:%d",ret);
        //wxMessageBox(mess,"coco", wxOK | wxICON_INFORMATION, this);
        liste_choisis=liste_choisis_p;
        liste_choisis_nom=liste_choisis_nom_p;
        init_arbre();
        //remplir_grille("");
        param_modifie=true;
     }    
   
    //event.Skip();
}

void biblioFrame::OnArbreSel(wxTreeEvent &event) {
    wxString val, ancienne_val;
    wxTreeItemId branche, ancienne_branche;
    wxTreeItemId root;
    wxString where;
    
    ancienne_branche=event.GetOldItem();
    branche=event.GetItem();
    root=arbre->GetRootItem();
    val=arbre->GetItemText(branche);
    if (ancienne_branche != branche ) {
        if (branche == root) {
            remplir_grille("");
        }
        else {
            if (val.Length() == 1) {
                where="WHERE auteur.nom LIKE '"+val+"%%' ";
                remplir_grille(where);
            } else {
                where="WHERE auteur.nom='"+val+"' ";
                remplir_grille(where);
            }                    
        }    
    }
}    

/*
 * MnuordredetriClick
 */
void biblioFrame::MnuordredetriClick(wxCommandEvent& event)
{
     wxArrayInt liste_tri_p;
     int ret;
     wxArrayString liste_tri_nom_p;

	liste_tri_p=liste_tri;
    choix_colonnes choisir(liste_a_choisir, &liste_tri_p, NULL, this, -1, "choix des champs utilisés pour le tri", wxDefaultPosition, wxDefaultSize, style_dialog_choix);
    ret=choisir.ShowModal();
    if (ret==0) {
        liste_tri=liste_tri_p;
        //liste_choisis_nom=liste_choisis_nom_p;
        init_arbre();
        //remplir_grille("");
        param_modifie=true;
     }    
   
    //event.Skip();
}
void biblioFrame::AfficheLivre(wxString id_l){
    wxString html_deb, html_fin;
    wxString html_tout;
    wxString query, mess, texte;
    wxString nom_fichier,nom_fichier_gros;
    wxString nom_col, val_col;
    wxFile fichier;
	//wxBitmap toolb_quit_BITMAP (toolb_quit_XPM);
    wxBitmap btmp_star1(star1_XPM);
    wxBitmap btmp_star2(star2_XPM);
    wxImage img;
    int nb_image, ret, taille;
    int i,j,k;
    long note;
    bool ya_img;

    // creation des images pour les notes
   /* btmp_smiley1.CopyFromIcon(WxBitmapButton_smiley_1_XPM);*/
    img=btmp_star1.ConvertToImage();
    img.SaveFile(gettempdir()+"\\star1.png");
    img=btmp_star2.ConvertToImage();
    img.SaveFile(gettempdir()+"\\star2.png");
    
    get_colonne("titre", id_l, nom_col, val_col);
    html_deb="<html><head></head><body bgcolor=\"#EEEEDD\"><CENTER> <B>"+val_col+" </B></CENTER>";
    html_fin="</body></html>";
    
    // récupération des images
    monlivre.select_image(id_l, query,nb_image);
    if (nb_image > 0) {
        html_deb+="<TABLE CELLPADDING=\"0\"  CELLSPACING=\"0\" WIDTH=\"100%\" > <TR>";
        html_fin="</TR></TABLE>"+html_fin;
        ret=amoi.transac_prepare(query);
        if (ret<0) {
            amoi.get_erreur(mess);
            wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        }    
        ret=amoi.transac_step();
        if (ret == SQLITE_ROW) {
            ya_img=false;
            for (i=0;i<nb_image;i++) {
                nom_fichier=gettempdir()+"\\"+id_l+"_";
                mess.Printf("%d",i);
                nom_fichier_gros=nom_fichier+mess+"_gros.jpg";
                nom_fichier+=mess+".jpg";
                fichier.Open(nom_fichier_gros,wxFile::write);
                ret=amoi.get_value_blob(i,&fichier,taille);
                fichier.Close();
                if (taille>0) {
                    if (ya_img==false) {
                        html_deb+="<TD VALIGN=\"TOP\" WIDTH=\"101\">";
                        ya_img=true;
                    }    
                    resize_image(nom_fichier_gros,100,-1,nom_fichier);
                    //html_deb+="<IMG BORDER=\"0\" WIDTH=\"100\" SRC=\"file:///c:/temp/0.jpg\"/>";
                    html_deb+="<a href=\""+nom_fichier_gros+"\">";
                    html_deb+="<IMG BORDER=\"0\"  SRC=\"";
                    html_deb+=nom_fichier+"\"/>";
                    html_deb+="</a>\n";
                }    
            }    
            if (ya_img==true) {
                html_deb+="<TD WIDTH=\"5\"></TD></TD> <TD VALIGN=\"TOP\" WITDH=\"100%\">";
                html_fin="</TD>"+html_fin;

            }    
            amoi.transac_fin();
            
        } else {
            amoi.get_erreur(mess);
            wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        }     

    }    

    // création du tableau des infos
    html_deb+="<TABLE CELLPADDING=\"2\" BORDER=\"5\" CELLSPACING=\"1\" WIDTH=\"100%\">\n ";
    html_fin="</TABLE>"+html_fin;
    j=0;
    for (i=0;i<monlivre.n_token();i++) {
        texte=monlivre.get_nom_token(i);
        if (texte.Left(6) == "image_")
            continue;
        get_colonne(texte, id_l, nom_col, val_col);
        if (val_col == "" || nom_col == "titre")
            continue;
        if (texte == "commentaire" || texte == "resume") {
            if (j==1) 
                html_deb+="<TD></TD><TD></TD></TR>";
            val_col.Replace("\n","<BR>\n",true);
            html_deb+="</TABLE><TABLE CELLPADDING=\"2\" BORDER=\"5\" CELLSPACING=\"1\" WIDTH=\"100%\">\n ";
            html_deb+="<TR><TD bgcolor=\"#CCFFCC\" WIDTH=\"100%\">"+nom_col+"</TD></TR>";
            html_deb+="<TR><TD WIDTH=\"100%\">"+val_col+"</TD></TR>\n";
            html_deb+="</TABLE>\n<TABLE CELLPADDING=\"2\" BORDER=\"5\" CELLSPACING=\"1\" WIDTH=\"100%\">\n";
            j=0;
            continue;
        } else if ( (j == 1) && (nom_col == "serie" || nom_col == "date_entree")) {
            html_deb+="<TD></TD><TD></TD></TR>";
            j=0;
        } else if (nom_col == "particularite") {
            val_col.ToLong(&note);
            mess.Printf("note:%d", (int)note);
            val_col=monlivre.get_label_particularite((int)note);
        }    
        if (j==0) {
            html_deb+="<TR>";
        }    
        html_deb+="<TD bgcolor=\"#CCFFCC\" WIDTH=\"25%\">"+nom_col+" : </TD>";
        if (nom_col == "note") {
            val_col.ToLong(&note);
                html_deb+="<TD WIDTH=\"25%\">";
            for(k=note;k>1;k-=2) {
                html_deb+="<IMG BORDER=\"0\" SRC=\""+gettempdir()+"\\star2.png\"/>";
            }    
            if (k == 1) 
                html_deb+="<IMG BORDER=\"0\" SRC=\""+gettempdir()+"\\star1.png\"/>";
            html_deb+="</TD>\n";
        } else    
            html_deb+="<TD WIDTH=\"25%\">"+val_col+"</TD>\n";
        
        if (j==1) {
            html_deb+="</TR>";
            j=0;
            continue;
        }
        j++;    
   }    
    html_tout=html_deb+html_fin;
    //visuhtml->SetPage(html_tout);
    fichier.Open(gettempdir()+"\\"+id_l+".htm",wxFile::write);
    fichier.Write(html_tout);
    fichier.Close();
    visuhtml->LoadPage(gettempdir()+"\\"+id_l+".htm");

    //wxMessageBox(html_tout,"coco", wxOK | wxICON_INFORMATION, this);
    
}    
void biblioFrame::get_colonne(wxString nomchamp, wxString idlivre, wxString &nomaffich, wxString &valeur) {
    wxString sansid;
    wxString query;
    int ret, taille;
    wxString mess;
    
    nomaffich=valeur="";
    if (nomchamp.Left(3) == "id_") {
        sansid=nomchamp.Mid(3);
        nomaffich=sansid;
        query="SELECT "+sansid+".nom FROM livre,"+sansid+" WHERE livre.rowid="+idlivre+" AND "+"livre."+nomchamp+"="+sansid+".rowid";
    } else {
        nomaffich=nomchamp;
        query="SELECT "+nomchamp+" FROM livre WHERE livre.rowid="+idlivre;
    }    
    if (nomaffich == "rowid")
        nomaffich="id";
    ret=amoi.transac_prepare(query);
    if (ret<0) {
        amoi.get_erreur(mess);
        wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        return;
    }

    ret=amoi.transac_step();

    if(ret==SQLITE_ROW ) {
        amoi.get_value_char(0,valeur,taille);
    }  
    amoi.transac_fin();

}    
void biblioFrame::sauve_config() {

	// sauvegarder les paramètres généraux dans la base config
	ParamManager* param = ParamManager::GetInstance("config");
	if (!param) {
        wxMessageBox ("biblioFrame::load_config() : instance de ParamManager non créée");
        return;
    }
    
    // sauvegarde de la base en cours de lecture (pour la réouvrir lors du prochain lancement
    param->Set("config", "INIT", "BASE", amoi.get_nombase());

    // sauvegarde de la position/taille...
    param->Set("config", "INIT", "MAXIMISED", this->IsMaximized());
    this->Maximize(false);  // pour pouvoir récupérer taille et position
    if (!IsIconized())
    {
        int x, y;
        this->GetSize(&x,&y);
        param->Set("config", "INIT", "TAILLE", x, y);
        this->GetPosition(&x,&y);
        param->Set("config", "INIT", "POSITION", x, y);
        param->Set("config", "INIT", "SPLIT_P", (long)(split_princip->GetSashPosition()));
        param->Set("config", "INIT", "SPLIT_D", (long)(split_droit->GetSashPosition()));
    }
    
    //sauvegarde des parametres de la base en cours (tri, colonnes affichées)
    wxString query, mess;
    int i, ret;
    if (amoi.ouverte()==true && param_modifie == true) {
        if (amoi.existe("config") == true) {
            query = "DROP TABLE config";
            amoi.exec_rapide(query);
        }
        query="CREATE TABLE config (type_param TEXT , nom_param TEXT, val1 TEXT, val2 TEXT)";
        ret=amoi.exec_rapide(query);
        if (ret<0) {
            amoi.get_erreur(mess);
            wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
            return;
        }
        query="CREATE INDEX ind_prim ON config (type_param , nom_param)";
        ret=amoi.exec_rapide(query);

       for (i=0;i<(int)liste_choisis.GetCount();i++) {
            mess.Printf("%d",liste_choisis.Item(i));
            query="INSERT INTO config (type_param, nom_param, val1, val2) VALUES ('INIT', 'COLONNE', '"+mess+"','"+liste_choisis_nom.Item(i)+"')";
            ret=amoi.exec_rapide(query);
       }    
        for (i=0;i<(int)liste_tri.GetCount();i++) {
            mess.Printf("%d",liste_tri.Item(i));
            query="INSERT INTO config (type_param, nom_param, val1) VALUES ('INIT', 'TRI', '"+mess+"')";
            amoi.exec_rapide(query);
       }    
    }    

}    

void biblioFrame::load_config() {
    
	// initialiser en fonction des valeurs présentes en base
	ParamManager* param = ParamManager::GetInstance("config");
	if (!param) {
        wxMessageBox ("biblioFrame::load_config() : instance de ParamManager non créée");
        return;
    }
    
    // récupération du nom de la base à ouvrir
    wxString valeur;
    param->GetOrSet("config", "INIT", "BASE", valeur);
    if (valeur !="") {
        wxFileName fich_conf(valeur);
        if (fich_conf.FileExists())
            ouvrir_base(valeur);
        else 
            wxMessageBox("le fichier "+valeur+ " n'existe pas","probleme", wxOK | wxICON_EXCLAMATION, this);
    }

    // récupération de la taille de la fenêtre
    long x = 800, y = 600;
    param->GetOrSet("config", "INIT", "TAILLE", x, y);
    if (x>0 && y>0) {
       this->SetSize(x,y);
    }

    //récupération de la position de la fenêtre
    x = 50;
    y = 50;    
    param->GetOrSet("config", "INIT", "POSITION", x, y);
    if (x>0 && y>0) {
        this->Move(x,y);
    }
    
    //récupération pour savoir si la fenêtre est maximisée
    valeur = "F";
    param->GetOrSet("config", "INIT", "MAXIMISED", valeur);
    if (valeur.CmpNoCase("T") == 0){
       this->Maximize(true);
    }

    // récupération de la position du spliter principal
    x = 100;
    param->GetOrSet("config", "INIT", "SPLIT_P", x);
    if (x>0) {
        split_princip->SetSashPosition(x);
    }
    
    // récupération de la position du spliter xxx
    x = 300;
    param->GetOrSet("config", "INIT", "SPLIT_D", x);
    if (x>0) {
        split_droit->SetSashPosition(x);
    }  
}    

/*
 * Mnulistes
 */
void biblioFrame::Mnulistes(wxCommandEvent& event)
{
    if (amoi.ouverte() == false)
        return;
    int ret;
    /*wxString mess;
    mess.Printf("%d",event.GetId());
                wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);*/
    if (event.GetId() == ID_MNU_LISTE_AUTEUR) {
        liste_champ choisir(&amoi, this, -1, "auteur");
        ret=choisir.ShowModal();
        if (choisir.modifie == true) {
            init_arbre();
            //remplir_grille("");
        }
    } else if (event.GetId() == ID_MNU_LISTE_SERIE) {
        liste_champ choisir(&amoi, this, -1, "serie");
        choisir.ShowModal();
    } else if (event.GetId() == ID_MNU_LISTE_GENRE) {
        liste_champ choisir(&amoi, this, -1, "genre");
        choisir.ShowModal();
    } else if (event.GetId() == ID_MNU_LISTE_EDITEUR) {
        liste_champ choisir(&amoi, this, -1, "editeur");
        choisir.ShowModal();
    } else if (event.GetId() == ID_MNU_LISTE_FORMAT) {
        liste_champ choisir(&amoi, this, -1, "format");
        choisir.ShowModal();
    } else if (event.GetId() == ID_MNU_LISTE_ARTISTE) {
        liste_champ choisir(&amoi, this, -1, "artiste");
        choisir.ShowModal();
    } else if (event.GetId() == ID_MNU_LISTE_ETAT) {
        liste_champ choisir(&amoi, this, -1, "etat");
        choisir.ShowModal();
    } else if (event.GetId() == ID_MNU_LISTE_LOCALISATION) {
        liste_champ choisir(&amoi, this, -1, "localisation");
        choisir.ShowModal();
    } else if (event.GetId() == ID_MNU_LISTE_SERIE_O) {
        liste_champ choisir(&amoi, this, -1, "serie_o");
        choisir.ShowModal();
    } else if (event.GetId() == ID_MNU_LISTE_PAYS) {
        liste_champ choisir(&amoi, this, -1, "pays");
        choisir.ShowModal();
    } else if (event.GetId() == ID_MNU_LISTE_LANGUE) {
        liste_champ choisir(&amoi, this, -1, "langue");
        choisir.ShowModal();
    } else if (event.GetId() == ID_MNU_LISTE_TRADUCTEUR) {
        liste_champ choisir(&amoi, this, -1, "traducteur");
        choisir.ShowModal();
    }    
	//event.Skip();
}


/*
 * MnurechercherClick
 */
void biblioFrame::MnurechercherClick(wxCommandEvent& event)
{
    list_from.Clear();
    recherche ma_recherche(this, -1, "Recherche", wxDefaultPosition, wxDefaultSize, wxSYSTEM_MENU|wxCAPTION| wxRESIZE_BORDER);
    
    ma_recherche.ShowModal();
    if (ma_recherche.table_liee.Len() > 0) {
        list_from.Add(ma_recherche.table_liee);
    }
    remplir_grille(ma_recherche.where);

    list_from.Remove(ma_recherche.table_liee);

    //event.Skip();
}



/*
 * Mnuapropos1047Click
 */
void biblioFrame::Mnuapropos1047Click(wxCommandEvent& event)
{
    apropos mon_apropos(&amoi, this, -1);// ,"Recherche", wxDefaultPosition, wxDefaultSize, wxSYSTEM_MENU|wxCAPTION| wxRESIZE_BORDER);
    
    mon_apropos.ShowModal();
	//event.Skip();
}

/*
 * Mnustatistique1048Click
 */
void biblioFrame::Mnustatistique1048Click(wxCommandEvent& event)
{
    if (mastat->IsShown() == false) {
        mastat->actualiser();
        mastat->Show();
    }
    else {
        mastat->actualiser();
        mastat->Raise();
    }
	//event.Skip();
}
void biblioFrame::OnSuppression( wxCommandEvent &event ) {
    wxString mess;
    mess=event.GetString();
    popup_effacelivre(event);
//        wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
	//event.Skip();
}
/*
 * Mnumenuitem_imprimeliste
 */
void biblioFrame::Mnumenuitem_imprimeliste(wxCommandEvent& event)
{
    wxString laliste;
    wxPrintData* config_imp;
    
    laliste=grille->BuildHTML();
        //wxMessageBox(texteht,"probleme", wxOK | wxICON_EXCLAMATION, this);
	//imprimehtml.PreviewText(texteht,gettempdir());
	config_imp = imprimehtml.GetPrintData();
	config_imp->SetOrientation(wxPORTRAIT);
	imprimehtml.PreviewText(laliste);
	//event.Skip();
}

/*
 * Mnuitem_imprimerlivre
 */
void biblioFrame::Mnuitem_imprimerlivre(wxCommandEvent& event)
{
    wxPrintData* config_imp;
    
    wxString texteht;
	texteht=visuhtml->GetOpenedPage();
        //wxMessageBox(texteht,"probleme", wxOK | wxICON_EXCLAMATION, this);
	//imprimehtml.PreviewText(texteht,gettempdir());
	config_imp = imprimehtml.GetPrintData();
	config_imp->SetOrientation(wxLANDSCAPE);
	imprimehtml.PreviewFile(texteht);
	//event.Skip();
}

/*void biblioFrame::OnKeyDown(wxKeyEvent &event){
    int key;
    wxString mess;
    
    key=event.GetKeyCode();
    mess.Printf("%d",key);
    wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
    
    event.Skip();
}*/

BEGIN_EVENT_TABLE(bellegrille, wxGrid)
	EVT_KEY_DOWN(bellegrille::OnKeyDown)
END_EVENT_TABLE()

void bellegrille::OnKeyDown(wxKeyEvent &event){
    int key;
    wxString mess;
    wxArrayInt selection;
    int sel;
    
    selection=GetSelectedRows();
    if (selection.GetCount() == 0) 
        sel=GetGridCursorRow();
    else
        sel=selection[0];

    
    key=event.GetKeyCode();
    if (key == WXK_DOWN) {
        if (sel<(GetNumberRows()-1)) {
            SelectRow(sel+1);
            SetGridCursor(sel+1,0);
            MakeCellVisible(sel+1,0);
        }
        event.Skip(false);
        return;
    } else if (key == WXK_UP) {
        if (sel > 0) {
            SelectRow(sel-1);
            SetGridCursor(sel-1,0);
            MakeCellVisible(sel-1,0);
        }
        event.Skip(false);
        return;
    } else if (key == WXK_RIGHT) {
        event.Skip(false);
        return;
    } else if (key == WXK_LEFT) {
        event.Skip(false);
        return;
    } else if (key == WXK_DELETE) {
        //wxMessageBox("plouf","probleme", wxOK | wxICON_EXCLAMATION, this);
        if (GetNumberRows()>0) {
            wxCommandEvent customevent( wxEVENT_SUPPRESSION, GetId() );
            customevent.SetEventObject( this );
            mess=GetRowLabelValue(sel);
            // Give it some contents
            customevent.SetString( mess );
            // Send it
            GetEventHandler()->ProcessEvent( customevent );
        }
        event.Skip(true);
        return;
    }
/*        mess.Printf("%d", key);
        wxMessageBox("plouf "+mess,"probleme", wxOK | wxICON_EXCLAMATION, this);*/
    //event.Skip();
}

wxString bellegrille::BuildHTML( )
{
    int nRow, nCol, nMaxRows;
    wxString strValue;
    wxString strContent;
    
    strContent.Empty();

    strContent += wxT("<html>\n");
    strContent += wxT("<body>\n");

    strContent += wxT("<center>\n");
    strContent += wxT("<table border=1 width=\"100%\">\n");
    strContent += wxT("<tr bgcolor=\"#C0C0C0\">\n");
    // column headers
    for( nCol = 0; nCol < GetNumberCols(); nCol++ )
    {
        strContent += wxT("<th align=\"center\" valign=\"bottom\">");
        strValue = GetColLabelValue( nCol );
        if( strValue.IsEmpty() )
        {
            strValue = wxT("&nbsp");
        }
        strContent += strValue;
        strContent += wxT("</th>\n");
    }
    strContent += wxT("</tr>\n");

    // data rows
    nMaxRows = GetNumberRows();
    for( nRow = 0; nRow < nMaxRows; nRow++ )
    {
        strContent += wxT("<tr>\n");

        for( nCol = 0; nCol < GetNumberCols(); nCol++ )
        {
            strContent += wxT("<td align=\"left\" valign=\"center\">");
            strValue = GetCellValue( nRow, nCol );
            if( strValue.IsEmpty() )
            {
                strValue = wxT("&nbsp");
            }
            strContent += strValue;
            strContent += wxT("</td>\n");
        }
        strContent += wxT("</tr>\n");
    }
    strContent += wxT("</table>\n");
    strContent += wxT("</center>\n");

    strContent += wxT("</body>\n");
    strContent += wxT("</html>\n");

    return strContent;
} 


/*
 * Mnuexporthtml1060Click
 */
void biblioFrame::Mnuexporthtml1060Click(wxCommandEvent& event)
{
    if (amoi.ouverte() == false) {
        wxMessageBox("Vous n'avez pas ouvert de base -> je ne  peux pas l'exporter","probleme", wxOK | wxICON_EXCLAMATION, this);
        return;
    }
    export_html_dlg mon_exporthtml(&amoi, this, -1);// ,"Recherche", wxDefaultPosition, wxDefaultSize, wxSYSTEM_MENU|wxCAPTION| wxRESIZE_BORDER);

    mon_exporthtml.ShowModal();
	//event.Skip();
}

/*
 * MnuimportercvsClick
 */
void biblioFrame::MnuimportercvsClick(wxCommandEvent& event)
{
    wxTextFile monfichier;
    wxString ligne, reste;
    int p_back;
    wxArrayString donnees;
    wxString mess, texte;
    int i, ret, ligne_courante;
    wxArrayString liste_a_choisir_lim;

    if (amoi.ouverte() == false)
        return;

    Nouv_livre ins_livre_batch(&amoi, this, -1, "Entrée d'un nouveau livre", wxDefaultPosition, wxDefaultSize);//, style_dialog_choix);

    wxString filename = wxFileSelector("Choix du fichier csv à ouvrir","","","","csv (*.txt)|*.txt|Tous (*.*)|*.*",wxOPEN|wxFILE_MUST_EXIST);

    if ( !filename.empty() )
    {
        monfichier.Open(filename);
        ligne=monfichier[0];
        i=0;
        mess="";
        while ((p_back=ligne.Find('\t'))>=0) {
            donnees.Add(ligne.Left(p_back));
            //mess+=ligne.Left(p_back)+"|\n";
            mess+=donnees[i]+"|\n";
            ligne=ligne.Mid(p_back+1);
            i++;
        }
        donnees.Add(ligne);
        texte.Printf("%d",donnees.GetCount());
        liste_a_choisir_lim=liste_a_choisir;
        liste_a_choisir_lim.RemoveAt(0);
        mess="Liste des colonnes contenues dans le fichier csv (ligne 0):\n\n"+mess+donnees[i]+"|\n\nnombre de lignes :"+texte;
        wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        //mess.Printf("%d",i);
        choix_colonnes choisir(liste_a_choisir_lim, &liste_choisis_import, &liste_choisis_nom_import, this, -1, "choix des colonnes à afficher", wxDefaultPosition, wxDefaultSize, style_dialog_choix);
        ret=choisir.ShowModal();
        if (ret==0) {
            if (liste_choisis_import.GetCount()!= donnees.GetCount()) {
                mess.Printf("Le nombre de colonnes selectionnée (%d) ne correspond pas au nombre se trouvant dans le fichier (%d)",liste_choisis_import.GetCount(), donnees.GetCount());
                wxMessageBox(mess,"Information", wxOK | wxICON_INFORMATION, this);
            } else {
                // récupération des données
                ligne_courante=1;
                // faudra mettre un while la
                for (ligne_courante=1;ligne_courante<(int)monfichier.GetLineCount();ligne_courante++) {
                    donnees.Clear();
                    ligne=monfichier[ligne_courante];
                    i=0;
                    mess="";
                    while ((p_back=ligne.Find('\t'))>=0) {
                        texte=ligne.Left(p_back);
                        // nettoyage du texte : supression des " de début et fin
                        if (texte.GetChar(0) == '\"' && texte.GetChar(texte.Length()-1) == '\"') {
                            texte=texte.Mid(1,texte.Length()-2);
                        }
                        donnees.Add(texte);
                        //mess+=ligne.Left(p_back)+"|\n";
                        //mess+=donnees[i]+"|\n";
                        ligne=ligne.Mid(p_back+1);
                        i++;
                    }
                    texte=ligne;
                    if (texte.GetChar(0) == '\"' && texte.GetChar(texte.Length()-1) == '\"') {
                        texte=texte.Mid(1,texte.Length()-2);
                    }
                    donnees.Add(texte);
                    /*mess="coco\n\n"+mess+donnees[i]+"|\n";
                    wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);*/
                    mess="";
                    //ins_livre_batch = new Nouv_livre(&amoi, this, -1, "Entrée d'un nouveau livre", wxDefaultPosition, wxDefaultSize, style_dialog_choix);
                    //ins_livre_batch.ShowModal();
                    for (i=0;i<(int)liste_choisis_nom_import.GetCount();i++) {
                        ins_livre_batch.init_champ(liste_a_choisir_lim[liste_choisis_import[i]], donnees[i]);
                        /*mess+=liste_a_choisir_lim[liste_choisis_import[i]]+":"+donnees[i]+"\n";*/
                    }
                    ins_livre_batch.inserer_livre();
                }
                //ins_livre_batch.ShowModal();
                //wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
                //delete ins_livre_batch;
            }
        }
    }

    init_arbre();
    //remplir_grille("");

	//event.Skip();
}

/*
 * Mnuexportcsv1062Click
 */
void biblioFrame::Mnuexportcsv1062Click(wxCommandEvent& event)
{
    wxFile monfichier;
    //wxArrayString liste_a_choisir_lim;
    wxString query, mess, texte;
    wxString ligne, nom_col, separateur;
    wxArrayInt liste_choisis_export;
    wxArrayString liste_choisis_nom_export;
    wxArrayInt liste_choisis_sauve;
    wxArrayString liste_choisis_nom_sauve;
    int ret, nbcol, taille, nb_lignes;
    choix_colonnes *choisir;
    //wxArrayString list_from;
    
    if (amoi.ouverte() == false) {
        wxMessageBox("Vous n'avez pas ouvert de base -> je ne  peux pas l'exporter","probleme", wxOK | wxICON_EXCLAMATION, this);
        return;
    }
    
    wxString filename = wxFileSelector("Choix du fichier csv à créer","","","","csv (*.csv)|*.csv|Tous (*.*)|*.*",wxFD_SAVE|wxFD_OVERWRITE_PROMPT );
    if ( filename.empty() )
    {
        return;
    }

    //liste_a_choisir_lim=liste_a_choisir;
    choisir=new choix_colonnes(liste_a_choisir, &liste_choisis_export, &liste_choisis_nom_export, this, -1, "choix des colonnes à exporter", wxDefaultPosition, wxDefaultSize, style_dialog_choix);
    ret=choisir->ShowModal();
    //choisir.Destroy();
    if (ret!=0) {
        return;
    }
    wxString liste_separateur[]={";", "Tabulation"};
    
    separateur=";";
    //separateur=choix_separateur.GetStringSelection();
    separateur=::wxGetSingleChoice(wxT("Choix du séparateur utilisé lors de la création du fichier CSV"), wxT("Choix du séparateur"), 2, liste_separateur);
    if (separateur.CompareTo("") == 0) {
        return;
    }

    //choix_separateur.Destroy();
    //wxMessageBox("ouaiii "+separateur,"probleme", wxOK | wxICON_EXCLAMATION, this);
    if (separateur.CompareTo("Tabulation") == 0) 
        separateur="\t";
    
    wxBusyCursor wait;
    
    monfichier.Open(filename,wxFile::write);
    
    //wxMessageBox("ouaiii "+filename,"probleme", wxOK | wxICON_EXCLAMATION, this);
    liste_choisis_sauve=liste_choisis;
    liste_choisis_nom_sauve=liste_choisis_nom;

    liste_choisis=liste_choisis_export;
    liste_choisis_nom=liste_choisis_nom_export;
    
    creation_select_livre(query,"","");
    
    liste_choisis=liste_choisis_sauve;
    liste_choisis_nom=liste_choisis_nom_sauve;
    //wxMessageBox("query "+query,"coucou", wxOK | wxICON_EXCLAMATION, this);
    
    ret=amoi.transac_prepare(query);
    if (ret<0) {
        amoi.get_erreur(mess);
        mess=query+"\n"+mess;
        wxMessageBox("Export CSV : "+mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        return;
    }
    ret=amoi.transac_step();
    nbcol=liste_choisis_nom_export.Count();
    ligne="";
    for (int i=0;i<nbcol;i++) {
        if (i>0) 
            ligne=ligne+separateur;
        nom_col=liste_choisis_nom_export[i];
        ligne=ligne+"\""+nom_col+"\"";
    }
    ligne=ligne+"\n";
    monfichier.Write(ligne);
    //wxMessageBox("ligne "+ligne,"coucou", wxOK | wxICON_EXCLAMATION, this);
    nb_lignes=0;
    while(ret==SQLITE_ROW) {
        nb_lignes++;
        ligne="";
        for (int i=0; i<nbcol;i++) {
            if (i>0)
                ligne=ligne+separateur;
                
            amoi.get_value_char(i+1,texte,taille);
            ligne=ligne+"\""+texte+"\"";
        }
        ligne=ligne+"\n";
        //wxMessageBox("ligne "+ligne,"coucou", wxOK | wxICON_EXCLAMATION, this);
        monfichier.Write(ligne);
        
        ret=amoi.transac_step();
    }
    monfichier.Close();
    
    amoi.transac_fin();
    mess.Printf("%d",nb_lignes);
    wxMessageBox(wxT("Fichier ")+filename+wxT(" créé.\nIl contient ")+mess+wxT(" Enregistrements"),"Export CSV", wxOK | wxICON_EXCLAMATION, this);
	//event.Skip();
    
}
void biblioFrame::image_click(wxHtmlLinkEvent &event)
{
    affiche_image *mon_image;
    
    wxHtmlLinkInfo monlien=event.GetLinkInfo();
    //wxMessageBox("lien cliqué :"+monlien.GetHref(),"TEST", wxOK | wxICON_EXCLAMATION, this);
    mon_image=new affiche_image(monlien.GetHref(),this);
    mon_image->ShowModal();
   	event.StopPropagation();
}
