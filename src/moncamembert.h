//---------------------------------------------------------------------------
//
// Name:        GestionCoul.h
// Author:      lootens
// Created:     29/08/2005 17:15:49
//
//Copyright  PE Epaillard, 20/07/05 
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
#ifndef __GESTIONCOUL_HPP_
#define __GESTIONCOUL_HPP_

// For compilers that support precompilation, includes "wx.h".
#include <wx/wxprec.h>

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
// Include your minimal set of headers here, or wx.h
#include <wx/wx.h>
#endif

//Do not add custom headers.
//wx-dvcpp designer will remove them
////Header Include Start
#include <wx/textctrl.h>
#include <wx/notebook.h>
#include <wx/button.h>
#include <wx/panel.h>
////Header Include End

#include <wx/frame.h>

//#include "moncamembert.h"

////Dialog Style Start
	#undef THIS_DIALOG_STYLE
	#define THIS_DIALOG_STYLE wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxMAXIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

#include <wx/scrolwin.h> // inheriting class's header file
#include <wx/dcmirror.h>
#include <wx/colordlg.h>
#include <wx/fontdlg.h>

class CarreCouleur;

WX_DECLARE_OBJARRAY(wxColour,wxArrayColour);
WX_DECLARE_OBJARRAY(wxRect,wxArrayRect);
//WX_DECLARE_OBJARRAY(double,wxArrayDouble);

WX_DEFINE_ARRAY_PTR(wxStaticText *,wxArrayPtrStaticText);
WX_DEFINE_ARRAY_PTR(CarreCouleur *,wxArrayPtrCarreCouleur);

// No description
class MonCamembert : public wxScrolledWindow
{
    private:
        DECLARE_EVENT_TABLE()
    
	public:
		// class constructor
		MonCamembert(wxWindow* parent,wxWindowID id = -1, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxHSCROLL | wxVSCROLL, const wxString& name = "MonCamembert");
		// class destructor
		~MonCamembert();
		
	private:
        
        void dessiner_portion(wxDC &dc,wxRealPoint ptCentre,double rayon,wxRealPoint& point1,double angle2,wxColour couleur);
        void OnMouseMove(wxMouseEvent &event);
        bool estDessine;
        
        // pour le cercle
        wxRealPoint ptCentre;
        double rayon;
        wxArrayDouble listeAngle;
        
        int hauteurTexteMin;
        int num_courant;
        wxArrayRect listeRect;
        wxStaticText texte;
    public:
	    wxArrayColour listeCouleur;
		// No description
		wxFont LaFont;
		wxFont TitreFont;
		wxFont AxeFont;
		wxArrayInt aiNbre;
        wxArrayString asCommentaire;
        wxColour couleurTexte;
        wxColour couleurTitre;
        wxColour couleurAxe;
        wxPen penTraits;
        wxSize tailleDessin;
        wxString Titre;
        int espaceDroit,espaceHaut,espaceBas,espaceGauche,espaceCentre;
        int espaceCase,espaceTexteCase,espaceRectangle,espaceTitreDessin;
        int espaceBarre;
        int calc_hauteur_min();
        int calc_largeur_min();
       void Dessiner();
        void DrawCercle(wxDC& dc);
	    enum myTypeGraph
	    {
             Cercle,
             Rectangle,
             RectangleBas
        } typeGraph;
    protected:
        void OnDraw(wxDC& dcOrig);
};

class GestionCoul : public wxDialog
{
private:
    DECLARE_EVENT_TABLE()
public:
    GestionCoul( wxWindow *parent,wxArrayColour ListeCouleur,wxArrayString ListeTexte,wxFont laFont,wxColour laCouleur,wxFont titreFont,wxColour laCouleurTitre,wxFont lAxeFont,wxColour lAxeCouleur,
        const wxString &title = _T("Gestion de liste de couleur"),
        const wxPoint& pos = wxDefaultPosition);
    GestionCoul( wxWindow *parent,MonCamembert *fromage,
        const wxString &title = _T("Gestion de liste de couleur"),
        const wxPoint& pos = wxDefaultPosition);
    virtual ~GestionCoul();
    void GestionCoul::wxButtonOK(wxCommandEvent& event);
    void GestionCoul::wxButtonCANCEL(wxCommandEvent& event);
public:

