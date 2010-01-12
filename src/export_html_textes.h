//---------------------------------------------------------------------------
//
// Name:        export_html_textes.h
// Author:      epaillard
// Created:     07/12/2006 17:08:00
// Description: export_html_textes class declaration
//
//Copyright PE Epaillard, 10/27/2004
//
//Fougny@gmail.com
//
//Ce logiciel est un programme informatique servant � [rappeler les
//caract�ristiques techniques de votre logiciel].
//
//Ce logiciel est r�gi par la licence CeCILL soumise au droit fran�ais et
//respectant les principes de diffusion des logiciels libres. Vous pouvez
//utiliser, modifier et/ou redistribuer ce programme sous les conditions
//de la licence CeCILL telle que diffus�e par le CEA, le CNRS et l'INRIA
//sur le site "http://www.cecill.info".
//
//En contrepartie de l'accessibilit� au code source et des droits de copie,
//de modification et de redistribution accord�s par cette licence, il n'est
//offert aux utilisateurs qu'une garantie limit�e.  Pour les m�mes raisons,
//seule une responsabilit� restreinte p�se sur l'auteur du programme,  le
//titulaire des droits patrimoniaux et les conc�dants successifs.
//
//A cet �gard  l'attention de l'utilisateur est attir�e sur les risques
//associ�s au chargement,  � l'utilisation,  � la modification et/ou au
//d�veloppement et � la reproduction du logiciel par l'utilisateur �tant
//donn� sa sp�cificit� de logiciel libre, qui peut le rendre complexe �
//manipuler et qui le r�serve donc � des d�veloppeurs et des professionnels
//avertis poss�dant  des  connaissances  informatiques approfondies.  Les
//utilisateurs sont donc invit�s � charger  et  tester  l'ad�quation  du
//logiciel � leurs besoins dans des conditions permettant d'assurer la
//s�curit� de leurs syst�mes et ou de leurs donn�es et, plus g�n�ralement,
//� l'utiliser et l'exploiter dans les m�mes conditions de s�curit�.
//
//Le fait que vous puissiez acc�der � cet en-t�te signifie que vous avez
//pris connaissance de la licence CeCILL, et que vous en avez accept� les
//termes.
//---------------------------------------------------------------------------

#ifndef __EXPORT_HTML_TEXTES_h__
#define __EXPORT_HTML_TEXTES_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/dialog.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
#include <wx/stattext.h>
#include <wx/textctrl.h>
////Header Include End

////Dialog Style Start
#undef export_html_textes_STYLE
#define export_html_textes_STYLE wxCAPTION | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class export_html_textes : public wxDialog
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		export_html_textes(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("export_html_textes"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = export_html_textes_STYLE);
		virtual ~export_html_textes();
	
	public:
		//Do not add custom control declarations
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxTextCtrl *WxMemo_pda_index;
		wxStaticText *WxStaticText11;
		wxTextCtrl *WxMemo_html_fiche_livre;
		wxStaticText *WxStaticText10;
		wxTextCtrl *WxMemo_html_fiche_auteur;
		wxStaticText *WxStaticText9;
		wxTextCtrl *WxMemo_html_accueil;
		wxStaticText *WxStaticText8;
		wxTextCtrl *WxMemo_html_index;
		wxStaticText *WxStaticText7;
		wxStaticText *WxStaticText6;
		wxTextCtrl *WxMemo_fiche_livre;
		wxStaticText *fiche_auteur;
		wxTextCtrl *WxMemo_fiche_auteur;
		wxStaticText *WxStaticText5;
		wxTextCtrl *WxMemo_livrotheque_css;
		wxStaticText *WxStaticText4;
		wxTextCtrl *WxMemo_ua_js;
		wxStaticText *WxStaticText3;
		wxTextCtrl *WxMemo_ftiens4_js;
		wxStaticText *WxStaticText2;
		wxTextCtrl *WxMemo_framelessNodes_js;
		wxStaticText *WxStaticText1;
		wxTextCtrl *WxMemo_index;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXMEMO_PDA_INDEX = 1025,
			ID_WXSTATICTEXT11 = 1024,
			ID_WXMEMO_HTML_FICHE_LIVRE = 1023,
			ID_WXSTATICTEXT10 = 1022,
			ID_WXMEMO_HTML_FICHE_AUTEUR = 1021,
			ID_WXSTATICTEXT9 = 1020,
			ID_WXMEMO_HTML_ACCUEIL = 1019,
			ID_WXSTATICTEXT8 = 1018,
			ID_WXMEMO_HTML_INDEX = 1017,
			ID_WXSTATICTEXT7 = 1015,
			ID_WXSTATICTEXT6 = 1014,
			ID_WXMEMO_FICHE_LIVRE = 1013,
			ID_FICHE_AUTEUR = 1012,
			ID_WXMEMO_FICHE_AUTEUR = 1011,
			ID_WXSTATICTEXT5 = 1010,
			ID_WXMEMO_LIVROTHEQUE_CSS = 1009,
			ID_WXSTATICTEXT4 = 1008,
			ID_WXMEMO_UA_JS = 1007,
			ID_WXSTATICTEXT3 = 1006,
			ID_WXMEMO_FTIENS4_JS = 1005,
			ID_WXSTATICTEXT2 = 1004,
			ID_WXMEMO_FRAMELESSNODES_JS = 1003,
			ID_WXSTATICTEXT1 = 1002,
			ID_WXMEMO_INDEX = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
