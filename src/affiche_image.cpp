//---------------------------------------------------------------------------
//
// Name:        affiche_image.cpp
// Author:      Fougny
// Created:     04/10/2007 11:10:12
// Description: affiche_image class implementation
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

#include "affiche_image.h"

long affiche_image::s_nbInstances = 0;

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// affiche_image
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(affiche_image,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(affiche_image::OnClose)
	EVT_KEY_UP(affiche_image::affiche_imageKeyUp)
	EVT_SIZE(affiche_image::affiche_imageSize)
	EVT_PAINT(affiche_image::affiche_imagePaint)
END_EVENT_TABLE()
////Event Table End

affiche_image::affiche_image(wxString c_image, wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
    s_nbInstances++;
    wxLogMessage("affiche_image::affiche_image() - nbInstances = %ld", s_nbInstances);

    //chemin_image=c_image;
    monimage.LoadFile(c_image);
	CreateGUIControls();
}

affiche_image::affiche_image(wxImage i_image, wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
    s_nbInstances++;
    wxLogMessage("affiche_image::affiche_image() - nbInstances = %ld", s_nbInstances);
    //chemin_image=c_image;
    monimage = i_image;
	CreateGUIControls();
}

affiche_image::affiche_image(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
    s_nbInstances++;
    wxLogMessage("affiche_image::affiche_image() - nbInstances = %ld", s_nbInstances);
	CreateGUIControls();
}

affiche_image::~affiche_image()
{
    s_nbInstances--;
    wxLogMessage("affiche_image::~affiche_image() - nbInstances = %ld", s_nbInstances);
//    wxMessageBox("dans affiche_image::~affiche_image()");
} 

void affiche_image::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	SetTitle(wxT("Image"));
	SetIcon(wxNullIcon);
	SetSize(8,8,517,331);
	Center();
	
	////GUI Items Creation End
		
	int largeur=monimage.GetWidth();
	int hauteur=monimage.GetHeight();
	
	// on affiche initialement l'image � sa taille native, mais avec un max de 3/4 de l'�cran
	wxSize screenSize = wxGetDisplaySize();
	int largeurMax = screenSize.GetWidth()*3/4;
	int hauteurMax = screenSize.GetHeight()*3/4;
	if (largeur > largeurMax) largeur = largeurMax;
	if (hauteur > hauteurMax) hauteur = hauteurMax;
    wxLogMessage("affiche_image::CreateGUIControls() : tailleMax = (%4d, %4d) - taille cible = (%4d, %4d)", largeurMax, hauteurMax, largeur, hauteur);
	this->SetSize(largeur+7,hauteur+33);  // 7, 33 : valeurs approch�es pour la dimension de la d�coration de la fen�tre
	Center();
//	WxPanel_image->SetSize(largeur, hauteur);


/*
	canvas_image = new ImageCanvas(monimage, WxPanel_image, ID_IMAGECANVAS_1,wxPoint(0,0),wxSize(largeur, hauteur));
	canvas_image->set_cliquable(false);
    canvas_image->Refresh();
*/
    dessine();
}

void affiche_image::OnClose(wxCloseEvent& /*event*/)
{
	Destroy();
}

/*
 * WxButton_nouv_annulClick
 */
void affiche_image::WxButton_nouv_annulClick(wxCommandEvent& event)
{
    //wxMessageBox("bouton","probleme", wxOK | wxICON_INFORMATION, this);
    SetReturnCode(0);
    EndModal(0);
    Destroy();
	// insert your code here
	//event.Skip();
}

void affiche_image::dessine()
{
    // afficher l'image directement dans le dlg
    wxBitmap bmp(imageAffichee);
    wxPaintDC dc( this );
    PrepareDC( dc );
    dc.Clear();
    dc.DrawBitmap( bmp, 0, 0 , TRUE);
}

/*
 * affiche_imagePaint
 */
