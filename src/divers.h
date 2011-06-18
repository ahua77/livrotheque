// Name:        divers.h
// Author:      PE EPAILLARD
// Created:     10/27/2004 12:22:10 AM
//
//Copyright PE Epaillard, 10/27/2004 
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

#ifndef __DIVERS_HPP_
#define __DIVERS_HPP_

#include <stdio.h>
#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif
#include <wx/dnd.h>
#include <wx/string.h>
#include <wx/image.h>
#include <wx/dataobj.h>


#define TAILLE_BLOCK 500
#define TAILLE_TOKEN 30

#define PARTICULARITE_NB 5

//#define NUM_VERSION_BASE "0.5"
// variable globale pour stocker le chemin de load d'images
static wxString chemin_image;
            
class DnDFile;
class ImageCanvas;
//prototypage
wxString gettempdir();
void resize_image(wxString nom_fichier,int larg,int haut,wxString nom_fichier_arrivee="");
void gestion_quote(wxString &chaine);
wxString gestion_quote2(const wxString& chaine); 
wxString string_nettoie(wxString lachaine);
void convert_html(wxString &texte);
void convert_html_total(wxString &texte); 
void convert_quote(wxString &texte);
//void rempli_canvas(ImageCanvas *lecanvas, wxImage *image);
    
class livre
{
private:
    wxString nom_table;
    int nb_token;
    wxString *valeur;
    wxString affiche;
    int nb_gen_encourt;

public:
    livre();
    ~livre(); 
    void gen_create_livre(wxString &ch_create);
    int gen_create_tout(wxString &ch_create, int &nb);
    void gen_create_personne(wxString &ch_create);
    int select_tout(char *query);
    void select_image(wxString id,wxString &query, int &nb_img);
    wxString get_label_particularite(int n_token);
    int n_token();
    wxString get_nom_token(int n_token);
    wxString Get_token_type(wxString nom_t);
};

/*class myBitmapPanel : public wxPanel
{
public:
    myBitmapPanel(wxWindow* parent, wxWindowID id = -1, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL, const wxString& name = "panel");
//    refresh();
};
*/


class DnDFile : public wxFileDropTarget
{
public:
    ImageCanvas *moncanvas;
    wxString chemin;
    DnDFile(ImageCanvas *lecanvas) { 
        moncanvas=lecanvas ;
        SetDataObject(new wxBitmapDataObject);
    }

    virtual bool OnDropFiles(wxCoord x, wxCoord y, const wxArrayString& filenames);
    virtual wxDragResult OnData(wxCoord x, wxCoord y, wxDragResult def);
};

class ImageCanvas : public wxScrolledWindow
{
    private :
    //wxString nom;
    public:
    bool charge;
    wxImage image_s;
    wxBitmap * m_bmp;
    bool cliquable;
    DnDFile *p_FileDrop;
     
    void rempli_canvas();
    ImageCanvas( wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size )
        : wxScrolledWindow( parent, id, pos, size, wxCLIP_CHILDREN  )
    {
        p_FileDrop = new DnDFile(this);
        cliquable=true;
        charge=false;
        this->SetDropTarget(p_FileDrop);
        //m_bmp=NULL;
    }    

    ImageCanvas( wxString ch_img, wxWindow *parent, wxWindowID id,
                        const wxPoint &pos, const wxSize &size )
            : wxScrolledWindow( parent, id, pos, size, wxCLIP_CHILDREN  )
    {
        p_FileDrop = new DnDFile(this);
        cliquable=true;
        bool tt;
        tt=image_s.LoadFile(ch_img);
        if (tt==true)
            rempli_canvas();
        this->SetDropTarget(p_FileDrop);
        //wxMessageBox("pou","probleme", wxOK | wxICON_EXCLAMATION, this);
    }
    ImageCanvas( wxImage image, wxWindow *parent, wxWindowID id,
                        const wxPoint &pos, const wxSize &size )
            : wxScrolledWindow( parent, id, pos, size, wxCLIP_CHILDREN  )
    {
        p_FileDrop = new DnDFile(this);
        cliquable=true;
        image_s=image;
        rempli_canvas();
        this->SetDropTarget(p_FileDrop);
        //wxMessageBox("pou","probleme", wxOK | wxICON_EXCLAMATION, this);
    }
    ~ImageCanvas() {
        /*efface();
        wxMessageBox(nom,"probleme", wxOK | wxICON_EXCLAMATION, this);*/
    }    
    void init(wxImage img) {
        efface();
        image_s = img;
        rempli_canvas();
        //charge=true;
    }    
    void init(wxString ch_img) {
        bool tt;
        tt=image_s.LoadFile(ch_img);
        efface();
        if (tt==true)
            rempli_canvas();
        else
            wxMessageBox("probleme lors du chargement de l'image : "+ch_img,"probleme", wxOK | wxICON_EXCLAMATION, this);
        
    }    
    void set_cliquable(bool click=true) {
        cliquable=click;
    }
    void OnLeftUp( wxMouseEvent &event );

    void OnPaint( wxPaintEvent &event )
    {
        //wxMessageBox("pou2","probleme", wxOK | wxICON_EXCLAMATION, this);
        wxPaintDC dc( this );
        PrepareDC( dc );
        if (charge==true)
            dc.DrawBitmap( *m_bmp, 1, 1 , TRUE);
        else
            dc.Clear();
    }
    void efface()
    {
        if(charge==true) {
            delete m_bmp;
            m_bmp=NULL;
            charge=false;
        }
    }        
private:
    //DECLARE_DYNAMIC_CLASS(ImageCanvas)
    DECLARE_EVENT_TABLE()
};


#endif

