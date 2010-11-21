//---------------------------------------------------------------------------
//
// Name:        newProgramFrame.h
// Author:      
// Created:     10/27/2004 12:22:10 AM
//
//Copyright PE Epaillard, 10/27/2004 
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
#ifndef __NEWPROGRAMFRAME_HPP_
#define __NEWPROGRAMFRAME_HPP_


#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "mabase.h"
#include "divers.h"
#include "choix_colonnes.h"
#include "liste_champ.h"
#include "recherche.h"
#include "Nouv_livre.h"
#include "affiche_image.h"
#include "apropos.h"
#include "statistique.h"
#include "export_html_dlg.h"
#include "FusionDlg.h"

////Header Include Start
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/toolbar.h>
////Header Include End
#include <wx/splitter.h>
#include <wx/treectrl.h>
#include <wx/grid.h>
#include <wx/html/htmlwin.h>
#include <wx/arrstr.h>
#include <wx/dynarray.h>
#include <wx/frame.h>
#include <wx/html/htmprint.h>
#include <wx/choicdlg.h>
#include <wx/textfile.h>
#include <wx/bitmap.h>
#include <wx/splash.h>

#define ID_SPLITTERWINDOW 10101
#define ID_SPLITTERWINDOW1 10103
#define ID_COMBOBOX 10104
#define ID_TREE_ARBRE 10105
#define ID_SPLITTERWINDOW2 10102
#define ID_WXGRID_GRILLE 10106
#define ID_HTMLWINDOW 10107
#define ID_EFFACELIVRE 10108
#define ID_DUPLIQUELIVRE 10109

//WX_DEFINE_ARRAY(int, ArrayOfInt);

#ifdef THIS_DIALOG_STYLE
#undef THIS_DIALOG_STYLE
#endif
////Dialog Style Start
#undef THIS_DIALOG_STYLE
#define THIS_DIALOG_STYLE wxWANTS_CHARS | wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxTHICK_FRAME | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

// id de mon evenement perso en cas de suppression
/*enum
{
    EVT_C_SUPPRESSION = 7500
};*/

DECLARE_EVENT_TYPE(wxEVENT_SUPPRESSION, -1)

class bellegrille : public wxGrid {
private:
    DECLARE_EVENT_TABLE()
    public:
    bellegrille(wxWindow* parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, 
        long style = wxWANTS_CHARS, const wxString& name = wxPanelNameStr) 
         : wxGrid(parent, id, pos, size, style, name) {
    }
    void OnKeyDown(wxKeyEvent &event);
    wxString BuildHTML();

};

class biblioFrame : public wxFrame
{
private:
    DECLARE_EVENT_TABLE()
public:
    enum {
    ////GUI Enum Control ID Start
			ID_MNU_OUVRIR_1015 = 1015,
			
			ID_MNU_FICHIER_QUIT = 1010,
			ID_MNU_OUVRIR_1022 = 1022,
			ID_MNU_CREERUNEBASE_1023 = 1023,
			ID_MNU_SUBMENUITEM9_1025 = 1025,
			ID_MNU_MENUITEM30_1058 = 1058,
			ID_MNU_IMPRIMERLALISTE_1059 = 1059,
			ID_MNU_MENUITEM29_1057 = 1057,
			ID_MNU_EXPORTHTML_1060 = 1060,
			ID_MNU_EXPORTCSV_1062 = 1062,
			ID_MNU_IMPORTERCVS_1026 = 1026,
			ID_MNU_1020 = 1020,
			ID_MNU_QUITTER_1011 = 1011,
			ID_MNU_OUTIL_1017 = 1017,
			ID_MNU_PARAMETRES = 1068,
			ID_MNU_ORDREDETRI = 1018,
			ID_MNU_CHOIXCOLONNES_1024 = 1024,
			ID_MNU_EDITION_1043 = 1043,
			ID_MNU_RECHERCHER_1045 = 1045,
			ID_MNU_LISTES_1027 = 1027,
			ID_MNU_LISTE_AUTEUR = 1028,
			ID_MNU_LISTE_SERIE = 1030,
			ID_MNU_LISTE_GENRE = 1031,
			ID_MNU_LISTE_EDITEUR = 1033,
			ID_MNU_LISTE_FORMAT = 1034,
			ID_MNU_LISTE_ARTISTE = 1035,
			ID_MNU_LISTE_ETAT = 1036,
			ID_MNU_LISTE_LOCALISATION = 1037,
			ID_MNU_LISTE_PAYS = 1038,
			ID_MNU_LISTE_LANGUE = 1039,
			ID_MNU_LISTE_TRADUCTEUR = 1040,
			ID_MNU_LISTE_SERIE_O = 1042,
			ID_MNU_STATISTIQUES = 1070,
			ID_MNU_STATISTIQUE_1048 = 1048,
			ID_MNU_AFFICHER_VALEUR_TOTALE = 1071,
			ID_MNU_APROPOS_1046 = 1046,
			ID_MNU__APROPOS_1047 = 1047,
			ID_MNU_VERIFIER_VERSION = 1072,
			
