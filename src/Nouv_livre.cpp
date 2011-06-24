//---------------------------------------------------------------------------
//
// Name:        Nouv_livre.cpp
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

#ifdef __GNUG__
    #pragma implementation "Nouv_livre.cpp"
#endif

/* for compilers that support precompilation
   includes "wx/wx.h" */

#include <wx/wxprec.h>
#include <wx/string.h>
#include <wx/radiobox.h>
#include <wx/calctrl.h>
#include <wx/datetime.h>
#include <wx/stream.h>
#include <stdlib.h>
#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#include "Nouv_livre.h" 

#include "star1.xpm"
#include "star2.xpm"
////Header Include Start
#include "Images/Nouv_livre_WxBitmapButton_supp_image_face_XPM.xpm"
#include "Images/Nouv_livre_WxBitmapButton_face_ouvrir_XPM.xpm"
////Header Include End
 
#include "VerifNouveauGroupeDlg.h"
#include "ParamManager.h"

long Nouv_livre::s_nbInstances = 0;

const wxString str_nePasModifier = "<< ne pas modifier >>";

//----------------------------------------------------------------------------
// Nouv_livre
//----------------------------------------------------------------------------

    ////Event Table Start
BEGIN_EVENT_TABLE(Nouv_livre,wxDialog)
	////Manual Code Start
	EVT_TEXT(ID_WXCOMBOBOX_AUTEUR,Nouv_livre::wxCombo_remplir)
	EVT_TEXT(ID_WXCOMBOBOX_SERIE,Nouv_livre::wxCombo_remplir)
	EVT_TEXT(ID_WXCOMBOBOX_GENRE,Nouv_livre::wxCombo_remplir)
	EVT_TEXT(ID_WXCOMBOBOX_EDITEUR,Nouv_livre::wxCombo_remplir)
	EVT_TEXT(ID_WXCOMBOBOX_FORMAT,Nouv_livre::wxCombo_remplir)
	EVT_TEXT(ID_WXCOMBOBOX_ARTISTE,Nouv_livre::wxCombo_remplir)
	EVT_TEXT(ID_WXCOMBOBOX_ETAT,Nouv_livre::wxCombo_remplir)
	EVT_TEXT(ID_WXCOMBOBOX_LOCALISATION,Nouv_livre::wxCombo_remplir)
	EVT_TEXT(ID_WXCOMBOBOX_SERIE_O,Nouv_livre::wxCombo_remplir)
	EVT_TEXT(ID_WXCOMBOBOX_PAYS,Nouv_livre::wxCombo_remplir)
	EVT_TEXT(ID_WXCOMBOBOX_LANGUE,Nouv_livre::wxCombo_remplir)
	EVT_TEXT(ID_WXCOMBOBOX_TRADUCTEUR,Nouv_livre::wxCombo_remplir)
	//	EVT_TEXT(ID_WXEDIT_DATE_LECTURE,Nouv_livre::wxEdit_Gesdate)
	//	EVT_TEXT(ID_WXEDIT_DATE_ACHAT,Nouv_livre::wxEdit_Gesdate)
	//EVT_PAINT(Nouv_livre::OnPaint)
	//EVT_PAINT(ImageCanvas::OnPaint)
	EVT_NOTEBOOK_PAGE_CHANGED(ID_WXNOTEBOOK_NOUV, Nouv_livre::change_page)
	////Manual Code End
	
	EVT_CLOSE(Nouv_livre::Nouv_livreClose)
	EVT_INIT_DIALOG(Nouv_livre::Nouv_livreInitDialog)
	EVT_BUTTON(ID_WXBITMAPBUTTON_SUP_IMAGE,Nouv_livre::WxBitmapButton_supp_image_faceClick)
	EVT_BUTTON(ID_WXBITMAPBUTTON_IMAGE_OUVRIR,Nouv_livre::WxBitmapButton_face_ouvrirClick)
	EVT_BUTTON(ID_WXBUTTON_TRADUCTEUR,Nouv_livre::WxButton_auteurClick)
	EVT_BUTTON(ID_WXBUTTON_LANGUE,Nouv_livre::WxButton_auteurClick)
	EVT_BUTTON(ID_WXBUTTON_PAYS,Nouv_livre::WxButton_auteurClick)
	EVT_BUTTON(ID_WXBUTTON_SERIE_O,Nouv_livre::WxButton_auteurClick)
	EVT_BUTTON(ID_WXBUTTON_LOCALISATION,Nouv_livre::WxButton_auteurClick)
	EVT_BUTTON(ID_WXBUTTON_ETAT,Nouv_livre::WxButton_auteurClick)
	
	EVT_COMMAND_SCROLL(ID_WXSLIDER_NOTE,Nouv_livre::WxSlider_noteScroll)
	EVT_BUTTON(ID_WXBUTTON_ARTISTE,Nouv_livre::WxButton_auteurClick)
	EVT_BUTTON(ID_WXBUTTON_FORMAT,Nouv_livre::WxButton_auteurClick)
	EVT_BUTTON(ID_WXBUTTON_EDITEUR,Nouv_livre::WxButton_auteurClick)
	EVT_BUTTON(ID_WXBUTTON_INTERNET,Nouv_livre::WxButton_internetClick)
	EVT_BUTTON(ID_WXBUTTON_GENRE,Nouv_livre::WxButton_auteurClick)
	EVT_BUTTON(ID_WXBUTTON_SERIE,Nouv_livre::WxButton_auteurClick)
	EVT_BUTTON(ID_WXBUTTON_AUTEUR,Nouv_livre::WxButton_auteurClick)
	EVT_BUTTON(ID_WXBUTTON_INTERNET_G,Nouv_livre::WxButton_internet_gClick)
	EVT_BUTTON(wxID_CANCEL ,Nouv_livre::WxButton_nouv_annulClick)
	EVT_BUTTON(ID_WXBUTTON_NOUV_OK,Nouv_livre::WxButton_nouv_okClick)
END_EVENT_TABLE()
    ////Event Table End



Nouv_livre::Nouv_livre( wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style )
    : wxDialog( parent, id, title, position, size, style)
{
    s_nbInstances++;
    wxLogMessage("Nouv_livre::Nouv_livre() - nbInstances = %ld", s_nbInstances);

    insertion=true;
    id_courant=_("-1");
    la_belle = NULL;
    m_itemInsertion = NULL;
    CreateGUIControls();
    SetTitle(title);

    // masquer toutes les CK "conserver"
    WxCheckBox_particularite->Show(false);
    WxCheckBox_note->Show(false);
    WxCheckBox_lecture->Show(false);
    WxCheckBox_achat->Show(false);
    WxCheckBox_publication->Show(false);
}

Nouv_livre::Nouv_livre(ma_base *pour_insere, wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style )
    : wxDialog( parent, id, title, position, size, style)
{
    s_nbInstances++;
    wxLogMessage("Nouv_livre::Nouv_livre() - nbInstances = %ld", s_nbInstances);

    insertion=true;
    id_courant=_("-1");
    la_belle=pour_insere;
    m_itemInsertion = NULL;
    CreateGUIControls();
    SetTitle(title);
    
    // masquer toutes les CK "conserver"
    WxCheckBox_particularite->Show(false);
    WxCheckBox_note->Show(false);
    WxCheckBox_lecture->Show(false);
    WxCheckBox_achat->Show(false);
    WxCheckBox_publication->Show(false);
}

Nouv_livre::Nouv_livre(ma_base *pour_insere, attenteInsertion* itemInsertion, wxWindow *parent, wxWindowID id, 
                       const wxString &title, const wxPoint &position, const wxSize& size, long style )
    : wxDialog( parent, id, title, position, size, style)
{
    s_nbInstances++;
    wxLogMessage("Nouv_livre::Nouv_livre() - nbInstances = %ld", s_nbInstances);

    insertion=true;
    id_courant=_("-1");
    la_belle=pour_insere;
    m_itemInsertion = itemInsertion;
    CreateGUIControls();
    SetTitle(title);
    
    // masquer toutes les CK "conserver"
    WxCheckBox_particularite->Show(false);
    WxCheckBox_note->Show(false);
    WxCheckBox_lecture->Show(false);
    WxCheckBox_achat->Show(false);
    WxCheckBox_publication->Show(false);
}


Nouv_livre::Nouv_livre(ma_base *pour_modif, wxString id_modif, bool insert, wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style )
    : wxDialog( parent, id, title, position, size, style)
{
    s_nbInstances++;
    wxLogMessage("Nouv_livre::Nouv_livre() - nbInstances = %ld", s_nbInstances);
    
    insertion=insert;
    id_courant=id_modif;
    la_belle=pour_modif;
    m_itemInsertion = NULL;
    CreateGUIControls();
    SetTitle(title);


    //wxMessageBox(id_modif,"coco", wxOK | wxICON_INFORMATION, this);
    // initialisation des données à partir de la table
    init_edit(_("titre"), WxEdit_titre);
    init_edit("sous_titre", WxEdit_sous_titre);
    init_edit("no_serie", WxEdit_no_serie);
    init_edit("isbn", WxEdit_isbn);
    init_date("date_publication", WxDatePickerCtrl_publication);
    init_edit("prix", WxEdit_prix);
    init_edit("recompense", WxEdit_recompense);
        
    //init_edit("date_achat", WxEdit_date_achat);
    init_date("date_achat", WxDatePickerCtrl_achat);
    init_edit("valeur", WxEdit_valeur);
    init_edit("reference", WxEdit_reference);
    init_edit("nb_pages", WxEdit_nb_pages);
    //init_edit("date_lecture", WxEdit_date_lecture);
    init_date("date_lecture", WxDatePickerCtrl_lecture);
    init_slider("note",WxSlider_note);
    init_etoiles();
    init_radiobox("particularite", wxRadioBox_particularite);
    init_statictext("date_maj", WxStaticText_date_maj_val);
    init_statictext("date_entree", WxStaticTextdate_entree_val);
    init_statictext("note",WxStaticText_val_note);

        
    init_edit("titre_original", WxEdit_titre_o);
    init_edit("sous_titre_o", WxEdit_sous_titre_o);
        
    init_edit("commentaire", WxMemo_commentaire);
    init_edit("resume", WxMemo_resume);
/*    image_face_charge=init_image("image_face", canvas_image_face, &image_face);
    image_dos_charge=init_image("image_dos", canvas_image_dos, &image_dos);
    image_divers_charge=init_image("image_tranche", canvas_image_divers, &image_divers);*/
    init_image("image_face", canvas_image_face);//, &image_face);
    init_image("image_dos", canvas_image_dos);//, &image_dos);
    init_image("image_tranche", canvas_image_divers);//, &image_divers);
    
    // masquer toutes les CK "conserver"
    WxCheckBox_particularite->Show(false);
    WxCheckBox_note->Show(false);
    WxCheckBox_lecture->Show(false);
    WxCheckBox_achat->Show(false);
    WxCheckBox_publication->Show(false);
}

Nouv_livre::Nouv_livre(ma_base *pour_modif, wxArrayInt liste_id, bool insert, 
                       wxWindow *parent, wxWindowID id, const wxString &title, 
                       const wxPoint &position, const wxSize& size, long style )
    : wxDialog( parent, id, title, position, size, style)
{
    s_nbInstances++;
    wxLogMessage("Nouv_livre::Nouv_livre() - nbInstances = %ld", s_nbInstances);
    
    // construction de la liste des id au format (xx, xx, xx) pour requête where id in (xx, xx, xx)
    m_listeIdRequete = "(";
    for (size_t ii = 0; ii < liste_id.GetCount(); ii++) {
        m_listeIdRequete += wxString::Format("%d", liste_id[ii]);
        if (ii < liste_id.GetCount() - 1)
            m_listeIdRequete += ", ";
    }
    m_listeIdRequete += ")";
    id_courant = "-1";
    
    insertion=insert;
    m_itemInsertion = NULL;
    la_belle=pour_modif;
    CreateGUIControls();
    SetTitle(title);

    //wxMessageBox(id_modif,"coco", wxOK | wxICON_INFORMATION, this);
    // initialisation des données à partir de la table
    init_edit(_("titre"), WxEdit_titre);
    init_edit("sous_titre", WxEdit_sous_titre);
    init_edit("no_serie", WxEdit_no_serie);
    init_edit("isbn", WxEdit_isbn);
    init_date("date_publication", WxDatePickerCtrl_publication, WxCheckBox_publication);
    init_edit("prix", WxEdit_prix);
    init_edit("recompense", WxEdit_recompense);
        
    //init_edit("date_achat", WxEdit_date_achat);
    init_date("date_achat", WxDatePickerCtrl_achat, WxCheckBox_achat);
    init_edit("valeur", WxEdit_valeur);
    init_edit("reference", WxEdit_reference);
    init_edit("nb_pages", WxEdit_nb_pages);
    //init_edit("date_lecture", WxEdit_date_lecture);
    init_date("date_lecture", WxDatePickerCtrl_lecture, WxCheckBox_lecture);
    init_slider("note", WxSlider_note, WxCheckBox_note);
    init_etoiles();
    init_radiobox("particularite", wxRadioBox_particularite, WxCheckBox_particularite);
    init_statictext("date_maj", WxStaticText_date_maj_val, "plusieurs valeurs");
    init_statictext("date_entree", WxStaticTextdate_entree_val, "plusieurs valeurs");
    init_statictext("note",WxStaticText_val_note, "");

        
    init_edit("titre_original", WxEdit_titre_o);
    init_edit("sous_titre_o", WxEdit_sous_titre_o);
        
    init_edit("commentaire", WxMemo_commentaire);
    init_edit("resume", WxMemo_resume);
    
    // masquer les onglets images qui ne sont pas supposées être partagées entre plusieurs livres ...
    // on supprime en fait les 3 derniers onglets, sans vérifier qu'il s'agit bien des images ...
    WxNotebook_nouv->DeletePage(WxNotebook_nouv->GetPageCount()-1);
    WxNotebook_nouv->DeletePage(WxNotebook_nouv->GetPageCount()-1);
    WxNotebook_nouv->DeletePage(WxNotebook_nouv->GetPageCount()-1);
}


