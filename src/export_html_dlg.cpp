//---------------------------------------------------------------------------
//
// Name:        export_html_dlg.cpp
// Author:      epaillard
// Created:     07/12/2006 11:21:18
// Description: export_html_dlg class implementation
//
//
//Copyright PE Epaillard, 10/27/2004
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

#include "export_html_dlg.h"
#include "divers.h"
#include <wx/filename.h>
//#include <wx/busyinfo.h>
#include <wx/progdlg.h>
//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

// images 
#include "template_book_1024_02.xpm"
#include "template_book_1024_03.xpm"
#include "template_book_1024_04.xpm"
#include "template_book_1024_01611.xpm"
#include "template_book_1024_051015.xpm"

#include "export_html_images.cpp"

#define MODE_HTML 0 
#define MODE_HTML_PDA 1
#define MODE_AJAX 2
//----------------------------------------------------------------------------
// export_html_dlg
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(export_html_dlg,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(export_html_dlg::OnClose)
	EVT_BUTTON(ID_WXBUTTON_CHEMIN_DEST,export_html_dlg::WxButton_chemin_destClick)
	EVT_BUTTON(ID_WXBUTTON_ANNUL,export_html_dlg::WxButton_annulClick)
	EVT_BUTTON(ID_WXBUTTON_OK,export_html_dlg::WxButton_okClick)
END_EVENT_TABLE()
////Event Table End

export_html_dlg::export_html_dlg(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
    la_belle=NULL;
	CreateGUIControls();
}

export_html_dlg::export_html_dlg( ma_base *pour_lecture, wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
    la_belle=pour_lecture;
	CreateGUIControls();
}

export_html_dlg::~export_html_dlg()
{
} 

void export_html_dlg::CreateGUIControls()
{
	//Do not add custom code here
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	SetTitle(wxT("Export HTML"));
	SetIcon(wxNullIcon);
	SetSize(8,8,320,430);
	Center();
	

	wxArrayString arrayStringFor_WxRadioBox_type;
	arrayStringFor_WxRadioBox_type.Add(wxT("Full HTML"));
	arrayStringFor_WxRadioBox_type.Add(wxT("HTML PDA"));
	arrayStringFor_WxRadioBox_type.Add(wxT("Ajax"));
	WxRadioBox_type = new wxRadioBox(this, ID_WXRADIOBOX_TYPE, wxT("Type de génération :"), wxPoint(3,8), wxSize(305,69), arrayStringFor_WxRadioBox_type, 2, wxRA_SPECIFY_COLS, wxDefaultValidator, wxT("WxRadioBox_type"));
	WxRadioBox_type->SetSelection(0);

	WxEdit_mail = new wxTextCtrl(this, ID_WXEDIT_MAIL, wxT("machin@truc.fr"), wxPoint(2,246), wxSize(305,18), 0, wxDefaultValidator, wxT("WxEdit_mail"));

	WxStaticText_mail = new wxStaticText(this, ID_WXSTATICTEXT_MAIL, wxT("Mail à mettre en bas des pages :"), wxPoint(3,225), wxDefaultSize, 0, wxT("WxStaticText_mail"));

	WxEdit_nom = new wxTextCtrl(this, ID_WXEDIT_NOM, wxT("Machin"), wxPoint(2,197), wxSize(305,18), 0, wxDefaultValidator, wxT("WxEdit_nom"));

	WxStaticText_nom = new wxStaticText(this, ID_WXSTATICTEXT_NOM, wxT("Nom utilisé pour le nom en bas des pages"), wxPoint(4,180), wxDefaultSize, 0, wxT("WxStaticText_nom"));

	WxEdit_titre = new wxTextCtrl(this, ID_WXEDIT_TITRE, wxT("La livrothèque de ..."), wxPoint(2,150), wxSize(305,18), 0, wxDefaultValidator, wxT("WxEdit_titre"));

	WxStaticText_titre = new wxStaticText(this, ID_WXSTATICTEXT_TITRE, wxT("Titre utilisé pour les pages webs :"), wxPoint(2,129), wxDefaultSize, 0, wxT("WxStaticText_titre"));

	WxMemo_texte_accueil = new wxTextCtrl(this, ID_WXMEMO_TEXTE_ACCUEIL, wxT(""), wxPoint(3,295), wxSize(305,64), wxTE_MULTILINE, wxDefaultValidator, wxT("WxMemo_texte_accueil"));
	WxMemo_texte_accueil->SetMaxLength(0);
	WxMemo_texte_accueil->AppendText(wxT("Bienvenue sur e-livrothèque !"));
	WxMemo_texte_accueil->SetFocus();
	WxMemo_texte_accueil->SetInsertionPointEnd();

	WxStaticText_texte_accueil = new wxStaticText(this, ID_WXSTATICTEXT_TEXTE_ACCUEIL, wxT("Texte d'accueil :"), wxPoint(9,273), wxDefaultSize, 0, wxT("WxStaticText_texte_accueil"));

	WxStaticText_destination = new wxStaticText(this, ID_WXSTATICTEXT_DESTINATION, wxT("Repertoire de destination :"), wxPoint(2,83), wxDefaultSize, 0, wxT("WxStaticText_destination"));

	WxEdit_chemin_dest = new wxTextCtrl(this, ID_WXEDIT_CHEMIN_DEST, wxT("WxEdit_chemin_dest"), wxPoint(2,101), wxSize(272,18), wxTE_READONLY, wxDefaultValidator, wxT("WxEdit_chemin_dest"));

	WxButton_chemin_dest = new wxButton(this, ID_WXBUTTON_CHEMIN_DEST, wxT("..."), wxPoint(278,101), wxSize(29,20), wxBU_TOP, wxDefaultValidator, wxT("WxButton_chemin_dest"));

	WxButton_annul = new wxButton(this, ID_WXBUTTON_ANNUL, wxT("Sortir"), wxPoint(178,369), wxSize(80,22), 0, wxDefaultValidator, wxT("WxButton_annul"));

	WxButton_ok = new wxButton(this, ID_WXBUTTON_OK, wxT("Lancer la génération"), wxPoint(19,369), wxSize(114,22), 0, wxDefaultValidator, wxT("WxButton_ok"));
	////GUI Items Creation End
	wxString chemin=::wxGetCwd();
	charge_config();
	
	    //image handler
    wxImage::AddHandler( new wxBMPHandler );
    wxImage::AddHandler( new wxPNGHandler );
    wxImage::AddHandler( new wxJPEGHandler );
    wxImage::AddHandler( new wxGIFHandler );
    wxImage::AddHandler( new wxPCXHandler );
    wxImage::AddHandler( new wxPNMHandler );
    wxImage::AddHandler( new wxTIFFHandler );
    wxImage::AddHandler( new wxXPMHandler );

}

void export_html_dlg::sauve_config() {
    wxString query, mess;
    int ret;

    if(la_belle->existe("config_export_html") == false )
    {
        query="CREATE TABLE config_export_html (type_param TEXT , nom_param TEXT, val1 TEXT, val2 TEXT)";
        ret=la_belle->exec_rapide(query);
        if (ret<0) {
            la_belle->get_erreur(mess);
            wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        }
    }
    query="DELETE FROM config_export_html WHERE type_param='INIT' AND nom_param='REP_DEST'";
    ret=la_belle->exec_rapide(query);
    query="INSERT INTO config_export_html(type_param, nom_param, val1) VALUES ('INIT', 'REP_DEST', '"+WxEdit_chemin_dest->GetValue()+"')";
    ret=la_belle->exec_rapide(query);
    if (ret<0) {
        la_belle->get_erreur(mess);
        wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
    }
    query="DELETE FROM config_export_html WHERE type_param='INIT' AND nom_param='TITRE'";
    ret=la_belle->exec_rapide(query);
    query="INSERT INTO config_export_html(type_param, nom_param, val1) VALUES ('INIT', 'TITRE', '"+WxEdit_titre->GetValue()+"')";
    ret=la_belle->exec_rapide(query);
    if (ret<0) {
        la_belle->get_erreur(mess);
        wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
    }
    query="DELETE FROM config_export_html WHERE type_param='INIT' AND nom_param='NOM'";
    ret=la_belle->exec_rapide(query);
    query="INSERT INTO config_export_html(type_param, nom_param, val1) VALUES ('INIT', 'NOM', '"+WxEdit_nom->GetValue()+"')";
    ret=la_belle->exec_rapide(query);
    if (ret<0) {
        la_belle->get_erreur(mess);
        wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
    }
    query="DELETE FROM config_export_html WHERE type_param='INIT' AND nom_param='MAIL'";
    ret=la_belle->exec_rapide(query);
    query="INSERT INTO config_export_html(type_param, nom_param, val1) VALUES ('INIT', 'MAIL', '"+WxEdit_mail->GetValue()+"')";
    ret=la_belle->exec_rapide(query);
    if (ret<0) {
        la_belle->get_erreur(mess);
        wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
    }
    query="DELETE FROM config_export_html WHERE type_param='INIT' AND nom_param='ACCUEIL'";
    ret=la_belle->exec_rapide(query);
    query="INSERT INTO config_export_html(type_param, nom_param, val1) VALUES ('INIT', 'ACCUEIL', '"+WxMemo_texte_accueil->GetValue()+"')";
    ret=la_belle->exec_rapide(query);
    if (ret<0) {
        la_belle->get_erreur(mess);
        wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
    }
    query="DELETE FROM config_export_html WHERE type_param='INIT' AND nom_param='GENERATION'";
    ret=la_belle->exec_rapide(query);
    mess.Printf("%d",WxRadioBox_type->GetSelection());
    query="INSERT INTO config_export_html(type_param, nom_param, val1) VALUES ('INIT', 'GENERATION', '"+mess+"')";
    ret=la_belle->exec_rapide(query);
    if (ret<0) {
        la_belle->get_erreur(mess);
        wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
    }
}

void export_html_dlg::charge_config() {
    if(la_belle->existe("config_export_html") == true )
    {
        wxString valeur, query, mess;
        int taille, ret;

        query = "SELECT val1 FROM config_export_html WHERE type_param='INIT' AND nom_param='REP_DEST'";
        ret=la_belle->transac_prepare(query);
        ret=la_belle->transac_step();

        if(ret==SQLITE_ROW ) {
            la_belle->get_value_char(0,valeur,taille);
        }
            //wxMessageBox(valeur,"chemin", wxOK | wxICON_EXCLAMATION, this);
        la_belle->transac_fin();
        
        wxString chemin;
        if (valeur.Length() > 0)
            chemin=valeur;
       	if (chemin[chemin.Length()-1]!=wxFileName::GetPathSeparator()) {
            chemin=chemin+wxFileName::GetPathSeparator();
        }
    	WxEdit_chemin_dest->SetValue(chemin);
    	
        query = "SELECT val1 FROM config_export_html WHERE type_param='INIT' AND nom_param='TITRE'";
        ret=la_belle->transac_prepare(query);
        ret=la_belle->transac_step();

        if(ret==SQLITE_ROW ) {
           la_belle->get_value_char(0,valeur,taille);
    	   WxEdit_titre->SetValue(valeur);
        }
            //wxMessageBox(valeur,"chemin", wxOK | wxICON_EXCLAMATION, this);
        la_belle->transac_fin();
    	
        query = "SELECT val1 FROM config_export_html WHERE type_param='INIT' AND nom_param='NOM'";
        ret=la_belle->transac_prepare(query);
        ret=la_belle->transac_step();

        if(ret==SQLITE_ROW ) {
           la_belle->get_value_char(0,valeur,taille);
    	   WxEdit_nom->SetValue(valeur);
        }
            //wxMessageBox(valeur,"chemin", wxOK | wxICON_EXCLAMATION, this);
        la_belle->transac_fin();

        query = "SELECT val1 FROM config_export_html WHERE type_param='INIT' AND nom_param='MAIL'";
        ret=la_belle->transac_prepare(query);
        ret=la_belle->transac_step();

        if(ret==SQLITE_ROW ) {
           la_belle->get_value_char(0,valeur,taille);
    	   WxEdit_mail->SetValue(valeur);
        }
            //wxMessageBox(valeur,"chemin", wxOK | wxICON_EXCLAMATION, this);
        la_belle->transac_fin();

        query = "SELECT val1 FROM config_export_html WHERE type_param='INIT' AND nom_param='ACCUEIL'";
        ret=la_belle->transac_prepare(query);
        ret=la_belle->transac_step();

        if(ret==SQLITE_ROW ) {
           la_belle->get_value_char(0,valeur,taille);
    	   WxMemo_texte_accueil->SetValue(valeur);
        }
        la_belle->transac_fin();
        
            //wxMessageBox(valeur,"chemin", wxOK | wxICON_EXCLAMATION, this);
        query = "SELECT val1 FROM config_export_html WHERE type_param='INIT' AND nom_param='GENERATION'";
        ret=la_belle->transac_prepare(query);
        ret=la_belle->transac_step();

        if(ret==SQLITE_ROW ) {
            double type_gen;
            la_belle->get_value_char(0,valeur,taille);
            valeur.ToDouble(&type_gen);
            WxRadioBox_type->SetSelection((int)type_gen);
        }
            //wxMessageBox(valeur,"chemin", wxOK | wxICON_EXCLAMATION, this);
        la_belle->transac_fin();

    }
}

void export_html_dlg::OnClose(wxCloseEvent& /*event*/)
{
	Destroy();
}

/*
 * WxButton_okClick
 *
 * génération des pages HTML
 */
void export_html_dlg::WxButton_okClick(wxCommandEvent& event)
{   
    wxWindowDisabler disableAll;
    export_html_textes contenu_fich(this);
    //wxBusyInfo occupe(wxT("Génération des pages ..."));
    wxProgressDialog information(wxT("Génération des pages ..."),wxT("Sauvegarde de la configuration ..."), 100, this, wxPD_APP_MODAL|wxPD_AUTO_HIDE|wxPD_SMOOTH|wxPD_ELAPSED_TIME);
    
    sauve_config();
    wxString texte, texte2, nomfich, arbre; 
    wxFile fichier;
    wxBitmap *limage;
    wxFile image_mem;

    // création de l'abrorescence
    wxString chemin_js=WxEdit_chemin_dest->GetValue()+wxT("js")+wxFileName::GetPathSeparator();
    if (::wxDirExists(chemin_js) == false) {
        ::wxMkdir(chemin_js);
    }
    wxString chemin_css=WxEdit_chemin_dest->GetValue()+wxT("css")+wxFileName::GetPathSeparator();
    if (::wxDirExists(chemin_css) == false) {
        ::wxMkdir(chemin_css);
    }
    wxString chemin_images=WxEdit_chemin_dest->GetValue()+wxT("images")+wxFileName::GetPathSeparator();
    if (::wxDirExists(chemin_images) == false) {
        ::wxMkdir(chemin_images);
    }
    wxString chemin_images_menu=chemin_images+wxT("menu")+wxFileName::GetPathSeparator();
    if (::wxDirExists(chemin_images_menu) == false) {
        ::wxMkdir(chemin_images_menu);
    }
    wxString chemin_images_ihm=chemin_images+wxT("ihm")+wxFileName::GetPathSeparator();
    if (::wxDirExists(chemin_images_ihm) == false) {
        ::wxMkdir(chemin_images_ihm);
    }
    wxString chemin_images_common=chemin_images+wxT("common")+wxFileName::GetPathSeparator();
    if (::wxDirExists(chemin_images_common) == false) {
        ::wxMkdir(chemin_images_common);
    }
    wxString chemin_images_covers=chemin_images+wxT("covers")+wxFileName::GetPathSeparator();
    if (::wxDirExists(chemin_images_covers) == false) {
        ::wxMkdir(chemin_images_covers);
    }
    wxString chemin_content=WxEdit_chemin_dest->GetValue()+wxT("content")+wxFileName::GetPathSeparator();
    if (::wxDirExists(chemin_content) == false) {
        ::wxMkdir(chemin_content);
    }
    wxString chemin_content_authors=chemin_content+wxT("authors")+wxFileName::GetPathSeparator();
    if (::wxDirExists(chemin_content_authors) == false) {
        ::wxMkdir(chemin_content_authors);
    }
    wxString chemin_content_authors_fiches=chemin_content_authors+wxT("fiches")+wxFileName::GetPathSeparator();
    if (::wxDirExists(chemin_content_authors_fiches) == false) {
        ::wxMkdir(chemin_content_authors_fiches);
    }
    wxString chemin_content_authors_listes=chemin_content_authors+wxT("listes")+wxFileName::GetPathSeparator();
    if (::wxDirExists(chemin_content_authors_listes) == false) {
        ::wxMkdir(chemin_content_authors_listes);
    }
    wxString chemin_content_books=chemin_content+wxT("books")+wxFileName::GetPathSeparator();
    if (::wxDirExists(chemin_content_books) == false) {
        ::wxMkdir(chemin_content_books);
    }
    wxString chemin_content_books_fiches=chemin_content_books+wxT("fiches")+wxFileName::GetPathSeparator();
    if (::wxDirExists(chemin_content_books_fiches) == false) {
        ::wxMkdir(chemin_content_books_fiches);
    }
    wxString chemin_content_books_listes=chemin_content_books+wxT("listes")+wxFileName::GetPathSeparator();
    if (::wxDirExists(chemin_content_books_listes) == false) {
        ::wxMkdir(chemin_content_books_listes);
    }
    wxString chemin_content_series=chemin_content+wxT("series")+wxFileName::GetPathSeparator();
    if (::wxDirExists(chemin_content_series) == false) {
        ::wxMkdir(chemin_content_series);
    }
    wxString chemin_content_series_fiches=chemin_content_series+wxT("fiches")+wxFileName::GetPathSeparator();
    if (::wxDirExists(chemin_content_series_fiches) == false) {
        ::wxMkdir(chemin_content_series_fiches);
    }
    wxString chemin_content_series_listes=chemin_content_series+wxT("listes")+wxFileName::GetPathSeparator();
    if (::wxDirExists(chemin_content_series_listes) == false) {
        ::wxMkdir(chemin_content_series_listes);
    }
    
    information.Update(20, wxT("génération des index"));
    
    //wxMessageBox(nomfich,"fichier", wxOK | wxICON_EXCLAMATION, this);
    //index.html
    nomfich=WxEdit_chemin_dest->GetValue()+wxT("index.html");
    fichier.Open(nomfich,wxFile::write);
    if (WxRadioBox_type->GetSelection() == MODE_AJAX) {
        texte=contenu_fich.WxMemo_index->GetValue();
        texte.Replace("#N_VERSION#",wxT("v1.0 (AJAX)"));
    } else if(WxRadioBox_type->GetSelection() == MODE_HTML ){
        texte=contenu_fich.WxMemo_html_index->GetValue();
        texte.Replace("#N_VERSION#",wxT("v1.0 (HTML)"));
    } else if(WxRadioBox_type->GetSelection() == MODE_HTML_PDA ){
        texte=contenu_fich.WxMemo_pda_index->GetValue();
        texte.Replace("#N_VERSION#",wxT("v1.0 (PDA)"));
    }
    texte.Replace("#TEXTE_ACCUEIL#",WxMemo_texte_accueil->GetValue());
    texte.Replace("#TITRE#",WxEdit_titre->GetValue());
    texte.Replace("#MAIL#",WxEdit_mail->GetValue());
    texte.Replace("#NOM_AUTEUR#",WxEdit_nom->GetValue());
    fichier.Write(texte);
    fichier.Close();
    
    //accueil.html (inutile en mode ajax)
    if (WxRadioBox_type->GetSelection() == MODE_HTML || WxRadioBox_type->GetSelection() == MODE_HTML_PDA) {
        nomfich=WxEdit_chemin_dest->GetValue()+wxT("accueil.html");
        fichier.Open(nomfich,wxFile::write);
        texte=contenu_fich.WxMemo_html_accueil->GetValue();
        texte.Replace("#TEXTE_ACCUEIL#",WxMemo_texte_accueil->GetValue());
        texte.Replace("#TITRE#",WxEdit_titre->GetValue());
        texte.Replace("#MAIL#",WxEdit_mail->GetValue());
        texte.Replace("#NOM_AUTEUR#",WxEdit_nom->GetValue());
        fichier.Write(texte);
        fichier.Close();
    }    
    
    
    //ua.js
    nomfich=chemin_js+wxT("ua.js");
    fichier.Open(nomfich,wxFile::write);
    texte=contenu_fich.WxMemo_ua_js->GetValue();
    fichier.Write(texte);
    fichier.Close();
    
    //ftiens4.js
    nomfich=chemin_js+wxT("ftiens4.js");
    fichier.Open(nomfich,wxFile::write);
    texte=contenu_fich.WxMemo_ftiens4_js->GetValue();
    fichier.Write(texte);
    fichier.Close();
    
    information.Update(30, wxT("génération des arbres"));
    //framelessNodes.js
    nomfich=chemin_js+wxT("framelessNodes.js");
    fichier.Open(nomfich,wxFile::write);
    texte=contenu_fich.WxMemo_framelessNodes_js->GetValue();
    arbre="";
    creation_tree_auteur(arbre);
    texte.Replace(wxT("#tree_auteur#"),arbre);
    arbre="";
    if (WxRadioBox_type->GetSelection() == MODE_AJAX) {
        texte2=contenu_fich.WxMemo_fiche_auteur->GetValue();
    } else if(WxRadioBox_type->GetSelection() == MODE_HTML || WxRadioBox_type->GetSelection() == MODE_HTML_PDA){
        texte2=contenu_fich.WxMemo_html_fiche_auteur->GetValue();
    }
    creation_tree_titre(arbre,chemin_content_books_listes, texte2);
    texte.Replace(wxT("#tree_titre#"),arbre);
    if (WxRadioBox_type->GetSelection() == MODE_AJAX) {
        texte2=contenu_fich.WxMemo_fiche_auteur->GetValue();
    } else if(WxRadioBox_type->GetSelection() == MODE_HTML || WxRadioBox_type->GetSelection() == MODE_HTML_PDA){
        texte2=contenu_fich.WxMemo_html_fiche_auteur->GetValue();
    }
    creation_tree_serie(arbre,chemin_content_series_listes,chemin_content_series_fiches, texte2);
    texte.Replace(wxT("#tree_serie#"),arbre);
    fichier.Write(texte);
    fichier.Close();
    
    //livrotheque.css
    nomfich=chemin_css+wxT("livrotheque.css");
    fichier.Open(nomfich,wxFile::write);
    texte=contenu_fich.WxMemo_livrotheque_css->GetValue();
    fichier.Write(texte);
    fichier.Close();
 
    information.Update(40, wxT("génération des images du menu"));

    // images/menus
    nomfich=chemin_images_menu+wxT("ftv2lastnode.png");
    image_mem.Open(nomfich, wxFile::write);
    image_mem.Write(ftv2lastnode_png, sizeof ftv2lastnode_png);
    image_mem.Close();
    
    nomfich=chemin_images_menu+wxT("ftv2mlastnode.png");
    image_mem.Open(nomfich, wxFile::write);
    image_mem.Write(ftv2mlastnode_png, sizeof ftv2mlastnode_png);
    image_mem.Close();

    nomfich=chemin_images_menu+wxT("ftv2mnode.png");
    image_mem.Open(nomfich, wxFile::write);
    image_mem.Write(ftv2mnode_png, sizeof ftv2mnode_png);
    image_mem.Close();

    nomfich=chemin_images_menu+wxT("ftv2node.png");
    image_mem.Open(nomfich, wxFile::write);
    image_mem.Write(ftv2node_png, sizeof ftv2node_png);
    image_mem.Close();

    nomfich=chemin_images_menu+wxT("ftv2plastnode.png");
    image_mem.Open(nomfich, wxFile::write);
    image_mem.Write(ftv2plastnode_png, sizeof ftv2plastnode_png);
    image_mem.Close();

    nomfich=chemin_images_menu+wxT("ftv2pnode.png");
    image_mem.Open(nomfich, wxFile::write);
    image_mem.Write(ftv2pnode_png, sizeof ftv2pnode_png);
    image_mem.Close();
 
    nomfich=chemin_images_menu+wxT("ftv2vertline.png");
    image_mem.Open(nomfich, wxFile::write);
    image_mem.Write(ftv2vertline_png, sizeof ftv2vertline_png);
    image_mem.Close();

    nomfich=chemin_images_menu+wxT("ftv2blank.png");
    image_mem.Open(nomfich, wxFile::write);
    image_mem.Write(ftv2blank_png, sizeof ftv2blank_png);
    image_mem.Close();
    
    nomfich=chemin_images_menu+wxT("transpix.png");
    image_mem.Open(nomfich, wxFile::write);
    image_mem.Write(transpix_png, sizeof transpix_png);
    image_mem.Close();
    nomfich=chemin_images_menu+wxT("ftv2folderclosed.png");
    image_mem.Open(nomfich, wxFile::write);
    image_mem.Write(transpix_png, sizeof transpix_png);
    image_mem.Close();
    nomfich=chemin_images_menu+wxT("ftv2doc.png");
    image_mem.Open(nomfich, wxFile::write);
    image_mem.Write(transpix_png, sizeof transpix_png);
    image_mem.Close();
    nomfich=chemin_images_menu+wxT("ftv2folderopen.png");
    image_mem.Open(nomfich, wxFile::write);
    image_mem.Write(transpix_png, sizeof transpix_png);
    image_mem.Close();
    
    // images/ihm
    if (WxRadioBox_type->GetSelection() != MODE_HTML_PDA) {
        nomfich=chemin_images_ihm+wxT("template_book_1024_02.png");
        limage= new wxBitmap(template_book_1024_02_xpm);
        limage->SaveFile(nomfich, wxBITMAP_TYPE_PNG);
        limage->~wxBitmap();
    
        nomfich=chemin_images_ihm+wxT("template_book_1024_03.png");
        limage= new wxBitmap(template_book_1024_03_xpm);
        limage->SaveFile(nomfich, wxBITMAP_TYPE_PNG);
        limage->~wxBitmap();
        
        nomfich=chemin_images_ihm+wxT("template_book_1024_04.png");
        limage= new wxBitmap(template_book_1024_04_xpm);
        limage->SaveFile(nomfich, wxBITMAP_TYPE_PNG);
        limage->~wxBitmap();
    
        nomfich=chemin_images_ihm+wxT("template_book_1024_01611.png");
        limage= new wxBitmap(template_book_1024_01611_xpm);
        limage->SaveFile(nomfich, wxBITMAP_TYPE_PNG);
        limage->~wxBitmap();
    
        nomfich=chemin_images_ihm+wxT("template_book_1024_051015.png");
        limage= new wxBitmap(template_book_1024_051015_xpm);
        limage->SaveFile(nomfich, wxBITMAP_TYPE_PNG);
        limage->~wxBitmap();
    }

    // images/common
    nomfich=chemin_images_common+wxT("transpix.png");

    information.Update(60, wxT("génération des fiches des auteurs"));
    // création des fiches des auteurs
        
    if (WxRadioBox_type->GetSelection() == MODE_AJAX) {
        texte=contenu_fich.WxMemo_fiche_auteur->GetValue();
    } else if(WxRadioBox_type->GetSelection() == MODE_HTML || WxRadioBox_type->GetSelection() == MODE_HTML_PDA){
        texte=contenu_fich.WxMemo_html_fiche_auteur->GetValue();
    }
    creation_fiches_auteurs(chemin_content_authors_fiches, chemin_content_authors_listes, texte);

    // création des listes des titres
    
    information.Update(70, wxT("génération des fiches des livres"));
    // création des fiches des livres
    if (WxRadioBox_type->GetSelection() == MODE_AJAX) {
        texte=contenu_fich.WxMemo_fiche_livre->GetValue();
    } else if(WxRadioBox_type->GetSelection() == MODE_HTML || WxRadioBox_type->GetSelection() == MODE_HTML_PDA){
        texte=contenu_fich.WxMemo_html_fiche_livre->GetValue();
    }
    creation_fiches_livres(chemin_content_books_fiches, chemin_images_covers, texte);

    information.Update(100, wxT("fini"));
    
    ::wxExecute(wxT("explorer ")+WxEdit_chemin_dest->GetValue());
}

void export_html_dlg::creation_fiches_livres(wxString chemin_fiche,wxString chemin_image, wxString &fiche) {
    wxString query, mess;
    wxString id_courant,valeur;
    int ret,taille;
    wxString fiche_courante, nomfich;
    wxFile fichier;
    wxString ligne_image;
    
    if (WxRadioBox_type->GetSelection() == MODE_AJAX) {
        ligne_image=wxT("<img onClick=\"javascript:open(this.src,'test','menu=no;status=no');\" name=\"#NOM_IMAGE#\" src=\"images/covers/#NOM_IMAGE#\" width=\"100\"> \n");
    } else if(WxRadioBox_type->GetSelection() == MODE_HTML || WxRadioBox_type->GetSelection() == MODE_HTML_PDA){
        ligne_image=wxT("<img onClick=\"javascript:open(this.src,'test','menu=no;status=no');\" name=\"#NOM_IMAGE#\" src=\"../../../images/covers/#NOM_IMAGE#\" width=\"100\"> \n");
    }
    
    
    query=wxT("SELECT livre.rowid, auteur.nom, livre.titre, livre.sous_titre, serie.nom, livre.no_serie, ");
    query=query+wxT("  genre.nom, livre.isbn, editeur.nom, livre.date_publication, livre.prix, livre.date_achat, ");
    query=query+wxT("  livre.date_lecture, livre.note, livre.particularite, livre.resume, livre.commentaire, ");
    query=query+wxT("  livre.date_entree, livre.date_maj, livre.image_face, livre.image_dos, livre.image_tranche");
    query=query+wxT("  FROM livre, auteur ");
    query=query+wxT(" LEFT JOIN serie ON livre.id_serie=serie.rowid ");
    query=query+wxT(" LEFT JOIN genre ON livre.id_genre=genre.rowid ");
    query=query+wxT(" LEFT JOIN editeur ON livre.id_editeur=editeur.rowid ");
    query=query+wxT(" WHERE livre.id_auteur=auteur.rowid ");
    query=query+wxT(" ORDER BY livre.rowid ");
    
    ret=la_belle->transac_prepare(query);
    if (ret<0) {
        la_belle->get_erreur(mess);
        wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
    }

    ret=la_belle->transac_step();
    if (ret<0) {
        la_belle->get_erreur(mess);
        wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
    }
    
    while(ret==SQLITE_ROW ) {
        fiche_courante=fiche;
        la_belle->get_value_char(0,id_courant,taille);
        la_belle->get_value_char(1,valeur,taille);
        fiche_courante.Replace(wxT("#AUTEUR#"),valeur);
        la_belle->get_value_char(2,valeur,taille);
        fiche_courante.Replace(wxT("#TITRE#"),valeur);
        la_belle->get_value_char(3,valeur,taille);
        fiche_courante.Replace(wxT("#SOUS_TITRE#"),valeur);
        la_belle->get_value_char(4,valeur,taille);
        fiche_courante.Replace(wxT("#SERIE#"),valeur);
        la_belle->get_value_char(5,valeur,taille);
        fiche_courante.Replace(wxT("#N_SERIE#"),valeur);
        la_belle->get_value_char(6,valeur,taille);
        fiche_courante.Replace(wxT("#GENRE#"),valeur);
        la_belle->get_value_char(7,valeur,taille);
        fiche_courante.Replace(wxT("#ISBN#"),valeur);
        la_belle->get_value_char(8,valeur,taille);
        fiche_courante.Replace(wxT("#EDITEUR#"),valeur);
        la_belle->get_value_char(9,valeur,taille);
        fiche_courante.Replace(wxT("#DATE_PUBLICATION#"),valeur);
        la_belle->get_value_char(10,valeur,taille);
        fiche_courante.Replace(wxT("#PRIX#"),valeur);
        la_belle->get_value_char(11,valeur,taille);
        fiche_courante.Replace(wxT("#DATE_ACHAT#"),valeur);
        la_belle->get_value_char(12,valeur,taille);
        fiche_courante.Replace(wxT("#DATE_LECTURE#"),valeur);
        la_belle->get_value_char(13,valeur,taille);
        fiche_courante.Replace(wxT("#NOTE#"),valeur);
        la_belle->get_value_char(14,valeur,taille);
        fiche_courante.Replace(wxT("#PARTICULARITE#"),valeur);
        la_belle->get_value_char(15,valeur,taille);
        valeur.Replace("\n","<BR>\n");
        fiche_courante.Replace(wxT("#RESUME#"),valeur);
        la_belle->get_value_char(16,valeur,taille);
        valeur.Replace("\n","<BR>\n");
        fiche_courante.Replace(wxT("#COMMENTAIRE#"),valeur);
        la_belle->get_value_char(17,valeur,taille);
        fiche_courante.Replace(wxT("#DATE_ENTREE#"),valeur);
        la_belle->get_value_char(18,valeur,taille);
        fiche_courante.Replace(wxT("#DATE_MAJ#"),valeur);

        // génération des images
        wxString l_images="";
        nomfich=wxT("cover_")+id_courant+wxT("_recto.jpg");
        fichier.Open(chemin_image+nomfich,wxFile::write);
        ret=la_belle->get_value_blob(19,&fichier,taille);
        if (taille > 0) {
            l_images=l_images+ligne_image;
            l_images.Replace(wxT("#NOM_IMAGE#"),nomfich);
        }
                
        nomfich=wxT("cover_")+id_courant+wxT("_verso.jpg");
        fichier.Open(chemin_image+nomfich,wxFile::write);
        ret=la_belle->get_value_blob(20,&fichier,taille);
        if (taille > 0) {
            l_images=l_images+ligne_image;
            l_images.Replace(wxT("#NOM_IMAGE#"),nomfich);
        }
        fiche_courante.Replace(wxT("#IMAGES#"),l_images);
        
        convert_html(fiche_courante);

        // sauvegarde de la fiche
        nomfich=chemin_fiche+wxT("bk_")+id_courant+wxT(".html");
        fichier.Open(nomfich,wxFile::write);
        fichier.Write(fiche_courante);
        fichier.Close();

       ret=la_belle->transac_step();
    }
    la_belle->transac_fin();
}

void export_html_dlg::creation_fiches_auteurs(wxString chemin_fiches, wxString chemin_listes, wxString &fiche) {
    wxString query, mess, caractere;
    wxString valeur, nomfich, nomfich_liste;
    wxString fiche_courante, tableau_fiche, cellule;
    wxString liste_courante, liste_complete, tableau_liste, tableau_liste_complete;
    wxString id_ancien, id_courant,nom_auteur, nom_auteur_ancien;
    int ret, taille;
    wxFile *fichier=NULL;
    wxFile *fichier_liste=NULL;
    wxString couleur=wxT("clair");
    wxString chaine_tableau;
    
    if (WxRadioBox_type->GetSelection() == MODE_AJAX) {
        chaine_tableau=wxT("<tr onClick=\"javascript:goAccueil('book','#ID_LIVRE#')\"> \n");
    } else if(WxRadioBox_type->GetSelection() == MODE_HTML || WxRadioBox_type->GetSelection() == MODE_HTML_PDA){
        chaine_tableau=wxT("<tr onClick=\"javascript:parent.goAccueil('content/books/fiches/bk_#ID_LIVRE#.html')\"> \n");
    }
    
    chaine_tableau=chaine_tableau+wxT("#CELLULES# </tr>\n");
    wxString template_ligne=wxT("<td class=\"#COULEUR#\">#DONNEE#</td> \n");

    query=wxT("SELECT livre.id_auteur, livre.rowid, auteur.nom, livre.titre, serie.nom, livre.no_serie ");
    query=query+wxT(" FROM livre, auteur ");
    query=query+wxT(" LEFT JOIN serie ON livre.id_serie=serie.rowid ");
    query=query+wxT(" WHERE livre.id_auteur=auteur.rowid ");
    query=query+wxT(" ORDER BY auteur.nom, serie.nom,  livre.no_serie, livre.titre ");
    
    ret=la_belle->transac_prepare(query);
    if (ret<0) {
        la_belle->get_erreur(mess);
        wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
    }
    
    ret=la_belle->transac_step();
    if (ret<0) {
        la_belle->get_erreur(mess);
        wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
    }
    id_ancien=wxT("");
    nom_auteur_ancien=wxT("");
    tableau_fiche=wxT("");
    tableau_liste=wxT("");
    tableau_liste_complete=wxT("");
    liste_complete=fiche;
    while(ret==SQLITE_ROW ) {
        la_belle->get_value_char(0,id_courant,taille);
        la_belle->get_value_char(2,nom_auteur,taille);
        // liste par auteur
        if (id_courant.CompareTo(id_ancien) != 0) {
            nomfich=chemin_fiches+wxT("au_")+id_courant+wxT(".html");
            nomfich_liste=chemin_listes+wxT("list_")+nom_auteur.Mid(0,1)+wxT(".html");
            if (fichier == NULL) {
                fichier = new wxFile();
                fichier->Open(nomfich,wxFile::write);
            } else {
                fiche_courante.Replace(wxT("#TABLEAU_LIVRE#"),tableau_fiche);
                tableau_fiche=wxT("");
                convert_html(fiche_courante);
                fichier->Write(fiche_courante);
                fichier->Close();
                fichier->Open(nomfich,wxFile::write);
            }
            fiche_courante=fiche;
            fiche_courante.Replace(wxT("#TITRE#"),wxT("Liste des livres écrits par : ")+nom_auteur);
        }
        //liste par lettre
        if (nom_auteur.Mid(0,1).CompareTo(nom_auteur_ancien.Mid(0,1)) != 0){
            //wxMessageBox("a:"+nom_auteur+" ac:"+nom_auteur_ancien,"probleme", wxOK | wxICON_EXCLAMATION, this);
            if (fichier_liste == NULL) {
                fichier_liste = new wxFile();
                fichier_liste->Open(nomfich_liste,wxFile::write);
            } else {
                liste_courante.Replace(wxT("#TABLEAU_LIVRE#"),tableau_liste);
                tableau_liste=wxT("");
                convert_html(liste_courante);
                fichier_liste->Write(liste_courante);
                fichier_liste->Close();
                fichier_liste->Open(nomfich_liste,wxFile::write);
            }
            liste_courante=fiche;
            liste_courante.Replace(wxT("#TITRE#"),wxT("Liste des livres dont le nom de l'auteur commence par la lettre ")+nom_auteur.Mid(0,1));
       }
        tableau_fiche=tableau_fiche+chaine_tableau;
        tableau_liste=tableau_liste+chaine_tableau;
        tableau_liste_complete=tableau_liste_complete+chaine_tableau;
        la_belle->get_value_char(1,valeur,taille);
        tableau_fiche.Replace(wxT("#ID_LIVRE#"),valeur);
        tableau_liste.Replace(wxT("#ID_LIVRE#"),valeur);
        tableau_liste_complete.Replace(wxT("#ID_LIVRE#"),valeur);
        wxString cellules=wxT("");
        for (int i=2;i<6;i++) {
            la_belle->get_value_char(i,valeur,taille);
            cellule=template_ligne;
            cellule.Replace(wxT("#COULEUR#"), couleur);
            cellule.Replace(wxT("#DONNEE#"), valeur);
            cellules=cellules+cellule;
        }
        tableau_fiche.Replace(wxT("#CELLULES#"),cellules);
        tableau_liste.Replace(wxT("#CELLULES#"),cellules);
        tableau_liste_complete.Replace(wxT("#CELLULES#"),cellules);
        ret=la_belle->transac_step();
        if(couleur.CompareTo(wxT("clair")) == 0) {
            couleur=wxT("fonce");
        }
        else {
            couleur=wxT("clair");
        }
        id_ancien=id_courant;
        nom_auteur_ancien=nom_auteur;
    }
    if (fichier != NULL) {
        fiche_courante.Replace(wxT("#TABLEAU_LIVRE#"),tableau_fiche);
        tableau_fiche=wxT("");
        convert_html(fiche_courante);
        fichier->Write(fiche_courante);
        fichier->Close();
    }
    if (fichier_liste != NULL) {
        liste_courante.Replace(wxT("#TABLEAU_LIVRE#"),tableau_liste);
        tableau_liste=wxT("");
        convert_html(liste_courante);
        fichier_liste->Write(liste_courante);
        fichier_liste->Close();
        liste_complete.Replace(wxT("#TITRE#"),wxT("Liste de tous les livres"));
        liste_complete.Replace(wxT("#TABLEAU_LIVRE#"),tableau_liste_complete);
        fichier_liste->Open(chemin_listes+"liste_complete.html",wxFile::write);
        convert_html(liste_complete);
        fichier_liste->Write(liste_complete);
        fichier_liste->Close();
    }
    
    la_belle->transac_fin();
    if (fichier != NULL) {
        fichier->Close();
    }
    
}


/*
 * creation_tree_auteur
 *    Création de l'arbre utilisé par ajax
 */
void export_html_dlg::creation_tree_auteur(wxString &arbre) {
    wxString modele_lettre, modele_auteur;
    wxString query, mess, caractere;
    wxString id_auteur, nom_auteur, chaine;
    int taille, ret;
    
    if (WxRadioBox_type->GetSelection() == MODE_AJAX) {
        arbre=wxT("racine_auteur = insFld(foldersTree, gFld(\"Auteurs\", \"javascript:goAccueil(\\\"authors_root\\\")\"))\n");
    } else if(WxRadioBox_type->GetSelection() == MODE_HTML || WxRadioBox_type->GetSelection() == MODE_HTML_PDA){
        arbre=wxT("racine_auteur = insFld(foldersTree, gFld(\"Auteurs\", \"javascript:goAccueil(\\\"content/authors/listes/liste_complete.html\\\")\"))\n");
    }

    if (WxRadioBox_type->GetSelection() == MODE_AJAX) {
        modele_lettre=wxT("rac_#LET# = insFld(racine_auteur, gFld(\"#LET#\", \"javascript:goAccueil(\\\"authors\\\",\\\"#LET#\\\")\"))\n");
    } else if(WxRadioBox_type->GetSelection() == MODE_HTML || WxRadioBox_type->GetSelection() == MODE_HTML_PDA){
        modele_lettre=wxT("rac_#LET# = insFld(racine_auteur, gFld(\"#LET#\", \"javascript:goAccueil(\\\"content/authors/listes/list_#LET#.html\\\")\"))\n");
    }
    
    if (WxRadioBox_type->GetSelection() == MODE_AJAX) {
        modele_auteur=wxT("insDoc(rac_#LET#, gLnk(\"S\", \"#nom_auteur#\", \"javascript:goAccueil('author','#id_auteur#')\"))\n");
    } else if(WxRadioBox_type->GetSelection() == MODE_HTML || WxRadioBox_type->GetSelection() == MODE_HTML_PDA){
        modele_auteur=wxT("insDoc(rac_#LET#, gLnk(\"S\", \"#nom_auteur#\", \"javascript:goAccueil('content/authors/fiches/au_#id_auteur#.html')\"))\n");
    }

    
    for (char i='A';i<='Z';i++) {
        query=wxT("SELECT livre.id_auteur, auteur.nom FROM livre, auteur WHERE livre.id_auteur = auteur.rowid AND (auteur.nom LIKE '#L_MINUS#\%' OR auteur.nom LIKE '#L_MAJUS#\%') GROUP BY auteur.rowid ORDER BY auteur.nom");
        caractere.Printf("%c",i);
        query.Replace(wxT("#L_MAJUS#"),caractere);
        caractere.Printf("%c",i+32);
        query.Replace(wxT("#L_MINUS#"),caractere);
        ret=la_belle->transac_prepare(query);
        if (ret<0) {
            la_belle->get_erreur(mess);
            wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        }
        ret=la_belle->transac_step();
        if (ret<0) {
            la_belle->get_erreur(mess);
            wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        }
        if (ret==SQLITE_ROW) {
            chaine=modele_lettre;
            caractere.Printf("%c",i);
            chaine.Replace(wxT("#LET#"),caractere);
            arbre=arbre+chaine;
        }
        while(ret==SQLITE_ROW ) {
            la_belle->get_value_char(0,id_auteur,taille);
            la_belle->get_value_char(1,nom_auteur,taille);
            convert_quote(nom_auteur);
            chaine=modele_auteur;
            chaine.Replace(wxT("#LET#"),caractere);
            chaine.Replace(wxT("#nom_auteur#"),nom_auteur);
            chaine.Replace(wxT("#id_auteur#"),id_auteur);
            arbre=arbre+chaine;
            //wxMessageBox(nom_auteur,id_auteur, wxOK | wxICON_EXCLAMATION, this);
            ret=la_belle->transac_step();
            if (ret<0) {
                la_belle->get_erreur(mess);
                wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
            }
        }
        la_belle->transac_fin();
    }
        //wxMessageBox(arbre,"arbre", wxOK | wxICON_EXCLAMATION, this);
    
}


/*
 * creation_tree_titre
 *    Création de l'arbre utilisé par ajax
 */
void export_html_dlg::creation_tree_titre(wxString &arbre, wxString chemin_listes, wxString &fiche) {
    wxString modele_lettre, modele_titre;
    wxString query, mess, caractere, valeur;
    wxString nomfich_liste;
    wxString id_livre , titre_livre, chaine;
    wxString liste_courante, tableau_liste, cellule;
    wxString couleur=wxT("clair");
    wxString chaine_tableau;
    wxFile *fichier_liste=NULL;
    int taille, ret;

    // pour l'arbre
    if (WxRadioBox_type->GetSelection() == MODE_AJAX) {
        arbre=wxT("racine_titre = insFld(foldersTree, gFld(\"Titres\", \"javascript:goAccueil(\\\"authors_root\\\")\"))\n");
    } else if(WxRadioBox_type->GetSelection() == MODE_HTML || WxRadioBox_type->GetSelection() == MODE_HTML_PDA){
        arbre=wxT("racine_titre = insFld(foldersTree, gFld(\"Titres\", \"javascript:goAccueil(\\\"content/authors/listes/liste_complete.html\\\")\"))\n");
    }

    if (WxRadioBox_type->GetSelection() == MODE_AJAX) {
        modele_lettre=wxT("rac_#LET# = insFld(racine_titre, gFld(\"#LET#\", \"javascript:goAccueil(\\\"books\\\",\\\"#LET#\\\")\"))\n");
    } else if(WxRadioBox_type->GetSelection() == MODE_HTML || WxRadioBox_type->GetSelection() == MODE_HTML_PDA){
        modele_lettre=wxT("rac_#LET# = insFld(racine_titre, gFld(\"#LET#\", \"javascript:goAccueil(\\\"content/books/listes/list_#LET#.html\\\")\"))\n");
    }
    if (WxRadioBox_type->GetSelection() == MODE_AJAX) {
        modele_titre=wxT("insDoc(rac_#LET#, gLnk(\"S\", \"#TITRE_LIVRE#\", \"javascript:goAccueil('book','#ID_LIVRE#')\"))\n");
    } else if(WxRadioBox_type->GetSelection() == MODE_HTML || WxRadioBox_type->GetSelection() == MODE_HTML_PDA){
        modele_titre=wxT("insDoc(rac_#LET#, gLnk(\"S\", \"#TITRE_LIVRE#\", \"javascript:goAccueil('content/books/fiches/bk_#ID_LIVRE#.html')\"))\n");
    }
    
    // pour les listes
    if (WxRadioBox_type->GetSelection() == MODE_AJAX) {
        chaine_tableau=wxT("<tr onClick=\"javascript:goAccueil('book','#ID_LIVRE#')\"> \n");
    } else if(WxRadioBox_type->GetSelection() == MODE_HTML || WxRadioBox_type->GetSelection() == MODE_HTML_PDA){
        chaine_tableau=wxT("<tr onClick=\"javascript:parent.goAccueil('content/books/fiches/bk_#ID_LIVRE#.html')\"> \n");
    }
    chaine_tableau=chaine_tableau+wxT("#CELLULES# </tr>\n");
    wxString template_ligne=wxT("<td class=\"#COULEUR#\">#DONNEE#</td> \n");


    for (char i='0';i<='Z';i++) {
        if (i>'9' && i< 'A')
            continue;
        query=wxT("SELECT livre.rowid, auteur.nom, livre.titre, serie.nom, livre.no_serie  ");
        query=query+wxT("FROM livre, auteur ");
        query=query+wxT(" LEFT JOIN serie ON livre.id_serie=serie.rowid ");
        query=query+wxT("WHERE (livre.titre LIKE '#L_MINUS#\%' OR livre.titre LIKE '#L_MAJUS#\%') ");
        query=query+wxT("AND livre.id_auteur=auteur.rowid  ");
        query=query+wxT("ORDER BY livre.titre");
        caractere.Printf("%c",i);
        query.Replace(wxT("#L_MAJUS#"),caractere);
        if (i>='A' && i<='Z')
            caractere.Printf("%c",i+32);
        else
            caractere.Printf("%c",i);
        query.Replace(wxT("#L_MINUS#"),caractere);
        ret=la_belle->transac_prepare(query);
        if (ret<0) {
            la_belle->get_erreur(mess);
            wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        }
        ret=la_belle->transac_step();
        if (ret<0) {
            la_belle->get_erreur(mess);
            wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        }
        if (ret==SQLITE_ROW) {
            chaine=modele_lettre;
            caractere.Printf("%c",i);
            chaine.Replace(wxT("#LET#"),caractere);
            arbre=arbre+chaine;
        }
        tableau_liste=wxT("");
        liste_courante=fiche;
        liste_courante.Replace(wxT("#TITRE#"),wxT("Liste des livres dont le nom de titre commence par la lettre ")+caractere);
        while(ret==SQLITE_ROW ) {
            // arbre
            la_belle->get_value_char(0,id_livre,taille);
            la_belle->get_value_char(2,titre_livre,taille);
            chaine=modele_titre;
            chaine.Replace(wxT("#LET#"),caractere);
            convert_quote(titre_livre);
            chaine.Replace(wxT("#TITRE_LIVRE#"),titre_livre);
            chaine.Replace(wxT("#ID_LIVRE#"),id_livre);
            arbre=arbre+chaine;
            
            // liste
            tableau_liste=tableau_liste+chaine_tableau;
            la_belle->get_value_char(1,valeur,taille);
            tableau_liste.Replace(wxT("#ID_LIVRE#"),id_livre);
            wxString cellules=wxT("");
            for (int i=1;i<5;i++) {
                la_belle->get_value_char(i,valeur,taille);
                cellule=template_ligne;
                cellule.Replace(wxT("#COULEUR#"), couleur);
                cellule.Replace(wxT("#DONNEE#"), valeur);
                cellules=cellules+cellule;
            }
            tableau_liste.Replace(wxT("#CELLULES#"),cellules);
            if(couleur.CompareTo(wxT("clair")) == 0) {
                couleur=wxT("fonce");
            }
            else {
                couleur=wxT("clair");
            }
            
            ret=la_belle->transac_step();
            if (ret<0) {
                la_belle->get_erreur(mess);
                wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
            }
        }
        liste_courante.Replace(wxT("#TABLEAU_LIVRE#"),tableau_liste);
        convert_html(liste_courante);
        //wxMessageBox(liste_courante,"pouet", wxOK | wxICON_EXCLAMATION, this);
        nomfich_liste=chemin_listes+wxT("list_")+caractere+wxT(".html");
        fichier_liste = new wxFile();
        fichier_liste->Open(nomfich_liste,wxFile::write);
        fichier_liste->Write(liste_courante);
        fichier_liste->Close();
        
        la_belle->transac_fin();
    }

}

/*
 * creation_tree_titre
 *    Création de l'arbre utilisé par ajax
 */
void export_html_dlg::creation_tree_serie(wxString &arbre, wxString chemin_listes, wxString chemin_fiches, wxString &fiche) {
    wxString modele_lettre, modele_serie;
    wxString query, mess, caractere, valeur;
    wxString nomfich_liste, nomfich;
    wxString id_livre, id_serie, id_serie_ancien , serie_livre, serie_livre_ancien, chaine;
    wxString liste_courante, fiche_courante, tableau_liste, tableau_fiche, cellule;
    wxString couleur=wxT("clair");
    wxString chaine_tableau;
    wxFile *fichier_liste=NULL,*fichier_fiche=NULL;
    int taille, ret, nb_trouve;

    // pour l'arbre
    if (WxRadioBox_type->GetSelection() == MODE_AJAX) {
        arbre=wxT("racine_serie = insFld(foldersTree, gFld(\"Séries\", \"javascript:goAccueil(\\\"authors_root\\\")\"))\n");
    } else if(WxRadioBox_type->GetSelection() == MODE_HTML || WxRadioBox_type->GetSelection() == MODE_HTML_PDA){
        arbre=wxT("racine_serie = insFld(foldersTree, gFld(\"Séries\", \"javascript:goAccueil(\\\"content/authors/listes/liste_complete.html\\\")\"))\n");
    }

    if (WxRadioBox_type->GetSelection() == MODE_AJAX) {
        modele_lettre=wxT("rac_#LET# = insFld(racine_serie, gFld(\"#LET#\", \"javascript:goAccueil(\\\"series\\\",\\\"#LET#\\\")\"))\n");
    } else if(WxRadioBox_type->GetSelection() == MODE_HTML || WxRadioBox_type->GetSelection() == MODE_HTML_PDA){
        modele_lettre=wxT("rac_#LET# = insFld(racine_serie, gFld(\"#LET#\", \"javascript:goAccueil(\\\"content/series/listes/list_#LET#.html\\\")\"))\n");
    }
    if (WxRadioBox_type->GetSelection() == MODE_AJAX) {
        modele_serie=wxT("insDoc(rac_#LET#, gLnk(\"S\", \"#NOM_SERIE#\", \"javascript:goAccueil('serie','#ID_SERIE#')\"))\n");
    } else if(WxRadioBox_type->GetSelection() == MODE_HTML || WxRadioBox_type->GetSelection() == MODE_HTML_PDA){
        modele_serie=wxT("insDoc(rac_#LET#, gLnk(\"S\", \"#NOM_SERIE#\", \"javascript:goAccueil('content/series/fiches/se_#ID_SERIE#.html')\"))\n");
    }

    // pour les listes
    if (WxRadioBox_type->GetSelection() == MODE_AJAX) {
        chaine_tableau=wxT("<tr onClick=\"javascript:goAccueil('book','#ID_LIVRE#')\"> \n");
    } else if(WxRadioBox_type->GetSelection() == MODE_HTML || WxRadioBox_type->GetSelection() == MODE_HTML_PDA){
        chaine_tableau=wxT("<tr onClick=\"javascript:parent.goAccueil('content/books/fiches/bk_#ID_LIVRE#.html')\"> \n");
    }
    chaine_tableau=chaine_tableau+wxT("#CELLULES# </tr>\n");
    wxString template_ligne=wxT("<td class=\"#COULEUR#\">#DONNEE#</td> \n");

    fichier_fiche = new wxFile();

    serie_livre_ancien="";
    for (char i='0';i<='Z';i++) {
        if (i>'9' && i< 'A')
            continue;
        query=wxT("SELECT livre.rowid, livre.id_serie, auteur.nom, livre.titre, serie.nom, livre.no_serie  ");
        query=query+wxT("FROM livre, auteur ");
        query=query+wxT(" LEFT JOIN serie ON livre.id_serie=serie.rowid ");
        query=query+wxT("WHERE (serie.nom LIKE '#L_MINUS#\%' OR serie.nom LIKE '#L_MAJUS#\%') ");
        query=query+wxT("AND livre.id_auteur=auteur.rowid  ");
        query=query+wxT("ORDER BY serie.nom, livre.no_serie");
        caractere.Printf("%c",i);
        query.Replace(wxT("#L_MAJUS#"),caractere);
        if (i>='A' && i<='Z')
            caractere.Printf("%c",i+32);
        else
            caractere.Printf("%c",i);
        query.Replace(wxT("#L_MINUS#"),caractere);
        ret=la_belle->transac_prepare(query);
        if (ret<0) {
            la_belle->get_erreur(mess);
            wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        }
        ret=la_belle->transac_step();
        if (ret<0) {
            la_belle->get_erreur(mess);
            wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        }
        if (ret==SQLITE_ROW) {
            chaine=modele_lettre;
            caractere.Printf("%c",i);
            chaine.Replace(wxT("#LET#"),caractere);
            arbre=arbre+chaine;
        }
        tableau_liste=wxT("");
        liste_courante=fiche;
        liste_courante.Replace(wxT("#TITRE#"),wxT("Liste des livres dont la serie commence par la lettre ")+caractere);
        fiche_courante=fiche;
        nb_trouve=0;
        id_serie_ancien="";
        while(ret==SQLITE_ROW ) {
            nb_trouve++;
            // arbre
            la_belle->get_value_char(0,id_livre,taille);
            la_belle->get_value_char(1,id_serie,taille);
            la_belle->get_value_char(4,serie_livre,taille);
            convert_quote(serie_livre);
            if (serie_livre.CompareTo(serie_livre_ancien) != 0) {
                chaine=modele_serie;
                chaine.Replace(wxT("#LET#"),caractere);
                chaine.Replace(wxT("#NOM_SERIE#"),serie_livre);
                chaine.Replace(wxT("#ID_SERIE#"),id_serie);
                arbre=arbre+chaine;
            }
            // fiche
            if (id_serie.CompareTo(id_serie_ancien) != 0) {
                nomfich=chemin_fiches+wxT("se_")+id_serie+wxT(".html");
                if (fichier_fiche->IsOpened() == FALSE) {
                    fichier_fiche->Open(nomfich,wxFile::write);
                    tableau_fiche=wxT("");
                } else {
                    fiche_courante.Replace(wxT("#TABLEAU_LIVRE#"),tableau_fiche);
                    tableau_fiche=wxT("");
                    convert_html(fiche_courante);
                    fichier_fiche->Write(fiche_courante);
                    fichier_fiche->Close();
                    fichier_fiche->Open(nomfich,wxFile::write);
                }
                fiche_courante=fiche;
                fiche_courante.Replace(wxT("#TITRE#"),wxT("Liste des livres de la serie : ")+serie_livre);
            }
            // liste
            tableau_liste=tableau_liste+chaine_tableau;
            tableau_fiche=tableau_fiche+chaine_tableau;
            la_belle->get_value_char(1,valeur,taille);
            tableau_liste.Replace(wxT("#ID_LIVRE#"),id_livre);
            tableau_fiche.Replace(wxT("#ID_LIVRE#"),id_livre);
            wxString cellules=wxT("");
            for (int i=2;i<6;i++) {
                la_belle->get_value_char(i,valeur,taille);
                cellule=template_ligne;
                cellule.Replace(wxT("#COULEUR#"), couleur);
                cellule.Replace(wxT("#DONNEE#"), valeur);
                cellules=cellules+cellule;
            }
            tableau_liste.Replace(wxT("#CELLULES#"),cellules);
            tableau_fiche.Replace(wxT("#CELLULES#"),cellules);
            if(couleur.CompareTo(wxT("clair")) == 0) {
                couleur=wxT("fonce");
            }
            else {
                couleur=wxT("clair");
            }

            ret=la_belle->transac_step();
            if (ret<0) {
                la_belle->get_erreur(mess);
                wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
            }
            id_serie_ancien=id_serie;
            serie_livre_ancien=serie_livre;
        }
        if (nb_trouve >0) {
            //liste
            liste_courante.Replace(wxT("#TABLEAU_LIVRE#"),tableau_liste);
            convert_html(liste_courante);
            //wxMessageBox(liste_courante,"pouet", wxOK | wxICON_EXCLAMATION, this);
            nomfich_liste=chemin_listes+wxT("list_")+caractere+wxT(".html");
            fichier_liste = new wxFile();
            fichier_liste->Open(nomfich_liste,wxFile::write);
            fichier_liste->Write(liste_courante);
            fichier_liste->Close();
            //fiche
            fiche_courante.Replace(wxT("#TABLEAU_LIVRE#"),tableau_fiche);
            tableau_fiche=wxT("");
            convert_html(fiche_courante);
            fichier_fiche->Write(fiche_courante);
            fichier_fiche->Close();
        }

        la_belle->transac_fin();
    }

}

/*
 * WxButton_annulClick
 */
void export_html_dlg::WxButton_annulClick(wxCommandEvent& event)
{
	Destroy();
}

/*
 * WxButton_chemin_destClick
 *  changement du répertoire de destination
 */
void export_html_dlg::WxButton_chemin_destClick(wxCommandEvent& event)
{
    wxString query, mess;
    int ret;
    wxDirDialog choix_dest(this, wxT("répertoire de destination"), WxEdit_chemin_dest->GetValue());
    
    if (choix_dest.ShowModal() == wxID_OK) {
        //wxMessageBox("tyest","probleme", wxOK | wxICON_EXCLAMATION, this);
        wxString chemin=choix_dest.GetPath();
    	if (chemin[chemin.Length()-1]!=wxFileName::GetPathSeparator()) {
            chemin=chemin+wxFileName::GetPathSeparator();
        }
        if(la_belle->existe("config_export_html") == false )
        {
            query="CREATE TABLE config_export_html (type_param TEXT , nom_param TEXT, val1 TEXT, val2 TEXT)";
            ret=la_belle->exec_rapide(query);
            if (ret<0) {
                la_belle->get_erreur(mess);
                wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
            }
        }
        query="DELETE FROM config_export_html WHERE type_param='INIT' AND nom_param='REP_DEST'";
        ret=la_belle->exec_rapide(query);
        if (ret<0) {
            la_belle->get_erreur(mess);
            wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        }
        query="INSERT INTO config_export_html(type_param, nom_param, val1) VALUES ('INIT', 'REP_DEST', '"+chemin+"')";
        ret=la_belle->exec_rapide(query);
        if (ret<0) {
            la_belle->get_erreur(mess);
            wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        }
        WxEdit_chemin_dest->SetValue(chemin);
    }
	// insert your code here
}
