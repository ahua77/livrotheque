//---------------------------------------------------------------------------
//
// Name:        Nouv_livre.h
// Author:      Fougny
// Created:     03/01/05 11:28:33
//
//Copyright  PE Epaillard, 03/01/05 
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
#ifndef __NOUV_LIVRE_HPP_
#define __NOUV_LIVRE_HPP_


#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "mabase.h"
#include "divers.h"
#include "liste_champ.h"
#include "nouv_autre.h"
#include "rech_internet_gen.h"
#include "rech_internet.h"
#include "attenteInsertion.h"

////Header Include Start
#include <wx/bmpbuttn.h>
#include <wx/slider.h>
#include <wx/checkbox.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/combobox.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/panel.h>
#include <wx/notebook.h>
#include <wx/button.h>
////Header Include End

#include <wx/dialog.h>
#include <wx/image.h>
#include <wx/bitmap.h>

//Compatibility for 2.4.x code
#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif
#ifndef wxFIXED_MINSIZE
#define wxFIXED_MINSIZE 0
#endif


#define ID_WXRADIOBOX_PARTICULARITE 1500
#define ID_IMAGECANVAS_IMAGE_FACE   1501
#define ID_IMAGECANVAS_IMAGE_DOS    1502
#define ID_IMAGECANVAS_IMAGE_DIVERS 1503
#define ID_IMAGECANVAS_STAR1        1504
#define ID_IMAGECANVAS_STAR2        1505
#define ID_IMAGECANVAS_STAR3        1506
#define ID_IMAGECANVAS_STAR4        1507
#define ID_IMAGECANVAS_STAR5        1508

#ifdef THIS_DIALOG_STYLE
#undef THIS_DIALOG_STYLE
#endif
////Dialog Style Start
#undef THIS_DIALOG_STYLE
#define THIS_DIALOG_STYLE wxWANTS_CHARS | wxCAPTION
////Dialog Style End


