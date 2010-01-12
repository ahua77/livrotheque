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
	EVT_BUTTON(wxID_CANCEL,affiche_image::WxButton_nouv_annulClick)
END_EVENT_TABLE()
////Event Table End

affiche_image::affiche_image(wxString c_image, wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
    //chemin_image=c_image;
    monimage.LoadFile(c_image);
	CreateGUIControls();
}

affiche_image::affiche_image(wxImage i_image, wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
    //chemin_image=c_image;
    monimage = i_image;
	CreateGUIControls();
}

affiche_image::affiche_image(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

affiche_image::~affiche_image()
{
} 

void affiche_image::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxPanel_image = new wxPanel(this, ID_WXPANEL_IMAGE, wxPoint(0,0), wxSize(427,524));
	WxPanel_image->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxButton_annul = new wxButton(WxPanel_image, wxID_CANCEL, wxT("Annuler"), wxPoint(0,0), wxSize(1,1), 0, wxDefaultValidator, wxT("WxButton_annul"));
	WxButton_annul->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	SetTitle(wxT("Image"));
	SetIcon(wxNullIcon);
	SetSize(8,8,435,558);
	Center();
	
	////GUI Items Creation End
	int largeur=monimage.GetWidth();
	int hauteur=monimage.GetHeight();
	this->SetSize(largeur+7,hauteur+33);
	WxPanel_image->SetSize(largeur, hauteur);


	canvas_image = new ImageCanvas(monimage, WxPanel_image, ID_IMAGECANVAS_1,wxPoint(0,0),wxSize(largeur, hauteur));
	canvas_image->set_cliquable(false);
    canvas_image->Refresh();
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
    //Destroy();
	// insert your code here
	//event.Skip();
}

