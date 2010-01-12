//---------------------------------------------------------------------------
//
// Name:        choix_colonnes.cpp
// Author:      
// Created:     12/01/05 12:55:25
//
//Copyright  PE Epaillard, 12/01/05 
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
    #pragma implementation "choix_colonnes.cpp"
#endif

/* for compilers that support precompilation
   includes "wx/wx.h" */

#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif


#include "choix_colonnes.h"

////Header Include Start
#include "Images/choix_colonnes_WxBitmapButton_bas_XPM.xpm"
#include "Images/choix_colonnes_WxBitmapButton_haut_XPM.xpm"
#include "Images/choix_colonnes_WxBitmapButton1_XPM.xpm"
#include "Images/choix_colonnes_wxButton_enleve_XPM.xpm"
////Header Include End



//----------------------------------------------------------------------------
// choix_colonnes
//----------------------------------------------------------------------------

    ////Event Table Start
BEGIN_EVENT_TABLE(choix_colonnes,wxDialog)
	////Manual Code Start
	//EVT_BUTTON(ID_BUTTON_ANNULER,choix_colonnes::WxButton_annulClick)
	//EVT_BUTTON(ID_BUTTON_OK,choix_colonnes::WxButton_okClick)
	//EVT_BUTTON(ID_BUTTON_AJOUTE,choix_colonnes::WxButton_ajouteClick)
	//EVT_BUTTON(ID_BUTTON_ENLEVE,choix_colonnes::WxButton_enleveClick)
	//EVT_LISTBOX_DCLICK(ID_LISTBOX_CHOISIS,choix_colonnes::WxButton_enleveClick)
	//	EVT_GRID_CMD_CELL_LEFT_DCLICK(ID_LISTBOX_CHOIX, choix_colonnes::WxGrid_ajouteClick)
	//EVT_LISTBOX_DCLICK(ID_LISTBOX_CHOIX, choix_colonnes::Wxlist_ajouteClick)
	////Manual Code End
	
	EVT_CLOSE(choix_colonnes::choix_colonnesClose)
	EVT_BUTTON(ID_WXBITMAPBUTTON_BAS,choix_colonnes::WxBitmapButton_basClick)
	EVT_BUTTON(ID_WXBITMAPBUTTON_HAUT,choix_colonnes::WxBitmapButton_hautClick)
	EVT_BUTTON(ID_WXBITMAPBUTTON1,choix_colonnes::WxButton_ajouteClick)
	EVT_BUTTON(ID_WXBUTTON_ENLEVE,choix_colonnes::WxButton_enleveClick)
	EVT_BUTTON(ID_WXBUTTON_ANNULER,choix_colonnes::WxButton_annulClick)
	EVT_BUTTON(ID_WXBUTTON_OK,choix_colonnes::WxButton_okClick)
	
	EVT_LISTBOX_DCLICK(ID_ITEMLISTBOX_CHOIX,choix_colonnes::Wxlist_ajouteClick)
END_EVENT_TABLE()
    ////Event Table End


 
choix_colonnes::choix_colonnes( wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style )
    : wxDialog( parent, id, title, position, size, style)
{
    CreateGUIControls();
}

choix_colonnes::choix_colonnes( wxArrayString &l_choix, wxArrayInt *l_choisis, wxArrayString *l_choisis_nom, wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style )
    : wxDialog( parent, id, title, position, size, style)
{
    liste_choix=l_choix;
    liste_choisis=l_choisis;
    liste_choisis_nom=l_choisis_nom;
    CreateGUIControls();
    init_listbox();
}


choix_colonnes::~choix_colonnes()
{
    
} 