Nouv_livre::~Nouv_livre()
{
    s_nbInstances--;
    wxLogMessage("Nouv_livre::~Nouv_livre() - nbInstances = %ld", s_nbInstances);    
} 

bool Nouv_livre::init_image(wxString nom_champ, ImageCanvas *moncanvas) {//, wxImage *monimage) {
    wxString query;
    int ret, taille;
    wxString texte;
    wxFile fichier;
    bool tt=false;
    
    query="SELECT " + nom_champ +" FROM livre WHERE rowid=" + id_courant;
    ret=la_belle->transac_prepare(query);
    if (ret<0) {
        la_belle->get_erreur(texte);
        wxMessageBox(texte,"probleme", wxOK | wxICON_EXCLAMATION, this);
        return false;
    }

    ret=la_belle->transac_step();
    if (ret<0) {
        la_belle->get_erreur(texte);
        wxMessageBox(texte,"probleme", wxOK | wxICON_EXCLAMATION, this);
        ret = SQLITE_ERROR;
    }

    if(ret==SQLITE_ROW ) {
        wxString chemin=gettempdir();
        chemin+="\\1.jpg";
        fichier.Open(chemin,wxFile::write);
        ret=la_belle->get_value_blob(0,&fichier,taille);
        if (ret<0) {
            la_belle->get_erreur(texte);
            wxMessageBox(texte,"probleme", wxOK | wxICON_EXCLAMATION, this);
            taille=0;
        }
        if (taille > 0) {
            moncanvas->init(chemin);
            /*tt=monimage->LoadFile(chemin, wxBITMAP_TYPE_JPEG);
            if (tt==true) {
                rempli_canvas(moncanvas, monimage);
            }    */
        }    
        /*affiche=new wxBitmap(tempo, -1);
        canvas_image_face->init(*affiche);        
        canvas_image_face->Refresh();*/

        //s_text->SetLabel(texte);
    }  
    la_belle->transac_fin();
    return tt;
}
void Nouv_livre::init_statictext(wxString nom_champ, wxStaticText *s_text, wxString texteSiVariable) {
    wxString query;
    int ret, taille;
    wxString texte;
    
    if (m_listeIdRequete != "") {      // cas d'une liste d'id --> afficher la valeur commune, ou "<< ne pas modifier >>"
        // query="SELECT " + nom_champ +" FROM livre WHERE rowid=" + id_courant;
        query = "SELECT DISTINCT " + nom_champ + " FROM livre WHERE rowid IN " + m_listeIdRequete;
        // wxMessageBox(query);

        int nbReponses = 0;
        if (la_belle->transac_prepare(query) < 0) {
            la_belle->get_erreur(texte);
            wxMessageBox(texte, "probleme", wxOK | wxICON_EXCLAMATION, this);
        }
        while (la_belle->transac_step()==SQLITE_ROW) {
            la_belle->get_value_char(0,texte,taille);
            nbReponses ++;
        }  
        la_belle->transac_fin();
        
        if (nbReponses == 1) {
            s_text->SetLabel(texte);
        } else if (nbReponses > 1) {
            s_text->SetLabel(texteSiVariable);
        }
    } else {    
        query="SELECT " + nom_champ +" FROM livre WHERE rowid=" + id_courant;
        //wxMessageBox(query,"coco", wxOK | wxICON_INFORMATION, this);
       
        ret=la_belle->transac_prepare(query);
        if (ret<0) {
            la_belle->get_erreur(texte);
            wxMessageBox(texte,"probleme", wxOK | wxICON_EXCLAMATION, this);
            return;
        }
    
        ret=la_belle->transac_step();
    
        if(ret==SQLITE_ROW ) {
            la_belle->get_value_char(0,texte,taille);
            s_text->SetLabel(texte);
        }  
        la_belle->transac_fin();
    }
}    

void Nouv_livre::init_radiobox(wxString nom_champ, wxRadioBox *radiobox, wxCheckBox* ckConserver)
{
    wxString query;
    int ret, taille;
    double val;
    wxString texte;
    
    if (m_listeIdRequete != "") {      // cas d'une liste d'id --> afficher la valeur commune, ou "<< ne pas modifier >>"
        // query="SELECT " + nom_champ +" FROM livre WHERE rowid=" + id_courant;
        query = "SELECT DISTINCT " + nom_champ + " FROM livre WHERE rowid IN " + m_listeIdRequete;
        // wxMessageBox(query);

        int nbReponses = 0;
        if (la_belle->transac_prepare(query) < 0) {
            la_belle->get_erreur(texte);
            wxMessageBox(texte, "probleme", wxOK | wxICON_EXCLAMATION, this);
        }
        while (la_belle->transac_step()==SQLITE_ROW) {
            la_belle->get_value_char(0,texte,taille);
            nbReponses ++;
        }  
        la_belle->transac_fin();
        
        if (nbReponses == 1) {
            la_belle->get_value_char(0,texte,taille);
            texte.ToDouble(&val);
            radiobox->SetSelection((int)val);
        } else if (nbReponses > 1) {
            ckConserver->SetValue(true);
            radiobox->SetSelection(-1);
        }
    } else {    
        query="SELECT " + nom_champ +" FROM livre WHERE rowid=" + id_courant;
        //wxMessageBox(query,"coco", wxOK | wxICON_INFORMATION, this);
       
        ret=la_belle->transac_prepare(query);
        if (ret<0) {
            la_belle->get_erreur(texte);
            wxMessageBox(texte,"probleme", wxOK | wxICON_EXCLAMATION, this);
            return;
        }
    
        ret=la_belle->transac_step();
    
        if(ret==SQLITE_ROW ) {
            la_belle->get_value_char(0,texte,taille);
            texte.ToDouble(&val);
            radiobox->SetSelection((int)val);
        }  
        la_belle->transac_fin();
    }
}    

void Nouv_livre::init_slider(wxString nom_champ, wxSlider *slider, wxCheckBox* ckConserver) {
    wxString query;
    int ret, taille;
    double val;
    wxString texte;
    
    if (m_listeIdRequete != "") {      // cas d'une liste d'id --> afficher la valeur commune, ou "<< ne pas modifier >>"
        // query="SELECT " + nom_champ +" FROM livre WHERE rowid=" + id_courant;
        query = "SELECT DISTINCT " + nom_champ + " FROM livre WHERE rowid IN " + m_listeIdRequete;
        // wxMessageBox(query);

        int nbReponses = 0;
        if (la_belle->transac_prepare(query) < 0) {
            la_belle->get_erreur(texte);
            wxMessageBox(texte, "probleme", wxOK | wxICON_EXCLAMATION, this);
        }
        while (la_belle->transac_step()==SQLITE_ROW) {
            la_belle->get_value_char(0,texte,taille);
            nbReponses ++;
        }  
        la_belle->transac_fin();
        
        if (nbReponses == 1) {
            texte.ToDouble(&val);
            slider->SetValue((int)val);
            if (ckConserver)
                ckConserver->SetValue(false);
        } else if (nbReponses > 1) {
            ckConserver->SetValue(true);
        }
    } else {    
        query="SELECT " + nom_champ +" FROM livre WHERE rowid=" + id_courant;
        //wxMessageBox(query,"coco", wxOK | wxICON_INFORMATION, this);
       
        ret=la_belle->transac_prepare(query);
        if (ret<0) {
            la_belle->get_erreur(texte);
            wxMessageBox(texte,"probleme", wxOK | wxICON_EXCLAMATION, this);
            return;
        }
    
        ret=la_belle->transac_step();
    
        if(ret==SQLITE_ROW ) {
            la_belle->get_value_char(0,texte,taille);
            texte.ToDouble(&val);
            slider->SetValue((int)val);
        }  
        la_belle->transac_fin();
    }
}    

void Nouv_livre::init_date(wxString nom_champ, wxDatePickerCtrl *zone, wxCheckBox* ckConserver) {
    wxString query;
    int ret, taille;
    wxString texte;
    wxDateTime madate;

    if (m_listeIdRequete != "") {      // cas d'une liste d'id --> afficher la valeur commune, ou "<< ne pas modifier >>"
        // query="SELECT " + nom_champ +" FROM livre WHERE rowid=" + id_courant;
        query = "SELECT DISTINCT " + nom_champ + " FROM livre WHERE rowid IN " + m_listeIdRequete;
        // wxMessageBox(query);

        int nbReponses = 0;
        if (la_belle->transac_prepare(query) < 0) {
            la_belle->get_erreur(texte);
            wxMessageBox(texte, "probleme", wxOK | wxICON_EXCLAMATION, this);
        }
        while (la_belle->transac_step()==SQLITE_ROW) {
            la_belle->get_value_char(0,texte,taille);
            nbReponses ++;
        }  
        la_belle->transac_fin();
        
        if (nbReponses == 1) {
            madate.ParseFormat(texte,"%d/%m/%Y");
            zone->SetValue(madate);
            if (ckConserver)
                ckConserver->SetValue(false);
        } else if (nbReponses > 1) {
            zone->SetValue(wxInvalidDateTime);
            ckConserver->SetValue(true);
        }
    } else {    
        query="SELECT " + nom_champ +" FROM livre WHERE rowid=" + id_courant;
        //wxMessageBox(query,"coco", wxOK | wxICON_INFORMATION, this);
       
        ret=la_belle->transac_prepare(query);
        if (ret<0) {
            la_belle->get_erreur(texte);
            wxMessageBox(texte,"probleme", wxOK | wxICON_EXCLAMATION, this);
            return;
        }
    
        ret=la_belle->transac_step();
    
        if(ret==SQLITE_ROW ) {
            la_belle->get_value_char(0,texte,taille);
        }  
        //wxMessageBox(texte,"date", wxOK | wxICON_EXCLAMATION, this);
        la_belle->transac_fin();
        madate.ParseFormat(texte,"%d/%m/%Y");
        zone->SetValue(madate);
        //wxMessageBox(madate.FormatISODate(),"date", wxOK | wxICON_EXCLAMATION, this);
    }    
}    



void Nouv_livre::init_edit(wxString nom_champ, wxTextCtrl *zone) {
    wxString query;
    int ret, taille;
    wxString texte;

    if (m_listeIdRequete != "") {      // cas d'une liste d'id --> afficher la valeur commune, ou "<< ne pas modifier >>"
        // query="SELECT " + nom_champ +" FROM livre WHERE rowid=" + id_courant;
        query = "SELECT DISTINCT " + nom_champ + " FROM livre WHERE rowid IN " + m_listeIdRequete;
        // wxMessageBox(query);

        int nbReponses = 0;
        if (la_belle->transac_prepare(query) < 0) {
            la_belle->get_erreur(texte);
            wxMessageBox(texte, "probleme", wxOK | wxICON_EXCLAMATION, this);
        }
        while (la_belle->transac_step()==SQLITE_ROW) {
            la_belle->get_value_char(0,texte,taille);
            nbReponses ++;
        }  
        la_belle->transac_fin();
        
        if (nbReponses == 1) {
            zone->SetValue(texte);
        } else if (nbReponses > 1) {
            zone->SetValue(str_nePasModifier);
        }
    } else if (id_courant != "-1") {     // si id n'est pas nul on initialise la valeur du champ
        query="SELECT " + nom_champ +" FROM livre WHERE rowid=" + id_courant;
        //wxMessageBox(query,"coco", wxOK | wxICON_INFORMATION, this);
       
        ret=la_belle->transac_prepare(query);
        if (ret<0) {
            la_belle->get_erreur(texte);
            wxMessageBox(texte,"probleme", wxOK | wxICON_EXCLAMATION, this);
            return;
        }
    
        ret=la_belle->transac_step();
    
        if(ret==SQLITE_ROW ) {
            la_belle->get_value_char(0,texte,taille);
            zone->SetValue(texte);
        }  
        la_belle->transac_fin();
    }
}

