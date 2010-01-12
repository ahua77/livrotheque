//---------------------------------------------------------------------------
//
// Name:        recherche.h
// Author:      Fougny
// Created:     11/02/05 15:05:20
//
//Copyright  PE Epaillard, 11/02/05 
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
#ifndef __RECHERCHE_HPP_
#define __RECHERCHE_HPP_


#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "divers.h"


////Header Include Start
#include <wx/button.h>
#include <wx/radiobut.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/combobox.h>
#include <wx/scrolwin.h>
////Header Include End

#include <wx/dialog.h>

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
	#define THIS_DIALOG_STYLE wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxTHICK_FRAME | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class recherche : public wxDialog
{
public:
 enum {
////GUI Enum Control ID Start
ID_WXSTATICTEXT_TYPE = 1016,
ID_WXRADIOBUTTON_TYPE_OU = 1015,
ID_WXRADIOBUTTON_TYPE_ET = 1013,
ID_WXSTATICTEXT_TEXTE = 1012,
ID_WXSTATICTEXT_CHAMP = 1011,
ID_WXEDIT_TEXTE = 1010,
ID_WXCOMBOBOX_CHAMP = 1009,
ID_WXSCROLLEDWINDOW1 = 1002,
////GUI Enum Control ID End
ID_DUMMY_VALUE_ //Dont Delete this DummyValue
}; //End of Enum
    recherche( wxWindow *parent, wxWindowID id = 1, const wxString &title = _T("recherche"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = THIS_DIALOG_STYLE);
    virtual ~recherche();
public:
  ////GUI Control Declaration Start
	wxButton *WxButton_rech_annul;
	wxButton *WxButton_rech_ok;
	wxBoxSizer *WxBoxSizer1;
	wxStaticText *WxStaticText_type;
	wxRadioButton *WxRadioButton_type_ou;
	wxRadioButton *WxRadioButton_type_et;
	wxStaticText *WxStaticText_texte;
	wxStaticText *WxStaticText_champ;
	wxTextCtrl *WxEdit_texte;
	wxComboBox *WxComboBox_champ;
	wxScrolledWindow *WxScrolledWindow1;
	wxBoxSizer *WxBoxSizer_fond;
  ////GUI Control Declaration End
  
    wxString where;
    wxArrayString liste_sel;
    wxString table_liee;
private:
    DECLARE_EVENT_TABLE()

public:
    void rechercheClose(wxCloseEvent& event);
    void CreateGUIControls(void);
    void WxButton_okClick(wxCommandEvent& event);
    void WxButton_rech_annulClick(wxCommandEvent& event);
    void init_tout();
    void OnOk(wxCommandEvent& event);
    void creation_where_simple(wxString nom_champ, wxArrayString liste_cherche);
    void creation_where_id(wxString nom_champ, wxArrayString liste_cherche);
};


#endif
 
 
 
 
