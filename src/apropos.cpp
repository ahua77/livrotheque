//---------------------------------------------------------------------------
//
// Name:        apropos.cpp
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
//
//---------------------------------------------------------------------------

#include <wx/settings.h>
#include "apropos.h"
#include <livrotheque_private.h>
#include "titre.xpm"
//Do not add custom headers.
//wx-dvcpp designer will remove them
////Header Include Start
////Header Include End



//----------------------------------------------------------------------------
// apropos
//----------------------------------------------------------------------------
     //Add Custom Events only in the appropriate Block.
    // Code added in  other places will be removed by wx-dvcpp 
    ////Event Table Start
BEGIN_EVENT_TABLE(apropos,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(apropos::aproposClose)
	EVT_BUTTON(wxID_CANCEL,apropos::WxButton1Click)
END_EVENT_TABLE()
    ////Event Table End
 


apropos::apropos( wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style )
    : wxDialog( parent, id, title, position, size, style)
{
    la_belle=NULL;
    CreateGUIControls();
}

apropos::apropos( ma_base *pour_insere, wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style )
    : wxDialog( parent, id, title, position, size, style)
{
    la_belle=pour_insere;
    CreateGUIControls();
}

apropos::~apropos() {} 

void apropos::CreateGUIControls(void)
{
    ma_base version;
    //Do not add custom Code here
    //wx-devcpp designer will remove them.
    //Add the custom code before or after the Blocks
    ////GUI Items Creation Start

	WxHyperLinkCtrl_URL = new wxHyperlinkCtrl(this, ID_WXHYPERLINKCTRL_URL, wxT("Site de livrothèque"), wxT("http://peepaillard.free.fr/"), wxPoint(7, 116), wxSize(205, 22), wxNO_BORDER | wxHL_CONTEXTMENU, wxT("WxHyperLinkCtrl_URL"));
	WxHyperLinkCtrl_URL->SetToolTip(wxT("accéder au site de livrothèque"));
	WxHyperLinkCtrl_URL->SetNormalColour(wxColour(0,0,255));
	WxHyperLinkCtrl_URL->SetFont(wxFont(12, wxSWISS, wxNORMAL, wxNORMAL, true, wxT("Arial")));

	WxStaticText_titre = new wxStaticText(this, ID_WXSTATICTEXT_TITRE, wxT("Version :"), wxPoint(216, 116), wxDefaultSize, 0, wxT("WxStaticText_titre"));
	WxStaticText_titre->SetFont(wxFont(12, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Arial")));

	WxNotebook1 = new wxNotebook(this, ID_WXNOTEBOOK1, wxPoint(4, 138), wxSize(399, 234), wxNB_DEFAULT);
	WxNotebook1->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxNoteBookPage_base = new wxPanel(WxNotebook1, ID_WXNOTEBOOKPAGE_BASE, wxPoint(4, 24), wxSize(391, 206));
	WxNoteBookPage_base->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));
	WxNotebook1->AddPage(WxNoteBookPage_base, wxT("Base"));

	WxStaticText_tnom_base = new wxStaticText(WxNoteBookPage_base, ID_WXSTATICTEXT_TNOM_BASE, wxT("Nom de la base : "), wxPoint(5, 15), wxDefaultSize, 0, wxT("WxStaticText_tnom_base"));
	WxStaticText_tnom_base->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_nom_base = new wxStaticText(WxNoteBookPage_base, ID_WXSTATICTEXT_NOM_BASE, wxT("nom"), wxPoint(90, 15), wxDefaultSize, 0, wxT("WxStaticText_nom_base"));
	WxStaticText_nom_base->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_tnb_livre = new wxStaticText(WxNoteBookPage_base, ID_WXSTATICTEXT_TNB_LIVRE, wxT("Nombre de livres dans la base :"), wxPoint(5, 60), wxDefaultSize, 0, wxT("WxStaticText_tnb_livre"));
	WxStaticText_tnb_livre->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_nb_livre = new wxStaticText(WxNoteBookPage_base, ID_WXSTATICTEXT_NB_LIVRE, wxT("nb"), wxPoint(160, 60), wxDefaultSize, 0, wxT("WxStaticText_nb_livre"));
	WxStaticText_nb_livre->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_ttaille_base = new wxStaticText(WxNoteBookPage_base, ID_WXSTATICTEXT_TTAILLE_BASE, wxT("Taille de la base :"), wxPoint(6, 38), wxDefaultSize, 0, wxT("WxStaticText_ttaille_base"));
	WxStaticText_ttaille_base->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_taille_base = new wxStaticText(WxNoteBookPage_base, ID_WXSTATICTEXT_TAILLE_BASE, wxT("taille"), wxPoint(98, 39), wxDefaultSize, 0, wxT("WxStaticText_taille_base"));
	WxStaticText_taille_base->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxNoteBookPage_tech = new wxPanel(WxNotebook1, ID_WXNOTEBOOKPAGE_tech, wxPoint(4, 24), wxSize(391, 206));
	WxNoteBookPage_tech->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));
	WxNotebook1->AddPage(WxNoteBookPage_tech, wxT("Technique"));

	WxStaticText_wx_tversion = new wxStaticText(WxNoteBookPage_tech, ID_WXSTATICTEXT_WX_TVERSION, wxT("WxWidget Version :"), wxPoint(14, 64), wxDefaultSize, 0, wxT("WxStaticText_wx_tversion"));
	WxStaticText_wx_tversion->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_wx_version = new wxStaticText(WxNoteBookPage_tech, ID_WXSTATICTEXT_WX_VERSION, wxT("1.0"), wxPoint(113, 65), wxDefaultSize, 0, wxT("WxStaticText_wx_version"));
	WxStaticText_wx_version->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_titre2 = new wxStaticText(WxNoteBookPage_tech, ID_WXSTATICTEXT_TITRE2, wxT("Créé en utilisant :"), wxPoint(7, 35), wxDefaultSize, 0, wxT("WxStaticText_titre2"));
	WxStaticText_titre2->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_sqlite_tversion = new wxStaticText(WxNoteBookPage_tech, ID_WXSTATICTEXT_SQLITE_TVERSION, wxT("Sqlite Version :"), wxPoint(12, 90), wxDefaultSize, 0, wxT("WxStaticText_sqlite_tversion"));
	WxStaticText_sqlite_tversion->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_sqlite_version = new wxStaticText(WxNoteBookPage_tech, ID_WXSTATICTEXT_SQLITE_VERSION, wxT("1.0"), wxPoint(86, 91), wxDefaultSize, 0, wxT("WxStaticText_sqlite_version"));
	WxStaticText_sqlite_version->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_tcurl = new wxStaticText(WxNoteBookPage_tech, ID_WXSTATICTEXT_TCURL, wxT("Curl Version :"), wxPoint(11, 118), wxDefaultSize, 0, wxT("WxStaticText_tcurl"));
	WxStaticText_tcurl->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_curl_version = new wxStaticText(WxNoteBookPage_tech, ID_WXSTATICTEXT_CURL_VERSION, wxT("1.0"), wxPoint(79, 119), wxDefaultSize, 0, wxT("WxStaticText_curl_version"));
	WxStaticText_curl_version->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxNoteBookPage_auteurs = new wxPanel(WxNotebook1, ID_WXNOTEBOOKPAGE_AUTEURS, wxPoint(4, 24), wxSize(391, 206));
	WxNoteBookPage_auteurs->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));
	WxNotebook1->AddPage(WxNoteBookPage_auteurs, wxT("Auteurs"));

	WxStaticText2 = new wxStaticText(WxNoteBookPage_auteurs, ID_WXSTATICTEXT2, wxT("Programmeur raleur : Fougny"), wxPoint(15, 31), wxDefaultSize, 0, wxT("WxStaticText2"));
	WxStaticText2->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText3 = new wxStaticText(WxNoteBookPage_auteurs, ID_WXSTATICTEXT3, wxT("Testeuse bugueuse : Esilenna"), wxPoint(14, 58), wxDefaultSize, 0, wxT("WxStaticText3"));
	WxStaticText3->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText4 = new wxStaticText(WxNoteBookPage_auteurs, ID_WXSTATICTEXT4, wxT("Maitre de la connexion et des statistiques : Ricco"), wxPoint(15, 85), wxDefaultSize, 0, wxT("WxStaticText4"));
	WxStaticText4->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText5 = new wxStaticText(WxNoteBookPage_auteurs, ID_WXSTATICTEXT5, wxT("Graphiste bougon : Shmirkin"), wxPoint(16, 116), wxDefaultSize, 0, wxT("WxStaticText5"));
	WxStaticText5->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText1 = new wxStaticText(WxNoteBookPage_auteurs, ID_WXSTATICTEXT1, wxT("Et merci à tous les forumeurs pour leurs remarques aussi diverses que variées."), wxPoint(11, 173), wxDefaultSize, 0, wxT("WxStaticText1"));
	WxStaticText1->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	/* Information sur la license de livrotheque
	*/
	WxNoteBookPage_license = new wxPanel(WxNotebook1, ID_WXNOTEBOOKPAGE_LICENSE, wxPoint(4, 24), wxSize(391, 206));
	WxNoteBookPage_license->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));
	WxNotebook1->AddPage(WxNoteBookPage_license, wxT("License"));

	WxMemo_license = new wxTextCtrl(WxNoteBookPage_license, ID_WXMEMO_LICENSE, wxEmptyString, wxPoint(1, 2), wxSize(388, 204), wxTE_READONLY | wxTE_AUTO_URL | wxTE_MULTILINE, wxDefaultValidator, wxT("WxMemo_license"));
	WxMemo_license->SetMaxLength(0);
	WxMemo_license->AppendText(wxT("Copyright PE Epaillard , 01/01/2005\n"));
	WxMemo_license->AppendText(wxT("\n"));
	WxMemo_license->AppendText(wxT("fougny@gmail.com\n"));
	WxMemo_license->AppendText(wxT("\n"));
	WxMemo_license->AppendText(wxT("Ce logiciel est un programme informatique servant à Gérer \n"));
	WxMemo_license->AppendText(wxT("une bibliothèque personnelle. \n"));
	WxMemo_license->AppendText(wxT("\n"));
	WxMemo_license->AppendText(wxT("Ce logiciel est régi par la licence CeCILL soumise au droit français et\n"));
	WxMemo_license->AppendText(wxT("respectant les principes de diffusion des logiciels libres. Vous pouvez\n"));
	WxMemo_license->AppendText(wxT("utiliser, modifier et/ou redistribuer ce programme sous les conditions\n"));
	WxMemo_license->AppendText(wxT("de la licence CeCILL telle que diffusée par le CEA, le CNRS et l'INRIA \n"));
	WxMemo_license->AppendText(wxT("sur le site \"http://www.cecill.info\".\n"));
	WxMemo_license->AppendText(wxT("\n"));
	WxMemo_license->AppendText(wxT("En contrepartie de l'accessibilité au code source et des droits de copie,\n"));
	WxMemo_license->AppendText(wxT("de modification et de redistribution accordés par cette licence, il n'est\n"));
	WxMemo_license->AppendText(wxT("offert aux utilisateurs qu'une garantie limitée.  Pour les mêmes raisons,\n"));
	WxMemo_license->AppendText(wxT("seule une responsabilité restreinte pèse sur l'auteur du programme,  le\n"));
	WxMemo_license->AppendText(wxT("titulaire des droits patrimoniaux et les concédants successifs.\n"));
	WxMemo_license->AppendText(wxT("\n"));
	WxMemo_license->AppendText(wxT("A cet égard  l'attention de l'utilisateur est attirée sur les risques\n"));
	WxMemo_license->AppendText(wxT("associés au chargement,  à l'utilisation,  à la modification et/ou au\n"));
	WxMemo_license->AppendText(wxT("développement et à la reproduction du logiciel par l'utilisateur étant \n"));
	WxMemo_license->AppendText(wxT("donné sa spécificité de logiciel libre, qui peut le rendre complexe à \n"));
	WxMemo_license->AppendText(wxT("manipuler et qui le réserve donc à des développeurs et des professionnels\n"));
	WxMemo_license->AppendText(wxT("avertis possédant  des  connaissances  informatiques approfondies.  Les\n"));
	WxMemo_license->AppendText(wxT("utilisateurs sont donc invités à charger  et  tester  l'adéquation  du\n"));
	WxMemo_license->AppendText(wxT("logiciel à leurs besoins dans des conditions permettant d'assurer la\n"));
	WxMemo_license->AppendText(wxT("sécurité de leurs systèmes et ou de leurs données et, plus généralement, \n"));
	WxMemo_license->AppendText(wxT("à l'utiliser et l'exploiter dans les mêmes conditions de sécurité. \n"));
	WxMemo_license->AppendText(wxT("\n"));
	WxMemo_license->AppendText(wxT("Le fait que vous puissiez accéder à cet en-tête signifie que vous avez \n"));
	WxMemo_license->AppendText(wxT("pris connaissance de la licence CeCILL, et que vous en avez accepté les\n"));
	WxMemo_license->AppendText(wxT("termes.\n"));
	WxMemo_license->SetFocus();
	WxMemo_license->SetInsertionPointEnd();
	WxMemo_license->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_nver = new wxStaticText(this, ID_WXSTATICTEXT_NVER, wxT("1.0"), wxPoint(284, 116), wxDefaultSize, 0, wxT("WxStaticText_nver"));
	WxStaticText_nver->SetFont(wxFont(12, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Arial")));

	WxButton2 = new wxButton(this, wxID_CANCEL, wxT("OK"), wxPoint(145, 372), wxSize(96, 34), 0, wxDefaultValidator, wxT("WxButton2"));
	WxButton2->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	SetTitle(wxT("a propos"));
	SetIcon(wxNullIcon);
	SetSize(8,8,421,448);
	Center();
	
    ////GUI Items Creation End
	wxBitmap WxStaticBitmap_titre_BITMAP(titre_xpm);
	WxStaticBitmap_titre = new wxStaticBitmap(this, ID_WXSTATICBITMAP_TITRE, WxStaticBitmap_titre_BITMAP, wxPoint(10,0), wxSize(385,116));
	WxStaticBitmap_titre->Enable(false);
    WxStaticText_nver->SetLabel(VER_STRING);
    WxStaticText_wx_version->SetLabel(wxVERSION_STRING);
    WxStaticText_sqlite_version->SetLabel(version.get_version());
    WxStaticText_curl_version->SetLabel(curl_version());
    if (la_belle == NULL || la_belle->ouverte() == false) {
        WxNotebook1->DeletePage(1);
    } else {
        init_donnee_base();
    }
    WxMemo_license->ShowPosition(1);
    //WxMemo_URL->SetBackgroundColour(this->GetBackgroundColour());
//    WxMemo_URL->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNHIGHLIGHT));
    //WxMemo_URL->Refresh();
}
void apropos::init_donnee_base() {
    wxFileName le_fichier(la_belle->ma_base::get_nombase());
    wxString query, texte, taille_for, tampon;
    int ret, taille;
    wxFile fichier;
    //double t_fichier;
    
    // nom de la base
    WxStaticText_nom_base->SetLabel(le_fichier.GetFullName());
    
    // taille de la base
    if (fichier.Open(la_belle->ma_base::get_nombase(), wxFile::read) == false) {
        wxMessageBox("plouf","coco", wxOK | wxICON_INFORMATION, this);
    }
    texte.Printf("%.lf",(fichier.Length()/1024.0));
    taille_for="";
    while (texte.Length() > 0) {
        taille =texte.Length()-3;
        tampon=taille_for;
        if (taille < 0)
            taille=0;
        //taille_for.Printf("% %",texte.Mid(taille), taille_for);
        taille_for=texte.Mid(taille)+ " " + tampon;
        texte.Truncate(taille);
        //wxMessageBox(taille_for + "|" + texte,"coco", wxOK | wxICON_INFORMATION, this);
    }
        
    WxStaticText_taille_base->SetLabel(taille_for + " Ko");

    // on compte le nombre de livres
    query="Select count(*) from livre";
    ret=la_belle->transac_prepare(query);
    if (ret>=0) {
        ret=la_belle->transac_step();
    }
    if (ret==SQLITE_ROW) {
        la_belle->get_value_char(0,texte,taille);
    }
    la_belle->transac_fin();
    WxStaticText_nb_livre->SetLabel(texte);
}
void apropos::aproposClose(wxCloseEvent& event)
{
    // --> Don't use Close with a wxDialog,
    // use Destroy instead.
    Destroy();
}
 

/*
 * WxButton1Click
 */
void apropos::WxButton1Click(wxCommandEvent& event)
{
	// insert your code here
    Destroy();
	event.Skip();
}

/*
 * WxMemo1ClickUrl
 */
void apropos::WxMemo1ClickUrl(wxTextUrlEvent& event)
{
    wxMouseEvent souris=event.GetMouseEvent();
    
    if (souris.m_leftDown == true) {
        ::wxLaunchDefaultBrowser("http://peepaillard.free.fr/");
//        ::wxShell("start "+WxMemo_URL->GetValue()+"");
    }
	// insert your code here
    souris.Skip();
	event.Skip();
}

/*
 * WxButton_siteClick
 */
void apropos::WxButton_siteClick(wxCommandEvent& event)
{
	// insert your code here
	::wxLaunchDefaultBrowser("http://peepaillard.free.fr/");
}