void Nouv_livre::CreateGUIControls(void)
{
    int largeur_obj, hauteur_obj;
    anc_combo=NULL;
    taille_entree=0;
/*    image_face_charge=false;
    image_dos_charge=false;
    image_divers_charge=false;*/
    int i, x, y; 
    //image_face=NULL;
	//n_livre =  new myBitmapPanel(WxNotebook_nouv, ID_N_LIVRE,wxPoint(4,24),wxSize(629,353) );
    ////GUI Items Creation Start

	wxInitAllImageHandlers();   //Initialize graphic format handlers

	WxButton_nouv_ok = new wxButton(this, ID_WXBUTTON_NOUV_OK, wxT("OK"), wxPoint(181, 383), wxSize(83, 28), 0, wxDefaultValidator, wxT("WxButton_nouv_ok"));
	WxButton_nouv_ok->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxButton_nouv_annul = new wxButton(this, wxID_CANCEL , wxT("Annuler"), wxPoint(367, 383), wxSize(79, 28), 0, wxDefaultValidator, wxT("WxButton_nouv_annul"));
	WxButton_nouv_annul->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxButton_internet_g = new wxButton(this, ID_WXBUTTON_INTERNET_G, wxT("Recherche internet"), wxPoint(530, 383), wxSize(101, 28), 0, wxDefaultValidator, wxT("WxButton_internet_g"));
	WxButton_internet_g->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxNotebook_nouv = new wxNotebook(this, ID_WXNOTEBOOK_NOUV, wxPoint(2, 0), wxSize(637, 381), wxNB_DEFAULT);
	WxNotebook_nouv->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	n_livre = new wxPanel(WxNotebook_nouv, ID_N_LIVRE, wxPoint(4, 24), wxSize(629, 353));
	n_livre->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));
	WxNotebook_nouv->AddPage(n_livre, wxT("Livre"));

	WxStaticText_titre = new wxStaticText(n_livre, ID_WXSTATICTEXT_TITRE, wxT("Titre :"), wxPoint(3, 23), wxDefaultSize, 0, wxT("WxStaticText_titre"));
	WxStaticText_titre->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_titre = new wxTextCtrl(n_livre, ID_WXEDIT_TITRE, wxT(""), wxPoint(52, 21), wxSize(236, 21), 0, wxDefaultValidator, wxT("WxEdit_titre"));
	WxEdit_titre->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_auteur = new wxStaticText(n_livre, ID_WXSTATICTEXT_AUTEUR, wxT("Auteur :"), wxPoint(319, 22), wxDefaultSize, 0, wxT("WxStaticText_auteur"));
	WxStaticText_auteur->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	wxArrayString arrayStringFor_WxComboBox_auteur;
	WxComboBox_auteur = new wxComboBox(n_livre, ID_WXCOMBOBOX_AUTEUR, wxT(""), wxPoint(365, 19), wxSize(232, 21), arrayStringFor_WxComboBox_auteur, 0, wxDefaultValidator, wxT("WxComboBox_auteur"));
	WxComboBox_auteur->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxButton_auteur = new wxButton(n_livre, ID_WXBUTTON_AUTEUR, wxT("..."), wxPoint(598, 20), wxSize(16, 20), 0, wxDefaultValidator, wxT("WxButton_auteur"));
	WxButton_auteur->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_sous_titre = new wxStaticText(n_livre, ID_WXSTATICTEXT8, wxT("sous titre :"), wxPoint(0, 47), wxDefaultSize, 0, wxT("WxStaticText_sous_titre"));
	WxStaticText_sous_titre->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_sous_titre = new wxTextCtrl(n_livre, ID_WXEDIT_SOUS_TITRE, wxT(""), wxPoint(52, 45), wxSize(236, 21), 0, wxDefaultValidator, wxT("WxEdit_sous_titre"));
	WxEdit_sous_titre->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_serie = new wxStaticText(n_livre, ID_WXSTATICTEXT_SERIE, wxT("Série :"), wxPoint(2, 73), wxDefaultSize, 0, wxT("WxStaticText_serie"));
	WxStaticText_serie->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	wxArrayString arrayStringFor_WxComboBox_serie;
	WxComboBox_serie = new wxComboBox(n_livre, ID_WXCOMBOBOX_SERIE, wxT(""), wxPoint(52, 71), wxSize(236, 21), arrayStringFor_WxComboBox_serie, wxCB_SORT, wxDefaultValidator, wxT("WxComboBox_serie"));
	WxComboBox_serie->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxButton_serie = new wxButton(n_livre, ID_WXBUTTON_SERIE, wxT("..."), wxPoint(290, 72), wxSize(15, 19), 0, wxDefaultValidator, wxT("WxButton_serie"));
	WxButton_serie->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_no_serie = new wxStaticText(n_livre, ID_WXSTATICTEXT_NO_SERIE, wxT("N° Serie :"), wxPoint(313, 73), wxDefaultSize, 0, wxT("WxStaticText_no_serie"));
	WxStaticText_no_serie->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_no_serie = new wxTextCtrl(n_livre, ID_WXEDIT_NO_SERIE, wxT(""), wxPoint(364, 71), wxSize(52, 21), 0, wxDefaultValidator, wxT("WxEdit_no_serie"));
	WxEdit_no_serie->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_genre = new wxStaticText(n_livre, ID_WXSTATICTEXT_GENRE, wxT("Genre :"), wxPoint(4, 103), wxDefaultSize, 0, wxT("WxStaticText_genre"));
	WxStaticText_genre->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	wxArrayString arrayStringFor_WxComboBox_genre;
	WxComboBox_genre = new wxComboBox(n_livre, ID_WXCOMBOBOX_GENRE, wxT(""), wxPoint(52, 100), wxSize(236, 21), arrayStringFor_WxComboBox_genre, 0, wxDefaultValidator, wxT("WxComboBox_genre"));
	WxComboBox_genre->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxButton_genre = new wxButton(n_livre, ID_WXBUTTON_GENRE, wxT("..."), wxPoint(290, 101), wxSize(15, 19), 0, wxDefaultValidator, wxT("WxButton_genre"));
	WxButton_genre->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_isbn = new wxStaticText(n_livre, ID_WXSTATICTEXT_ISBN, wxT("I.S.B.N :"), wxPoint(314, 105), wxDefaultSize, 0, wxT("WxStaticText_isbn"));
	WxStaticText_isbn->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_isbn = new wxTextCtrl(n_livre, ID_WXEDIT_ISBN, wxT(""), wxPoint(363, 100), wxSize(121, 21), 0, wxDefaultValidator, wxT("WxEdit_isbn"));
	WxEdit_isbn->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxButton_internet = new wxButton(n_livre, ID_WXBUTTON_INTERNET, wxT("Recherche internet (ISBN)"), wxPoint(489, 101), wxSize(131, 19), 0, wxDefaultValidator, wxT("WxButton_internet"));
	WxButton_internet->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_editeur = new wxStaticText(n_livre, ID_WXSTATICTEXT_EDITEUR, wxT("Editeur :"), wxPoint(3, 132), wxDefaultSize, 0, wxT("WxStaticText_editeur"));
	WxStaticText_editeur->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	wxArrayString arrayStringFor_WxComboBox_editeur;
	WxComboBox_editeur = new wxComboBox(n_livre, ID_WXCOMBOBOX_EDITEUR, wxT(""), wxPoint(52, 129), wxSize(236, 21), arrayStringFor_WxComboBox_editeur, 0, wxDefaultValidator, wxT("WxComboBox_editeur"));
	WxComboBox_editeur->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxButton_editeur = new wxButton(n_livre, ID_WXBUTTON_EDITEUR, wxT("..."), wxPoint(290, 130), wxSize(15, 19), 0, wxDefaultValidator, wxT("WxButton_editeur"));
	WxButton_editeur->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_date_pub = new wxStaticText(n_livre, ID_WXSTATICTEXT_DATE_PUB, wxT("Date de publication :"), wxPoint(316, 132), wxDefaultSize, 0, wxT("WxStaticText_date_pub"));
	WxStaticText_date_pub->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	wxDateTime WxDatePickerCtrl_publication_Date(1,wxDateTime::Mar,2006,15,30,9,783);
	WxDatePickerCtrl_publication = new wxDatePickerCtrl(n_livre, ID_WXDATEPICKERCTRL_PUBLICATION, WxDatePickerCtrl_publication_Date, wxPoint(421, 129), wxSize(123, 21) , wxDP_DROPDOWN | wxDP_ALLOWNONE, wxDefaultValidator, wxT("WxDatePickerCtrl_publication"));
	WxDatePickerCtrl_publication->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_format = new wxStaticText(n_livre, ID_WXSTATICTEXT_FORMAT, wxT("Format :"), wxPoint(2, 162), wxDefaultSize, 0, wxT("WxStaticText_format"));
	WxStaticText_format->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	wxArrayString arrayStringFor_WxComboBox_format;
	WxComboBox_format = new wxComboBox(n_livre, ID_WXCOMBOBOX_FORMAT, wxT(""), wxPoint(52, 158), wxSize(236, 21), arrayStringFor_WxComboBox_format, 0, wxDefaultValidator, wxT("WxComboBox_format"));
	WxComboBox_format->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxButton_format = new wxButton(n_livre, ID_WXBUTTON_FORMAT, wxT("..."), wxPoint(290, 158), wxSize(15, 19), 0, wxDefaultValidator, wxT("WxButton_format"));
	WxButton_format->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_artiste = new wxStaticText(n_livre, ID_WXSTATICTEXT_ARTISTE, wxT("Artiste :"), wxPoint(315, 159), wxDefaultSize, 0, wxT("WxStaticText_artiste"));
	WxStaticText_artiste->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	wxArrayString arrayStringFor_WxComboBox_artiste;
	WxComboBox_artiste = new wxComboBox(n_livre, ID_WXCOMBOBOX_ARTISTE, wxT(""), wxPoint(357, 157), wxSize(238, 21), arrayStringFor_WxComboBox_artiste, 0, wxDefaultValidator, wxT("WxComboBox_artiste"));
	WxComboBox_artiste->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxButton_artiste = new wxButton(n_livre, ID_WXBUTTON_ARTISTE, wxT("..."), wxPoint(597, 157), wxSize(15, 19), 0, wxDefaultValidator, wxT("WxButton_artiste"));
	WxButton_artiste->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_prix = new wxStaticText(n_livre, ID_WXSTATICTEXT_PRIX, wxT("Prix :"), wxPoint(4, 188), wxDefaultSize, 0, wxT("WxStaticText_prix"));
	WxStaticText_prix->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_prix = new wxTextCtrl(n_livre, ID_WXEDIT_PRIX, wxT(""), wxPoint(52, 187), wxSize(106, 21), 0, wxDefaultValidator, wxT("WxEdit_prix"));
	WxEdit_prix->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_recompense = new wxTextCtrl(n_livre, ID_WXEDIT_RECOMPENSE, wxT(""), wxPoint(357, 185), wxSize(236, 21), 0, wxDefaultValidator, wxT("WxEdit_recompense"));
	WxEdit_recompense->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_recompense = new wxStaticText(n_livre, ID_WXSTATICTEXT_RECOMPENSE, wxT("Recompense :"), wxPoint(281, 186), wxDefaultSize, 0, wxT("WxStaticText_recompense"));
	WxStaticText_recompense->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_date_entree = new wxStaticText(n_livre, ID_WXSTATICTEXT_DATE_ENTREE, wxT("Date entree :"), wxPoint(9, 326), wxDefaultSize, 0, wxT("WxStaticText_date_entree"));
	WxStaticText_date_entree->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticTextdate_entree_val = new wxStaticText(n_livre, ID_WXSTATICTEXTDATE_ENTREE_VAL, wxT("01/01/1980"), wxPoint(74, 326), wxDefaultSize, 0, wxT("WxStaticTextdate_entree_val"));
	WxStaticTextdate_entree_val->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_date_maj = new wxStaticText(n_livre, ID_WXSTATICTEXT_DATE_MAJ, wxT("Date de dernière mise à jour :"), wxPoint(246, 324), wxDefaultSize, 0, wxT("WxStaticText_date_maj"));
	WxStaticText_date_maj->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_date_maj_val = new wxStaticText(n_livre, ID_WXSTATICTEXT_DATE_MAJ_VAL, wxT("01/01/1980"), wxPoint(387, 324), wxDefaultSize, 0, wxT("WxStaticText_date_maj_val"));
	WxStaticText_date_maj_val->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxCheckBox_publication = new wxCheckBox(n_livre, ID_WXCHECKBOX_PUBLICATION, wxT("conserver"), wxPoint(547, 131), wxSize(73, 17), 0, wxDefaultValidator, wxT("WxCheckBox_publication"));
	WxCheckBox_publication->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	n_detail = new wxPanel(WxNotebook_nouv, ID_N_DETAIL, wxPoint(4, 24), wxSize(629, 353));
	n_detail->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));
	WxNotebook_nouv->AddPage(n_detail, wxT("Détails"));

	WxStaticText_date_achat = new wxStaticText(n_detail, ID_WXSTATICTEXT_DATE_ACHAT, wxT("Date d'achat :"), wxPoint(2, 18), wxDefaultSize, 0, wxT("WxStaticText_date_achat"));
	WxStaticText_date_achat->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	wxDateTime WxDatePickerCtrl_achat_Date(3,wxDateTime::Mar,2006,9,42,43,852);
	WxDatePickerCtrl_achat = new wxDatePickerCtrl(n_detail, ID_WXDATEPICKERCTRL_ACHAT, WxDatePickerCtrl_achat_Date, wxPoint(79, 14), wxSize(148, 21) , wxDP_DROPDOWN | wxDP_ALLOWNONE, wxDefaultValidator, wxT("WxDatePickerCtrl_achat"));
	WxDatePickerCtrl_achat->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_valeur = new wxStaticText(n_detail, ID_WXSTATICTEXT_VALEUR, wxT("Valeur :"), wxPoint(28, 42), wxDefaultSize, 0, wxT("WxStaticText_valeur"));
	WxStaticText_valeur->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_valeur = new wxTextCtrl(n_detail, ID_WXEDIT_VALEUR, wxT(""), wxPoint(80, 39), wxSize(236, 21), 0, wxDefaultValidator, wxT("WxEdit_valeur"));
	WxEdit_valeur->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_note = new wxStaticText(n_detail, ID_WXSTATICTEXT_NOTE, wxT("Note :"), wxPoint(337, 20), wxDefaultSize, 0, wxT("WxStaticText_note"));
	WxStaticText_note->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxSlider_note = new wxSlider(n_detail, ID_WXSLIDER_NOTE, 0, 0, 10, wxPoint(396, 14), wxSize(150, 30), wxSL_HORIZONTAL | wxSL_SELRANGE , wxDefaultValidator, wxT("WxSlider_note"));
	WxSlider_note->SetToolTip(wxT("Note du livre (0 à 10)"));
	WxSlider_note->SetRange(0,10);
	WxSlider_note->SetValue(0);
	WxSlider_note->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_val_note = new wxStaticText(n_detail, ID_WXSTATICTEXT_VAL_NOTE, wxT("0"), wxPoint(550, 18), wxDefaultSize, 0, wxT("WxStaticText_val_note"));
	WxStaticText_val_note->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_nul = new wxStaticText(n_detail, ID_WXSTATICTEXT_NUL, wxT("Nul"), wxPoint(395, 48), wxDefaultSize, 0, wxT("WxStaticText_nul"));
	WxStaticText_nul->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_genial = new wxStaticText(n_detail, ID_WXSTATICTEXT_GENIAL, wxT("Génial"), wxPoint(521, 48), wxDefaultSize, 0, wxT("WxStaticText_genial"));
	WxStaticText_genial->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_reference = new wxStaticText(n_detail, ID_WXSTATICTEXT_REFERENCE, wxT("Reference :"), wxPoint(8, 65), wxDefaultSize, 0, wxT("WxStaticText_reference"));
	WxStaticText_reference->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_reference = new wxTextCtrl(n_detail, ID_WXEDIT_REFERENCE, wxT(""), wxPoint(80, 65), wxSize(236, 21), 0, wxDefaultValidator, wxT("WxEdit_reference"));
	WxEdit_reference->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_nb_pages = new wxStaticText(n_detail, ID_WXSTATICTEXT_NB_PAGES, wxT("Nb de pages :"), wxPoint(1, 94), wxDefaultSize, 0, wxT("WxStaticText_nb_pages"));
	WxStaticText_nb_pages->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_nb_pages = new wxTextCtrl(n_detail, ID_WXEDIT_NB_PAGES, wxT(""), wxPoint(80, 90), wxSize(90, 21), 0, wxDefaultValidator, wxT("WxEdit_nb_pages"));
	WxEdit_nb_pages->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_etat = new wxStaticText(n_detail, ID_WXSTATICTEXT_ETAT, wxT("Etat :"), wxPoint(38, 118), wxDefaultSize, 0, wxT("WxStaticText_etat"));
	WxStaticText_etat->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	wxArrayString arrayStringFor_WxComboBox_etat;
	WxComboBox_etat = new wxComboBox(n_detail, ID_WXCOMBOBOX_ETAT, wxT(""), wxPoint(80, 117), wxSize(236, 21), arrayStringFor_WxComboBox_etat, 0, wxDefaultValidator, wxT("WxComboBox_etat"));
	WxComboBox_etat->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxButton_etat = new wxButton(n_detail, ID_WXBUTTON_ETAT, wxT("..."), wxPoint(318, 117), wxSize(15, 19), 0, wxDefaultValidator, wxT("WxButton_etat"));
	WxButton_etat->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_condition = new wxStaticText(n_detail, ID_WXSTATICTEXT_CONDITION, wxT("Localisation :"), wxPoint(13, 144), wxDefaultSize, 0, wxT("WxStaticText_condition"));
	WxStaticText_condition->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	wxArrayString arrayStringFor_WxComboBox_localisation;
	WxComboBox_localisation = new wxComboBox(n_detail, ID_WXCOMBOBOX_LOCALISATION, wxT(""), wxPoint(80, 142), wxSize(236, 21), arrayStringFor_WxComboBox_localisation, 0, wxDefaultValidator, wxT("WxComboBox_localisation"));
	WxComboBox_localisation->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxButton_localisation = new wxButton(n_detail, ID_WXBUTTON_LOCALISATION, wxT("..."), wxPoint(318, 142), wxSize(15, 19), 0, wxDefaultValidator, wxT("WxButton_localisation"));
	WxButton_localisation->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_date_lecture = new wxStaticText(n_detail, ID_WXSTATICTEXT_DATE_LECTURE, wxT("Date de lecture :"), wxPoint(-1, 171), wxDefaultSize, 0, wxT("WxStaticText_date_lecture"));
	WxStaticText_date_lecture->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	wxDateTime WxDatePickerCtrl_lecture_Date(3,wxDateTime::Mar,2006,9,44,33,303);
	WxDatePickerCtrl_lecture = new wxDatePickerCtrl(n_detail, ID_WXDATEPICKERCTRL_LECTURE, WxDatePickerCtrl_lecture_Date, wxPoint(80, 169), wxSize(148, 21) , wxDP_DROPDOWN | wxDP_ALLOWNONE, wxDefaultValidator, wxT("WxDatePickerCtrl_lecture"));
	WxDatePickerCtrl_lecture->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxCheckBox_achat = new wxCheckBox(n_detail, ID_WXCHECKBOX_ACHAT, wxT("conserver"), wxPoint(232, 16), wxSize(97, 17), 0, wxDefaultValidator, wxT("WxCheckBox_achat"));
	WxCheckBox_achat->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxCheckBox_lecture = new wxCheckBox(n_detail, ID_WXCHECKBOX_LECTURE, wxT("conserver"), wxPoint(233, 172), wxSize(97, 17), 0, wxDefaultValidator, wxT("WxCheckBox_lecture"));
	WxCheckBox_lecture->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxCheckBox_note = new wxCheckBox(n_detail, ID_WXCHECKBOX_Note, wxT("conserver"), wxPoint(560, 31), wxSize(74, 17), 0, wxDefaultValidator, wxT("WxCheckBox_note"));
	WxCheckBox_note->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxCheckBox_particularite = new wxCheckBox(n_detail, ID_WXCHECKBOX_PARTICULARITE, wxT("conserver"), wxPoint(560, 108), wxSize(97, 17), 0, wxDefaultValidator, wxT("WxCheckBox_particularite"));
	WxCheckBox_particularite->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	n_vo = new wxPanel(WxNotebook_nouv, ID_N_VO, wxPoint(4, 24), wxSize(629, 353));
	n_vo->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));
	WxNotebook_nouv->AddPage(n_vo, wxT("Version originale"));

	WxStaticText_titre_o = new wxStaticText(n_vo, ID_WXSTATICTEXT_TITRE_O, wxT("Titre original :"), wxPoint(23, 33), wxDefaultSize, 0, wxT("WxStaticText_titre_o"));
	WxStaticText_titre_o->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_titre_o = new wxTextCtrl(n_vo, ID_WXEDIT_TITRE_O, wxT(""), wxPoint(95, 28), wxSize(238, 21), 0, wxDefaultValidator, wxT("WxEdit_titre_o"));
	WxEdit_titre_o->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_sous_titre_o = new wxStaticText(n_vo, ID_WXSTATICTEXT_SOUS_TITRE_O, wxT("Sous titre original :"), wxPoint(5, 60), wxDefaultSize, 0, wxT("WxStaticText_sous_titre_o"));
	WxStaticText_sous_titre_o->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_sous_titre_o = new wxTextCtrl(n_vo, ID_WXEDIT_SOUS_TITRE_O, wxT(""), wxPoint(95, 55), wxSize(238, 21), 0, wxDefaultValidator, wxT("WxEdit_sous_titre_o"));
	WxEdit_sous_titre_o->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_serie_o = new wxStaticText(n_vo, ID_WXSTATICTEXT_SERIE_O, wxT("serie originale :"), wxPoint(6, 84), wxDefaultSize, 0, wxT("WxStaticText_serie_o"));
	WxStaticText_serie_o->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	wxArrayString arrayStringFor_WxComboBox_serie_o;
	WxComboBox_serie_o = new wxComboBox(n_vo, ID_WXCOMBOBOX_SERIE_O, wxT(""), wxPoint(95, 80), wxSize(238, 21), arrayStringFor_WxComboBox_serie_o, 0, wxDefaultValidator, wxT("WxComboBox_serie_o"));
	WxComboBox_serie_o->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxButton_serie_o = new wxButton(n_vo, ID_WXBUTTON_SERIE_O, wxT("..."), wxPoint(335, 80), wxSize(15, 19), 0, wxDefaultValidator, wxT("WxButton_serie_o"));
	WxButton_serie_o->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_pays = new wxStaticText(n_vo, ID_WXSTATICTEXT_PAYS, wxT("Pays d'origine :"), wxPoint(9, 108), wxDefaultSize, 0, wxT("WxStaticText_pays"));
	WxStaticText_pays->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	wxArrayString arrayStringFor_WxComboBox_pays;
	WxComboBox_pays = new wxComboBox(n_vo, ID_WXCOMBOBOX_PAYS, wxT(""), wxPoint(95, 106), wxSize(238, 21), arrayStringFor_WxComboBox_pays, 0, wxDefaultValidator, wxT("WxComboBox_pays"));
	WxComboBox_pays->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxButton_pays = new wxButton(n_vo, ID_WXBUTTON_PAYS, wxT("..."), wxPoint(335, 107), wxSize(15, 19), 0, wxDefaultValidator, wxT("WxButton_pays"));
	WxButton_pays->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_langue = new wxStaticText(n_vo, ID_WXSTATICTEXT_LANGUE_O, wxT("Langue d'origine :"), wxPoint(0, 136), wxDefaultSize, 0, wxT("WxStaticText_langue"));
	WxStaticText_langue->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	wxArrayString arrayStringFor_WxComboBox_langue;
	WxComboBox_langue = new wxComboBox(n_vo, ID_WXCOMBOBOX_LANGUE, wxT(""), wxPoint(95, 133), wxSize(238, 21), arrayStringFor_WxComboBox_langue, 0, wxDefaultValidator, wxT("WxComboBox_langue"));
	WxComboBox_langue->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxButton_langue = new wxButton(n_vo, ID_WXBUTTON_LANGUE, wxT("..."), wxPoint(335, 133), wxSize(15, 19), 0, wxDefaultValidator, wxT("WxButton_langue"));
	WxButton_langue->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_traducteur = new wxStaticText(n_vo, ID_WXSTATICTEXT_TRADUCTEUR, wxT("Traducteur :"), wxPoint(22, 160), wxDefaultSize, 0, wxT("WxStaticText_traducteur"));
	WxStaticText_traducteur->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	wxArrayString arrayStringFor_WxComboBox_traducteur;
	WxComboBox_traducteur = new wxComboBox(n_vo, ID_WXCOMBOBOX_TRADUCTEUR, wxT(""), wxPoint(95, 157), wxSize(238, 21), arrayStringFor_WxComboBox_traducteur, 0, wxDefaultValidator, wxT("WxComboBox_traducteur"));
	WxComboBox_traducteur->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxButton_traducteur = new wxButton(n_vo, ID_WXBUTTON_TRADUCTEUR, wxT("..."), wxPoint(335, 158), wxSize(15, 19), 0, wxDefaultValidator, wxT("WxButton_traducteur"));
	WxButton_traducteur->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	n_resume = new wxPanel(WxNotebook_nouv, ID_N_RESUME, wxPoint(4, 24), wxSize(629, 353));
	n_resume->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));
	WxNotebook_nouv->AddPage(n_resume, wxT("resumé"));

	WxStaticText_commentaire = new wxStaticText(n_resume, ID_WXSTATICTEXT_COMMENTAIRE, wxT("Commentaire :"), wxPoint(3, -2), wxDefaultSize, 0, wxT("WxStaticText_commentaire"));
	WxStaticText_commentaire->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxMemo_commentaire = new wxTextCtrl(n_resume, ID_WXMEMO_COMMENTAIRE, wxEmptyString, wxPoint(0, 15), wxSize(629, 159), wxTE_MULTILINE, wxDefaultValidator, wxT("WxMemo_commentaire"));
	WxMemo_commentaire->SetMaxLength(0);
	WxMemo_commentaire->SetFocus();
	WxMemo_commentaire->SetInsertionPointEnd();
	WxMemo_commentaire->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_resume = new wxStaticText(n_resume, ID_WXSTATICTEXT_RESUME, wxT("Résumé :"), wxPoint(3, 175), wxDefaultSize, 0, wxT("WxStaticText_resume"));
	WxStaticText_resume->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxMemo_resume = new wxTextCtrl(n_resume, ID_WXMEMO_RESUME, wxEmptyString, wxPoint(0, 192), wxSize(629, 161), wxTE_MULTILINE, wxDefaultValidator, wxT("WxMemo_resume"));
	WxMemo_resume->SetMaxLength(0);
	WxMemo_resume->SetFocus();
	WxMemo_resume->SetInsertionPointEnd();
	WxMemo_resume->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	n_image_face = new wxPanel(WxNotebook_nouv, ID_N_IMAGE_FACE, wxPoint(4, 24), wxSize(629, 353));
	n_image_face->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));
	WxNotebook_nouv->AddPage(n_image_face, wxT("image face"));

	wxBitmap WxBitmapButton_face_ouvrir_BITMAP (Nouv_livre_WxBitmapButton_face_ouvrir_XPM);
	WxBitmapButton_face_ouvrir = new wxBitmapButton(n_image_face, ID_WXBITMAPBUTTON_IMAGE_OUVRIR, WxBitmapButton_face_ouvrir_BITMAP, wxPoint(605, 0), wxSize(20, 20), wxBU_AUTODRAW, wxDefaultValidator, wxT("WxBitmapButton_face_ouvrir"));
	WxBitmapButton_face_ouvrir->SetToolTip(wxT("charger une image"));
	WxBitmapButton_face_ouvrir->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	wxBitmap WxBitmapButton_supp_image_face_BITMAP (Nouv_livre_WxBitmapButton_supp_image_face_XPM);
	WxBitmapButton_supp_image_face = new wxBitmapButton(n_image_face, ID_WXBITMAPBUTTON_SUP_IMAGE, WxBitmapButton_supp_image_face_BITMAP, wxPoint(605, 22), wxSize(20, 20), wxBU_AUTODRAW, wxDefaultValidator, wxT("WxBitmapButton_supp_image_face"));
	WxBitmapButton_supp_image_face->SetToolTip(wxT("Supprimer l'image"));
	WxBitmapButton_supp_image_face->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	n_image_dos = new wxPanel(WxNotebook_nouv, ID_WXNOTEBOOKPAGE1, wxPoint(4, 24), wxSize(629, 353));
	n_image_dos->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));
	WxNotebook_nouv->AddPage(n_image_dos, wxT("image dos"));

	n_image_divers = new wxPanel(WxNotebook_nouv, ID_N_IMAGE_DIVERS, wxPoint(4, 24), wxSize(629, 353));
	n_image_divers->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));
	WxNotebook_nouv->AddPage(n_image_divers, wxT("image divers"));

	SetTitle(wxT("Nouveau livre"));
	SetIcon(wxNullIcon);
	SetSize(8,8,664,455);
	Center();
	
    ////GUI Items Creation End
    // initialisation des dates  
    WxDatePickerCtrl_publication->SetValue(wxDateTime::Now());
    WxDatePickerCtrl_achat->SetValue(wxDateTime::Now());
    WxDatePickerCtrl_lecture->SetValue(wxDateTime::Now());
    // boutons identiques sur les 3 panels 
	WxBitmapButton_dos_ouvrir =  new wxBitmapButton(n_image_dos, ID_WXBITMAPBUTTON_IMAGE_OUVRIR, WxBitmapButton_face_ouvrir_BITMAP, wxPoint(605,0),wxSize(20,20) );
	WxBitmapButton_dos_ouvrir->SetToolTip(wxT(_("charger une image")));

	WxBitmapButton_supp_image_dos =  new wxBitmapButton(n_image_dos, ID_WXBITMAPBUTTON_SUP_IMAGE, WxBitmapButton_supp_image_face_BITMAP, wxPoint(605,22),wxSize(20,20) );
	WxBitmapButton_supp_image_dos->SetToolTip(wxT(_("Supprimer l'image")));

	WxBitmapButton_divers_ouvrir =  new wxBitmapButton(n_image_divers, ID_WXBITMAPBUTTON_IMAGE_OUVRIR, WxBitmapButton_face_ouvrir_BITMAP, wxPoint(605,0),wxSize(20,20) );
	WxBitmapButton_divers_ouvrir->SetToolTip(wxT(_("charger une image")));

	WxBitmapButton_supp_image_divers =  new wxBitmapButton(n_image_divers, ID_WXBITMAPBUTTON_SUP_IMAGE, WxBitmapButton_supp_image_face_BITMAP, wxPoint(605,22),wxSize(20,20) );
	WxBitmapButton_supp_image_divers->SetToolTip(wxT(_("Supprimer l'image")));

    
    n_image_face->GetSize(&largeur_obj,&hauteur_obj);
    canvas_image_face = new ImageCanvas(n_image_face, ID_IMAGECANVAS_IMAGE_FACE, wxPoint(0,0),wxSize(largeur_obj-50,hauteur_obj) );
    canvas_image_dos = new ImageCanvas(n_image_dos, ID_IMAGECANVAS_IMAGE_DOS, wxPoint(0,0),wxSize(largeur_obj-50,hauteur_obj) );
    canvas_image_divers = new ImageCanvas(n_image_divers, ID_IMAGECANVAS_IMAGE_DIVERS, wxPoint(0,0),wxSize(largeur_obj-50,hauteur_obj) );
    //intitialisation de la note
    WxSlider_note->SetValue(5);
    WxStaticText_val_note->SetLabel(_("5"));
    // gestion des images des notes
    WxStaticText_nul->GetPosition(&x, &y);
    x+=30; 
    //canvas_note1 = new ImageCanvas(n_detail, ID_IMAGECANVAS_STAR1, wxPoint(x,y-5),wxSize(15,15) );
    wxString texte;
    for (i=0;i<6;i++) {
        texte.Printf("star:%d",i);
        canvas_note[i] = new ImageCanvas(n_detail, ID_IMAGECANVAS_STAR1+i, wxPoint(x,y-5),wxSize(15,15) );
/*        if (i<2) 
            canvas_note[i]->init(star2_XPM);
        if (i==2)
            canvas_note[i]->init(star1_XPM);*/
        x+=16;
    }    
    init_etoiles();
    //canvas_note[0]->init(star2_XPM);
    // cretion de la radio_box
    create_radiobox();
    // initialisation des combobox
    init_combo(WxComboBox_auteur, "auteur");
    init_combo(WxComboBox_serie, "serie");
    init_combo(WxComboBox_genre, "genre");
    init_combo(WxComboBox_editeur, "editeur");
    init_combo(WxComboBox_format, "format");
    init_combo(WxComboBox_artiste, "artiste");
    init_combo(WxComboBox_etat, "etat");
    init_combo(WxComboBox_localisation, "localisation");
    init_combo(WxComboBox_serie_o, "serie_o");
    init_combo(WxComboBox_pays, "pays");
    init_combo(WxComboBox_langue, "langue");
    init_combo(WxComboBox_traducteur, "traducteur");
    SetFocus();
}