			ID_BARRE_STATUT = 1009,
			ID_WXTOOLBUTTON_ABOUT = 1055,
			ID_WXSEPARATOR5 = 1056,
			ID_TOOLB_PARAM = 1065,
			ID_WXSEPARATOR6 = 1066,
			ID_WXTOOLBUTTON_STAT = 1049,
			ID_WXSEPARATOR4 = 1052,
			ID_TOOLB_FUSION_GENRE = 1064,
			ID_WXSEPARATOR7 = 1067,
			ID_WXTOOLBUTTON_TRI = 1054,
			ID_WXTOOLBUTTON_COLONNE = 1053,
			ID_WXSEPARATOR3 = 1051,
			ID_WXTOOLB_RECH_INTERNET = 1069,
			ID_WXTOOLB_INSERER_ISBN = 1063,
			ID_WXTOOLB_INSERER = 1014,
			ID_WXSEPARATOR2 = 1013,
			ID_TOOLB_OUVRIR = 1008,
			ID_TOOLB_NOUV = 1007,
			ID_WXSEPARATOR1 = 1012,
			ID_TOOLB_QUIT = 1006,
			ID_TOOLB_PRINC = 1003,
    ////GUI Enum Control ID End
			ID_MNU_VERIFIER_VERSION_SILENCIEUX = 2000,
			ID_TIMER_VERIFIER_VERSION = 2001,
    ID_DUMMY_VALUE_ //Dont Delete this DummyValue
    }; //End of Enum
    biblioFrame( wxWindow *parent, wxWindowID id = 1, const wxString &title = _T("Livrotheque"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxWANTS_CHARS |wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxTHICK_FRAME | wxMINIMIZE_BOX | wxMAXIMIZE_BOX |  wxCLOSE_BOX );
    virtual ~biblioFrame();
public:
  ////GUI Control Declaration Start
		wxMenu *WxPopupMenu_grille;
		wxMenuBar *monmenu;
		wxStatusBar *barre_statut;
		wxToolBar *toolb_princ;
 ////GUI Control Declaration End

    wxSplitterWindow* split_princip;
    wxSplitterWindow* split_gauche;
    wxComboBox* choix_arbre;
    wxTreeCtrl* arbre;
    wxSplitterWindow* split_droit;
    bellegrille* grille;
    wxHtmlWindow* visuhtml;
    ma_base amoi;
    ma_base config;
    livre monlivre;
    // pour la liste des choix
    wxArrayInt liste_choisis;
    wxArrayInt liste_tri;
    wxArrayString liste_choisis_nom;
    wxArrayString liste_a_choisir;
    bool param_modifie;
    statistique *mastat;
    // import csv
    wxArrayInt liste_choisis_import;
    wxArrayString liste_choisis_nom_import;
    wxArrayString list_from;
    bool grille_ok;
    wxHtmlEasyPrinting imprimehtml;
public:

    void biblioFrameClose(wxCloseEvent& event);
    void CreateGUIControls(void);
	void toolb_quitClick(wxCommandEvent& event);

    void OnSplitterwindowSashPosChanged( wxSplitterEvent& event );
    void OnSplitterwindowDclick( wxSplitterEvent& event );
	void Mnuquitter1011Click(wxCommandEvent& event);
	void OuvrirClick(wxCommandEvent& event);
	void ouvrir_base(wxString base);
	void toolb_NouvClick(wxCommandEvent& event);
	void insererClick(wxCommandEvent& event);
	void insererClickIsbn(wxCommandEvent& event);
	void insererClick_interne(wxCommandEvent& event, BOOL modeIsbn);
	void fusionGenre(wxCommandEvent& event);
	void parametrer(wxCommandEvent& event);
    void OnSelectLivre( wxGridEvent& event );
    void OnGrilleClickDroit( wxGridEvent& event );
	void OnGrilleLabelLeftClick(wxGridEvent& event);
	void remplir_grille(wxString where);
	int creer_base();
	void popup_MnuouvrirClick(wxCommandEvent& event);
	void init_colonnes();
	void init_arbre();
	void creation_select_livre(wxString &select, wxString where, wxString order_by);
	void OnArbreSel(wxTreeEvent &event);
	void MnuordredetriClick(wxCommandEvent& event);
	void OnSelectlignegrille(wxGridEvent &event);
	void get_colonne(wxString nomchamp, wxString idlivre, wxString &nomaffich, wxString &valeur);
	void AfficheLivre(wxString id_l);
	int trouve_ligne(wxString Label);
	void sauve_config();
	void load_config();
	void Mnulistes(wxCommandEvent& event);
	void MnuimportercvsClick(wxCommandEvent& event);
	void popup_effacelivre(wxCommandEvent& event);
	void dupliquelivre(wxCommandEvent& event);
	//void OnKeyDown(wxKeyEvent &event);
	void MnurechercherClick(wxCommandEvent& event);
	void Mnuapropos1047Click(wxCommandEvent& event);
	void Mnustatistique1048Click(wxCommandEvent& event);
    void OnSuppression( wxCommandEvent &event );
	void Mnumenuitem_imprimeliste(wxCommandEvent& event);
	void Mnuitem_imprimerlivre(wxCommandEvent& event);
	void Mnuexporthtml1060Click(wxCommandEvent& event);
	void Mnuexportcsv1062Click(wxCommandEvent& event);
    void image_click(wxHtmlLinkEvent &event);
	void toolb_recherche_internetClick(wxCommandEvent& event);
	void OnAfficherValeurTotale(wxCommandEvent& event);
	void OnVerifierVersion(wxCommandEvent& event);
	void OnVerifierVersionSilencieux(wxCommandEvent& event);
    void OnTimerVerifierVersion(wxTimerEvent& event);
    void verifierVersion(bool silencieux);
		
private:
    wxSplashScreen* m_splash;
    wxTimer* m_timerVerif;
    void killSplash();
    void fermerBaseLivre();
    void modifieLivre(wxString id);
};


#endif
 
 
 
 
