//---------------------------------------------------------------------------
//
// Name:        recherche.cpp
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

#ifdef __GNUG__
    #pragma implementation "recherche.cpp"
#endif

/* for compilers that support precompilation
   includes "wx/wx.h" */

#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif


#include "recherche.h"

////Header Include Start
////Header Include End


long recherche::s_nbInstances = 0;

//----------------------------------------------------------------------------
// recherche
//----------------------------------------------------------------------------

    ////Event Table Start
BEGIN_EVENT_TABLE(recherche,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(recherche::rechercheClose)
	EVT_BUTTON(wxID_CANCEL,recherche::WxButton_rech_annulClick)
	EVT_BUTTON(wxID_OK,recherche::OnOk)
END_EVENT_TABLE()
    ////Event Table End


recherche::recherche( wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style )
    : wxDialog( parent, id, title, position, size, style)
{
    s_nbInstances++;
    wxLogMessage("recherche::recherche() - nbInstances = %ld", s_nbInstances);

    CreateGUIControls();
    init_tout();
}

recherche::~recherche()
{
    s_nbInstances--;
    wxLogMessage("recherche::~recherche() - nbInstances = %ld", s_nbInstances);
} 

void recherche::CreateGUIControls(void)
{
    ////GUI Items Creation Start

	wxBoxSizer* WxBoxSizer_fond = new wxBoxSizer(wxVERTICAL);
	this->SetSizer(WxBoxSizer_fond);
	this->SetAutoLayout(TRUE);

	WxScrolledWindow1 = new wxScrolledWindow(this, ID_WXSCROLLEDWINDOW1, wxPoint(5,5), wxSize(350,200), wxVSCROLL | wxHSCROLL);
	WxBoxSizer_fond->Add(WxScrolledWindow1,1,wxALIGN_CENTER_HORIZONTAL | wxALL,5);

	wxArrayString arrayStringFor_WxComboBox_champ;
	WxComboBox_champ = new wxComboBox(WxScrolledWindow1, ID_WXCOMBOBOX_CHAMP, wxT(""), wxPoint(16,24), wxSize(260,21), arrayStringFor_WxComboBox_champ, wxCB_READONLY, wxDefaultValidator, wxT("WxComboBox_champ"));

	WxEdit_texte = new wxTextCtrl(WxScrolledWindow1, ID_WXEDIT_TEXTE, wxT(""), wxPoint(16,75), wxSize(260,21), 0, wxDefaultValidator, wxT("WxEdit_texte"));
	WxEdit_texte->SetMaxLength(0);

	WxStaticText_champ = new wxStaticText(WxScrolledWindow1, ID_WXSTATICTEXT_CHAMP, wxT("Champs sur lequel effectuer la recherche :"), wxPoint(7,4), wxSize(203,17), 0, wxT("WxStaticText_champ"));

	WxStaticText_texte = new wxStaticText(WxScrolledWindow1, ID_WXSTATICTEXT_TEXTE, wxT("Texte à rechercher :"), wxPoint(7,54), wxSize(100,17), 0, wxT("WxStaticText_texte"));

	WxRadioButton_type_et = new wxRadioButton(WxScrolledWindow1, ID_WXRADIOBUTTON_TYPE_ET, wxT("Type ET"), wxPoint(16,122), wxSize(117,32), 0, wxDefaultValidator, wxT("WxRadioButton_type_et"));
	WxRadioButton_type_et->SetToolTip(wxT("Tous Les mots doivent être présent Dans le champ"));
	WxRadioButton_type_et->SetValue(true);

	WxRadioButton_type_ou = new wxRadioButton(WxScrolledWindow1, ID_WXRADIOBUTTON_TYPE_OU, wxT("Type OU"), wxPoint(16,145), wxSize(118,25), 0, wxDefaultValidator, wxT("WxRadioButton_type_ou"));
	WxRadioButton_type_ou->SetToolTip(wxT("Un des mots doit être présent dans le champ"));

	WxStaticText_type = new wxStaticText(WxScrolledWindow1, ID_WXSTATICTEXT_TYPE, wxT("Type de recherche à utiliser :"), wxPoint(7,106), wxSize(141,17), 0, wxT("WxStaticText_type"));

	wxBoxSizer* WxBoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer_fond->Add(WxBoxSizer1,0,wxALIGN_CENTER_HORIZONTAL | wxALL,5);

	WxButton_rech_ok = new wxButton(this, wxID_OK, wxT("OK"), wxPoint(5,5), wxSize(80,28), 0, wxDefaultValidator, wxT("WxButton_rech_ok"));
	WxBoxSizer1->Add(WxButton_rech_ok,0,wxALIGN_CENTER_VERTICAL | wxALL,5);

	WxButton_rech_annul = new wxButton(this, wxID_CANCEL, wxT("Annuler"), wxPoint(95,5), wxSize(80,28), 0, wxDefaultValidator, wxT("WxButton_rech_annul"));
	WxBoxSizer1->Add(WxButton_rech_annul,0,wxALIGN_CENTER_VERTICAL | wxALL,5);

	GetSizer()->Fit(this);
	GetSizer()->SetSizeHints(this);
	this->SetTitle(wxT("recherche"));
	this->Center();
	this->SetIcon(wxNullIcon);
	
    ////GUI Items Creation End
}

void recherche::rechercheClose(wxCloseEvent& event)
{
    // --> Don't use Close with a wxDialog,
    // use Destroy instead.
    Destroy();
}
 
/*
 * WxButton_rech_annulClick
 */
void recherche::WxButton_rech_annulClick(wxCommandEvent& event)
{
    // insert your code here
    Destroy();
    event.Skip();
}

void recherche::init_tout()
{
    livre monlivre;
    wxString texte;
    int i=0;

    liste_sel.Clear();
    WxComboBox_champ->Clear();
    
    while(monlivre.get_nom_token(i).Length() > 0) {
        texte=monlivre.get_nom_token(i);
        if(texte.Left(6) != "image_") {
            liste_sel.Add(texte);
            if (texte.Left(3) == "id_") 
                WxComboBox_champ->Append(texte.Mid(3));
            else
                WxComboBox_champ->Append(texte);
        }    
        i++;
    }
    WxComboBox_champ->SetSelection(0);
}

void recherche::OnOk(wxCommandEvent& event)
{
    wxString mess;
    int n_sel, i;
    wxString recherche, tempo;
    wxArrayString liste_cherche;

    n_sel=WxComboBox_champ->GetSelection();
    
    recherche = string_nettoie(WxEdit_texte->GetValue());

    //wxMessageBox(nom_champ+" |"+recherche+"|","coco0", wxOK | wxICON_INFORMATION, this);

    // création de la liste de mots à rechercher
    i=recherche.Find(' ');
    while( i > 0) {
        liste_cherche.Add(recherche.Left(i));
        tempo=recherche.Mid(i+1);
        recherche=tempo;
        //wxMessageBox("cherche |"+recherche+"|","coco1", wxOK | wxICON_INFORMATION, this);
        i=recherche.Find(' ');
    }
    if (recherche.Len()>0)
        liste_cherche.Add(recherche);
/*    for (i=0;i<liste_cherche.GetCount();i++)
        wxMessageBox(" |"+liste_cherche[i]+"|","coco2", wxOK | wxICON_INFORMATION, this);

    if (liste_cherche.GetCount() <= 0) {
        wxMessageBox(" |"+liste_cherche[i]+"|","coco2", wxOK | wxICON_INFORMATION, this);
    }
    */
    if (liste_sel[n_sel].Left(3) == "id_") {
        creation_where_id(liste_sel[n_sel], liste_cherche);
        //wxMessageBox("ID "+liste_sel[n_sel],"coco3", wxOK | wxICON_INFORMATION, this);
    } else {
        creation_where_simple(liste_sel[n_sel], liste_cherche);
    }

    Destroy();
    event.Skip();
}

void recherche::creation_where_id(wxString nom_champ, wxArrayString liste_cherche) {
    // int i;

    table_liee = nom_champ.Mid(3);
    if (liste_cherche.GetCount() > 0) {
        wxString val = liste_cherche[0];
        gestion_quote(val);
        where="WHERE "+table_liee+".nom LIKE '%"+val+"%' ";
    }

    for(size_t i=1; i<liste_cherche.GetCount() ; i++) {
        if (WxRadioButton_type_ou->GetValue() == true)
            where+=" OR ";
        else if (WxRadioButton_type_et->GetValue() == true)
            where+=" AND ";
        wxString val = liste_cherche[i];
        gestion_quote(val);
        where+=table_liee+".nom LIKE '%"+val+"%' ";
    }

    //wxMessageBox("|"+table_liee+"|","where", wxOK | wxICON_INFORMATION, this);
    table_liee=nom_champ;

}

void recherche::creation_where_simple(wxString nom_champ, wxArrayString liste_cherche) {
    // int i;
    
    if (liste_cherche.GetCount() > 0) {
        wxString val = liste_cherche[0];
        gestion_quote(val);
        where="WHERE livre."+nom_champ+" LIKE '%"+val+"%' ";
    }

    for(size_t i=1; i<liste_cherche.GetCount() ; i++) {
        if (WxRadioButton_type_ou->GetValue() == true)
            where+=" OR ";
        else if (WxRadioButton_type_et->GetValue() == true)
            where+=" AND ";
        wxString val = liste_cherche[i];
        gestion_quote(val);
        where+="livre."+nom_champ+" LIKE '%"+val+"%' ";
    }
    
    //wxMessageBox(where,"where", wxOK | wxICON_INFORMATION, this);

}
