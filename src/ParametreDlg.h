///-----------------------------------------------------------------
///
/// @file      ParametreDlg.h
/// @author    cubbiste
/// Created:   12/12/2009 18:10:19
/// @section   DESCRIPTION
///            ParametreDlg class declaration
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

#ifndef __PARAMETREDLG_H__
#define __PARAMETREDLG_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/dialog.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/radiobut.h>
#include <wx/checkbox.h>
#include <wx/statline.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/panel.h>
#include <wx/notebook.h>
#include <wx/sizer.h>
////Header Include End

////Dialog Style Start
#undef ParametreDlg_STYLE
#define ParametreDlg_STYLE wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

enum E_choixAbsent {
    E_CA_neRienFaire,
    E_CA_prevenir,
    E_CA_chercherSurInternet,
    E_CA_LASTVALUE
};

enum E_choixPresent {
    E_CP_neRienFaire,
    E_CP_prevenir,
    E_CP_selectionner,
    E_CP_ajouterSelection,
    E_CP_modifier,
    E_CP_LASTVALUE
};

class ParametreDlg : public wxDialog
{
	private:
		void BN_OKClick(wxCommandEvent& event);
		DECLARE_EVENT_TABLE();
		
	public:
		ParametreDlg(wxWindow *parent, int ongletActif, wxWindowID id = 1, const wxString &title = wxT("Paramètres"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = ParametreDlg_STYLE);
		virtual ~ParametreDlg();
		void BN_CANCELClick(wxCommandEvent& event);
		void CK_useTopNClick(wxCommandEvent& event);
		void ParametreDlgInitDialog(wxInitDialogEvent& event);
		void CK_use_largeur_max_colonnesClick(wxCommandEvent& event);
		void CK_UseSauvegardeClick(wxCommandEvent& event);
		void RB_SauveDossierBaseClick(wxCommandEvent& event);
		void RB_SauveDossierSpecifieClick(wxCommandEvent& event);
		void BN_ParcourirSaveClick(wxCommandEvent& event);
		void WxCheckBox_proxyClick(wxCommandEvent& event);
		void WxNotebook1PageChanged(wxNotebookEvent& event);
		void ParametreDlgSize(wxSizeEvent& event);
	
	private:
		//Do not add custom control declarations between 
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxStdDialogButtonSizer *WxStdDialogButtonSizer1;
		wxButton *btnOK;
		wxButton *btnCANCEL;
		wxTextCtrl *ET_lecteurCodesBarre;
		wxStaticText *WxStaticText8;
		wxBoxSizer *WxBoxSizer26;
		wxChoice *CH_saisieRapide_ISBNpresent;
		wxStaticText *WxStaticText20;
		wxChoice *CH_saisieRapide_ISBNabsent;
		wxStaticText *WxStaticText19;
		wxBoxSizer *WxBoxSizer27;
		wxStaticBoxSizer *WxSBB_saisieRapide;
		wxBoxSizer *WxBoxSizer3;
		wxPanel *WxNoteBookPage6;
		wxTextCtrl *ET_TailleCarImpression;
		wxStaticText *WxStaticText13;
		wxBoxSizer *WxBoxSizer7;
		wxStaticLine *WxStaticLine5;
		wxStaticText *WxST_Impression_4;
		wxStaticText *WxST_Impression_3;
		wxStaticText *WxST_Impression_2;
		wxStaticText *WxST_Impression_1;
		wxGridSizer *WxGridSizer1;
		wxTextCtrl *ET_PiedPageDroite;
		wxTextCtrl *ET_PiedPageCentre;
		wxTextCtrl *ET_PiedPageGauche;
		wxBoxSizer *WxBoxSizer5;
		wxStaticBoxSizer *WxStaticBoxSizer3;
		wxTextCtrl *ET_EnteteDroite;
		wxTextCtrl *ET_EnteteCentre;
		wxTextCtrl *ET_EnteteGauche;
		wxBoxSizer *WxBoxSizer6;
		wxStaticBoxSizer *WxStaticBoxSizer2;
		wxBoxSizer *WxBoxSizer4;
		wxPanel *WxNoteBookPage5;
		wxCheckBox *WxCheck_verifVersion;
		wxBoxSizer *WxBoxSizer15;
		wxTextCtrl *WxEdit_timeout;
		wxStaticText *WxStaticText9;
		wxBoxSizer *WxBoxSizer9;
		wxTextCtrl *WxEdit_proxy_pass;
		wxStaticText *WxStaticText_proxy_pass;
		wxTextCtrl *WxEdit_proxy_port;
		wxStaticText *WxStaticText_proxy_port;
		wxTextCtrl *WxEdit_proxy_util;
		wxStaticText *WxStaticText_proxy_util;
		wxTextCtrl *WxEdit_proxy_adr;
		wxStaticText *WxStaticText_proxy_adr;
		wxFlexGridSizer *WxGridSizer2;
		wxStaticBoxSizer *WxStaticBoxSizer1;
		wxCheckBox *WxCheckBox_proxy;
		wxBoxSizer *WxBoxSizer16;
		wxBoxSizer *WxBoxSizer8;
		wxPanel *WxNoteBookPage7;
		wxStaticText *WxST_Sauvegarde_2;
		wxStaticText *WxST_Sauvegarde_1;
		wxStaticLine *WxStaticLine7;
		wxButton *BN_ParcourirSave;
		wxTextCtrl *ET_Rep_Sauvegarde;
		wxBoxSizer *WxBoxSizer23;
		wxRadioButton *RB_SauveDossierSpecifie;
		wxBoxSizer *WxBoxSizer22;
		wxRadioButton *RB_SauveDossierBase;
		wxBoxSizer *WxBoxSizer21;
		wxStaticText *WxStaticText11;
		wxBoxSizer *WxBoxSizer20;
		wxTextCtrl *ET_NB_CONSERVATION;
		wxStaticText *WxStaticText5;
		wxStaticText *WxStaticText6;
		wxTextCtrl *ET_FrequenceSauvegarde;
		wxStaticText *WxStaticText4;
		wxFlexGridSizer *WxFlexGridSizer1;
		wxCheckBox *CK_UseSauvegarde;
		wxBoxSizer *WxBoxSizer24;
		wxBoxSizer *WxBoxSizer19;
		wxPanel *WxNoteBookPage3;
		wxStaticLine *WxStaticLine1;
		wxStaticText *WxStaticText1;
		wxTextCtrl *ET_ValueTopN;
		wxStaticText *WxStaticText10;
		wxCheckBox *CK_useTopN;
		wxBoxSizer *WxBoxSizer18;
		wxBoxSizer *WxBoxSizer17;
		wxPanel *WxNoteBookPage2;
		wxStaticText *WxStaticText3;
		wxTextCtrl *ET_LargeurMaxColonnes;
		wxStaticText *WxStaticText21;
		wxCheckBox *CK_use_largeur_max_colonnes;
		wxBoxSizer *WxBoxSizer14;
		wxStaticLine *WxStaticLine4;
		wxCheckBox *CK_cleanTmpOnExit;
		wxBoxSizer *WxBoxSizer13;
		wxCheckBox *CK_use_splash_screen;
		wxBoxSizer *WxBoxSizer12;
		wxStaticLine *WxStaticLine3;
		wxCheckBox *CK_avertirNouveau_traducteur;
		wxCheckBox *CK_avertirNouveau_localisation;
		wxCheckBox *CK_avertirNouveau_editeur;
		wxCheckBox *CK_avertirNouveau_langue;
		wxCheckBox *CK_avertirNouveau_etat;
		wxCheckBox *CK_avertirNouveau_genre;
		wxCheckBox *CK_avertirNouveau_pays;
		wxCheckBox *CK_avertirNouveau_artiste;
		wxCheckBox *CK_avertirNouveau_serie;
		wxCheckBox *CK_avertirNouveau_serie_o;
		wxCheckBox *CK_avertirNouveau_format;
		wxCheckBox *CK_avertirNouveau_auteur;
		wxGridSizer *WxGridSizer3;
		wxStaticText *WxStaticText2;
		wxBoxSizer *WxBoxSizer11;
		wxStaticLine *WxStaticLine2;
		wxTextCtrl *ET_TaillePoliceAffichage;
		wxStaticText *WxStaticText7;
		wxBoxSizer *WxBoxSizer25;
		wxBoxSizer *WxBoxSizer10;
		wxPanel *WxNoteBookPage4;
		wxNotebook *WxNotebook1;
		wxBoxSizer *WxBoxSizer2;
		wxBoxSizer *WxBoxSizer1;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXEDIT1 = 1253,
			ID_WXSTATICTEXT_lecteurCodesBarre = 1252,
			ID_CH_SAISIERAPIDE_ISBNPRESENT = 1275,
			ID_WXSTATICTEXT20 = 1274,
			ID_CH_SAISIERAPIDE_ISBNABSENT = 1273,
			ID_WXSTATICTEXT19 = 1272,
			ID_WXNOTEBOOKPAGE6 = 1148,
			ID_WX_ET_TAILLE_CAR_IMPRESSION = 1147,
			ID_WXSTATICTEXT13 = 1139,
			ID_WXSTATICLINE5 = 1146,
			ID_WXSTATICTEXT17 = 1145,
			ID_WXSTATICTEXT16 = 1144,
			ID_WXSTATICTEXT14 = 1142,
			ID_WXSTATICTEXT15 = 1141,
			ID_ET_PIEDPAGEDROITE = 1220,
			ID_ET_PIEDPAGECENTRE = 1219,
			ID_ET_PIEDPAGEGAUCHE = 1218,
			ID_ET_ENTETEDROITE = 1224,
			ID_ET_ENTETECENTRE = 1223,
			ID_ET_ENTETEGAUCHE = 1222,
			ID_WXNOTEBOOKPAGE5 = 1123,
			ID_WXCHECK_VERIFVERSION = 1204,
			ID_WX_TIMEOUT = 1120,
			ID_WXSTATICTEXT9 = 1121,
			ID_WXEDIT_PROXY_PASS = 1119,
			ID_WXSTATICTEXT_PROXY_PASS = 1117,
			ID_WXEDIT_PROXY_PORT = 1113,
			ID_WXSTATICTEXT_PROXY_PORT = 1115,
			ID_WXEDIT_PROXY_UTIL = 1118,
			ID_WXSTATICTEXT_PROXY_UTIL = 1116,
			ID_WXEDIT_PROXY_ADR = 1112,
			ID_WXSTATICTEXT_PROXY_ADR = 1114,
			ID_WXCHECKBOX_PROXY = 1206,
			ID_WXNOTEBOOKPAGE7 = 1169,
			ID_WXSTATICTEXT7 = 1052,
			ID_WXSTATICTEXT8 = 1053,
			ID_WXSTATICLINE7 = 1050,
			ID_BN_PARCOURIRSAVE = 1246,
			ID_ET_REP_SAUVEGARDE = 1245,
			ID_RB_SAUVEDOSSIERSPECIFIE = 1243,
			ID_RB_SAUVEDOSSIERBASE = 1241,
			ID_WXSTATICTEXT11 = 1239,
			ID_ET_NB_CONSERVATION = 1237,
			ID_WXSTATICTEXT5 = 1236,
			ID_WXSTATICTEXT6 = 1235,
			ID_ET_FREQUENCESAUVEGARDE = 1234,
			ID_WXSTATICTEXT4 = 1233,
			ID_CK_USESAUVEGARDE = 1248,
			ID_WXNOTEBOOKPAGE3 = 1042,
			ID_WXSTATICLINE1 = 1007,
			ID_WXSTATICTEXT1 = 1229,
			ID_ET_VALUETOPN = 1228,
			ID_WXSTATICTEXT10 = 1230,
			ID_CK_USETOPN = 1227,
			ID_WXNOTEBOOKPAGE2 = 1003,
			ID_WXSTATICTEXT3 = 1041,
			ID_WX_ET_LARGEUR_MAX_COLONNES = 1040,
			ID_WX_CK_USE_LARGEUR_MAX_COLONNES = 1039,
			ID_WXSTATICLINE4 = 1036,
			ID_WX_CK_CLEAN_TMP_ON_EXIT = 1037,
			ID_WX_CK_UseSplashScreen = 1010,
			ID_WXSTATICLINE3 = 1036,
			ID_WX_CK_avertirNouveau_traducteur = 1032,
			ID_WX_CK_avertirNouveau_localisation = 1025,
			ID_WX_CK_avertirNouveau_editeur = 1015,
			ID_WX_CK_avertirNouveau_langue = 1033,
			ID_WX_CK_avertirNouveau_etat = 1024,
			ID_WX_CK_avertirNouveau_genre = 1014,
			ID_WX_CK_avertirNouveau_pays = 1034,
			ID_WX_CK_avertirNouveau_artiste = 1023,
			ID_WX_CK_avertirNouveau_serie = 1013,
			ID_WX_CK_avertirNouveau_serie_o = 1035,
			ID_WX_CK_avertirNouveau_format = 1022,
			ID_WX_CK_avertirNouveau_auteur = 1012,
			ID_WXSTATICTEXT2 = 1011,
			ID_WXSTATICLINE2 = 1249,
			ID_WX_ET_TAILLE_POLICE_AFFICHAGE = 1040,
			ID_WXSTATICTEXT21 = 1201,
			ID_WXNOTEBOOKPAGE4 = 1194,
			ID_WXNOTEBOOK1 = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
		void change_etat_proxy();
        wxString choixAbsentStr(E_choixAbsent val);
        wxString choixPresentStr(E_choixPresent val);
        static long s_nbInstances;
};

#endif
