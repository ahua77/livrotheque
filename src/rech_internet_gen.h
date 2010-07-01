//---------------------------------------------------------------------------
//
// Name:        rech_internet_gen.h
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
#ifndef __RECH_INTERNET_GEN_HPP_
#define __RECH_INTERNET_GEN_HPP_


// For compilers that support precompilation, includes "wx.h".
#include <wx/wxprec.h>

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
// Include your minimal set of headers here, or wx.h
#include <wx/wx.h>
#endif

#include "livre_html.h"
#include "mabase.h"
#include "divers.h"
#include "rech_internet.h"
//Do not add custom headers.
//wx-dvcpp designer will remove them
////Header Include Start
#include <wx/radiobox.h>
#include <wx/grid.h>
#include <wx/checkbox.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/statbox.h>
////Header Include End

#include <wx/dialog.h>
#include <wx/gdicmn.h>

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
#define THIS_DIALOG_STYLE wxCAPTION | wxDIALOG_NO_PARENT
////Dialog Style End

class rech_internet_gen : public wxDialog
{
public:
    rech_internet_gen( wxWindow *parent, wxWindowID id = 1, const wxString &title = _T("Recherche Internet générale"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = THIS_DIALOG_STYLE);
    virtual ~rech_internet_gen();

public:
    rech_internet *ma_recherche;
  //Do not add custom Control Declarations here.
  //wx-devcpp will remove them. Try adding the custom code 
  //after the block.
  ////GUI Control Declaration Start
		wxRadioBox *WxRadioBox_choix_recherche;
		wxButton *WxButton_recherche;
		wxStaticText *WxStaticText1;
		wxGrid *WxGrid_general;
		wxGrid *WxGrid_precis;
		wxStaticText *WxStaticText_recherche;
		wxTextCtrl *WxEdit_recherche;
		wxCheckBox *WxCheckBox_proxy;
		wxTextCtrl *WxEdit_proxy_pass;
		wxStaticText *WxStaticText_proxy_pass;
		wxTextCtrl *WxEdit_proxy_util;
		wxStaticText *WxStaticText_proxy_util;
		wxTextCtrl *WxEdit_proxy_port;
		wxStaticText *WxStaticText_proxy_port;
		wxTextCtrl *WxEdit_proxy_adr;
		wxStaticText *WxStaticText_proxy_adr;
		wxButton *WxButton_ok;
		wxStaticBox *WxStaticBox_proxy;
  ////GUI Control Declaration End

private:
    DECLARE_EVENT_TABLE()
    ma_base config;

public:
    //Note: if you receive any error with these enums, then you need to
    //change your old form code that are based on the #define control ids.
    //#defines may replace a numeric value for the enums names.
    //Try copy pasting the below block in your old Form header Files.
	enum {
////GUI Enum Control ID Start
			ID_WXRADIOBOX1 = 1054,
			ID_WXBUTTON_RECHERCHE = 1053,
			ID_WXSTATICTEXT1 = 1052,
			ID_WXGRID_GENERAL = 1051,
			ID_WXGRID_PRECIS = 1050,
			ID_WXSTATICTEXT_RECHERCHE = 1049,
			ID_WXEDIT_RECHERCHE = 1048,
			ID_WXCHECKBOX_PROXY = 1047,
			ID_WXEDIT_PROXY_PASS = 1046,
			ID_WXSTATICTEXT_PROXY_PASS = 1045,
			ID_WXEDIT_PROXY_UTIL = 1044,
			ID_WXSTATICTEXT_PROXY_UTIL = 1043,
			ID_WXEDIT_PROXY_PORT = 1042,
			ID_WXSTATICTEXT_PROXY_PORT = 1041,
			ID_WXEDIT_PROXY_ADR = 1040,
			ID_WXSTATICTEXT_PROXY_ADR = 1039,
			ID_WXSTATICBOX_PROXY = 1038,
////GUI Enum Control ID End
   ID_DUMMY_VALUE_ //Dont Delete this DummyValue
   }; //End of Enum

public:
    void rech_internet_genClose(wxCloseEvent& event);
    void CreateGUIControls(void);
	void WxButton_okClick(wxCommandEvent& event);
	void WxButton_rechercheClick(wxCommandEvent& event);
	void WxCheckBox_proxyClick(wxCommandEvent& event);
    void change_etat_proxy();
    void init_grille(wxGrid *grille);
    void rempli_grille(wxGrid *Grille, liste_caracteristiques *laliste);
    void sauve_config() ;
    void load_config();
	void WxGrid_precisCellLeftDoubleClick(wxGridEvent& event);
	
private:
    static liste_caracteristiques s_list_livres;
    static wxString s_critere;
    static long s_nbInstances;

};


#endif
 
 
 
 
