//---------------------------------------------------------------------------
//
// Name:        nouv_autre.cpp
// Author:      fougny
// Created:     31/01/2005 20:54:44
//
//Copyright  PE Epaillard, 31/01/2005 
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
    #pragma implementation "nouv_autre.cpp"
#endif

/* for compilers that support precompilation
   includes "wx/wx.h" */

#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif


#include "nouv_autre.h"

////Header Include Start
#include "Images/nouv_autre_WxBitmapButton_supprime_XPM.xpm"
#include "Images/nouv_autre_WxBitmapButton1_ouvrir_XPM.xpm"
////Header Include End



//----------------------------------------------------------------------------
// nouv_autre
//----------------------------------------------------------------------------

    ////Event Table Start
BEGIN_EVENT_TABLE(nouv_autre,wxDialog)
	////Manual Code Start
	//	EVT_TEXT(ID_WXEDIT_DATE_NAISSANCE,nouv_autre::wxEdit_Gesdate)
	//	EVT_TEXT(ID_WXEDIT_DATE_MORT,nouv_autre::wxEdit_Gesdate)
	////Manual Code End
	
	EVT_CLOSE(nouv_autre::nouv_autreClose)
	EVT_BUTTON(wxID_CANCEL,nouv_autre::WxButton_annulClick)
	EVT_BUTTON(ID_WXBUTTON_OK,nouv_autre::WxButton_okClick)
	
	EVT_GRID_CELL_LEFT_DCLICK(nouv_autre::WxGrid_listeCellLeftDoubleClick)
	EVT_BUTTON(ID_WXBITMAPBUTTON_SUPPRIME,nouv_autre::WxBitmapButton_supprimeClick)
	EVT_BUTTON(ID_WXBITMAPBUTTON1_OUVRIR,nouv_autre::WxBitmapButton1_ouvrirClick)
END_EVENT_TABLE()
    ////Event Table End



nouv_autre::nouv_autre( wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style )
    : wxDialog( parent, id, title, position, size, style)
{
    CreateGUIControls();
}

nouv_autre::nouv_autre( ma_base *pour_modif, wxString id_champ, wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style )
    : wxDialog( parent, id, title, position, size, style)
{
    wxString champ;
    wxString type;
    int x,y;
    
    la_belle=pour_modif;
    id_courant=id_champ;
    nom_table=title;
    CreateGUIControls();
    champ="id_"+nom_table;
    type=monlivre.Get_token_type(champ);
    type_table="";
    if(type.Right(2) != "_P") {
        type_table="";
        WxStaticText_date_mort->Destroy();
        WxDatePickerCtrl_mort->Destroy();
        WxStaticText_date_naissance->Destroy();
        WxDatePickerCtrl_naissance->Destroy();
        WxBitmapButton_supprime->Destroy();
        WxBitmapButton1_ouvrir->Destroy();
        WxStaticText_image->Destroy();
        WxPanel_image->Destroy();
        WxEdit_nom->GetPosition(&x,&y);
        WxStaticText_commentaire->Move(x,y+30);
    } else {
        type_table="_P";
    }    
        //wxMessageBox(type_table,"probleme", wxOK | wxICON_EXCLAMATION, this);
    init_tout();
}

nouv_autre::~nouv_autre()
{
    
} 