void Nouv_livre::create_radiobox()
{ 
    int count;
    wxString *items = new wxString[PARTICULARITE_NB];
    
    for (count=0;count<PARTICULARITE_NB;count++) {
        items[count] = monlivre.get_label_particularite(count);
    }    
    count=PARTICULARITE_NB; 
   	wxRadioBox_particularite =  new wxRadioBox(n_detail, ID_WXRADIOBOX_PARTICULARITE, _("Particularité") , wxPoint(360,70),wxSize(200,(21+count*21)), count,items,1, wxRA_SPECIFY_COLS );
   	delete [] items;
}
void Nouv_livre::Nouv_livreClose(wxCloseEvent& event)
{
    //int i;
    // --> Don't use Close with a wxDialog,
    // use Destroy instead.
    /*for (i=0;i<5;i++) 
        delete canvas_note[i];*/
        
    Destroy();
}
 
/*
 * WxButton_nouv_okClick
 */
void Nouv_livre::WxButton_nouv_okClick(wxCommandEvent& event)
{
    int ret;
    long num;
    wxString mess;
    
    ret=inserer_livre();
    if (ret>=0) {
        if (id_courant!="-1") {
            id_courant.ToLong(&num);
            SetReturnCode((int) num);
            EndModal((int) num);
        } else {    
            EndModal(1);
        //wxMessageBox("rhha","probleme", wxOK | wxICON_INFORMATION, this);
        }    
        
        wxLogMessage("Nouv_livre::WxButton_nouv_okClick() - avant Destroy()");
        Destroy();
        wxLogMessage("Nouv_livre::WxButton_nouv_okClick() - après Destroy()");
    }
    // insert your code here
    event.Skip();

}

