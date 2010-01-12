//---------------------------------------------------------------------------
//
// Name:        rech_internet.h
// Author:      Epaillard
// Created:     06/06/05 17:52:38
//
//Copyright  PE Epaillard, 06/06/05 
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
#ifndef __RECH_INTERNET_HPP_
#define __RECH_INTERNET_HPP_


// For compilers that support precompilation, includes "wx.h".
#include <wx/wxprec.h>

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
// Include your minimal set of headers here, or wx.h
#include <wx/wx.h>
#endif


//Do not add custom headers.
//wx-dvcpp designer will remove them
////Header Include Start
#include <wx/radiobox.h>
#include <wx/panel.h>
#include <wx/checkbox.h>
#include <wx/statbox.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
////Header Include End

#include <wx/textdlg.h>
#include <wx/dialog.h>
#include <curl/curl.h>
#include <curl/types.h>
#include <curl/easy.h>
#include <wx/ffile.h>
#include <wx/file.h>

#include "mabase.h"
#include "divers.h"
#include "livre_html.h"

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

class rech_internet : public wxDialog
{
public:
    rech_internet( wxWindow *parent, wxWindowID id = 1, const wxString &title = _T("recherche sur internet"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = THIS_DIALOG_STYLE);
    virtual ~rech_internet();

public:

    bool recherche_auto;
  //Do not add custom Control Declarations here.
  //wx-devcpp will remove them. Try adding the custom code 
  //after the block.
  ////GUI Control Declaration Start
		wxRadioBox *WxRadioBox_choix_recherche;
		wxCheckBox *WxCheckBox_format;
		wxTextCtrl *WxEdit_format;
		wxStaticText *WxStaticText_format;
		wxCheckBox *WxCheckBox_nb_pages;
		wxTextCtrl *WxEdit_nb_pages;
		wxStaticText *WxStaticText_nb_pages;
		wxButton *wxID_CANCEL;
		wxButton *WxButton_OK;
		wxStaticText *WxStaticText_image_verso;
		wxCheckBox *WxCheckBox_image_dos;
		wxPanel *WxPanel_image_dos;
		wxCheckBox *WxCheckBox_image_face;
		wxPanel *WxPanel_image_face;
		wxStaticText *WxStaticText_image_face;
		wxCheckBox *WxCheckBox_commentaire;
		wxStaticText *WxStaticText_commentaire;
		wxTextCtrl *WxMemo_commentaire;
		wxCheckBox *WxCheckBox_prix;
		wxTextCtrl *WxEdit_prix;
		wxStaticText *WxStaticText_prix;
		wxCheckBox *WxCheckBox_traducteur;
		wxTextCtrl *WxEdit_traducteur;
		wxStaticText *WxStaticText_traducteur;
		wxCheckBox *WxCheckBox_langue;
		wxTextCtrl *WxEdit_langue;
		wxStaticText *WxStaticText_langue;
		wxCheckBox *WxCheckBox_date_pub;
		wxTextCtrl *WxEdit_date_pub;
		wxStaticText *WxStaticText_date_pub;
		wxCheckBox *WxCheckBox_genre;
		wxTextCtrl *WxEdit_genre;
		wxStaticText *WxStaticText_genre;
		wxCheckBox *WxCheckBox_editeur;
		wxTextCtrl *WxEdit_editeur;
		wxStaticText *WxStaticText_editeur;
		wxCheckBox *WxCheckBox_titre;
		wxTextCtrl *WxEdit_titre;
		wxStaticText *WxStaticText_titre;
		wxCheckBox *WxCheckBox_auteur;
		wxTextCtrl *WxEdit_auteur;
		wxStaticText *WxStaticText_auteur;
		wxCheckBox *WxCheckBox_minuscule;
		wxCheckBox *WxCheckBox_auteur_inverse;
		wxTextCtrl *WxEdit_proxy_pass;
		wxTextCtrl *WxMemo_URL;
		wxStaticText *WxStaticText_url;
		wxStaticText *WxStaticText_aide;
		wxStaticText *WxStaticText_proxy_pass;
		wxTextCtrl *WxEdit_proxy_port;
		wxStaticText *WxStaticText_proxy_port;
		wxTextCtrl *WxEdit_proxy_util;
		wxStaticText *WxStaticText_proxy_util;
		wxTextCtrl *WxEdit_proxy_adr;
		wxStaticText *WxStaticText_proxy_adr;
		wxCheckBox *WxCheckBox_proxy;
		wxStaticBox *WxStaticBox_proxy;
		wxButton *WxButton_lancer;
		wxTextCtrl *WxEdit_isbn;
		wxStaticText *WxStaticText_isbn;
  ////GUI Control Declaration End
  
    wxString img_recto;
    wxString img_verso;
    /*wxString Titre;
    wxString Auteur;
    wxString Editeur;
    wxString Collection;
    wxString Genre;
    wxString Date_parution;
    wxString Langue;
    wxString Traducteur;
    wxString Presentation;
    wxString Ean;
    wxString Prix;
    wxString Commentaires;
*/
private:
    DECLARE_EVENT_TABLE()
    wxString isbn;
//    ma_base config;
    wxString auteur;
    wxString traducteur;
    wxString titre;
    wxString genre;
    int type_recherche;
public:
    //Note: if you receive any error with these enums, then you need to
    //change your old form code that are based on the #define control ids.
    //#defines may replace a numeric value for the enums names.
    //Try copy pasting the below block in your old Form header Files.
	enum {
////GUI Enum Control ID Start
			ID_WXRADIOBOX_CHOIX_RECHERCHE = 1072,
			ID_WXCHECKBOX_FORMAT = 1071,
			ID_WXEDIT_FORMAT = 1070,
			ID_WXSTATICTEXT_FORMAT = 1069,
			ID_WXCHECKBOX_NB_PAGES = 1067,
			ID_WXEDIT_NB_PAGES = 1065,
			ID_WXSTATICTEXT_NB_PAGES = 1064,
			ID_WXBUTTON_ANNULER = 1041,
			ID_WXBUTTON_OK = 1001,
			ID_WXSTATICTEXT_IMAGE_VERSO = 1047,
			ID_WXCHECKBOX_IMAGE_DOS = 1054,
			ID_WXPANEL_IMAGE_DOS = 1040,
			ID_WXCHECKBOX_IMAGE_FACE = 1053,
			ID_WXPANEL_IMAGE_FACE = 1039,
			ID_WXSTATICTEXT_IMAGE_FACE = 1046,
			ID_WXCHECKBOX_COMMENTAIRE = 1052,
			ID_WXSTATICTEXT_COMMENTAIRE = 1038,
			ID_WXMEMO_COMMENTAIRE = 1037,
			ID_WXCHECKBOX_PRIX = 1051,
			ID_WXEDIT_PRIX = 1036,
			ID_WXSTATICTEXT_PRIX = 1035,
			ID_WXCHECKBOX_TRADUCTEUR = 1045,
			ID_WXEDIT_TRADUCTEUR = 1034,
			ID_WXSTATICTEXT_TRADUCTEUR = 1033,
			ID_WXCHECKBOX_LANGUE = 1050,
			ID_WXEDIT_LANGUE = 1032,
			ID_WXSTATICTEXT_LANGUE = 1031,
			ID_WXCHECKBOX_DATE_PUB = 1044,
			ID_WXEDIT_DATE_PUB = 1030,
			ID_WXSTATICTEXT_DATE_PUB = 1029,
			ID_WXCHECKBOX_GENRE = 1049,
			ID_WXEDIT_GENRE = 1028,
			ID_WXSTATICTEXT_GENRE = 1027,
			ID_WXCHECKBOX_EDITEUR = 1043,
			ID_WXEDIT_EDITEUR = 1025,
			ID_WXSTATICTEXT_EDITEUR = 1023,
			ID_WXCHECKBOX_TITRE = 1048,
			ID_WXEDIT_TITRE = 1022,
			ID_WXSTATICTEXT_TITRE = 1021,
			ID_WXCHECKBOX_AUTEUR = 1042,
			ID_WXEDIT_AUTEUR = 1005,
			ID_WXSTATICTEXT_AUTEUR = 1006,
			ID_WXCHECKBOX_MINUSCULE = 1059,
			ID_WXCHECKBOX_AUTEUR_INVERSE = 1058,
			ID_WXEDIT_PROXY_PASS = 1019,
			ID_WXMEMO_URL = 1057,
			ID_WXSTATICTEXT_URL = 1055,
			ID_WXSTATICTEXT_AIDE = 1026,
			ID_WXSTATICTEXT_PROXY_PASS = 1018,
			ID_WXEDIT_PROXY_PORT = 1020,
			ID_WXSTATICTEXT_PROXY_PORT = 1014,
			ID_WXEDIT_PROXY_UTIL = 1017,
			ID_WXSTATICTEXT_PROXY_UTIL = 1016,
			ID_WXEDIT_PROXY_ADR = 1013,
			ID_WXSTATICTEXT_PROXY_ADR = 1012,
			ID_WXCHECKBOX_PROXY = 1011,
			ID_WXSTATICBOX_PROXY = 1010,
			ID_WXBUTTON_LANCER = 1004,
			ID_WXEDIT_ISBN = 1003,
			ID_WXSTATICTEXT_ISBN = 1002,
////GUI Enum Control ID End
ID_IMAGE_FACE = 1500 ,
ID_IMAGE_DOS = 1501 ,
   ID_DUMMY_VALUE_ //Dont Delete this DummyValue
   }; //End of Enum

public:
    rech_internet(wxString p_isbn, wxWindow *parent, int moteur_recherche=-1, wxWindowID id = 1, const wxString &title = _T("recherche sur internet"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = THIS_DIALOG_STYLE);
    void rech_internetClose(wxCloseEvent& event);
    void CreateGUIControls(void);
	void WxButton_OKClick(wxCommandEvent& event);
/*    int traiter_isbn();
    int recupData(wxString url,wxString nom_fichier);
    int chercher_TD(wxString texte,wxString texte_a_chercher,wxString& texte_retour,int decalage);
    bool trancher(wxString& partie_droite,wxString& partie_gauche,wxString centre);
    size_t write_d(void *ptr,size_t size, size_t nmemb, void *stream);*/
	void WxButton_lancerClick(wxCommandEvent& event);
	void WxCheckBox_proxyClick(wxCommandEvent& event);
	void sauve_config();
	void load_config();
    void change_etat_proxy();
	void WxButton_annulerClick(wxCommandEvent& event);
	void WxCheckBox_Click(wxCommandEvent& event);
	void WxMemo_URLClickUrl(wxTextUrlEvent& event);
    void lancer_recherche();
    void inverse_auteur();
    void minusculisation();
};


#endif
 
 
 
 