void choix_colonnes::init_listbox()
{
    int i;
    int n_val;
    wxString val;
    
    for (i=0;i<(int)liste_choix.GetCount();i++) {
        val=liste_choix[i];
        if (val.Left(3) == "id_") {
            itemListBox_choix->Append(val.Mid(3));
        } else {
            itemListBox_choix->Append(val);
        }   
    }     
    for (i=0;i<(int)liste_choisis->GetCount();i++) {
        n_val=liste_choisis->Item(i);
        val=liste_choix[n_val];
        if (val.Left(3) == "id_") {
            itemListBox_choisis->Append(val.Mid(3));
        } else {
            itemListBox_choisis->Append(val);
        }   
        itemListBox_choix->SetString(n_val,"");
    }    
}    
void choix_colonnes::CreateGUIControls(void)
{
    ////GUI Items Creation Start

	itemSplitterWindow_gauche =new wxSplitterWindow(this, ID_ITEMSPLITTERWINDOW_GAUCHE, wxPoint(0,0), wxSize(200,507) );

	wxArrayString arrayStringFor_itemListBox_choix;
	itemListBox_choix = new wxListBox(itemSplitterWindow_gauche, ID_ITEMLISTBOX_CHOIX, wxPoint(5,58), wxSize(100,390), arrayStringFor_itemListBox_choix, wxLB_SINGLE);

	itemSplitterWindow_droit =new wxSplitterWindow(itemSplitterWindow_gauche, ID_ITEMSPLITTERWINDOW_DROIT, wxPoint(115,5), wxSize(70,497) );

	itemPanel_bouton = new wxPanel(itemSplitterWindow_droit, ID_ITEMPANEL_BOUTON, wxPoint(5,5), wxSize(60,289));

	wxButton_OK = new wxButton(itemPanel_bouton, ID_WXBUTTON_OK, wxT("OK"), wxPoint(2,5), wxSize(50,20), 0, wxDefaultValidator, wxT("wxButton_OK"));

	wxButton_annuler = new wxButton(itemPanel_bouton, ID_WXBUTTON_ANNULER, wxT("Annuler"), wxPoint(2,30), wxSize(50,20), 0, wxDefaultValidator, wxT("wxButton_annuler"));

	wxBitmap wxButton_enleve_BITMAP (choix_colonnes_wxButton_enleve_XPM);
	wxButton_enleve = new wxBitmapButton(itemPanel_bouton, ID_WXBUTTON_ENLEVE, wxButton_enleve_BITMAP, wxPoint(3,85), wxSize(50,20), wxBU_AUTODRAW, wxDefaultValidator, wxT("wxButton_enleve"));

	wxBitmap WxBitmapButton1_BITMAP (choix_colonnes_WxBitmapButton1_XPM);
	WxBitmapButton1 = new wxBitmapButton(itemPanel_bouton, ID_WXBITMAPBUTTON1, WxBitmapButton1_BITMAP, wxPoint(2,110), wxSize(50,20), wxBU_AUTODRAW, wxDefaultValidator, wxT("WxBitmapButton1"));

	wxBitmap WxBitmapButton_haut_BITMAP (choix_colonnes_WxBitmapButton_haut_XPM);
	WxBitmapButton_haut = new wxBitmapButton(itemPanel_bouton, ID_WXBITMAPBUTTON_HAUT, WxBitmapButton_haut_BITMAP, wxPoint(30,140), wxSize(20,50), wxBU_AUTODRAW, wxDefaultValidator, wxT("WxBitmapButton_haut"));

	wxBitmap WxBitmapButton_bas_BITMAP (choix_colonnes_WxBitmapButton_bas_XPM);
	WxBitmapButton_bas = new wxBitmapButton(itemPanel_bouton, ID_WXBITMAPBUTTON_BAS, WxBitmapButton_bas_BITMAP, wxPoint(30,195), wxSize(20,50), wxBU_AUTODRAW, wxDefaultValidator, wxT("WxBitmapButton_bas"));

	wxArrayString arrayStringFor_itemListBox_choisis;
	itemListBox_choisis = new wxListBox(itemSplitterWindow_droit, ID_ITEMLISTBOX_CHOISIS, wxPoint(75,55), wxSize(40,188), arrayStringFor_itemListBox_choisis, wxLB_SINGLE);

	itemSplitterWindow_droit->SplitVertically(itemPanel_bouton,itemListBox_choisis,40);
	itemSplitterWindow_gauche->SplitVertically(itemListBox_choix,itemSplitterWindow_droit,160);

	itemSplitterWindow_droit->SplitVertically(itemPanel_bouton,itemListBox_choisis,40);

	SetTitle(wxT("choix_colonnes"));
	SetIcon(wxNullIcon);
	SetSize(8,8,208,541);
	Center();
	
    ////GUI Items Creation End

	this->SetSize(-1,-1,400,500);
    
    itemSplitterWindow_gauche->SetMinimumPaneSize(10);
    itemSplitterWindow_droit->SetMinimumPaneSize(55);

//    itemSplitterWindow_gauche = new wxSplitterWindow( this, ID_SPLITTERWINDOW_GAUCHE, wxDefaultPosition, wxSize(395, 480), wxSP_3DBORDER|wxSP_3DSASH|wxNO_BORDER );
    //itemSplitterWindow_gauche = new wxSplitterWindow( this, ID_SPLITTERWINDOW_GAUCHE, wxDefaultPosition, wxSize(392, 492), wxNO_BORDER );

    //wxString* itemListBox3Strings = NULL;
    //itemListBox_choix = new wxListBox( itemSplitterWindow_gauche, ID_LISTBOX_CHOIX, wxDefaultPosition, wxDefaultSize, 0, itemListBox3Strings, wxLB_SINGLE );

//    itemSplitterWindow_droit = new wxSplitterWindow( itemSplitterWindow_gauche, ID_SPLITTERWINDOW_DROIT, wxDefaultPosition, wxSize(100, 100), wxSP_3DBORDER|wxSP_3DSASH|wxNO_BORDER );
    //itemSplitterWindow_droit = new wxSplitterWindow( itemSplitterWindow_gauche, ID_SPLITTERWINDOW_DROIT, wxDefaultPosition, wxSize(100, 100), wxNO_BORDER );

    //itemPanel_bouton = new wxPanel( itemSplitterWindow_droit, ID_PANEL_BOUTON, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    
    //wxButton_OK = new wxButton( itemPanel_bouton, ID_BUTTON_OK, _("OK"), wxDefaultPosition, wxSize(50, 20), 0 );
    //wxButton_annuler = new wxButton( itemPanel_bouton, wxID_CANCEL, _("Annuler"), wxPoint(0, 25), wxSize(50, 20), 0 );
    //wxButton_ajoute = new wxButton( itemPanel_bouton, ID_BUTTON_AJOUTE, _("---->"), wxPoint(0, 150), wxSize(50, 20), 0 );
    //wxButton_enleve = new wxButton( itemPanel_bouton, ID_BUTTON_ENLEVE, _("<----"), wxPoint(0, 175), wxSize(50, 20), 0 );


    //wxString* itemListBox6Strings = NULL;
    //itemListBox_choisis = new wxListBox( itemSplitterWindow_droit, ID_LISTBOX_CHOISIS, wxDefaultPosition, wxDefaultSize, 0, itemListBox6Strings, wxLB_SINGLE );

    //itemSplitterWindow_gauche->SplitVertically(itemListBox_choix, itemSplitterWindow_droit, 50);
    //itemSplitterWindow_droit->SplitVertically(itemPanel_bouton, itemListBox_choisis, 1);


}

