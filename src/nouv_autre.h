//---------------------------------------------------------------------------
//
// Name:        nouv_autre.h
// Author:      fougny
// Created:     31/01/2005 20:54:44
//
//Copyright  PE Epaillard, 31/01/2005 
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
#ifndef __NOUV_AUTRE_HPP_
#define __NOUV_AUTRE_HPP_


#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "mabase.h"
#include "divers.h"
#include "Nouv_livre.h"

////Header Include Start
#include <wx/button.h>
#include <wx/grid.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/panel.h>
#include <wx/bmpbuttn.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/scrolwin.h>
#include <wx/sizer.h>
////Header Include End
#include <wx/filename.h>
#include <wx/dialog.h>

//Compatibility for 2.4.x code
#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif
#ifndef wxFIXED_MINSIZE
#define wxFIXED_MINSIZE 0
#endif

#define ID_IMAGECANVAS_IMAGE 1501

#ifdef THIS_DIALOG_STYLE
#undef THIS_DIALOG_STYLE
#endif

////Dialog Style Start
#undef THIS_DIALOG_STYLE
#define THIS_DIALOG_STYLE wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxTHICK_FRAME | wxCLOSE_BOX
////Dialog Style End

class nouv_autre : public wxDialog
{
public:
 enum {
////GUI Enum Control ID Start
			ID_WXBUTTON_OK = 1013,
			ID_WXGRID_LISTE = 1022,
			ID_WXMEMO_COMMENTAIRE = 1004,
			ID_WXDATEPICKERCTRL_MORT = 1024,
			ID_WXDATEPICKERCTRL_NAISSANCE = 1023,
			ID_WXPANEL_IMAGE = 1020,
			ID_WXBITMAPBUTTON_SUPPRIME = 1008,
			ID_WXBITMAPBUTTON1_OUVRIR = 1007,
			ID_WXSTATICTEXT_IMAGE = 1006,
			ID_WXSTATICTEXT_COMMENTAIRE = 1011,
			ID_WXSTATICTEXT_DATE_MORT = 1017,
			ID_WXSTATICTEXT_DATE_NAISSANCE = 1015,
			ID_WXEDIT_NOM = 1010,
			ID_WXSTATICTEXT_NOM = 1009,
			ID_WXSCROLLEDWINDOW1 = 1003,
////GUI Enum Control ID End
ID_DUMMY_VALUE_ //Dont Delete this DummyValue
}; //End of Enum
    nouv_autre( wxWindow *parent, wxWindowID id = 1, const wxString &title = _T("modif"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = THIS_DIALOG_STYLE);
    virtual ~nouv_autre();
public:
  ////GUI Control Declaration Start
		wxButton *WxButton_annul;
		wxButton *WxButton_ok;
		wxBoxSizer *WxBoxSizer2;
		wxGrid *WxGrid_liste;
		wxTextCtrl *WxMemo_commentaire;
		wxDatePickerCtrl *WxDatePickerCtrl_mort;
		wxDatePickerCtrl *WxDatePickerCtrl_naissance;
		wxPanel *WxPanel_image;
		wxBitmapButton *WxBitmapButton_supprime;
		wxBitmapButton *WxBitmapButton1_ouvrir;
		wxStaticText *WxStaticText_image;
		wxStaticText *WxStaticText_commentaire;
		wxStaticText *WxStaticText_date_mort;
		wxStaticText *WxStaticText_date_naissance;
		wxTextCtrl *WxEdit_nom;
		wxStaticText *WxStaticText_nom;
		wxScrolledWindow *WxScrolledWindow1;
		wxBoxSizer *WxBoxSizer1;
  ////GUI Control Declaration End
    ma_base *la_belle;
    wxString id_courant;
    wxString type_table;
    wxString nom_table;
    livre monlivre;
    /*wxImage image;
    bool image_charge;*/
    ImageCanvas *canvas_image;
    
    
private:
    DECLARE_EVENT_TABLE()

public:
    nouv_autre( ma_base *pour_modif, wxString id_champ, wxWindow *parent, wxWindowID id = 1, const wxString &title = _T("modif"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = THIS_DIALOG_STYLE);
    void nouv_autreClose(wxCloseEvent& event);
    void CreateGUIControls(void);
	void WxButton_annulClick(wxCommandEvent& event);
	void WxButton_okClick(wxCommandEvent& event);
	void init_tout();
	//void rempli_canvas(ImageCanvas *lecanvas, wxImage *image);
	void enregistrer();
	void WxBitmapButton_supprimeClick(wxCommandEvent& event);
	void WxBitmapButton1_ouvrirClick(wxCommandEvent& event);
	void wxEdit_Gesdate(wxCommandEvent& event);
	void WxGrid_listeCellLeftDoubleClick(wxGridEvent& event);
};


#endif
 
 
 
 