/*
 * WxButton_nouv_annulClick
 */
void Nouv_livre::WxButton_nouv_annulClick(wxCommandEvent& event)
{
    //wxMessageBox("rhha","probleme", wxOK | wxICON_INFORMATION, this);
    SetReturnCode(0);
    EndModal(0);
    Destroy();
	// insert your code here
	//event.Skip();
}

int Nouv_livre::inserer_livre() {
    wxString query;
    wxString nom_champs;
    wxString valeur_champs;
    wxString mess;
    wxString tempo;
    wxOutputStream mystream;
    wxFile monfichier;
    int ret;
    bool tt;
   
   
    if (WxEdit_titre->GetValue().Length() == 0 || WxComboBox_auteur->GetValue().Length() == 0) {
        wxMessageBox("Le titre et l'auteur du livre sont obligatoires","probleme", wxOK | wxICON_INFORMATION, this);
        return -1;
    }    

    //insertion des données dans les tables annexes
    insere_table_annexe(WxComboBox_auteur, "auteur");
    insere_table_annexe(WxComboBox_serie, "serie", "séries");
    insere_table_annexe(WxComboBox_genre, "genre");
    insere_table_annexe(WxComboBox_editeur, "editeur", "éditeurs");
    insere_table_annexe(WxComboBox_format, "format");
    insere_table_annexe(WxComboBox_artiste, "artiste");
    insere_table_annexe(WxComboBox_etat, "etat", "états");
    insere_table_annexe(WxComboBox_localisation, "localisation");
    insere_table_annexe(WxComboBox_serie_o, "serie_o", "séries originales");
    insere_table_annexe(WxComboBox_pays, "pays", "pays");
    insere_table_annexe(WxComboBox_langue, "langue");
    insere_table_annexe(WxComboBox_traducteur, "traducteur");

    ajoute_champ(nom_champs, valeur_champs, "titre", WxEdit_titre->GetValue());
    ajoute_champ(nom_champs, valeur_champs, "id_auteur", WxComboBox_auteur->GetValue());
    ajoute_champ(nom_champs, valeur_champs, "sous_titre", WxEdit_sous_titre->GetValue());
    ajoute_champ(nom_champs, valeur_champs, "id_serie", WxComboBox_serie->GetValue());
    ajoute_champ(nom_champs, valeur_champs, "no_serie", WxEdit_no_serie->GetValue());
    ajoute_champ(nom_champs, valeur_champs, "id_genre", WxComboBox_genre->GetValue());
    ajoute_champ(nom_champs, valeur_champs, "isbn", WxEdit_isbn->GetValue());
    ajoute_champ(nom_champs, valeur_champs, "id_editeur", WxComboBox_editeur->GetValue());
    //ajoute_champ(nom_champs, valeur_champs, "date_publication", WxEdit_date_pub->GetValue());
    if (WxDatePickerCtrl_publication->GetValue().IsValid() == true) {
        ajoute_champ(nom_champs, valeur_champs, "date_publication", WxDatePickerCtrl_publication->GetValue().Format("%d/%m/%Y"), WxCheckBox_publication);
    } else {
        ajoute_champ(nom_champs, valeur_champs, "date_publication", "", WxCheckBox_publication);
    }
    ajoute_champ(nom_champs, valeur_champs, "id_format", WxComboBox_format->GetValue());
    ajoute_champ(nom_champs, valeur_champs, "id_artiste", WxComboBox_artiste->GetValue());
    ajoute_champ(nom_champs, valeur_champs, "prix", WxEdit_prix->GetValue());
    ajoute_champ(nom_champs, valeur_champs, "recompense", WxEdit_recompense->GetValue());
    
    //ajoute_champ(nom_champs, valeur_champs, "date_achat", WxEdit_date_achat->GetValue());
    if (WxDatePickerCtrl_achat->GetValue().IsValid() == true) {
        ajoute_champ(nom_champs, valeur_champs, "date_achat", WxDatePickerCtrl_achat->GetValue().Format("%d/%m/%Y"), WxCheckBox_achat);
    } else {
        ajoute_champ(nom_champs, valeur_champs, "date_achat", "", WxCheckBox_achat);
    }
    ajoute_champ(nom_champs, valeur_champs, "valeur", WxEdit_valeur->GetValue());
    ajoute_champ(nom_champs, valeur_champs, "reference", WxEdit_reference->GetValue());
    ajoute_champ(nom_champs, valeur_champs, "nb_pages", WxEdit_nb_pages->GetValue());
    ajoute_champ(nom_champs, valeur_champs, "id_etat", WxComboBox_etat->GetValue());
    ajoute_champ(nom_champs, valeur_champs, "id_localisation", WxComboBox_localisation->GetValue());
    //ajoute_champ(nom_champs, valeur_champs, "date_lecture", WxEdit_date_lecture->GetValue());
    if (WxDatePickerCtrl_lecture->GetValue().IsValid() == true) {
        ajoute_champ(nom_champs, valeur_champs, "date_lecture", WxDatePickerCtrl_lecture->GetValue().Format("%d/%m/%Y"), WxCheckBox_lecture);
    } else {
        ajoute_champ(nom_champs, valeur_champs, "date_lecture", "", WxCheckBox_lecture);
    }
    tempo.Printf("%d",WxSlider_note->GetValue());
    ajoute_champ(nom_champs, valeur_champs, "note", tempo, WxCheckBox_note);
    tempo.Printf("%d",wxRadioBox_particularite->GetSelection());
    ajoute_champ(nom_champs, valeur_champs, "particularite", tempo, WxCheckBox_particularite);

    
    ajoute_champ(nom_champs, valeur_champs, "titre_original", WxEdit_titre_o->GetValue());
    ajoute_champ(nom_champs, valeur_champs, "sous_titre_o", WxEdit_sous_titre_o->GetValue());
    ajoute_champ(nom_champs, valeur_champs, "id_serie_o", WxComboBox_serie_o->GetValue());
    ajoute_champ(nom_champs, valeur_champs, "id_pays", WxComboBox_pays->GetValue());
    ajoute_champ(nom_champs, valeur_champs, "id_langue", WxComboBox_langue->GetValue());
    ajoute_champ(nom_champs, valeur_champs, "id_traducteur", WxComboBox_traducteur->GetValue());
    
    ajoute_champ(nom_champs, valeur_champs, "commentaire", WxMemo_commentaire->GetValue());
    ajoute_champ(nom_champs, valeur_champs, "resume", WxMemo_resume->GetValue());

    wxDateTime madate = wxDateTime::Today();
    if (insertion == true)
        ajoute_champ(nom_champs, valeur_champs, "date_entree", madate.Format("%d/%m/%Y"));
    ajoute_champ(nom_champs, valeur_champs, "date_maj", madate.Format("%d/%m/%Y"));

/*        ajoute_image(nom_champs, valeur_champs, "image_face", image_face_charge);
    ajoute_image(nom_champs, valeur_champs, "image_dos", image_dos_charge);
    ajoute_image(nom_champs, valeur_champs, "image_tranche", image_divers_charge);*/
    if (m_listeIdRequete == "") { 
        ajoute_image(nom_champs, valeur_champs, "image_face", canvas_image_face->charge);
        ajoute_image(nom_champs, valeur_champs, "image_dos", canvas_image_dos->charge);
        ajoute_image(nom_champs, valeur_champs, "image_tranche", canvas_image_divers->charge);
    }
    nom_champs.Truncate(nom_champs.Length()-2);
    
  // wxMessageBox(nom_champs,"nom_champs", wxOK | wxICON_EXCLAMATION, this);            
    if (insertion == true) {
        valeur_champs.Truncate(valeur_champs.Length()-2);
        query="INSERT into livre (" + nom_champs + ") VALUES (" + valeur_champs + ")";
    } else {
        query="UPDATE livre SET " + nom_champs;
        if (m_listeIdRequete == "")
            query += " WHERE rowid=" +id_courant;
        else
            query += " WHERE rowid IN " + m_listeIdRequete;
    }    
    // wxMessageBox(query,"query", wxOK | wxICON_EXCLAMATION, this);

    ret=la_belle->transac_prepare(query);
    if (ret<0) {
        la_belle->get_erreur(mess);
        wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        return -1;
    }


    if (m_listeIdRequete == "") {  // la gestion des images est inutile si on est en modification groupée d'un ensemble de livres
        int n_blob=0;
        if (canvas_image_face->charge == true) {
            wxString chemin=gettempdir();
            chemin+="\\0.jpg";
            canvas_image_face->image_s.SaveFile(chemin,wxBITMAP_TYPE_JPEG);
            tt=monfichier.Open(chemin, wxFile::read);
            if (tt == false) {
                mess="Probleme lors de la lecture de " + chemin + "impossible de sauver dans la base";
                wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
                return -1;
            }    
           
            n_blob++;
            ret=la_belle->transac_blob(n_blob,&monfichier);
            if (ret<0) {
                la_belle->get_erreur(mess);
                wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
                return -1;
            }
            monfichier.Close();
            //wxMessageBox(query,"probleme", wxOK | wxICON_EXCLAMATION, this);
        }    
        if (canvas_image_dos->charge == true) {
            wxString chemin=gettempdir();
            chemin+="\\0.jpg";
            canvas_image_dos->image_s.SaveFile(chemin,wxBITMAP_TYPE_JPEG);
            tt=monfichier.Open(chemin, wxFile::read);
            if (tt == false) {
                mess="Probleme lors de la lecture de " + chemin + "impossible de sauver dans la base";
                wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
                return -1;
            }    
           
            n_blob++;
            ret=la_belle->transac_blob(n_blob,&monfichier);
            if (ret<0) {
                la_belle->get_erreur(mess);
                wxMessageBox(mess,"probleme image dos", wxOK | wxICON_EXCLAMATION, this);
                return -1;
            }
            monfichier.Close();
            //wxMessageBox(query,"probleme", wxOK | wxICON_EXCLAMATION, this);
        }    
        if (canvas_image_divers->charge == true) {
            wxString chemin=gettempdir();
            chemin+="\\0.jpg";
            canvas_image_divers->image_s.SaveFile(chemin,wxBITMAP_TYPE_JPEG);
            tt=monfichier.Open(chemin, wxFile::read);
            if (tt == false) {
                mess="Probleme lors de la lecture de " + chemin + "impossible de sauver dans la base";
                wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
                return -1;
            }    
           
            n_blob++;
            ret=la_belle->transac_blob(n_blob,&monfichier);
            if (ret<0) {
                la_belle->get_erreur(mess);
                wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
                return -1;
            }
            monfichier.Close();
            //wxMessageBox(query,"probleme", wxOK | wxICON_EXCLAMATION, this);
        }    
    }
        ret=la_belle->transac_step();
        if (ret<0) {
            la_belle->get_erreur(mess);
            wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
            return -1;
        }
        ret=la_belle->transac_fin();
        if (ret<0) {
            la_belle->get_erreur(mess);
            wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
            return -1;
        }
    
    /*** fin de 'a rectiver' ***/
    
    /*ret=la_belle->exec_rapide(query);
    if (ret<0) {
        la_belle->get_erreur(mess);
        wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        return -1;
    }*/

    return 0;
}