void choix_colonnes::choix_colonnesClose(wxCloseEvent& event)
{
    // --> Don't use Close with a wxDialog,
    // use Destroy instead.
    Destroy();
}

/*
 * WxButton_ajouteClick
 */
void choix_colonnes::WxButton_ajouteClick(wxCommandEvent& event)
{
    ajouteClick();
    event.Skip();
}

void choix_colonnes::Wxlist_ajouteClick( wxCommandEvent &event ) 
{
    ajouteClick();
    event.Skip();
}
void choix_colonnes::ajouteClick() {
    int num_choix;
    int num_choisi;
    wxString texte;
    wxString val;
    wxString val_insere;
    
	// insert your code here
	num_choix=itemListBox_choix->GetSelection();
	num_choisi=itemListBox_choisis->GetSelection();
	texte.Printf("g:%d d:%d",num_choix, num_choisi);
	if (num_choix < 0) {
        wxMessageBox("Vous devez selectionner un champ dans la liste de gauche","Oups", wxOK | wxICON_INFORMATION, this);
        return;
    }    
    val=itemListBox_choix->GetString(num_choix);
    if (val.Length() == 0) {
        wxMessageBox("Ce Champ à déja été selectionné","Oups", wxOK | wxICON_INFORMATION, this);
        return;
    }    
        
    if (val.Left(3) == "id_") 
        val_insere=val.Mid(3);
    else
        val_insere=val;
    if (num_choisi<0) {
        itemListBox_choisis->Append(val_insere);
        liste_choisis->Add(num_choix);
        if (liste_choisis_nom != NULL)
            liste_choisis_nom->Add(val_insere);
    }    
    else {
        itemListBox_choisis->Insert(val_insere,num_choisi);
        liste_choisis->Insert(num_choix, num_choisi);
        if (liste_choisis_nom != NULL)
            liste_choisis_nom->Insert(val_insere, num_choisi);
    }    
    itemListBox_choix->SetString(num_choix,"");
}    

/*
 * WxButton_enleveClick
 */