  //Do not add custom Control Declarations here.
  //wx-devcpp will remove them. Try adding the custom code 
  //after the block.
  ////GUI Control Declaration Start
	wxTextCtrl *TexteAxe;
	wxButton *wxButtonAxe;
	wxPanel *WxNoteBookPageAxe;
	wxTextCtrl *TexteTexte;
	wxButton *wxButtonTexte;
	wxPanel *WxNoteBookPageTexte;
	wxTextCtrl *TexteTitre;
	wxButton *wxButtonTitre;
	wxPanel *WxNoteBookPageTitre;
	wxScrolledWindow *WxNoteBookPageCouleur;
	wxNotebook *WxNotebook1;
	wxButton *BUTTONANNULER;
	wxButton *BUTTONOK;
	wxPanel *WxPanel1;
  ////GUI Control Declaration End
  
public:
    wxArrayColour mesCouleurs;
    wxFont maFont;
    wxFont monTitreFont;
    wxFont monAxeFont;
    wxColour maCouleur;
    wxColour monTitreCouleur;
    wxColour monAxeCouleur;
private:
    MonCamembert *vache;
    wxFont maFontTmp;
    wxFont monTitreFontTmp;
    wxFont monAxeFontTmp;
    wxArrayColour mesCouleursTmp;
    wxColour maCouleurTmp;
    wxColour monTitreCouleurTmp;
    wxColour monAxeCouleurTmp;
    wxArrayString mesCommentaires;
    
    wxArrayPtrCarreCouleur listeCarreCouleur;
    wxArrayPtrStaticText listeStaticText;
        
public:
    //Note: if you receive any error with these enums, then you need to
    //change your old form code that are based on the #define control ids.
    //#defines may replace a numeric value for the enums names.
    //Try copy pasting the below block in your old Form header Files.
	enum {
////GUI Enum Control ID Start
ID_TEXTEAXE = 1022,
ID_BUTTONAXE = 1021,
ID_WXNOTEBOOKPAGEAXE = 1016,
ID_TEXTETEXTE = 1020,
ID_BUTTONTEXTE = 1019,
ID_WXNOTEBOOKPAGETEXTE = 1015,
ID_TEXTETITRE = 1018,
ID_BUTTONTITRE = 1017,
ID_WXNOTEBOOKPAGETITRE = 1014,
ID_WXNOTEBOOKPAGECOULEUR = 1013,
ID_WXNOTEBOOK1 = 1012,
ID_WXBUTTON2 = 1011,
ID_WXBUTTON1 = 1010,
ID_WXPANEL1 = 1009,
////GUI Enum Control ID End
ID_BUTTONOK = 1150,
ID_BUTTONANNULER = 1151,
   ID_DUMMY_VALUE_ //Dont Delete this DummyValue
   }; //End of Enum

public:
    void GestionCoulClose(wxCloseEvent& event);
    void CreateGUIControls(void);
    void ChangeCouleur(wxCommandEvent& event);
	void wxButtonTitreClick(wxCommandEvent& event);
	void wxButtonTexteClick(wxCommandEvent& event);
	void wxButtonAxeClick(wxCommandEvent& event);

};

class CarreCouleur : public wxWindow
{
private:
    DECLARE_EVENT_TABLE()
public:
    CarreCouleur(wxWindow *parent,wxPoint position,wxSize size,wxColour couleurFond,int id);
    ~CarreCouleur();
    
    void DBClick(wxMouseEvent& event);
    wxColour couleurFond;
    int numero;
    
};

enum
{
    GLC_CH_COLOR = 7500
};


#endif
 
 
 
 