class Nouv_livre : public wxDialog
{
public:
 enum {
////GUI Enum Control ID Start
			ID_N_IMAGE_DIVERS = 1082,
			ID_WXNOTEBOOKPAGE1 = 1081,
			ID_WXBITMAPBUTTON_SUP_IMAGE = 1080,
			ID_WXBITMAPBUTTON_IMAGE_OUVRIR = 1078,
			ID_N_IMAGE_FACE = 1077,
			ID_WXMEMO_RESUME = 1076,
			ID_WXSTATICTEXT_RESUME = 1072,
			ID_WXMEMO_COMMENTAIRE = 1074,
			ID_WXSTATICTEXT_COMMENTAIRE = 1070,
			ID_N_RESUME = 1069,
			ID_WXBUTTON_TRADUCTEUR = 1096,
			ID_WXCOMBOBOX_TRADUCTEUR = 1068,
			ID_WXSTATICTEXT_TRADUCTEUR = 1067,
			ID_WXBUTTON_LANGUE = 1095,
			ID_WXCOMBOBOX_LANGUE = 1064,
			ID_WXSTATICTEXT_LANGUE_O = 1063,
			ID_WXBUTTON_PAYS = 1094,
			ID_WXCOMBOBOX_PAYS = 1060,
			ID_WXSTATICTEXT_PAYS = 1058,
			ID_WXBUTTON_SERIE_O = 1099,
			ID_WXCOMBOBOX_SERIE_O = 1098,
			ID_WXSTATICTEXT_SERIE_O = 1097,
			ID_WXEDIT_SOUS_TITRE_O = 1062,
			ID_WXSTATICTEXT_SOUS_TITRE_O = 1061,
			ID_WXEDIT_TITRE_O = 1057,
			ID_WXSTATICTEXT_TITRE_O = 1056,
			ID_N_VO = 1043,
			ID_WXCHECKBOX_PARTICULARITE = 1110,
			ID_WXCHECKBOX_Note = 1109,
			ID_WXCHECKBOX_LECTURE = 1108,
			ID_WXCHECKBOX_ACHAT = 1107,
			ID_WXDATEPICKERCTRL_LECTURE = 1105,
			ID_WXSTATICTEXT_DATE_LECTURE = 1050,
			ID_WXBUTTON_LOCALISATION = 1093,
			ID_WXCOMBOBOX_LOCALISATION = 1045,
			ID_WXSTATICTEXT_CONDITION = 1044,
			ID_WXBUTTON_ETAT = 1092,
			ID_WXCOMBOBOX_ETAT = 1038,
			ID_WXSTATICTEXT_ETAT = 1039,
			ID_WXEDIT_NB_PAGES = 1036,
			ID_WXSTATICTEXT_NB_PAGES = 1035,
			ID_WXEDIT_REFERENCE = 1032,
			ID_WXSTATICTEXT_REFERENCE = 1031,
			ID_WXSTATICTEXT_GENIAL = 1030,
			ID_WXSTATICTEXT_NUL = 1029,
			ID_WXSTATICTEXT_VAL_NOTE = 1028,
			ID_WXSLIDER_NOTE = 1027,
			ID_WXSTATICTEXT_NOTE = 1025,
			ID_WXEDIT_VALEUR = 1024,
			ID_WXSTATICTEXT_VALEUR = 1023,
			ID_WXDATEPICKERCTRL_ACHAT = 1104,
			ID_WXSTATICTEXT_DATE_ACHAT = 1021,
			ID_N_DETAIL = 1004,
			ID_WXCHECKBOX_PUBLICATION = 1106,
			ID_WXSTATICTEXT_DATE_MAJ_VAL = 1055,
			ID_WXSTATICTEXT_DATE_MAJ = 1054,
			ID_WXSTATICTEXTDATE_ENTREE_VAL = 1053,
			ID_WXSTATICTEXT_DATE_ENTREE = 1052,
			ID_WXSTATICTEXT_RECOMPENSE = 1085,
			ID_WXEDIT_RECOMPENSE = 1084,
			ID_WXEDIT_PRIX = 1066,
			ID_WXSTATICTEXT_PRIX = 1065,
			ID_WXBUTTON_ARTISTE = 1091,
			ID_WXCOMBOBOX_ARTISTE = 1049,
			ID_WXSTATICTEXT_ARTISTE = 1048,
			ID_WXBUTTON_FORMAT = 1090,
			ID_WXCOMBOBOX_FORMAT = 1047,
			ID_WXSTATICTEXT_FORMAT = 1046,
			ID_WXDATEPICKERCTRL_PUBLICATION = 1103,
			ID_WXSTATICTEXT_DATE_PUB = 1018,
			ID_WXBUTTON_EDITEUR = 1089,
			ID_WXCOMBOBOX_EDITEUR = 1020,
			ID_WXSTATICTEXT_EDITEUR = 1019,
			ID_WXBUTTON_INTERNET = 1100,
			ID_WXEDIT_ISBN = 1034,
			ID_WXSTATICTEXT_ISBN = 1033,
			ID_WXBUTTON_GENRE = 1088,
			ID_WXCOMBOBOX_GENRE = 1016,
			ID_WXSTATICTEXT_GENRE = 1015,
			ID_WXEDIT_NO_SERIE = 1014,
			ID_WXSTATICTEXT_NO_SERIE = 1013,
			ID_WXBUTTON_SERIE = 1087,
			ID_WXCOMBOBOX_SERIE = 1010,
			ID_WXSTATICTEXT_SERIE = 1009,
			ID_WXEDIT_SOUS_TITRE = 1041,
			ID_WXSTATICTEXT8 = 1040,
			ID_WXBUTTON_AUTEUR = 1086,
			ID_WXCOMBOBOX_AUTEUR = 1012,
			ID_WXSTATICTEXT_AUTEUR = 1011,
			ID_WXEDIT_TITRE = 1008,
			ID_WXSTATICTEXT_TITRE = 1005,
			ID_N_LIVRE = 1003,
			ID_WXNOTEBOOK_NOUV = 1001,
			ID_WXBUTTON_INTERNET_G = 1102,
			ID_WXBUTTON_NOUV_OK = 1006,
////GUI Enum Control ID End
ID_DUMMY_VALUE_ //Dont Delete this DummyValue
}; //End of Enum
    Nouv_livre( wxWindow *parent, wxWindowID id = 1, const wxString &title = _T("Nouveau livre"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = THIS_DIALOG_STYLE);
    virtual ~Nouv_livre();
public:
	//myBitmapPanel *WxPanel_image_face;

  ////GUI Control Declaration Start
		wxPanel *n_image_divers;
		wxPanel *n_image_dos;
		wxBitmapButton *WxBitmapButton_supp_image_face;
		wxBitmapButton *WxBitmapButton_face_ouvrir;
		wxPanel *n_image_face;
		wxTextCtrl *WxMemo_resume;
		wxStaticText *WxStaticText_resume;
		wxTextCtrl *WxMemo_commentaire;
		wxStaticText *WxStaticText_commentaire;
		wxPanel *n_resume;
		wxButton *WxButton_traducteur;
		wxComboBox *WxComboBox_traducteur;
		wxStaticText *WxStaticText_traducteur;
		wxButton *WxButton_langue;
		wxComboBox *WxComboBox_langue;
		wxStaticText *WxStaticText_langue;
		wxButton *WxButton_pays;
		wxComboBox *WxComboBox_pays;
		wxStaticText *WxStaticText_pays;
		wxButton *WxButton_serie_o;
		wxComboBox *WxComboBox_serie_o;
		wxStaticText *WxStaticText_serie_o;
		wxTextCtrl *WxEdit_sous_titre_o;
		wxStaticText *WxStaticText_sous_titre_o;
		wxTextCtrl *WxEdit_titre_o;
		wxStaticText *WxStaticText_titre_o;
		wxPanel *n_vo;
		wxCheckBox *WxCheckBox_particularite;
		wxCheckBox *WxCheckBox_note;
		wxCheckBox *WxCheckBox_lecture;
		wxCheckBox *WxCheckBox_achat;
		wxDatePickerCtrl *WxDatePickerCtrl_lecture;
		wxStaticText *WxStaticText_date_lecture;
		wxButton *WxButton_localisation;
		wxComboBox *WxComboBox_localisation;
		wxStaticText *WxStaticText_condition;
		wxButton *WxButton_etat;
		wxComboBox *WxComboBox_etat;
		wxStaticText *WxStaticText_etat;
		wxTextCtrl *WxEdit_nb_pages;
		wxStaticText *WxStaticText_nb_pages;
		wxTextCtrl *WxEdit_reference;
		wxStaticText *WxStaticText_reference;
		wxStaticText *WxStaticText_genial;
		wxStaticText *WxStaticText_nul;
		wxStaticText *WxStaticText_val_note;
		wxSlider *WxSlider_note;
		wxStaticText *WxStaticText_note;
		wxTextCtrl *WxEdit_valeur;
		wxStaticText *WxStaticText_valeur;
		wxDatePickerCtrl *WxDatePickerCtrl_achat;
		wxStaticText *WxStaticText_date_achat;
		wxPanel *n_detail;
		wxCheckBox *WxCheckBox_publication;
		wxStaticText *WxStaticText_date_maj_val;
		wxStaticText *WxStaticText_date_maj;
		wxStaticText *WxStaticTextdate_entree_val;
		wxStaticText *WxStaticText_date_entree;
		wxStaticText *WxStaticText_recompense;
		wxTextCtrl *WxEdit_recompense;
		wxTextCtrl *WxEdit_prix;
		wxStaticText *WxStaticText_prix;
		wxButton *WxButton_artiste;
		wxComboBox *WxComboBox_artiste;
		wxStaticText *WxStaticText_artiste;
		wxButton *WxButton_format;
		wxComboBox *WxComboBox_format;
		wxStaticText *WxStaticText_format;
		wxDatePickerCtrl *WxDatePickerCtrl_publication;
		wxStaticText *WxStaticText_date_pub;
		wxButton *WxButton_editeur;
		wxComboBox *WxComboBox_editeur;
		wxStaticText *WxStaticText_editeur;
		wxButton *WxButton_internet;
		wxTextCtrl *WxEdit_isbn;
		wxStaticText *WxStaticText_isbn;
		wxButton *WxButton_genre;
		wxComboBox *WxComboBox_genre;
		wxStaticText *WxStaticText_genre;
		wxTextCtrl *WxEdit_no_serie;
		wxStaticText *WxStaticText_no_serie;
		wxButton *WxButton_serie;
		wxComboBox *WxComboBox_serie;
		wxStaticText *WxStaticText_serie;
		wxTextCtrl *WxEdit_sous_titre;
		wxStaticText *WxStaticText_sous_titre;
		wxButton *WxButton_auteur;
		wxComboBox *WxComboBox_auteur;
		wxStaticText *WxStaticText_auteur;
		wxTextCtrl *WxEdit_titre;
		wxStaticText *WxStaticText_titre;
		wxPanel *n_livre;
		wxNotebook *WxNotebook_nouv;
		wxButton *WxButton_internet_g;
		wxButton *WxButton_nouv_annul;
		wxButton *WxButton_nouv_ok;
  ////GUI Control Declaration End
	wxBitmapButton *WxBitmapButton_supp_image_dos;
	wxBitmapButton *WxBitmapButton_dos_ouvrir;
	wxBitmapButton *WxBitmapButton_supp_image_divers;
	wxBitmapButton *WxBitmapButton_divers_ouvrir;

    wxRadioBox *wxRadioBox_particularite;
    ma_base *la_belle;
    livre monlivre;
    // pour l'autocompletion
    wxComboBox *anc_combo;
    int taille_entree; 
    // gestion des images pour la note
    ImageCanvas *canvas_note[6];
    // pour savoir si on est en insertion ou en modification
    bool insertion;
    wxString id_courant;
    // gestion de l'image
    /*wxImage image_face;
    bool     image_face_charge;*/
    ImageCanvas *canvas_image_face;
    /*wxImage image_dos;
    bool     image_dos_charge;*/
    ImageCanvas *canvas_image_dos;
    /*wxImage image_divers;
    bool     image_divers_charge;*/
    ImageCanvas *canvas_image_divers;
private:
    DECLARE_EVENT_TABLE()

public:
    Nouv_livre( ma_base *pour_insere, wxWindow *parent, wxWindowID id = 1, const wxString &title = _T("Nouveau livre"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = THIS_DIALOG_STYLE);
    Nouv_livre( ma_base *pour_modif,wxString id_modif, bool insert, wxWindow *parent, wxWindowID id = 1, const wxString &title = _T("Modification du livre"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = THIS_DIALOG_STYLE);
    Nouv_livre (ma_base *pour_modif, wxArrayInt liste_id, bool insert, wxWindow *parent, wxWindowID id, 
        const wxString &title = _T("Modification de livres en masse"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = THIS_DIALOG_STYLE);
    Nouv_livre( ma_base *pour_insere, attenteInsertion* itemInsertion, wxWindow *parent, wxWindowID id = 1, 
        const wxString &title = _T("Nouveau livre"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = THIS_DIALOG_STYLE);
                
    void init_edit(wxString nom_champ, wxTextCtrl *zone);
    void init_date(wxString nom_champ, wxDatePickerCtrl *zone, wxCheckBox* ckConserver = NULL);
    void init_statictext(wxString nom_champ, wxStaticText *s_text, wxString texteSiVariable = "");
    void init_radiobox(wxString nom_champ, wxRadioBox *zonen , wxCheckBox* ckConserver = NULL);
    void init_slider(wxString nom_champ, wxSlider *slider, wxCheckBox* ckConserver = NULL);
    bool init_image(wxString nom_champ, ImageCanvas *moncavas);//, wxImage *monimage);
    void init_etoiles();
	int init_combo(wxComboBox *lacombo, wxString nomtable);
    void Nouv_livreClose(wxCloseEvent& event);
    void CreateGUIControls(void);
	void WxButton_nouv_okClick(wxCommandEvent& event);
	void WxButton_nouv_annulClick(wxCommandEvent& event);
	void WxSlider_noteScroll(wxScrollEvent& event);
	int inserer_livre();
	void wxCombo_remplir(wxCommandEvent& event);
	void wxCombo_select(wxInitDialogEvent& event);
	int insere_table_annexe(wxComboBox *donnee, wxString nom_table, wxString libelleGroupePluriel=_T(""));
	void ajoute_champ(wxString &liste_champ, wxString &liste_valeur, wxString n_champ, wxString v_champ, wxCheckBox* ckConserver = NULL);
	void ajoute_image(wxString &liste_champ, wxString &liste_valeur, wxString n_champ, bool charge);
	void create_radiobox();
	void WxButtondate_pubClick(wxCommandEvent& event);
	void wxEdit_Gesdate(wxCommandEvent& event);
	void WxBitmapButton_face_ouvrirClick(wxCommandEvent& event);
	//void OnPaint(wxPaintEvent& event);
	void change_page(wxNotebookEvent &event);
	void WxBitmapButton_supp_image_faceClick(wxCommandEvent& event);
	//wxString gettempdir();
	/*void rempli_canvas(ImageCanvas *lecanvas, wxImage *image);*/
	void WxButton_auteurClick(wxCommandEvent& event);
    void init_champ(wxString nom_champ, wxString valeur);
	void WxButton_internetClick(wxCommandEvent& event);
	void WxButton_internet_gClick(wxCommandEvent& event);
    void mise_a_jour(rech_internet *rech);
	void Nouv_livreInitDialog(wxInitDialogEvent& event);

private:    
    static long s_nbInstances;
    wxString m_listeIdRequete;
    attenteInsertion* m_itemInsertion;
};


#endif
 
 
 
 