void nouv_autre::CreateGUIControls(void)
{
    int largeur_obj, hauteur_obj;
    ////GUI Items Creation Start

	wxInitAllImageHandlers();   //Initialize graphic format handlers

	WxBoxSizer1 = new wxBoxSizer(wxVERTICAL);
	this->SetSizer(WxBoxSizer1);
	this->SetAutoLayout(true);

	WxScrolledWindow1 = new wxScrolledWindow(this, ID_WXSCROLLEDWINDOW1, wxPoint(5, 0), wxSize(500, 167));
	WxScrolledWindow1->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));
	WxBoxSizer1->Add(WxScrolledWindow1,0,wxALIGN_CENTER | wxALL,0);

	WxStaticText_nom = new wxStaticText(WxScrolledWindow1, ID_WXSTATICTEXT_NOM, wxT("Nom :"), wxPoint(7, 8), wxDefaultSize, 0, wxT("WxStaticText_nom"));
	WxStaticText_nom->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_nom = new wxTextCtrl(WxScrolledWindow1, ID_WXEDIT_NOM, wxT(""), wxPoint(6, 24), wxSize(229, 21), 0, wxDefaultValidator, wxT("WxEdit_nom"));
	WxEdit_nom->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_date_naissance = new wxStaticText(WxScrolledWindow1, ID_WXSTATICTEXT_DATE_NAISSANCE, wxT("Date de naissance :"), wxPoint(7, 51), wxDefaultSize, 0, wxT("WxStaticText_date_naissance"));
	WxStaticText_date_naissance->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_date_mort = new wxStaticText(WxScrolledWindow1, ID_WXSTATICTEXT_DATE_MORT, wxT("Date du décès"), wxPoint(8, 99), wxDefaultSize, 0, wxT("WxStaticText_date_mort"));
	WxStaticText_date_mort->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_commentaire = new wxStaticText(WxScrolledWindow1, ID_WXSTATICTEXT_COMMENTAIRE, wxT("Commentaire :"), wxPoint(4, 146), wxDefaultSize, 0, wxT("WxStaticText_commentaire"));
	WxStaticText_commentaire->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_image = new wxStaticText(WxScrolledWindow1, ID_WXSTATICTEXT_IMAGE, wxT("Image :"), wxPoint(226, 3), wxDefaultSize, 0, wxT("WxStaticText_image"));
	WxStaticText_image->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	wxBitmap WxBitmapButton1_ouvrir_BITMAP (nouv_autre_WxBitmapButton1_ouvrir_XPM);
	WxBitmapButton1_ouvrir = new wxBitmapButton(WxScrolledWindow1, ID_WXBITMAPBUTTON1_OUVRIR, WxBitmapButton1_ouvrir_BITMAP, wxPoint(242, 25), wxSize(22, 22), wxBU_AUTODRAW, wxDefaultValidator, wxT("WxBitmapButton1_ouvrir"));
	WxBitmapButton1_ouvrir->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	wxBitmap WxBitmapButton_supprime_BITMAP (nouv_autre_WxBitmapButton_supprime_XPM);
	WxBitmapButton_supprime = new wxBitmapButton(WxScrolledWindow1, ID_WXBITMAPBUTTON_SUPPRIME, WxBitmapButton_supprime_BITMAP, wxPoint(241, 50), wxSize(22, 22), wxBU_AUTODRAW, wxDefaultValidator, wxT("WxBitmapButton_supprime"));
	WxBitmapButton_supprime->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxPanel_image = new wxPanel(WxScrolledWindow1, ID_WXPANEL_IMAGE, wxPoint(269, 0), wxSize(226, 162));
	WxPanel_image->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	wxDateTime WxDatePickerCtrl_naissance_Date(3,wxDateTime::Mar,2006,10,5,10,294);
	WxDatePickerCtrl_naissance = new wxDatePickerCtrl(WxScrolledWindow1, ID_WXDATEPICKERCTRL_NAISSANCE, WxDatePickerCtrl_naissance_Date, wxPoint(7, 72), wxSize(140, 21) , wxDP_DROPDOWN | wxDP_ALLOWNONE, wxDefaultValidator, wxT("WxDatePickerCtrl_naissance"));
	WxDatePickerCtrl_naissance->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	wxDateTime WxDatePickerCtrl_mort_Date(3,wxDateTime::Mar,2006,10,6,19,306);
	WxDatePickerCtrl_mort = new wxDatePickerCtrl(WxScrolledWindow1, ID_WXDATEPICKERCTRL_MORT, WxDatePickerCtrl_mort_Date, wxPoint(6, 116), wxSize(140, 21) , wxDP_DROPDOWN | wxDP_ALLOWNONE, wxDefaultValidator, wxT("WxDatePickerCtrl_mort"));
	WxDatePickerCtrl_mort->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxMemo_commentaire = new wxTextCtrl(this, ID_WXMEMO_COMMENTAIRE, wxEmptyString, wxPoint(5, 167), wxSize(500, 138), wxTE_MULTILINE, wxDefaultValidator, wxT("WxMemo_commentaire"));
	WxMemo_commentaire->SetMaxLength(0);
	WxMemo_commentaire->SetFocus();
	WxMemo_commentaire->SetInsertionPointEnd();
	WxMemo_commentaire->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));
	WxBoxSizer1->Add(WxMemo_commentaire,1,wxALIGN_CENTER | wxALL,0);

	WxGrid_liste = new wxGrid(this, ID_WXGRID_LISTE, wxPoint(5, 310), wxSize(501, 100));
	WxGrid_liste->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));
	WxGrid_liste->SetDefaultColSize(50);
	WxGrid_liste->SetDefaultRowSize(20);
	WxGrid_liste->SetRowLabelSize(25);
	WxGrid_liste->SetColLabelSize(15);
	WxGrid_liste->CreateGrid(5,3,wxGrid::wxGridSelectRows);
	WxBoxSizer1->Add(WxGrid_liste,1,wxALIGN_CENTER | wxALL,5);

	WxBoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer1->Add(WxBoxSizer2, 0, wxALIGN_CENTER | wxALL, 5);

	WxButton_ok = new wxButton(this, ID_WXBUTTON_OK, wxT("OK"), wxPoint(5, 5), wxSize(80, 28), 0, wxDefaultValidator, wxT("WxButton_ok"));
	WxButton_ok->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));
	WxBoxSizer2->Add(WxButton_ok,0,wxALIGN_CENTER | wxALL,5);

	WxButton_annul = new wxButton(this, wxID_CANCEL, wxT("Annuler"), wxPoint(95, 5), wxSize(80, 28), 0, wxDefaultValidator, wxT("WxButton_annul"));
	WxButton_annul->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));
	WxBoxSizer2->Add(WxButton_annul,0,wxALIGN_CENTER | wxALL,5);

	SetTitle(wxT("modif"));
	SetIcon(wxNullIcon);
	
	GetSizer()->Layout();
	GetSizer()->Fit(this);
	GetSizer()->SetSizeHints(this);
	Center();
	
    ////GUI Items Creation End
    WxPanel_image->GetSize(&largeur_obj,&hauteur_obj);
    canvas_image = new ImageCanvas(WxPanel_image, ID_IMAGECANVAS_IMAGE, wxPoint(0,0),wxSize(largeur_obj,hauteur_obj) );
    //image_charge=false;
}