//ajouter les champ pour le select dans nom et valeur si la donnée n'est pas vide
void Nouv_livre::ajoute_champ(wxString &liste_champ, wxString &liste_valeur, wxString n_champ, wxString v_champ, wxCheckBox* ckConserver)
{
    wxString tempo;
    // on supprime les blancs à droite et à gauche
    /*v_champ.Trim(true);
    v_champ.Trim(false);*/
 
    // si le champ est marqué "ne pas modifier", on sort sans rien modifier
    if (v_champ == str_nePasModifier)
        return;
    if (ckConserver != NULL) {
        if (ckConserver->GetValue() == true)
            return;
    }
 
    
    //wxMessageBox(v_champ,"probleme", wxOK | wxICON_EXCLAMATION, this);
    gestion_quote(v_champ);
    //if (v_champ.Length() == 0) {
    //    return;
    //}
    if(insertion ==false) {
        liste_champ+=n_champ + "='" + v_champ + "', ";
    } else {
        tempo=n_champ+", ";
        liste_champ+=tempo;
        tempo="'"+v_champ+"', ";
        liste_valeur+=tempo;
    }    
}

//ajouter les champ pour le select dans nom et valeur si la donnée n'est pas vide
void Nouv_livre::ajoute_image(wxString &liste_champ, wxString &liste_valeur, wxString n_champ, bool charge)
{
    wxString tempo;
    // on supprime les blancs à droite et à gauche

    if (charge == false) {
        if(insertion ==false) {
            liste_champ+=n_champ + "='', ";
        } else {
            tempo=n_champ+", ";
            liste_champ+=tempo;
            tempo="'', ";
            liste_valeur+=tempo;
        }
    } else {
        if(insertion ==false) {
            liste_champ+=n_champ + "=?, ";
        } else {
            tempo=n_champ+", ";
            liste_champ+=tempo;
            tempo="?, ";
            liste_valeur+=tempo;   
        }         
    }    
}

// insere la donnée dans la table si besoin est et met l'id dans la combobox
// ne pas insérer la valeur spéciale "<< ne pas modifier >>"
int Nouv_livre::insere_table_annexe(wxComboBox *donnee, wxString nom_table, wxString libelleGroupePluriel)
{
    wxString query;
    wxString resultat;
    wxString valeur;
    wxString mess;
    
    valeur=donnee->GetValue();

    if (valeur == str_nePasModifier)
        return 0;

    /*valeur.Trim(true);
    valeur.Trim(false);*/
    // si la donnée est vide on ne fait rien
    if (valeur.Length() == 0)
        return 0;
        
    wxString valeurPourSql = valeur;
    gestion_quote(valeurPourSql);
    // on regarde si la donnée est déja dans la table
    query="SELECT rowid from " + nom_table + " where nom='" + valeurPourSql + "'";
    int id = 0;
    int retSelect = la_belle->get_value_int_rapide(query, id);
    
    if (retSelect == -1) {   // problème pendant l'interrogation de la base
        la_belle->get_erreur(mess);
        wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        return -1;
    } else if (retSelect == 0) {  // la valeur n'est pas encore en base
        ParamManager* param = ParamManager::GetInstance("config");
        BOOL verifNouveau = true;
        param->GetOrSet("config", "VERIF_NOUVEAU", nom_table, verifNouveau);
        if (verifNouveau) {    
            VerifNouveauGroupeDlg* dlgVerif = new VerifNouveauGroupeDlg(this, *la_belle, valeur, nom_table, libelleGroupePluriel);
            dlgVerif->ShowModal();
            valeur = dlgVerif->valeur();
            valeurPourSql = valeur;
            gestion_quote(valeurPourSql);

            if (dlgVerif->toujoursCreer() == true) {  // conserver en base config le nouveau paramètre
                param->Set("config", "VERIF_NOUVEAU", nom_table, false);
            }
            // refaire requete de selection en base pour voir si la nouvelle valeur existe
            query="SELECT rowid from " + nom_table + " where nom='" + valeurPourSql + "'";
            retSelect = la_belle->get_value_int_rapide(query, id);
            
            /* TODO : vérifier demande abandon de traitement du livre (ou supprimer du dlg !) */
        }
    }

    if (retSelect == -1) {   // problème pendant l'interrogation de la base
        la_belle->get_erreur(mess);
        wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        return -1;
    } else if (retSelect == 0) { // la valeur n'est pas encore en base : l'insérer
        query="INSERT INTO " + nom_table + " (nom) VALUES ('" + valeurPourSql + "')";
        la_belle->exec_rapide(query);
        query="SELECT rowid from " + nom_table + " where nom='" + valeurPourSql + "'";
        retSelect = la_belle->get_value_int_rapide(query, id);
    }
    
    // a ce stade, id contient l'id lu en base (déjà présent ou fraichement inséré) : le stocker dans la combobox pour utilisation future     
    resultat.Printf("%d", id);
    donnee->SetValue(resultat);
            /* TODO : utiliser SetClientData pour éviter affichage des données numériques */

    return 0;
}    

