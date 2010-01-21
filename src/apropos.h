//---------------------------------------------------------------------------
//
// Name:        apropos.h
// Author:      Epaillard
// Created:     29/06/05 17:50:05
//Copyright ou © ou Copr. PE Epaillard, 29/06/05 
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
//---------------------------------------------------------------------------
#ifndef __APROPOS_HPP_
#define __APROPOS_HPP_


// For compilers that support precompilation, includes "wx.h".
#include <wx/wxprec.h>

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
// Include your minimal set of headers here, or wx.h
#include <wx/wx.h>
#endif


#include "mabase.h"
#include <curl/curl.h>
//Do not add custom headers.
//wx-dvcpp designer will remove them
////Header Include Start
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/notebook.h>
#include <wx/stattext.h>
#include <wx/hyperlink.h>
////Header Include End

#include "mabase.h"
#include <wx/dialog.h>
#include <wx/filename.h>
#include <wx/file.h>

//Compatibility for 2.4.x code
#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif
#ifndef wxFIXED_MINSIZE
#define wxFIXED_MINSIZE 0
#endif
#ifdef THIS_DIALOG_STYLE
#undef THIS_DIALOG_STYLE
#endif

////Dialog Style Start
#undef THIS_DIALOG_STYLE
#define THIS_DIALOG_STYLE wxCAPTION | wxSYSTEM_MENU | wxDIALOG_NO_PARENT
////Dialog Style End

class apropos : public wxDialog
{
public:
    apropos( wxWindow *parent, wxWindowID id = 1, const wxString &title = _T("a propos"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = THIS_DIALOG_STYLE);
    virtual ~apropos();

public:

  //Do not add custom Control Declarations here.
  //wx-devcpp will remove them. Try adding the custom code 
  //after the block.
  ////GUI Control Declaration Start
		wxStaticText *WxStaticText6;
		wxButton *WxButton2;
		wxStaticText *WxStaticText_nver;
		wxTextCtrl *WxMemo_license;
		wxPanel *WxNoteBookPage_license;
		wxStaticText *WxStaticText1;
		wxStaticText *WxStaticText5;
		wxStaticText *WxStaticText4;
		wxStaticText *WxStaticText3;
		wxStaticText *WxStaticText2;
		wxPanel *WxNoteBookPage_auteurs;
		wxStaticText *WxStaticText_curl_version;
		wxStaticText *WxStaticText_tcurl;
		wxStaticText *WxStaticText_sqlite_version;
		wxStaticText *WxStaticText_sqlite_tversion;
		wxStaticText *WxStaticText_titre2;
		wxStaticText *WxStaticText_wx_version;
		wxStaticText *WxStaticText_wx_tversion;
		wxPanel *WxNoteBookPage_tech;
		wxStaticText *WxStaticText_taille_base;
		wxStaticText *WxStaticText_ttaille_base;
		wxStaticText *WxStaticText_nb_livre;
		wxStaticText *WxStaticText_tnb_livre;
		wxStaticText *WxStaticText_nom_base;
		wxStaticText *WxStaticText_tnom_base;
		wxPanel *WxNoteBookPage_base;
		wxNotebook *WxNotebook1;
		wxStaticText *WxStaticText_titre;
		wxHyperlinkCtrl *WxHyperLinkCtrl_URL;
  ////GUI Control Declaration End
		wxStaticBitmap *WxStaticBitmap_titre;

private:
    DECLARE_EVENT_TABLE()

public:
    //Note: if you receive any error with these enums, then you need to
    //change your old form code that are based on the #define control ids.
    //#defines may replace a numeric value for the enums names.
    //Try copy pasting the below block in your old Form header Files.
	enum {
			ID_WXSTATICBITMAP_TITRE = 1541,
////GUI Enum Control ID Start
			ID_WXSTATICTEXT6 = 1056,
			ID_WXSTATICTEXT_NVER = 1025,
			ID_WXMEMO_LICENSE = 1040,
			ID_WXNOTEBOOKPAGE_LICENSE = 1039,
			ID_WXSTATICTEXT1 = 1055,
			ID_WXSTATICTEXT5 = 1051,
			ID_WXSTATICTEXT4 = 1050,
			ID_WXSTATICTEXT3 = 1049,
			ID_WXSTATICTEXT2 = 1048,
			ID_WXNOTEBOOKPAGE_AUTEURS = 1041,
			ID_WXSTATICTEXT_CURL_VERSION = 1020,
			ID_WXSTATICTEXT_TCURL = 1019,
			ID_WXSTATICTEXT_SQLITE_VERSION = 1018,
			ID_WXSTATICTEXT_SQLITE_TVERSION = 1017,
			ID_WXSTATICTEXT_TITRE2 = 1016,
			ID_WXSTATICTEXT_WX_VERSION = 1015,
			ID_WXSTATICTEXT_WX_TVERSION = 1014,
			ID_WXNOTEBOOKPAGE_tech = 1013,
			ID_WXSTATICTEXT_TAILLE_BASE = 1033,
			ID_WXSTATICTEXT_TTAILLE_BASE = 1032,
			ID_WXSTATICTEXT_NB_LIVRE = 1031,
			ID_WXSTATICTEXT_TNB_LIVRE = 1030,
			ID_WXSTATICTEXT_NOM_BASE = 1029,
			ID_WXSTATICTEXT_TNOM_BASE = 1027,
			ID_WXNOTEBOOKPAGE_BASE = 1026,
			ID_WXNOTEBOOK1 = 1010,
			ID_WXSTATICTEXT_TITRE = 1002,
			ID_WXHYPERLINKCTRL_URL = 1054,
////GUI Enum Control ID End
   ID_DUMMY_VALUE_ //Dont Delete this DummyValue
   }; //End of Enum

    ma_base *la_belle;

public:
    apropos( ma_base *pour_insere, wxWindow *parent, wxWindowID id = 1, const wxString &title = _T("a propos"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = THIS_DIALOG_STYLE);
    void aproposClose(wxCloseEvent& event);
    void CreateGUIControls(void);
	void WxButton1Click(wxCommandEvent& event);
    void init_donnee_base();
		void WxMemo1ClickUrl(wxTextUrlEvent& event);
		void WxButton_siteClick(wxCommandEvent& event);

};


#endif
 
 
 
 