void nouv_autre::init_tout() {
    wxString query, mess, join;
    int i;
    int ret, taille;
    wxFile fichier;
    wxDateTime madate;
    //bool tt;
    
    query = "SELECT nom, commentaire";
    if (type_table == "_P") {
        query+=", date_naissance, date_mort, image_auteur";
    }
    query+=" FROM "+nom_table+" WHERE rowid="+id_courant;
    
    ret=la_belle->transac_prepare(query);
    if (ret<0) {
        la_belle->get_erreur(mess);
        wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
    }

    ret=la_belle->transac_step();

    // destruction de la grille
	int ir = WxGrid_liste->GetNumberRows();
	if (ir)
		WxGrid_liste->DeleteRows(0, ir);
/*	ir = WxGrid_liste->GetNumberCols();
	if (ir)
		WxGrid_liste->DeleteCols(0, ir);*/
    
    // initialisation de la grille
	WxGrid_liste->SetSelectionMode(wxGrid::wxGridSelectRows);
    WxGrid_liste->SetColLabelValue(0,"id");
    WxGrid_liste->SetColLabelValue(1,"Auteur");
    WxGrid_liste->SetColLabelValue(2,"Titre");
    


    if (ret!=SQLITE_ROW) {
        la_belle->transac_fin();
        return;
    }  

    la_belle->get_value_char(0,mess,taille);
    WxEdit_nom->SetValue(mess);
    la_belle->get_value_char(1,mess,taille);
    WxMemo_commentaire->SetValue(mess);
    if (type_table == "_P") {
        la_belle->get_value_char(2,mess,taille);
        madate.ParseFormat(mess,"%d/%m/%Y");
        WxDatePickerCtrl_naissance->SetValue(madate);
        //WxEdit_date_naissance->SetValue(mess);
        
        la_belle->get_value_char(3,mess,taille);
        madate.ParseFormat(mess,"%d/%m/%Y");
        WxDatePickerCtrl_mort->SetValue(madate);
        //WxEdit_date_mort->SetValue(mess);
        
        wxString chemin=gettempdir();
        chemin+="\\a1.jpg";
        fichier.Open(chemin,wxFile::write);
        ret=la_belle->get_value_blob(4,&fichier,taille);
        if (ret<0) {
            la_belle->get_erreur(mess);
            wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
            taille=0;
        }
        if (taille > 0) {
            canvas_image->init(chemin);
/*            tt=image.LoadFile(chemin, wxBITMAP_TYPE_JPEG);
            if (tt==true) {
                image_charge=true;
                rempli_canvas(canvas_image, &image);
            }    */
        }    
    }    
    
    la_belle->transac_fin();
    
//    query="SELECT livre.rowid, auteur.nom, livre.titre FROM livre LEFT JOIN auteur ON livre.id_auteur=auteur.rowid where livre.id_auteur="+id_courant;
    //saloperie de left join de merde
    if (nom_table!="auteur")
        join= "LEFT JOIN "+nom_table+" ON livre.id_"+nom_table+"="+nom_table+".rowid ";
    query="SELECT livre.rowid, auteur.nom, livre.titre FROM livre LEFT JOIN auteur ON livre.id_auteur=auteur.rowid "+join+" where livre.id_"+nom_table+"="+id_courant+" order by upper(auteur.nom)";
    ret=la_belle->transac_prepare(query);
    if (ret<0) {
        la_belle->get_erreur(mess);
        wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
    }

    ret=la_belle->transac_step();
    i=0;
    while(ret==SQLITE_ROW) {
        WxGrid_liste->AppendRows();
        la_belle->get_value_char(0,mess,taille);
        WxGrid_liste->SetCellValue(i,0,mess);
        WxGrid_liste->SetReadOnly( i, 0, true );
        la_belle->get_value_char(1,mess,taille);
        WxGrid_liste->SetCellValue(i,1,mess);
        WxGrid_liste->SetReadOnly( i, 1, true );
        la_belle->get_value_char(2,mess,taille);
        WxGrid_liste->SetCellValue(i,2,mess);
        WxGrid_liste->SetReadOnly( i, 2, true );
        
        i++;
        ret=la_belle->transac_step();
    }
    la_belle->transac_fin();
    WxGrid_liste->AutoSizeColumns(true);
    WxGrid_liste->AutoSizeRows(true);
}    