/*
 * WxSlider_noteScroll
 */
void Nouv_livre::WxSlider_noteScroll(wxScrollEvent& event)
{
    wxString mess;
    //int i;
    int note;
//    while 
    note=WxSlider_note->GetValue();
    mess.Printf("%d",note);
    WxStaticText_val_note->SetLabel(mess);
    
    init_etoiles();
     
	// insert your code here
	event.Skip();
}

void Nouv_livre::init_etoiles() {
    int note,i ;
    div_t divresult;
    wxImage star1(star1_XPM);
    wxImage star2(star2_XPM);

    note=WxSlider_note->GetValue();
     for(i=note;i>1;i-=2) {
         divresult=div(i,2);
         if ((divresult.quot-1)>=0) {
             canvas_note[divresult.quot-1]->init(star2);
//             canvas_note[divresult.quot-1]->init(star2_XPM);
             canvas_note[divresult.quot-1]->Refresh();
         }    
     }    
     divresult=div(note,2);
     if (i==1) {
         canvas_note[divresult.quot]->init(star1);
         //canvas_note[divresult.quot]->init(star1_XPM);
         canvas_note[divresult.quot]->Refresh();
         divresult.quot++;
     }    
     
     for (i=divresult.quot;i<5;i++) {
        canvas_note[i]->efface();
        canvas_note[i]->Refresh();
     }    
}    
int Nouv_livre::init_combo(wxComboBox *lacombo, wxString nomtable)
{
    wxString query;
    wxString mess;
    int ret, taille;
//    int i=0;
     wxString texte;

    lacombo->Clear();

    if (m_listeIdRequete != "") {      // cas d'une liste d'id --> afficher la valeur commune, ou "<< ne pas modifier >>"
        // SELECT nom FROM auteur where rowid in (SELECT distinct id_auteur FROM livre where rowid in (16, 17, 18))
        query = "SELECT nom FROM " + nomtable + " WHERE rowid IN "
                "(SELECT DISTINCT id_" + nomtable + " FROM livre WHERE rowid IN " + m_listeIdRequete + ")";
        // wxMessageBox(query);

        int nbReponses = 0;
        if (la_belle->transac_prepare(query) < 0) {
            la_belle->get_erreur(mess);
            wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        }
        while (la_belle->transac_step()==SQLITE_ROW) {
            la_belle->get_value_char(0,texte,taille);
            nbReponses ++;
        }  
        la_belle->transac_fin();
        
        if (nbReponses == 1) {
            lacombo->SetValue(texte);
        } else if (nbReponses > 1) {
            lacombo->SetValue(str_nePasModifier);
        }
    } else if (id_courant != "-1") {     // si id n'est pas nul on initialise la valeur de la combo
        query = "SELECT nom FROM  " + nomtable + " WHERE rowid "
                "= (SELECT id_" + nomtable + " FROM livre where rowid=" + id_courant + ")";
        //wxMessageBox(query, "test", wxOK | wxICON_EXCLAMATION, this);

        ret=la_belle->transac_prepare(query);
        if (ret<0) {
            la_belle->get_erreur(mess);
            wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        }
        
        ret=la_belle->transac_step();
    
        if(ret==SQLITE_ROW) {
            la_belle->get_value_char(0,texte,taille);
            lacombo->SetValue(texte);
        }  
        la_belle->transac_fin();

    }    
    query="SELECT nom from " + nomtable + " order by upper(nom)";
         //wxMessageBox(query,"probleme", wxOK | wxICON_EXCLAMATION, this);
   
    ret=la_belle->transac_prepare(query);
    if (ret<0) {
        la_belle->get_erreur(mess);
        wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
    }

    ret=la_belle->transac_step();

    while(ret==SQLITE_ROW) {
        la_belle->get_value_char(0,texte,taille);
        lacombo->Append(texte);
        ret=la_belle->transac_step();
    }  
    la_belle->transac_fin();
     lacombo->SetSelection(0, 0);
    return 0;
}    

void Nouv_livre::wxCombo_remplir(wxCommandEvent& event)
{
    wxComboBox *macombo;
    wxString mastring;
    wxString tempo1, tempo2;
    int taille;
    wxString choix;
    int i,nb_choix;
    
    macombo = (wxComboBox*)event.GetEventObject();
    if (anc_combo != macombo) {
        taille_entree=0;
    }    
    anc_combo=macombo;    
    mastring=macombo->GetValue();
    taille=mastring.Length();
        //tempo1.Printf("t:%d, te:%d",taille, taille_entree);
        //WxStaticText_date_maj_val->SetLabel(tempo1);
   if (taille<=taille_entree) {
        taille_entree=taille;
        event.StopPropagation();// .Skip();
        return;
    }    
    taille_entree=taille;
    nb_choix=macombo->GetCount();
    for(i=0;i<nb_choix;i++) {
        choix=macombo->GetString(i);
        tempo1=choix.Lower();
        tempo2=mastring.Lower();
        if (tempo1.StartsWith(tempo2.Left(taille_entree)) == true) {
            macombo->SetValue(choix);
            macombo->SetSelection (taille_entree, -1);
            return;
        }    
    }    
	event.Skip();

}

/*void Nouv_livre::wxEdit_Gesdate(wxCommandEvent& event){
    wxTextCtrl *texte_date;
    wxString valeur;

   texte_date = (wxTextCtrl*)event.GetEventObject();
   valeur=texte_date->GetValue();

   if(texte_date->GetInsertionPoint() == 2){// && date_mod==true){
      //wxMessageBox(valeur,"probleme", wxOK | wxICON_EXCLAMATION, this);
      if (valeur.Length() == 2) {
       valeur.Append("/");
         texte_date->SetValue(valeur);
       texte_date->SetInsertionPoint(3);
     } else if(valeur.GetChar(2) !='/'){
       valeur.SetChar(2,'/');
       texte_date->SetValue(valeur);
       texte_date->SetInsertionPoint(3);
      }    
   }    

   if(texte_date->GetInsertionPoint() == 5){// && date_mod==true){
      //wxMessageBox(valeur,"probleme", wxOK | wxICON_EXCLAMATION, this);
      if (valeur.Length() == 5) {
       valeur.Append("/");
       texte_date->SetValue(valeur);
       texte_date->SetInsertionPoint(6);
      }    
      else if (valeur.GetChar(5) !='/') {
       valeur.SetChar(5,'/');
       //wxMessageBox(valeur,"probleme", wxOK | wxICON_EXCLAMATION, this);
      
       texte_date->SetValue(valeur);
       texte_date->SetInsertionPoint(6);
      }    
   }
    event.Skip();
}    
*/
/*
 * WxBitmapButton_face_ouvrirClick
 */
void Nouv_livre::WxBitmapButton_face_ouvrirClick(wxCommandEvent& event)
{
    //bool tt=true;
    
                //wxMessageBox(chemin_image,"avant", wxOK | wxICON_EXCLAMATION, this);
    wxString filename = wxFileSelector("Ouvrir une image",chemin_image,"","","image (tout format reconnu)|*.jpg;*.jpeg;*.png;*.gif;*.bmp|Tous (*.*)|*.*",wxOPEN|wxFILE_MUST_EXIST);
                //wxMessageBox(chemin_image,"apres", wxOK | wxICON_EXCLAMATION, this);
    

    if ( !filename.empty() )
    {
        wxFileName lefichier(filename);
        chemin_image=lefichier.GetPath();
        
        if (WxNotebook_nouv->GetSelection() == 4) {
            canvas_image_face->init(filename);
            /*tt=image_face.LoadFile(filename);
            if (tt==true) {
                rempli_canvas(canvas_image_face, &image_face);
                image_face_charge=true;
            } else {
                wxMessageBox("Probleme de chargement de l'image","probleme", wxOK | wxICON_EXCLAMATION, this);
            }*/
        } else if (WxNotebook_nouv->GetSelection() == 5) {
            canvas_image_dos->init(filename);
            /*tt=image_dos.LoadFile(filename);
            if (tt==true) {
                rempli_canvas(canvas_image_dos, &image_dos);
                image_dos_charge=true;
            } else {
                wxMessageBox("Probleme de chargement de l'image","probleme", wxOK | wxICON_EXCLAMATION, this);
            }*/
        } else if (WxNotebook_nouv->GetSelection() == 6) {
            canvas_image_divers->init(filename);
            /*tt=image_divers.LoadFile(filename);
            if (tt==true) {
                rempli_canvas(canvas_image_divers, &image_divers);
                image_divers_charge=true;
            } else {
                wxMessageBox("Probleme de chargement de l'image","probleme", wxOK | wxICON_EXCLAMATION, this);
            }*/
        } else {
            return;
        }            
    }    
    // insert your code here
    event.Skip();
}
/*
 * WxBitmapButton_supp_image_faceClick
 */
void Nouv_livre::WxBitmapButton_supp_image_faceClick(wxCommandEvent& event)
{
        if (WxNotebook_nouv->GetSelection() == 4) {
            canvas_image_face->efface();
            canvas_image_face->Refresh();
            //image_face_charge=false;
        } else if (WxNotebook_nouv->GetSelection() == 5) {
            canvas_image_dos->efface();
            canvas_image_dos->Refresh();
            //image_dos_charge=false;
        } else if (WxNotebook_nouv->GetSelection() == 6) {
            canvas_image_divers->efface();
            canvas_image_divers->Refresh();
            //image_divers_charge=false;
        } else {
            return;
        }            
    
    // insert your code here
	event.Skip();
}

/*void Nouv_livre::rempli_canvas(ImageCanvas *lecanvas, wxImage *image) {
    int largeur_obj,hauteur_obj;
    int largeur_img,hauteur_img;
    float multi; 
    wxBitmap *affiche;
    wxImage tempo;

    lecanvas->GetSize(&largeur_obj,&hauteur_obj);
    largeur_obj-=50;
    multi=0.0;
    largeur_img=image->GetWidth();
    hauteur_img=image->GetHeight();
    if (largeur_img>largeur_obj) {
        multi=(float)largeur_obj/(float)largeur_img;
        largeur_img=(int)(multi*(float)largeur_img);
        hauteur_img=(int)(multi*(float)hauteur_img);
    }
    if (hauteur_img>hauteur_obj) {
        multi=(float)hauteur_obj/(float)hauteur_img;
        largeur_img=(int)(multi*(float)largeur_img);
        hauteur_img=(int)(multi*(float)hauteur_img);
    }
    tempo=image->Scale(largeur_img, hauteur_img);
    affiche=new wxBitmap(tempo, -1);
    lecanvas->init(*affiche);        
    lecanvas->Refresh();
}*/
void Nouv_livre::change_page(wxNotebookEvent &event) {
/*    if (event.GetSelection() == 4 ) {
        canvas_image_face->Refresh();
    }    */
    event.Skip();
}    



/*
 * WxButton_auteurClick
 */
