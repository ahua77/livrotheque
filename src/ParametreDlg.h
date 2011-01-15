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
#include <wx/statbox.h>
#include <wx/button.h>
#include <wx/radiobut.h>
#include <wx/textctrl.h>
#include <wx/statline.h>
#include <wx/checkbox.h>
#include <wx/stattext.h>
#include <wx/panel.h>
#include <wx/notebook.h>
////Header Include End

////Dialog Style Start
#undef ParametreDlg_STYLE
#define ParametreDlg_STYLE wxCAPTION | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

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
	
	private:
		//Do not add custom control declarations between 
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxTextCtrl *ET_TailleCarImpression;
		wxButton *BN_CANCEL;
		wxButton *BN_OK;
		wxStaticLine *WxStaticLine5;
		wxStaticText *WxStaticText17;
		wxStaticText *WxStaticText16;
		wxStaticText *WxStaticText14;
		wxStaticText *WxStaticText15;
		wxStaticText *WxStaticText13;
		wxTextCtrl *ET_PiedPageDroite;
		wxTextCtrl *ET_PiedPageCentre;
		wxTextCtrl *ET_PiedPageGauche;
		wxStaticText *WxStaticText12;
		wxTextCtrl *ET_EnteteDroite;
		wxTextCtrl *ET_EnteteCentre;
		wxTextCtrl *ET_EnteteGauche;
		wxStaticText *WxStaticText10;
		wxPanel *WxNoteBookPage5;
		wxCheckBox *WxCheck_verifVersion;
		wxStaticText *WxStaticText9;
		wxTextCtrl *WxEdit_timeout;
		wxTextCtrl *WxEdit_proxy_pass;
		wxTextCtrl *WxEdit_proxy_util;
		wxStaticText *WxStaticText_proxy_pass;
		wxStaticText *WxStaticText_proxy_util;
		wxStaticText *WxStaticText_proxy_port;
		wxStaticText *WxStaticText_proxy_adr;
		wxTextCtrl *WxEdit_proxy_port;
		wxTextCtrl *WxEdit_proxy_adr;
		wxStaticBox *WxStaticBox_proxy;
		wxCheckBox *WxCheckBox_proxy;
		wxPanel *WxNoteBookPage4;
		wxButton *BN_ParcourirSave;
		wxTextCtrl *ET_Rep_Sauvegarde;
		wxRadioButton *RB_SauveDossierSpecifie;
		wxRadioButton *RB_SauveDossierBase;
		wxStaticText *WxStaticText11;
		wxStaticText *WxStaticText6;
		wxStaticText *WxStaticText8;
		wxStaticText *WxStaticText7;
		wxStaticLine *WxStaticLine4;
		wxStaticText *WxStaticText5;
		wxStaticText *WxStaticText4;
		wxTextCtrl *ET_NB_CONSERVATION;
		wxTextCtrl *ET_FrequenceSauvegarde;
		wxCheckBox *CK_UseSauvegarde;
		wxPanel *WxNoteBookPage3;
		wxStaticLine *WxStaticLine1;
		wxStaticText *WxStaticText1;
		wxTextCtrl *ET_ValueTopN;
		wxCheckBox *CK_useTopN;
		wxPanel *WxNoteBookPage2;
		wxStaticText *WxStaticText3;
		wxTextCtrl *ET_LargeurMaxColonnes;
		wxCheckBox *CK_use_largeur_max_colonnes;
		wxStaticLine *WxStaticLine3;
		wxCheckBox *CK_cleanTmpOnExit;
		wxCheckBox *CK_use_splash_screen;
		wxStaticLine *WxStaticLine2;
		wxCheckBox *CK_avertirNouveau_traducteur;
		wxCheckBox *CK_avertirNouveau_langue;
		wxCheckBox *CK_avertirNouveau_pays;
		wxCheckBox *CK_avertirNouveau_serie_o;
		wxCheckBox *CK_avertirNouveau_localisation;
		wxCheckBox *CK_avertirNouveau_etat;
		wxCheckBox *CK_avertirNouveau_artiste;
		wxCheckBox *CK_avertirNouveau_format;
		wxCheckBox *CK_avertirNouveau_editeur;
		wxCheckBox *CK_avertirNouveau_genre;
		wxCheckBox *CK_avertirNouveau_serie;
		wxCheckBox *CK_avertirNouveau_auteur;
		wxStaticText *WxStaticText2;
		wxPanel *WxNoteBookPage1;
		wxNotebook *WxNotebook1;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WX_ET_TAILLE_CAR_IMPRESSION = 1147,
			ID_WX_BNCANCEL = 1009,
			ID_WX_BNOK = 1008,
			ID_WXSTATICLINE5 = 1146,
			ID_WXSTATICTEXT17 = 1145,
			ID_WXSTATICTEXT16 = 1144,
			ID_WXSTATICTEXT14 = 1142,
			ID_WXSTATICTEXT15 = 1141,
			ID_WXSTATICTEXT13 = 1139,
			ID_WX_ET_PIEDPAGE_DROITE = 1137,
			ID_WX_ET_PIEDPAGE_CENTRE = 1136,
			ID_WX_ET_PIEDPAGE_GAUCHE = 1135,
			ID_WXSTATICTEXT12 = 1134,
			ID_WX_ET_ENTETE_DROITE = 1127,
			ID_WX_ET_ENTETE_CENTRE = 1126,
			ID_WX_ET_ENTETE_GAUCHE = 1125,
			ID_WXSTATICTEXT10 = 1124,
			ID_WXNOTEBOOKPAGE5 = 1123,
			ID_WXCHECKBOX1 = 1122,
			ID_WXSTATICTEXT9 = 1121,
			ID_WX_TIMEOUT = 1120,
			ID_WXEDIT_PROXY_PASS = 1119,
			ID_WXEDIT_PROXY_UTIL = 1118,
			ID_WXSTATICTEXT_PROXY_PASS = 1117,
			ID_WXSTATICTEXT_PROXY_UTIL = 1116,
			ID_WXSTATICTEXT_PROXY_PORT = 1115,
			ID_WXSTATICTEXT_PROXY_ADR = 1114,
			ID_WXEDIT_PROXY_PORT = 1113,
			ID_WXEDIT_PROXY_ADR = 1112,
			ID_WXSTATICBOX_PROXY = 1111,
			ID_WXCHECKBOX_PROXY = 1110,
			ID_WXNOTEBOOKPAGE4 = 1064,
			ID_WX_BN_PARCOURIR_SAVE = 1063,
			ID_WX_ET_REP_SAUVE = 1062,
			ID_WX_RB_SAUVE_DOSSIER_SPECIFIE = 1061,
			ID_WX_RB_SAUVE_DOSSIER_BASE = 1060,
			ID_WXSTATICTEXT11 = 1059,
			ID_WXSTATICTEXT6 = 1058,
			ID_WXSTATICTEXT8 = 1053,
			ID_WXSTATICTEXT7 = 1052,
			ID_WXSTATICLINE4 = 1050,
			ID_WXSTATICTEXT5 = 1047,
			ID_WXSTATICTEXT4 = 1046,
			ID_WX_ET_NB_CONSERV = 1045,
			ID_WX_ET_FREQ_SAUVE = 1044,
			ID_WX_CK_UseSauvegarde = 1043,
			ID_WXNOTEBOOKPAGE3 = 1042,
			ID_WXSTATICLINE1 = 1007,
			ID_WXSTATICTEXT1 = 1006,
			ID_WXEDIT1 = 1005,
			ID_WX_CK_UseTopN = 1004,
			ID_WXNOTEBOOKPAGE2 = 1003,
			ID_WXSTATICTEXT3 = 1041,
			ID_WX_ET_LARGEUR_MAX_COLONNES = 1040,
			ID_WX_CK_USE_LARGEUR_MAX_COLONNES = 1039,
			ID_WXSTATICLINE3 = 1038,
			ID_WX_CK_CLEAN_TMP_ON_EXIT = 1037,
			ID_WX_CK_UseSplashScreen = 1010,
			ID_WXSTATICLINE2 = 1036,
			ID_WX_CK_avertirNouveau_traducteur = 1032,
			ID_WX_CK_avertirNouveau_langue = 1033,
			ID_WX_CK_avertirNouveau_pays = 1034,
			ID_WX_CK_avertirNouveau_serie_o = 1035,
			ID_WX_CK_avertirNouveau_localisation = 1025,
			ID_WX_CK_avertirNouveau_etat = 1024,
			ID_WX_CK_avertirNouveau_artiste = 1023,
			ID_WX_CK_avertirNouveau_format = 1022,
			ID_WX_CK_avertirNouveau_editeur = 1015,
			ID_WX_CK_avertirNouveau_genre = 1014,
			ID_WX_CK_avertirNouveau_serie = 1013,
			ID_WX_CK_avertirNouveau_auteur = 1012,
			ID_WXSTATICTEXT2 = 1011,
			ID_WXNOTEBOOKPAGE1 = 1002,
			ID_WXNOTEBOOK1 = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
		void change_etat_proxy();
        static long s_nbInstances;
};

#endif