void nouv_autre::nouv_autreClose(wxCloseEvent& event)
{
    // --> Don't use Close with a wxDialog,
    // use Destroy instead.
    Destroy();
}
 
/*
 * WxButton_annulClick
 */
void nouv_autre::WxButton_annulClick(wxCommandEvent& event)
{
    Destroy();
	// insert your code here
	event.Skip();
}

/*
 * WxButton_okClick
 */
void nouv_autre::WxButton_okClick(wxCommandEvent& event)
{
    enregistrer();
    Destroy();
	// insert your code here
	event.Skip();
}
void nouv_autre::enregistrer() {
    wxString query;
    wxString mess;
    wxFile monfichier;
    bool tt;
    int ret;

    //wxMessageBox(id_courant,"probleme", wxOK | wxICON_EXCLAMATION, this);
    if (id_courant =="-1" || id_courant=="") {
        query="INSERT INTO "+nom_table+"( nom, commentaire";
        if (type_table == "_P") {
            query+=", date_naissance, date_mort, image_auteur";
        }
        mess=WxEdit_nom->GetValue();
        gestion_quote(mess);
        query+=") VALUES ('"+mess+"','";
        mess=WxMemo_commentaire->GetValue();
        gestion_quote(mess);
        query+=mess+"'";
        if (type_table == "_P") {
            mess=WxDatePickerCtrl_naissance->GetValue().Format("%d/%m/%Y");
            //mess=WxEdit_date_naissance->GetValue();
            gestion_quote(mess);
            query+=",'"+mess;
            mess=WxDatePickerCtrl_mort->GetValue().Format("%d/%m/%Y");
            //mess=WxEdit_date_mort->GetValue();
            gestion_quote(mess);
            query+="','"+mess+"',?";
        }    
        query+=")";
    } else {
        mess=WxEdit_nom->GetValue();
        gestion_quote(mess);
        query="UPDATE "+nom_table+" SET nom='"+mess;
        mess=WxMemo_commentaire->GetValue();
        gestion_quote(mess);
        query+="', commentaire='"+mess+"'";
        if (type_table == "_P") {
            mess=WxDatePickerCtrl_naissance->GetValue().Format("%d/%m/%Y");
            //mess=WxEdit_date_naissance->GetValue();
            gestion_quote(mess);
            query+=",date_naissance='"+mess+"',date_mort='";
            mess=WxDatePickerCtrl_mort->GetValue().Format("%d/%m/%Y");
            //mess=WxEdit_date_mort->GetValue();
            gestion_quote(mess);
            query+=mess+"',image_auteur=?";
        }    
        query+=" WHERE rowid="+id_courant;
    }    

//    wxMessageBox(query,"probleme", wxOK | wxICON_EXCLAMATION, this);
    ret=la_belle->transac_prepare(query);
    if (ret<0) {
        la_belle->get_erreur(mess);
        wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        return;
    }
    
    if (canvas_image->charge == true) {
        wxString chemin=gettempdir();
        chemin+="\\a0.jpg";
        canvas_image->image_s.SaveFile(chemin,wxBITMAP_TYPE_JPEG);
        tt=monfichier.Open(chemin, wxFile::read);
        if (tt == false) {
            mess="Probleme lors de la lecture de " + chemin + "impossible de sauver dans la base";
            wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
            return;
        }    
       
        ret=la_belle->transac_blob(1,&monfichier);
        if (ret<0) {
            la_belle->get_erreur(mess);
            wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
            return;
        }
        //wxMessageBox(query,"probleme", wxOK | wxICON_EXCLAMATION, this);
    }    

    ret=la_belle->transac_step();
    if (ret<0) {
        la_belle->get_erreur(mess);
        wxMessageBox(query+"\n"+mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        return;
    }
    ret=la_belle->transac_fin();
    if (ret<0) {
        la_belle->get_erreur(mess);
        wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        return;
    }
    //query_update="UPDATE "+nom_table+" SET ";
    
}    
/*void nouv_autre::rempli_canvas(ImageCanvas *lecanvas, wxImage *image) {
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

/*
 * WxBitmapButton1_ouvrirClick
 */
void nouv_autre::WxBitmapButton1_ouvrirClick(wxCommandEvent& event)
{
    //bool tt=true;

    wxString filename = wxFileSelector("Ouvrir une image",chemin_image,"","","image (tout format reconnu)|*.jpg;*.jpeg;*.png;*.gif;*.bmp|Tous (*.*)|*.*",wxOPEN|wxFILE_MUST_EXIST);

    if ( !filename.empty() )
    {
        wxFileName lefichier(filename);
        chemin_image=lefichier.GetPath();
        canvas_image->init(filename);
        /*tt=image.LoadFile(filename);
        if (tt==true) {
            rempli_canvas(canvas_image, &image);
            image_charge=true;
        } else {
            wxMessageBox("Probleme de chargement de l'image","probleme", wxOK | wxICON_EXCLAMATION, this);
        }*/
    } else {
        return;
    }            
    // insert your code here
    event.Skip();
}

/*void nouv_autre::wxEdit_Gesdate(wxCommandEvent& event){
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
 * WxBitmapButton_supprimeClick
 */ 
void nouv_autre::WxBitmapButton_supprimeClick(wxCommandEvent& event)
{
    canvas_image->efface();
    canvas_image->Refresh();
    //image_charge=false;
	// insert your code here
	event.Skip();
}


/*
 * WxGrid_listeCellLeftDoubleClick
 */
void nouv_autre::WxGrid_listeCellLeftDoubleClick(wxGridEvent& event)
{
    int nb_ligne, ret;
    wxString id;
    //wxString mess;
    
    nb_ligne=event.GetRow();
    id=WxGrid_liste->GetCellValue(nb_ligne,0);
    //wxMessageBox(id,"probleme", wxOK | wxICON_EXCLAMATION, this);
    Nouv_livre insere_livre(la_belle, id,false, this, -1, "Modification du livre", wxDefaultPosition, wxDefaultSize);//, style_dialog_choix);
    ret=insere_livre.ShowModal();
    init_tout();
}