void Nouv_livre::WxButton_auteurClick(wxCommandEvent& event)
{
    int ret, taille;
    wxString nom_table="auteur";
    wxString valeur="";
    wxString id="";
    wxString query, mess;
    wxComboBox *macombo=NULL;
/*    wxString toto;
    
    toto.Printf("%d %d", event.m_id, event.GetId());
    wxMessageBox(toto,"probleme", wxOK | wxICON_EXCLAMATION, this);*/
    if (event.GetId() == ID_WXBUTTON_AUTEUR) {
        nom_table="auteur";
        macombo=WxComboBox_auteur;
    } else if (event.GetId() == ID_WXBUTTON_SERIE) {
        nom_table="serie";
        macombo=WxComboBox_serie;
    } else if (event.GetId() == ID_WXBUTTON_GENRE) {
        nom_table="genre";
        macombo=WxComboBox_genre;
    } else if (event.GetId() == ID_WXBUTTON_EDITEUR) {
        nom_table="editeur";
        macombo=WxComboBox_editeur;
    } else if (event.GetId() == ID_WXBUTTON_FORMAT) {
        nom_table="format";
        macombo=WxComboBox_format;
    } else if (event.GetId() == ID_WXBUTTON_ARTISTE) {
        nom_table="artiste";
        macombo=WxComboBox_artiste;
    } else if (event.GetId() == ID_WXBUTTON_ETAT) {
        nom_table="etat";
        macombo=WxComboBox_etat;
    } else if (event.GetId() == ID_WXBUTTON_LOCALISATION) {
        nom_table="localisation";
        macombo=WxComboBox_localisation;
    } else if (event.GetId() == ID_WXBUTTON_SERIE_O) {
        nom_table="serie_o";
        macombo=WxComboBox_serie_o;
    } else if (event.GetId() == ID_WXBUTTON_PAYS) {
        nom_table="pays";
        macombo=WxComboBox_pays;
    } else if (event.GetId() == ID_WXBUTTON_LANGUE) {
        nom_table="langue";
        macombo=WxComboBox_langue;
    } else if (event.GetId() == ID_WXBUTTON_TRADUCTEUR) {
        nom_table="traducteur";
        macombo=WxComboBox_traducteur;
    }    
    valeur=macombo->GetValue();
    if (valeur!="") {
        gestion_quote(valeur);
        query="SELECT rowid FROM "+nom_table+" WHERE nom='"+valeur+"'";
        ret=la_belle->transac_prepare(query);
        if (ret<0) {
            la_belle->get_erreur(mess);
            wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        }

        ret=la_belle->transac_step();
    
        if (ret==SQLITE_ROW) {
            la_belle->get_value_char(0,id,taille);
        }  
        la_belle->transac_fin();
    }    
    if (id =="") {
        liste_champ* choisir = new liste_champ(la_belle, this, -1, nom_table);
        ret=choisir->ShowModal();
    } else {    
            nouv_autre* nouv = new nouv_autre(la_belle, id, this, -1, nom_table);
        ret=nouv->ShowModal();
    }    
    init_combo(macombo,nom_table);
	// insert your code here
	event.Skip();

}

void Nouv_livre::init_champ(wxString nom_champ, wxString valeur){
    long val;
    wxDateTime madate;

    
    if (nom_champ == "id_auteur") {
            wxMessageBox(valeur,"date", wxOK | wxICON_EXCLAMATION, this);
        WxComboBox_auteur->SetValue(valeur);
    } else if ( nom_champ == "titre") {
        WxEdit_titre->SetValue(valeur);
    } else if ( nom_champ == "sous_titre") {
        WxEdit_sous_titre->SetValue(valeur);
    } else if ( nom_champ == "id_serie") {
        WxComboBox_serie->SetValue(valeur);
    } else if ( nom_champ == "no_serie") {
        WxEdit_no_serie->SetValue(valeur);
    } else if ( nom_champ == "id_genre") {
        WxComboBox_genre->SetValue(valeur);
    } else if ( nom_champ == "isbn") {
        WxEdit_isbn->SetValue(valeur);
    } else if ( nom_champ == "id_editeur") {
        WxComboBox_editeur->SetValue(valeur);
    } else if ( nom_champ == "date_publication") {
        madate.ParseFormat(valeur,"%d/%m/%Y");
        WxDatePickerCtrl_publication->SetValue(madate);
        //WxEdit_date_pub->SetValue(valeur);
    } else if ( nom_champ == "id_format") {
        WxComboBox_format->SetValue(valeur);
    } else if ( nom_champ == "id_artiste") {
        WxComboBox_artiste->SetValue(valeur);
    } else if ( nom_champ == "prix") {
        WxEdit_prix->SetValue(valeur);
    } else if ( nom_champ == "recompense") {
        WxEdit_recompense->SetValue(valeur);
    } else if ( nom_champ == "date_achat") {
            wxMessageBox(valeur,"date", wxOK | wxICON_EXCLAMATION, this);
        madate.ParseFormat(valeur,"%d/%m/%Y");
        WxDatePickerCtrl_achat->SetValue(madate);
        //WxEdit_date_achat->SetValue(valeur);
    } else if ( nom_champ == "valeur") {
        WxEdit_valeur->SetValue(valeur);
    } else if ( nom_champ == "reference") {
        WxEdit_reference->SetValue(valeur);
    } else if ( nom_champ == "nb_pages") {
        WxEdit_nb_pages->SetValue(valeur);
    } else if ( nom_champ == "id_etat") {
        WxComboBox_etat->SetValue(valeur);
    } else if ( nom_champ == "id_localisation") {
        WxComboBox_localisation->SetValue(valeur);
    } else if ( nom_champ == "date_lecture") {
        madate.ParseFormat(valeur,"%d/%m/%Y");
        WxDatePickerCtrl_lecture->SetValue(madate);
        //WxEdit_date_lecture->SetValue(valeur);
    } else if ( nom_champ == "note") {
        valeur.ToLong(&val);
        WxSlider_note->SetValue(val);
    } else if ( nom_champ == "particularite") {
    } else if ( nom_champ == "titre_original") {
        WxEdit_titre_o->SetValue(valeur);
    } else if ( nom_champ == "sous_titre_o") {
        WxEdit_sous_titre_o->SetValue(valeur);
    } else if ( nom_champ == "id_serie_o") {
        WxComboBox_serie_o->SetValue(valeur);
    } else if ( nom_champ == "id_pays") {
        WxComboBox_pays->SetValue(valeur);
    } else if ( nom_champ == "id_langue") {
        WxComboBox_langue->SetValue(valeur);
    } else if ( nom_champ == "id_traducteur") {
        WxComboBox_traducteur->SetValue(valeur);
    } else if ( nom_champ == "commentaire") {
        WxMemo_commentaire->SetValue(valeur);
    } else if ( nom_champ == "resume") {
        WxMemo_resume->SetValue(valeur);
    } 
}    


void Nouv_livre::mise_a_jour(rech_internet *rech) {
    //bool tt;
    wxDateTime madate;
    
    WxEdit_isbn->SetValue(rech->WxEdit_isbn->GetValue());
    if (rech->WxCheckBox_auteur->IsChecked() == true)
        WxComboBox_auteur->SetValue(rech->WxEdit_auteur->GetValue());
    if (rech->WxCheckBox_titre->IsChecked() == true)
        WxEdit_titre->SetValue(rech->WxEdit_titre->GetValue());
    if (rech->WxCheckBox_editeur->IsChecked() == true)
        WxComboBox_editeur->SetValue(rech->WxEdit_editeur->GetValue());
    if (rech->WxCheckBox_genre->IsChecked() == true)
        WxComboBox_genre->SetValue(rech->WxEdit_genre->GetValue());
    if (rech->WxCheckBox_date_pub->IsChecked() == true)
        madate.ParseFormat(rech->WxEdit_date_pub->GetValue(),"%d/%m/%Y");
        WxDatePickerCtrl_publication->SetValue(madate);
        //WxEdit_date_pub->SetValue(rech->WxEdit_date_pub->GetValue());
    if (rech->WxCheckBox_langue->IsChecked() == true)
        WxComboBox_langue->SetValue(rech->WxEdit_langue->GetValue());
    if (rech->WxCheckBox_traducteur->IsChecked() == true)
        WxComboBox_traducteur->SetValue(rech->WxEdit_traducteur->GetValue());
    if (rech->WxCheckBox_prix->IsChecked() == true)
        WxEdit_prix->SetValue(rech->WxEdit_prix->GetValue());
    if (rech->WxCheckBox_format->IsChecked() == true)
        WxComboBox_format->SetValue(rech->WxEdit_format->GetValue());
      if (rech->WxCheckBox_nb_pages->IsChecked() == true)
        WxEdit_nb_pages->SetValue(rech->WxEdit_nb_pages->GetValue());
  if (rech->WxCheckBox_commentaire->IsChecked() == true)
        WxMemo_resume->SetValue(rech->WxMemo_commentaire->GetValue());
    if (rech->WxCheckBox_image_face->IsChecked() == true) {
        canvas_image_face->init(rech->img_recto);
        /*tt=image_face.LoadFile(rech->img_recto);
        if (tt==true) {
            rempli_canvas(canvas_image_face, &image_face);
            image_face_charge=true;
        } else {
            wxMessageBox("Probleme de chargement de l'image","probleme", wxOK | wxICON_EXCLAMATION, this);
        }*/
    }
    if (rech->WxCheckBox_image_dos->IsChecked() == true) {
        canvas_image_dos->init(rech->img_verso);
        /*tt=image_dos.LoadFile(rech->img_verso);
        if (tt==true) {
            rempli_canvas(canvas_image_dos, &image_dos);
            image_dos_charge=true;
        } else {
            wxMessageBox("Probleme de chargement de l'image","probleme", wxOK | wxICON_EXCLAMATION, this);
        }*/
    }
}
/*
 * WxButton_internetClick
 */
void Nouv_livre::WxButton_internetClick(wxCommandEvent& event)
{
    
    
    
    int ret ;
    wxString isbn, isbn_init;
    wxString ean;
    
    isbn_init=WxEdit_isbn->GetValue();
    for (unsigned int i=0;i<isbn_init.Len();i++) {
        char c=isbn_init[i];
        if ( c == 'x' || c == 'X' || (c>='0' && c<='9'))
            isbn=isbn+c;
    }
    
    int checksum=0;
    // Calcul EAN
    if (isbn.Len() == 13) {
        ean=isbn;
    } else if (isbn.Len() == 10) {
        ean="978"+isbn.Left(9);
        // calcul du checksum 
        long num;
        int mult=1;
        for (unsigned int i=0;i<ean.Len();i++) {
            ean.Mid(i,1).ToLong(&num);
            checksum=checksum+(((int) num) * mult);
            if (mult == 1)
                mult=3;
            else
                mult=1;
        }
        div_t res=div(checksum,10);
        checksum=res.rem;
        if (checksum !=0)
            checksum=10-checksum;
        //wxMessageBox(wxString::Format("%d",checksum),"probleme", wxOK | wxICON_EXCLAMATION, this);
        ean=ean+wxString::Format("%d",checksum);
    } else {
        wxMessageBox("L'I.S.B.N doit contenir 10 ou 13 caractères sinon il n'est pas valide","probleme", wxOK | wxICON_EXCLAMATION, this);
    	event.Skip();
        return;
    }
        
    wxString query;
    int ret_query;
    wxString texte;
    
    query="SELECT rowid FROM livre WHERE isbn=" + ean;
   
    ret_query=la_belle->transac_prepare(query);
    if (ret_query<0) {
        la_belle->get_erreur(texte);
        wxMessageBox(texte,"probleme", wxOK | wxICON_EXCLAMATION, this);
     	event.Skip();
       return;
    }

    ret_query=la_belle->transac_step();
    

    if(ret_query==SQLITE_ROW ) {
        // il y a donc deja un livre en base avec le meme ISBN
        int ret_mb = wxMessageBox("Attention, cet I.S.B.N. est déjà présent en base.\nVoulez-vous continuer ?","Entrée en doublon", wxYES_NO | wxICON_QUESTION, this);
        if (ret_mb==wxNO) {
            la_belle->transac_fin();
        	event.Skip();
            return;
        }
            
    }  
    else { // isbn inconnu en base --> rien à faire de particulier
    }
    la_belle->transac_fin();
    
    // fin modif - 2009-11-26
    
    
    rech_internet* rech = new rech_internet(ean, this, -1);
    ret=rech->ShowModal();
    if (ret == 0) { 
        mise_a_jour(rech);
    }

	// insert your code here
	event.Skip();
}

/*
 * WxButton_internet_gClick
 */
void Nouv_livre::WxButton_internet_gClick(wxCommandEvent& event)
{
    rech_internet_gen* rech_gen = new rech_internet_gen(this, -1);
    
    if (WxEdit_titre->GetValue() != "") {
        rech_gen->WxEdit_recherche->SetValue(WxEdit_titre->GetValue());
    } else if (WxComboBox_auteur->GetValue() != "") {
        rech_gen->WxEdit_recherche->SetValue(WxComboBox_auteur->GetValue());
    }
    
    int ret = rech_gen->ShowModal();
    if (ret == 0) { 
        //wxMessageBox("popo","probleme", wxOK | wxICON_EXCLAMATION, this);
        mise_a_jour(rech_gen->ma_recherche);
    }

	event.Skip();
}

/*
 * Nouv_livreInitDialog
 */
void Nouv_livre::Nouv_livreInitDialog(wxInitDialogEvent& event)
{
	wxLogMessage("Nouv_livre::Nouv_livreInitDialog() - m_itemInsertion = 0x%x", m_itemInsertion);

    if (m_itemInsertion) {
        if (m_itemInsertion->isbn() != "") {
            WxEdit_isbn->SetValue(m_itemInsertion->isbn());
        	wxDialog::EmulateButtonClickIfPresent(ID_WXBUTTON_INTERNET);
        } else if (m_itemInsertion->titre() != "" || m_itemInsertion->auteur() != "") {
            WxEdit_titre->SetValue(m_itemInsertion->titre());
            WxComboBox_auteur->SetValue(m_itemInsertion->auteur());
        	wxDialog::EmulateButtonClickIfPresent(ID_WXBUTTON_INTERNET_G);
        }
    } else {
        event.Skip(false);
    }
}