void affiche_image::affiche_imagePaint(wxPaintEvent& event)
{
	dessine();
}

/*
 * affiche_imageSize
 */
void affiche_image::affiche_imageSize(wxSizeEvent& event)
{
    wxLogMessage("entree dans affiche_image::affiche_imageSize()");
    wxSize tailleClientAvant = this->GetClientSize();
    int largeurClientAvant = tailleClientAvant.GetWidth();
    int hauteurClientAvant = tailleClientAvant.GetHeight();
    
    // si la taille de la zone client = la taille de l'image d�j� affich�e : on s'arr�te l�
    if (largeurClientAvant == imageAffichee.GetWidth() && hauteurClientAvant == imageAffichee.GetHeight())
        return;
    
	wxSize tailleDlgAvant = this->GetSize();
    int largeurDlgAvant = tailleDlgAvant.GetWidth();
    int hauteurDlgAvant = tailleDlgAvant.GetHeight();
    
    int largeurDeco = largeurDlgAvant - largeurClientAvant;
    int hauteurDeco = hauteurDlgAvant - hauteurClientAvant;
    	
    int largeurImageAvant = imageAffichee.GetWidth();
    int hauteurImageAvant = imageAffichee.GetHeight();	

    // taille minimum de la zone client et donc de l'image : 30x30
    if (largeurClientAvant < 30) largeurClientAvant = 30;
    if (hauteurClientAvant < 30) hauteurClientAvant = 30;    
    	
	float ratio_h = (float)(hauteurClientAvant) / (float)(monimage.GetHeight());
	float ratio_w = (float)(largeurClientAvant) / (float)(monimage.GetWidth());
    float ratio = ratio_h;
    if (ratio > ratio_w) ratio=ratio_w;

    // calcul de la nouvelle taille de l'image = taille zone client cible
    int largeurClientApres = (int)((float)(monimage.GetWidth())*ratio);
    int hauteurClientApres = (int)((float)(monimage.GetHeight())*ratio);
    // ... et de la nouvelle taille de la fenetre
    int largeurDlgApres = largeurClientApres + largeurDeco;
    int hauteurDlgApres = hauteurClientApres + hauteurDeco;
    
    // si les dimensions de l'image ont finalement chang�, on recalcule l'image
    if (largeurClientApres != imageAffichee.GetWidth() || hauteurClientApres != imageAffichee.GetHeight()) {
        imageAffichee = monimage.Scale(largeurClientApres, hauteurClientApres);
/*  sauvegarde du bitmap dans %temp%, uniquement � des fins de debug
        wxString filename;
        filename.Printf("\\imgAffiche_%d_%d.bmp", largeurDc, hauteurDc);
        imageAffichee.SaveFile(gettempdir()+filename, wxBITMAP_TYPE_BMP);
*/
    }

    // si les dimensions de la fenetre ont �t� modifi�es pour tenir compte du ratio de l'image, on la retaille
    if (largeurDlgApres != largeurDlgAvant || hauteurDlgApres != hauteurDlgAvant) {
        SetSize(largeurDlgApres, hauteurDlgApres);
    }

    wxLogMessage("   dlg   : (%4d, %4d) ==> (%4d, %4d)", largeurDlgAvant, hauteurDlgAvant, largeurDlgApres, hauteurDlgApres);
    wxLogMessage("   image : (%4d, %4d) ==> (%4d, %4d)", largeurImageAvant, hauteurImageAvant, largeurClientApres, hauteurClientApres);

    // on force le rafraichissement de l'affichage
    Refresh();
}

/*
 * affiche_imageKeyUp
 */
void affiche_image::affiche_imageKeyUp(wxKeyEvent& event)
{
    wxLogMessage("affiche_image::affiche_imageKeyUp : GetKeyCode --> %d", event.GetKeyCode());
	if (event.GetKeyCode() == WXK_ESCAPE ) {
        EndModal(0);
    } else {
        event.Skip();
    }
}
