//---------------------------------------------------------------------------
//
// Name:        affiche_image.h
// Author:      Fougny
// Created:     04/10/2007 11:10:12
// Description: affiche_image class declaration
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

#ifndef __AFFICHE_IMAGE_h__
#define __AFFICHE_IMAGE_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/dialog.h>
#else
	#include <wx/wxprec.h>
#endif

#include "divers.h"

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
////Header Include End

////Dialog Style Start
#undef affiche_image_STYLE
#define affiche_image_STYLE wxWANTS_CHARS | wxNO_BORDER | wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxCLOSE_BOX
////Dialog Style End

class affiche_image : public wxDialog
{
	private:
		DECLARE_EVENT_TABLE();
		
    private:
		affiche_image(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Image"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = affiche_image_STYLE);
		virtual ~affiche_image();
	
	private:
		//Do not add custom control declarations between 
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		////GUI Control Declaration End
		//wxString chemin_image;
        // ImageCanvas *canvas_image;
        wxImage monimage;
        wxImage imageAffichee;
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			////GUI Enum Control ID End
			ID_IMAGECANVAS_1 = 1500,
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
        void WxButton_nouv_annulClick(wxCommandEvent& event);
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
		void dessine();
		
	public:
		affiche_image(wxString c_image, wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Image"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = affiche_image_STYLE);
		affiche_image(wxImage i_image, wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Image"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = affiche_image_STYLE);
		void affiche_imagePaint(wxPaintEvent& event);
		void affiche_imageSize(wxSizeEvent& event);
		void affiche_imageKeyUp(wxKeyEvent& event);

    private:    
        static long s_nbInstances;
};

#endif