void choix_colonnes::WxButton_enleveClick(wxCommandEvent& event)
{
    int num_choix;
    int num_choisi;
    int i;
    wxString texte;
    wxString val;
    wxString val_insere;
    
	// insert your code here
	//num_choix=itemListBox_choix->GetSelection();
	num_choisi=itemListBox_choisis->GetSelection();
	if (num_choisi < 0) {
        wxMessageBox("Vous devez selectionner un champ dans la liste de droite","Oups", wxOK | wxICON_INFORMATION, this);
        event.Skip();
        return;
    }    
    val=itemListBox_choisis->GetString(num_choisi);
    for (i=0;i<(int)liste_choix.GetCount();i++) {
        texte="id_"+val;
        if (liste_choix.Item(i) == val || liste_choix.Item(i) == texte) {
            num_choix=i;
            break;
        }    
    }    
    
    itemListBox_choisis->Delete(num_choisi);
    liste_choisis->RemoveAt(num_choisi);
    if (liste_choisis_nom != NULL)
        liste_choisis_nom->RemoveAt(num_choisi);
    itemListBox_choix->SetString(num_choix,val);

    event.Skip();
}
/*
 * WxButton_annulClick
 */
void choix_colonnes::WxButton_annulClick(wxCommandEvent& event)
{
    SetReturnCode(1);
    EndModal(1);
    Destroy();
	// insert your code here
	//event.Skip();
}


void choix_colonnes::WxButton_okClick(wxCommandEvent& event)
{
    EndModal(0);
    Destroy();
	// insert your code here
	//event.Skip();
}

/* deplace le texte selectionné dans listbox_choisi
 si haut = true -> vers le haut
 si haut = false -> vers le bas
*/
void choix_colonnes::deplace_choisi(bool haut) {
    wxString val, val_insere;
    wxString texte;
    int i,num_choix;

	int num_choisi=itemListBox_choisis->GetSelection();

    val=itemListBox_choisis->GetString(num_choisi);
    for (i=0;i<(int)liste_choix.GetCount();i++) {
        texte="id_"+val;
        if (liste_choix.Item(i) == val || liste_choix.Item(i) == texte) {
            num_choix=i;
            break;
        }
    }

    itemListBox_choisis->Delete(num_choisi);
    liste_choisis->RemoveAt(num_choisi);
    if (liste_choisis_nom != NULL)
        liste_choisis_nom->RemoveAt(num_choisi);
    if (haut == true)
        num_choisi--;
    else
        num_choisi++;

    if (val.Left(3) == "id_")
        val_insere=val.Mid(3);
    else
        val_insere=val;

    if (num_choisi<0) {
        itemListBox_choisis->Append(val_insere);
        liste_choisis->Add(num_choix);
        if (liste_choisis_nom != NULL)
            liste_choisis_nom->Add(val_insere);
    }
    else {
        itemListBox_choisis->Insert(val_insere,num_choisi);
        liste_choisis->Insert(num_choix, num_choisi);
        if (liste_choisis_nom != NULL)
            liste_choisis_nom->Insert(val_insere, num_choisi);
    }
    itemListBox_choisis->SetSelection(num_choisi);

}
/*
 * WxBitmapButton_hautClick
 */
void choix_colonnes::WxBitmapButton_hautClick(wxCommandEvent& event)
{
	int num_choisi=itemListBox_choisis->GetSelection();
	if (num_choisi < 0) {
        wxMessageBox("Vous devez selectionner un champ dans la liste de droite","Oups", wxOK | wxICON_INFORMATION, this);
        event.Skip();
        return;
    }
	if (num_choisi == 0) {
        //wxMessageBox("déja tout en haut","Oups", wxOK | wxICON_INFORMATION, this);
        event.Skip();
        return;
    }
    deplace_choisi(true);
}

/*
 * WxBitmapButton_basClick
 */
void choix_colonnes::WxBitmapButton_basClick(wxCommandEvent& event)
{
	int num_choisi=itemListBox_choisis->GetSelection();
	if (num_choisi < 0) {
        wxMessageBox("Vous devez selectionner un champ dans la liste de droite","Oups", wxOK | wxICON_INFORMATION, this);
        event.Skip();
        return;
    }
	if (num_choisi >= (itemListBox_choisis->GetCount()-1)) {
        //wxMessageBox("déja tout en bas","Oups", wxOK | wxICON_INFORMATION, this);
        event.Skip();
        return;
    }
    deplace_choisi(false);
}
