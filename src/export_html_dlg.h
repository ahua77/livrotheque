//---------------------------------------------------------------------------
//
// Name:        export_html_dlg.h
// Author:      epaillard
// Created:     07/12/2006 11:21:18
// Description: export_html_dlg class declaration
//
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
//
//---------------------------------------------------------------------------

#ifndef __EXPORT_HTML_DLG_h__
#define __EXPORT_HTML_DLG_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif
#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/dialog.h>
#else
	#include <wx/wxprec.h>
#endif

#include "mabase.h"
#include "export_html_textes.h"

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
////Header Include End

////Dialog Style Start
#undef export_html_dlg_STYLE
#define export_html_dlg_STYLE wxCAPTION | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxCLOSE_BOX
////Dialog Style End

class export_html_dlg : public wxDialog
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		export_html_dlg(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Export HTML"), 
            const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = export_html_dlg_STYLE);
		virtual ~export_html_dlg();
		void WxButton_okClick(wxCommandEvent& event);
		void WxButton_annulClick(wxCommandEvent& event);
	
	private:
		//Do not add custom control declarations
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxRadioBox *WxRadioBox_type;
		wxTextCtrl *WxEdit_mail;
		wxStaticText *WxStaticText_mail;
		wxTextCtrl *WxEdit_nom;
		wxStaticText *WxStaticText_nom;
		wxTextCtrl *WxEdit_titre;
		wxStaticText *WxStaticText_titre;
		wxTextCtrl *WxMemo_texte_accueil;
		wxStaticText *WxStaticText_texte_accueil;
		wxStaticText *WxStaticText_destination;
		wxTextCtrl *WxEdit_chemin_dest;
		wxButton *WxButton_chemin_dest;
		wxButton *WxButton_annul;
		wxButton *WxButton_ok;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXRADIOBOX_TYPE = 1018,
			ID_WXEDIT_MAIL = 1014,
			ID_WXSTATICTEXT_MAIL = 1013,
			ID_WXEDIT_NOM = 1012,
			ID_WXSTATICTEXT_NOM = 1011,
			ID_WXEDIT_TITRE = 1010,
			ID_WXSTATICTEXT_TITRE = 1009,
			ID_WXMEMO_TEXTE_ACCUEIL = 1008,
			ID_WXSTATICTEXT_TEXTE_ACCUEIL = 1007,
			ID_WXSTATICTEXT_DESTINATION = 1006,
			ID_WXEDIT_CHEMIN_DEST = 1005,
			ID_WXBUTTON_CHEMIN_DEST = 1004,
			ID_WXBUTTON_ANNUL = 1002,
			ID_WXBUTTON_OK = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
        ma_base *la_belle;
        
	public:
		export_html_dlg(ma_base *pour_lecture, wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Export HTML"),
            const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = export_html_dlg_STYLE);
	
	private:
        void sauve_config();
        void charge_config();
        void creation_fiches_auteurs(wxString chemin_fiches, wxString chemin_listes, wxString &fiche);
        void creation_fiches_livres(wxString chemin_fiche,wxString chemin_image, wxString &fiche);
        //void creation_listes_titres(wxString chemin_listes, wxString &fiche);
        void creation_tree_titre(wxString &arbre, wxString chemin_listes, wxString &fiche);
        void creation_tree_serie(wxString &arbre, wxString chemin_listes, wxString chemin_fiches, wxString &fiche);
        void creation_tree_auteur(wxString &arbre);
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
		void WxButton_chemin_destClick(wxCommandEvent& event);
};

#endif
