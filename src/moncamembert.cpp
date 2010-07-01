//---------------------------------------------------------------------------
//
// Name:        GestionCoul.cpp
// Author:      lootens
// Created:     29/08/2005 17:15:49
//
//Copyright  PE Epaillard, 29/08/2005 
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

#include "moncamembert.h"

//Do not add custom headers.
//wx-dvcpp designer will remove them
////Header Include Start
////Header Include End

#include <wx/log.h>

#include <wx/arrimpl.cpp>
WX_DEFINE_OBJARRAY(wxArrayColour);
WX_DEFINE_OBJARRAY(wxArrayRect);
//WX_DEFINE_OBJARRAY(wxArrayDouble);

BEGIN_DECLARE_EVENT_TYPES()
    DECLARE_EVENT_TYPE(wxEVT_CH_COLOR, 7777)
END_DECLARE_EVENT_TYPES()

DEFINE_EVENT_TYPE(wxEVT_CH_COLOR)

// it may also be convenient to define an event table macro for this event type
#define EVT_CH_COLOR(id, fn) \
    DECLARE_EVENT_TABLE_ENTRY( \
        wxEVT_CH_COLOR, id, wxID_ANY, \
        (wxObjectEventFunction)(wxEventFunction) wxStaticCastEvent( wxCommandEventFunction, &fn ), \
        (wxObject *) NULL \
    ),

/*
#include <wx/file.h>
void EcrireFichier(wxString texte);

void EcrireFichier(wxString texte)
{
    wxFile file(_T("trace.txt"),wxFile::read_write);
    file.SeekEnd(0);
    file.Write(texte + "\n");
    file.Close();
}
*/

long GestionCoul::s_nbInstances = 0;


//----------------------------------------------------------------------------
// GestionCoul
//----------------------------------------------------------------------------
     //Add Custom Events only in the appropriate Block.
    // Code added in  other places will be removed by wx-dvcpp 
    ////Event Table Start
BEGIN_EVENT_TABLE(GestionCoul,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(GestionCoul::GestionCoulClose)
	EVT_BUTTON(ID_BUTTONTITRE,GestionCoul::wxButtonTitreClick)
	EVT_BUTTON(ID_BUTTONOK,GestionCoul::wxButtonOK)
	EVT_BUTTON(ID_BUTTONANNULER,GestionCoul::wxButtonCANCEL)
	EVT_BUTTON(ID_BUTTONTEXTE,GestionCoul::wxButtonTexteClick)
	EVT_BUTTON(ID_BUTTONAXE,GestionCoul::wxButtonAxeClick)
	EVT_CH_COLOR(GLC_CH_COLOR,GestionCoul::ChangeCouleur)
END_EVENT_TABLE()
    ////Event Table End

GestionCoul::GestionCoul(wxWindow *parent,wxArrayColour ListeCouleur,wxArrayString ListeTexte,wxFont laFont,wxColour laCouleur,wxFont leTitreFont,wxColour leTitreCouleur,wxFont lAxeFont,wxColour lAxeCouleur,
        const wxString &title,
        const wxPoint& pos)
    : wxDialog( parent, wxID_ANY, title, pos, wxSize(500,500), wxCAPTION)
{
    s_nbInstances++;
    wxLogMessage("GestionCoul::GestionCoul() - nbInstances = %ld", s_nbInstances);

    wxFont fontT(14,wxMODERN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD);
    wxColour couleurT=*wxBLACK;
    int i;
    
    CreateGUIControls();
    
    listeCarreCouleur.Clear();
    listeStaticText.Clear();
    
    vache=NULL;
    maFont = laFont;
    maFontTmp = laFont;
    monTitreFont = leTitreFont;
    monTitreFontTmp = leTitreFont;
    monAxeFont = lAxeFont;
    monAxeFontTmp = lAxeFont;
    
    maCouleur = laCouleur;
    maCouleurTmp = laCouleur;
    monTitreCouleur = leTitreCouleur;
    monTitreCouleurTmp = leTitreCouleur;
    monAxeCouleur = lAxeCouleur;
    monAxeCouleurTmp = lAxeCouleur;
    
    mesCouleurs = ListeCouleur;
    mesCouleursTmp = ListeCouleur;
    
    mesCommentaires = ListeTexte;
  
    for (i=0;i<(int) mesCommentaires.GetCount();i++)
    {
        CarreCouleur* MaWindow;
        MaWindow = new CarreCouleur(WxNoteBookPageCouleur,wxPoint(10,27*i + 10),wxSize(25,25),mesCouleursTmp.Item(i),i);
        listeCarreCouleur.Add(MaWindow);
        
        wxStaticText *staticText;
        staticText = new wxStaticText(WxNoteBookPageCouleur,wxID_ANY,mesCommentaires.Item(i),wxPoint(40,27*i + 11));
        staticText->SetFont(fontT);
        staticText->SetForegroundColour(couleurT);
        listeStaticText.Add(staticText);
    }
    
    listeStaticText.Shrink();
    listeCarreCouleur.Shrink();
    
    if (27*i + 10 + 25 > 530)
    {
        WxNoteBookPageCouleur->SetScrollbars(0,10,0,(27*i + 10 + 25+9)/10);
    }

    TexteTexte->SetForegroundColour(maCouleurTmp);
	TexteTexte->SetFont(maFontTmp);
	
	TexteTitre->SetForegroundColour(monTitreCouleurTmp);
	TexteTitre->SetFont(monTitreFontTmp);
	
	TexteAxe->SetForegroundColour(monAxeCouleurTmp);
	TexteAxe->SetFont(monAxeFontTmp);
	
}

GestionCoul::GestionCoul(wxWindow *parent,MonCamembert *fromage,
        const wxString &title,
        const wxPoint& pos)
    :wxDialog(parent,wxID_ANY,title,pos,wxSize(500,500),wxCAPTION) 
{
    s_nbInstances++;
    wxLogMessage("GestionCoul::GestionCoul() - nbInstances = %ld", s_nbInstances);

    wxFont fontT(14,wxMODERN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD);
    wxColour couleurT=*wxBLACK;
    int i;
    
    CreateGUIControls();
    
    listeCarreCouleur.Clear();
    listeStaticText.Clear();
    
    maFont = fromage->LaFont;
    maFontTmp = fromage->LaFont;
    monTitreFontTmp = fromage->TitreFont;
    monTitreFont = fromage->TitreFont;
    monAxeFont = fromage->AxeFont;
    monAxeFontTmp = fromage->AxeFont;
    
    maCouleur = fromage->couleurTexte;
    maCouleurTmp = fromage->couleurTexte;
    monTitreCouleur = fromage->couleurTitre;
    monTitreCouleurTmp = fromage->couleurTitre;
    monAxeCouleur = fromage->couleurAxe;
    monAxeCouleurTmp = fromage->couleurAxe;
    
    mesCouleurs = fromage->listeCouleur;
    mesCouleursTmp = fromage->listeCouleur;
    
    mesCommentaires = fromage->asCommentaire;

    vache=fromage;
    
    for (i=0;i<(int) mesCommentaires.GetCount();i++)
    {
        CarreCouleur* MaWindow;
        MaWindow = new CarreCouleur(WxNoteBookPageCouleur,wxPoint(10,27*i + 10),wxSize(25,25),mesCouleursTmp.Item(i),i);
        listeCarreCouleur.Add(MaWindow);
        
        wxStaticText *staticText;
        staticText = new wxStaticText(WxNoteBookPageCouleur,wxID_ANY,mesCommentaires.Item(i),wxPoint(40,27*i + 11));
        staticText->SetFont(fontT);
        staticText->SetForegroundColour(couleurT);
        listeStaticText.Add(staticText);
    }
    
    listeStaticText.Shrink();
    listeCarreCouleur.Shrink();
    
    if (27*i + 10 + 25 > 530)
    {
        WxNoteBookPageCouleur->SetScrollbars(0,10,0,(27*i + 10 + 25+9)/10);
    }

    TexteTexte->SetForegroundColour(maCouleurTmp);
	TexteTexte->SetFont(maFontTmp);
	
	TexteTitre->SetForegroundColour(monTitreCouleurTmp);
	TexteTitre->SetFont(monTitreFontTmp);
	
	TexteAxe->SetForegroundColour(monAxeCouleurTmp);
	TexteAxe->SetFont(monAxeFontTmp);
	
}

GestionCoul::~GestionCoul()
{
    s_nbInstances--;
    wxLogMessage("GestionCoul::~GestionCoul() - nbInstances = %ld", s_nbInstances);
} 

void GestionCoul::CreateGUIControls(void)
{
    //Do not add custom Code here
    //wx-devcpp designer will remove them.
    //Add the custom code before or after the Blocks
    ////GUI Items Creation Start

	WxPanel1 = new wxPanel(this, ID_WXPANEL1, wxPoint(0,0), wxSize(565,601));

	BUTTONOK = new wxButton(WxPanel1, ID_BUTTONOK, wxT("Sauvegarder"), wxPoint(35,555), wxSize(180,35), 0, wxDefaultValidator, wxT("BUTTONOK"));

	BUTTONANNULER = new wxButton(WxPanel1, ID_BUTTONANNULER, wxT("Annuler"), wxPoint(340,555), wxSize(180,35), 0, wxDefaultValidator, wxT("BUTTONANNULER"));

	WxNotebook1 = new wxNotebook(WxPanel1, ID_WXNOTEBOOK1, wxPoint(12,16),wxSize(539,528));

	WxNoteBookPageCouleur = new wxScrolledWindow(WxNotebook1, ID_WXNOTEBOOKPAGECOULEUR, wxPoint(4,24), wxSize(531,500));
	WxNotebook1->AddPage(WxNoteBookPageCouleur, wxT("Couleur"));

	WxNoteBookPageTitre = new wxPanel(WxNotebook1, ID_WXNOTEBOOKPAGETITRE, wxPoint(4,24), wxSize(531,500));
	WxNotebook1->AddPage(WxNoteBookPageTitre, wxT("Titre"));
	
	WxNoteBookPageTexte = new wxPanel(WxNotebook1, ID_WXNOTEBOOKPAGETEXTE, wxPoint(4,24), wxSize(531,500));
	WxNotebook1->AddPage(WxNoteBookPageTexte, wxT("Texte"));

	wxButtonTitre = new wxButton(WxNoteBookPageTitre, ID_BUTTONTITRE, wxT("Changer la font du Titre"), wxPoint(180,10), wxSize(180,35), 0, wxDefaultValidator, wxT("wxButtonTitre"));

	TexteTitre = new wxTextCtrl(WxNoteBookPageTitre, ID_TEXTETITRE, wxT("Texte d'essai"), wxPoint(2,55), wxSize(525,440), 0, wxDefaultValidator, wxT("TexteTitre"));
	TexteTitre->SetMaxLength(0);

	wxButtonTexte = new wxButton(WxNoteBookPageTexte, ID_BUTTONTEXTE, wxT("Changer la font du Texte"), wxPoint(180,10), wxSize(180,35), 0, wxDefaultValidator, wxT("wxButtonTexte"));

	TexteTexte = new wxTextCtrl(WxNoteBookPageTexte, ID_TEXTETEXTE, wxT("Texte d'essai"), wxPoint(2,55), wxSize(525,440), 0, wxDefaultValidator, wxT("TexteTexte"));
	TexteTexte->SetMaxLength(0);

	WxNoteBookPageAxe = new wxPanel(WxNotebook1, ID_WXNOTEBOOKPAGEAXE, wxPoint(4,24), wxSize(531,500));
	WxNotebook1->AddPage(WxNoteBookPageAxe, wxT("Axe"));

	wxButtonAxe = new wxButton(WxNoteBookPageAxe, ID_BUTTONAXE, wxT("Changer la font de l'Axe"), wxPoint(180,10), wxSize(180,35), 0, wxDefaultValidator, wxT("wxButtonAxe"));

	TexteAxe = new wxTextCtrl(WxNoteBookPageAxe, ID_TEXTEAXE, wxT("Texte d'essai"), wxPoint(2,55), wxSize(525,440), 0, wxDefaultValidator, wxT("TexteAxe"));
	TexteAxe->SetMaxLength(0);

	this->SetSize(8,8,573,635);
	this->SetTitle(wxT("Gestion des Couleurs et des Fonts"));
	this->Center();
	this->SetIcon(wxNullIcon);
	
    ////GUI Items Creation End
}

void GestionCoul::GestionCoulClose(wxCloseEvent& event)
{
    // --> Don't use Close with a Frame,
    // use Destroy instead.
    Destroy();
}

void GestionCoul::wxButtonOK(wxCommandEvent& event)
{
    mesCouleurs = mesCouleursTmp;
	maFont = maFontTmp;
	maCouleur = maCouleurTmp;
	monTitreFont = monTitreFontTmp;
	monTitreCouleur = monTitreCouleurTmp;
	monAxeFont = monAxeFontTmp;
	monAxeCouleur = monAxeCouleurTmp;
    if (vache != NULL) {
        vache->listeCouleur = mesCouleurs;
        vache->LaFont = maFont;
        vache->couleurTexte = maCouleur;
        vache->couleurTitre = monTitreCouleur;
        vache->TitreFont = monTitreFont;
        vache->AxeFont = monAxeFont;
        vache->couleurAxe = monAxeCouleur;
        vache->Dessiner();
    }
    
    EndModal(1);
    Destroy();
    event.Skip();
}

void GestionCoul::wxButtonCANCEL(wxCommandEvent& event)
{
    EndModal(0);
    Destroy();
    event.Skip();
}

void GestionCoul::ChangeCouleur(wxCommandEvent& event)
{
     mesCouleursTmp.Item(event.GetInt())=*(wxColour*)event.GetClientData();
     
     event.Skip();
}

BEGIN_EVENT_TABLE(CarreCouleur,wxWindow)
    EVT_LEFT_DCLICK(CarreCouleur::DBClick)
END_EVENT_TABLE()

CarreCouleur::CarreCouleur(wxWindow *parent,wxPoint position,wxSize size,wxColour couleur,int id)
   :wxWindow(parent,wxID_ANY,position,size,wxDOUBLE_BORDER)
{
    numero = id;
    SetBackgroundColour(couleur);
    couleurFond = couleur;
}

CarreCouleur::~CarreCouleur()
{
               
}

void CarreCouleur::DBClick(wxMouseEvent& event)
{    
    wxColourData data;
    data.SetColour(couleurFond);
    wxColourDialog dialog(this, &data);

    if ( dialog.ShowModal() == wxID_OK )
    {
        couleurFond = dialog.GetColourData().GetColour();
        SetBackgroundColour(couleurFond);
        Refresh();
        
        wxCommandEvent eventCustom(wxEVT_CH_COLOR,GLC_CH_COLOR);
        eventCustom.SetClientData(&couleurFond);
        eventCustom.SetInt(numero);
        ProcessEvent(eventCustom);
    }

    event.Skip();         
}

BEGIN_EVENT_TABLE(MonCamembert, wxScrolledWindow)
    EVT_MOTION (MonCamembert::OnMouseMove)
END_EVENT_TABLE()

// class constructor
MonCamembert::MonCamembert(wxWindow* parent,wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name)
: wxScrolledWindow(parent, id, pos, size,style,name)
{
	// insert your code here

    //Titre
    Titre = "Pour PE";
    couleurTitre = wxColour(200,123,23);
    
    //Axe
    couleurAxe = *wxBLACK;
    AxeFont = wxFont(8,wxMODERN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL);
    
    //init font
    LaFont=wxFont(12,wxMODERN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD);
    TitreFont=wxFont(20,wxMODERN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD);
    
    //init liste nbre
    aiNbre.Clear();
    
    //init liste commentaire
    asCommentaire.Clear();
    
    // flag dessin
    estDessine = false;
    
    //init couleur fond
    couleurTexte=*wxBLACK;
    
    //init traits
    penTraits = *wxBLACK_PEN;
    
    //init size
    //int largeur,hauteur;
    //GetVirtualSize(&largeur,&hauteur);
    tailleDessin=size;
    
    espaceDroit = 10;
    espaceHaut = 3;
    espaceBas = 5;
    espaceGauche = 5;
    espaceCentre = 5;
    espaceRectangle = 5;
    espaceTitreDessin = 3;
    espaceCase=5;
    espaceTexteCase=5;
    espaceBarre=5;
    
    hauteurTexteMin=0;
    //type de graphique
    //typeGraph=Cercle;
    typeGraph=RectangleBas;
    
    texte.Create(this,wxID_ANY,"");
    texte.Show(false);
    num_courant = -1;
}

// class destructor
MonCamembert::~MonCamembert()
{
	// insert your code here
}

void MonCamembert::OnMouseMove(wxMouseEvent &event)
{
    int heightTmp,widthTmp,clientWidth,clientHeight;
    wxPoint pos_mouse = event.GetPosition();
    wxClientDC dc(this);
    //PrepareDC(dc);
    DoPrepareDC(dc);
    wxPoint pos = event.GetLogicalPosition(dc);
    
    if (typeGraph == Rectangle || typeGraph == RectangleBas)
    {
        wxRect rectTmp;
        bool dans_rect;
        
        dans_rect=false;
    
        for (int i=0;i<(int)listeRect.GetCount();i++)
        {
            if (listeRect.Item(i).Inside(pos))
            {
                if (num_courant != i)
                {
                    wxString strTexte;
                    strTexte.Printf("(%d)",aiNbre.Item(i));
                    texte.SetLabel(asCommentaire.Item(i) + strTexte);
                    texte.SetFont(LaFont);
                    
                    wxColour couleur_inverse;
                    int rouge,vert,bleu;
                    rouge = (int) listeCouleur.Item(i).Red();
                    vert = (int) listeCouleur.Item(i).Green();
                    bleu = (int) listeCouleur.Item(i).Blue();
                    rouge = (rouge < 123 ? 255 : 0);
                    vert = (vert < 123 ? 255 : 0);
                    bleu = (bleu < 123 ? 255 : 0);
                    couleur_inverse.Set(rouge,vert,bleu);
                    
                    texte.SetForegroundColour(couleur_inverse);
                    texte.SetBackgroundColour(listeCouleur.Item(i));
                    if (!texte.IsShown())
                    {
                       texte.Show(true);
                    }
                    num_courant=i;
                }
                dans_rect=true;
                break;
            }
        }
        
        if (texte.IsShown() && !dans_rect)
        {
            texte.Show(false);
            num_courant = -1;
        }
    }
    if (typeGraph == Cercle)
    {
        wxRect rectTmp;
        bool dans_arc;
        double distance;
        double angle1=360,angle2,alpha=10;
        double PI = 4 * atan(1);
        
        dans_arc=false;
    
        distance = (double) sqrt((ptCentre.x - pos.x)*(ptCentre.x - pos.x) + (ptCentre.y - pos.y)*(ptCentre.y - pos.y));
        if (distance > 3)
        {
            alpha = acos((pos.x-ptCentre.x)/distance) *180/PI;
            if (pos.y < ptCentre.y)
            {
                alpha = 360-alpha;          
            }
        }
        if ((distance < rayon) && (distance > 5))
        {
            for (int i=0;i<(int)listeAngle.GetCount();i++)
            {
                angle2 = listeAngle.Item(i);
                if (angle2 != angle1)
                {
                    if (alpha<angle1 && alpha>angle2)
                    {
                        if (num_courant != i)
                        {
                            wxString strTexte;
                            strTexte.Printf("(%d)",aiNbre.Item(i));
                            texte.SetLabel(asCommentaire.Item(i) + strTexte);
                            texte.SetFont(LaFont);
                            
                            wxColour couleur_inverse;
                            int rouge,vert,bleu;
                            rouge = (int) listeCouleur.Item(i).Red();
                            vert = (int) listeCouleur.Item(i).Green();
                            bleu = (int) listeCouleur.Item(i).Blue();
                            rouge = (rouge < 123 ? 255 : 0);
                            vert = (vert < 123 ? 255 : 0);
                            bleu = (bleu < 123 ? 255 : 0);
                            couleur_inverse.Set(rouge,vert,bleu);
                            
                            texte.SetForegroundColour(couleur_inverse);
                            texte.SetBackgroundColour(listeCouleur.Item(i));
                            if (!texte.IsShown())
                            {
                               texte.Show(true);
                            }
                            num_courant=i;
                        }
                        dans_arc=true;
                        break;
                    }
                }
                angle1=angle2;
            }
        }
        if (texte.IsShown() && !dans_arc)
        {
            texte.Show(false);
            num_courant = -1;
        }
    }
    texte.GetSize(&widthTmp,&heightTmp);
    this->GetClientSize(&clientWidth,&clientHeight);
    if (pos_mouse.x + widthTmp >= clientWidth)
    {
        texte.Move(pos_mouse.x - widthTmp,pos_mouse.y - heightTmp);
    } else {
        texte.Move(pos_mouse.x,pos_mouse.y - heightTmp);
    }
    event.Skip();
}

// No description
void MonCamembert::DrawCercle(wxDC& dc)
{
    //EcrireFichier("debut draw cercle");
	/* TODO (#1#): Implement test2DFrm::DrawCercle() */
	float Total=0;
	int iNb,iNbCom;
	double xComDeb=0,yComDeb=0;
	double angle1=360,angle2;
	wxRealPoint pointDebut;
	int hauteurAxe,largeurAxe;
	
	int largeurColonne=0;
	int valeurMax=0;
	int hauteurRectangle=0;
	int pas,pasPixel;
	int valeur;
	valeur=0;
	pas=0;
	pasPixel=0;
	
	int largeurNombre,hauteurNombre;

    iNb = aiNbre.GetCount();
	iNbCom = asCommentaire.GetCount();
	
	int hauteur,largeur;
    hauteur = tailleDessin.GetHeight();
    largeur = tailleDessin.GetWidth();
    
	dc.SetPen(penTraits);
    dc.DrawRectangle(0,0,largeur,hauteur);
	    
	//cherche hauteur,largeur titre
	dc.SetTextForeground(couleurTitre);
    dc.SetFont(TitreFont);
    
    int hauteurTitre,largeurTitre;
    dc.GetTextExtent(Titre,&largeurTitre,&hauteurTitre);
	dc.DrawText(Titre,(wxCoord)((largeur - largeurTitre)/2),(wxCoord)(espaceHaut));
    
    //cherche hauteur,largeur Texte
    dc.SetTextForeground(couleurTexte);
    dc.SetFont(LaFont);
    int hauteurFont,largeurFont,hauteurFontMax,largeurFontMax;
    hauteurFontMax=0;
    largeurFontMax=0;    
    
    //EcrireFichier("debut calcul font Max");
    for (int i=0;i < iNb;i++)
    {
        dc.GetTextExtent(asCommentaire.Item(i),&largeurFont,&hauteurFont);
        if (hauteurFont > hauteurFontMax)
            hauteurFontMax = hauteurFont;
        if (largeurFont > largeurFontMax)
            largeurFontMax = largeurFont;
        if (valeurMax<aiNbre.Item(i))
            valeurMax=aiNbre.Item(i);
        Total += aiNbre.Item(i);
    }
    //EcrireFichier("fin calcul font Max");
    //EcrireFichier("debut calcul taille");
    if (typeGraph == Cercle)
    {
        listeAngle.Clear();
        
    	int largeurCercle;
    	largeurCercle = largeur - espaceGauche - espaceDroit - espaceCentre - espaceTexteCase - hauteurFontMax - largeurFontMax;
    	int hauteurCercle;
    	hauteurCercle = hauteur - espaceHaut - espaceBas - hauteurTitre - espaceTitreDessin;
    		
    	if (largeurCercle<40 || hauteurCercle<40)
    	{
            estDessine = false;
            //wxMessageBox("Le cercle a dessiner est trop petit","Cercle", wxOK | wxICON_EXCLAMATION);
            return;
        }
    	if (largeurCercle<hauteurCercle)
    	{
            rayon = (double)largeurCercle/2;
        } else {
            rayon = (double)hauteurCercle/2;
        }
        ptCentre=wxRealPoint(rayon + (double)espaceGauche,rayon + (double)(espaceHaut + hauteurTitre + espaceTitreDessin));	
    	
    	xComDeb = ptCentre.x + (double)espaceCentre + rayon;
    	yComDeb = (double)(espaceHaut + hauteurTitre + espaceTitreDessin);
    	
    	pointDebut=wxRealPoint(ptCentre.x + rayon,ptCentre.y);
    }
    if (typeGraph == Rectangle || typeGraph == RectangleBas)
    {   
        //EcrireFichier("debut rect clear");
        listeRect.Clear();
        //EcrireFichier("fin rect clear");
        if (typeGraph == Rectangle)
        {
  	        hauteurRectangle = hauteur - espaceHaut - espaceBas - hauteurTitre - espaceTitreDessin;
        }
        if (typeGraph == RectangleBas)
        {
  	        hauteurRectangle = hauteur - espaceHaut - espaceBas - hauteurTitre - espaceTitreDessin - espaceTexteCase - largeurFontMax;
        }
    	//EcrireFichier("apres hauteur rect");
    	
    	hauteurTexteMin = 0;
    	//cherche hauteur,largeur Axe
        dc.SetTextForeground(couleurAxe);
        dc.SetFont(AxeFont);
        
        hauteurAxe=0;
        largeurAxe=0;
        wxString valTest;
        valTest.Printf("%d",valeurMax);
        dc.GetTextExtent(valTest,&largeurAxe,&hauteurAxe);
        //EcrireFichier("apres Axe");
        
    	int largeurRectangle=0;
    	if (typeGraph == Rectangle)
        {
  	        largeurRectangle = largeur - espaceGauche - espaceDroit - espaceCentre - espaceTexteCase - hauteurFontMax - largeurFontMax - largeurAxe - espaceRectangle - espaceBarre;
        }
        if (typeGraph == RectangleBas)
        {
  	        largeurRectangle = largeur - espaceGauche - espaceDroit - largeurAxe - espaceRectangle - espaceBarre;
        }
    	//EcrireFichier("apres largeur rect");
    	
    	if (largeurRectangle<((iNb-1)*espaceRectangle+3*iNb) || hauteurRectangle<40)
    	{
            estDessine = false;
            //wxMessageBox("Le dessin est trop petit","Rectangle", wxOK | wxICON_EXCLAMATION);
            return;
        }
        //EcrireFichier("apres test largeur");
        
        largeurColonne = (int) ((largeurRectangle-(iNb-1)*espaceRectangle)/iNb);
        
        xComDeb = (double) (largeurRectangle + espaceGauche + espaceCentre + espaceBarre + largeurAxe + espaceRectangle);
        dc.SetBrush(wxBrush(*wxBLACK, wxSOLID));
        if (typeGraph == Rectangle)
        {
    	    yComDeb = (double)(espaceHaut + hauteurTitre + espaceTitreDessin);
    	    dc.DrawLine((wxCoord)(espaceGauche + largeurAxe + espaceRectangle),(wxCoord)yComDeb,(wxCoord)(espaceGauche + largeurAxe + espaceRectangle),(wxCoord)(yComDeb + hauteurRectangle));
    	    dc.DrawLine((wxCoord)(espaceGauche + largeurAxe + espaceRectangle),(wxCoord)(yComDeb + hauteurRectangle),(wxCoord)(espaceGauche + largeurAxe + espaceRectangle + largeurRectangle + espaceBarre),(wxCoord)(yComDeb + hauteurRectangle));
    	
    	    dc.DrawLine((wxCoord)(espaceGauche + largeurAxe + espaceRectangle),(wxCoord)yComDeb,(wxCoord)(espaceGauche + largeurAxe),(wxCoord)yComDeb);
    	    dc.DrawText(valTest,(wxCoord)(espaceGauche),(wxCoord)(yComDeb - hauteurAxe/2));
        }
    	if (typeGraph == RectangleBas)
    	{
            yComDeb = (double)(espaceHaut + hauteurTitre + espaceTitreDessin);
            
            dc.DrawLine((wxCoord)(espaceGauche + largeurAxe + espaceRectangle),(wxCoord)yComDeb,(wxCoord)(espaceGauche + largeurAxe + espaceRectangle),(wxCoord)(yComDeb + hauteurRectangle));
    	    dc.DrawLine((wxCoord)(espaceGauche + largeurAxe + espaceRectangle),(wxCoord)(yComDeb + hauteurRectangle),(wxCoord)(espaceGauche + largeurAxe + espaceRectangle + largeurRectangle + espaceBarre),(wxCoord)(yComDeb + hauteurRectangle));
    	
    	    dc.DrawLine((wxCoord)(espaceGauche + largeurAxe + espaceRectangle),(wxCoord)yComDeb,(wxCoord)(espaceGauche + largeurAxe),(wxCoord)yComDeb);
    	    dc.DrawText(valTest,(wxCoord)(espaceGauche),(wxCoord)(yComDeb - hauteurAxe/2));
    	    
    	    yComDeb = hauteurRectangle + espaceHaut + hauteurTitre + espaceTitreDessin + espaceTexteCase;
        }
        //EcrireFichier("apres com deb");
        
    	//graduation
    	int nbGradu;
    	nbGradu = (int) (hauteurRectangle / (4*hauteurAxe));
    	
    	if (nbGradu >= 1)
    	{
            pas = (int) (round((double)((double)valeurMax/(double)nbGradu)/5) * 5);
            if (pas==0)
            {
               pas = (int) (round((double)((double)valeurMax/(double)nbGradu)/4) * 4);
            }
            if (pas==0)
            {
               pas = (int) (round((double)((double)valeurMax/(double)nbGradu)/3) * 3);
            }
            if (pas==0)
            {
               pas = (int) (round((double)((double)valeurMax/(double)nbGradu)/2) * 2);
            }
            if (pas==0)
            {
               pas = 1;
            }
            pasPixel = (int) (pas * hauteurRectangle / valeurMax);
        }
    	//EcrireFichier("apres calcul graduation");
    	
    	int j=0;
    	int yMin,yCourant=0;
        dc.GetTextExtent("0123456789",&largeurNombre,&hauteurNombre);
    	yMin = (int) (espaceHaut + hauteurTitre + espaceTitreDessin + hauteurNombre/2);
    	if (typeGraph == Rectangle)
        {
    	    yCourant = hauteur - espaceBas - j*pasPixel;
        }
        if (typeGraph == RectangleBas)
        {
            yCourant = hauteur - espaceBas - j*pasPixel - espaceTexteCase - largeurFontMax;
        }
    	while (yCourant>yMin && ((int) valeurMax > (int) pas*j) && pas!=0)
    	{
            //wxString test;
            //test.Printf("ycour=%d,ymin=%d,valeurmax=%d,pas*j=%d",yCourant,yMin,(int) valeurMax,(int) pas*j);
            //EcrireFichier(test);
              
            if (typeGraph == Rectangle)
            {
                dc.DrawLine((wxCoord)(espaceGauche + largeurAxe + espaceRectangle),(wxCoord)(hauteur - espaceBas - j*pasPixel),(wxCoord)(espaceGauche + largeurAxe),(wxCoord)(hauteur - espaceBas - j*pasPixel));
            }
            if (typeGraph == RectangleBas)
            {
                //EcrireFichier("draw graduation");
                dc.DrawLine((wxCoord)(espaceGauche + largeurAxe + espaceRectangle),(wxCoord)(hauteur - espaceBas - j*pasPixel - espaceTexteCase - largeurFontMax),(wxCoord)(espaceGauche + largeurAxe),(wxCoord)(hauteur - espaceBas - j*pasPixel - espaceTexteCase - largeurFontMax));
            }
            valTest.Printf("%d",pas*j);
            dc.GetTextExtent(valTest,&largeurNombre,&hauteurNombre);

            if (j!=0)
            {
                if (typeGraph == Rectangle)
                {
                    dc.DrawText(valTest,(wxCoord)(espaceGauche + largeurAxe - largeurNombre),(wxCoord)(hauteur - espaceBas - j*pasPixel - hauteurAxe/2));
                }
                if (typeGraph == RectangleBas)
                {
                    //EcrireFichier("draw texte axe");
                    dc.DrawText(valTest,(wxCoord)(espaceGauche + largeurAxe - largeurNombre),(wxCoord)(hauteur - espaceBas - j*pasPixel - hauteurAxe/2 - espaceTexteCase - largeurFontMax));
                }
            }
            j++;
            if (typeGraph == Rectangle)
            {
        	    yCourant = hauteur - espaceBas - j*pasPixel;
            }
            if (typeGraph == RectangleBas)
            {
                yCourant = hauteur - espaceBas - j*pasPixel - espaceTexteCase - largeurFontMax;
            }
        }

    }
    //EcrireFichier("fin calcul taille");
    
    dc.SetTextForeground(couleurTexte);
    dc.SetFont(LaFont);
	if (iNb != 0 && iNbCom == iNb)
	{
        if (Total != 0)
        {
            for (int i=0;i<iNb;i++)
        	{
                dc.SetBrush(wxBrush(listeCouleur.Item(i), wxSOLID));
                if (typeGraph == Cercle)
                {
                    if (i == iNb-1)
                    {
                        angle2=0;
                    } else
                    {
                        angle2 = angle1 - 360*(double)(aiNbre.Item(i))/(double)Total;
                    }
                    listeAngle.Add(angle2);
                    if (aiNbre.Item(i) != 0)
                    {
        	            dessiner_portion(dc,ptCentre,rayon,pointDebut,angle2,listeCouleur.Item(i));
                        angle1 = angle2;
                    }
                }
                if (typeGraph == Rectangle || typeGraph == RectangleBas)
                {
                    wxString mess;
                    //mess.Printf("x=%d,y=%d,larg=%d,haut=%d,hauteur=%d,nombre=%d
                    
                    dc.SetBrush(wxBrush(listeCouleur.Item(i), wxSOLID));
                    if (typeGraph == Rectangle)
                    {
                        dc.DrawRectangle(espaceBarre + largeurAxe + espaceRectangle + espaceGauche + i*(espaceRectangle + largeurColonne),hauteur - espaceBas - (aiNbre.Item(i)*hauteurRectangle/valeurMax),largeurColonne,aiNbre.Item(i)*hauteurRectangle/valeurMax + 1);
                        listeRect.Add(wxRect(espaceBarre + largeurAxe + espaceRectangle + espaceGauche + i*(espaceRectangle + largeurColonne),hauteur - espaceBas - (aiNbre.Item(i)*hauteurRectangle/valeurMax),largeurColonne,aiNbre.Item(i)*hauteurRectangle/valeurMax + 1));
                    }
                    if (typeGraph == RectangleBas)
                    {
                        dc.DrawRectangle(espaceBarre + largeurAxe + espaceRectangle + espaceGauche + i*(espaceRectangle + largeurColonne),hauteur - espaceTexteCase - largeurFontMax - espaceBas - (aiNbre.Item(i)*hauteurRectangle/valeurMax),largeurColonne,aiNbre.Item(i)*hauteurRectangle/valeurMax + 1);
                        listeRect.Add(wxRect(espaceBarre + largeurAxe + espaceRectangle + espaceGauche + i*(espaceRectangle + largeurColonne),hauteur - espaceTexteCase - largeurFontMax - espaceBas - (aiNbre.Item(i)*hauteurRectangle/valeurMax),largeurColonne,aiNbre.Item(i)*hauteurRectangle/valeurMax + 1));
                    }
                    dc.SetBrush(wxBrush(*wxBLACK, wxSOLID));
                    if (typeGraph == Rectangle)
                    {
                        dc.DrawLine((wxCoord)(espaceBarre + largeurAxe + espaceRectangle + espaceGauche + i*(espaceRectangle + largeurColonne)),hauteur - espaceBas,(wxCoord)(espaceBarre + largeurAxe + espaceRectangle + espaceGauche + i*(espaceRectangle + largeurColonne)),hauteur - espaceBas - espaceRectangle);
                        dc.DrawLine((wxCoord)(espaceBarre + largeurAxe + espaceRectangle + espaceGauche + largeurColonne - 1 + i*(espaceRectangle + largeurColonne)),hauteur - espaceBas,(wxCoord)(espaceBarre + largeurAxe + espaceRectangle + espaceGauche + largeurColonne - 1 + i*(espaceRectangle + largeurColonne)),hauteur - espaceBas - espaceRectangle);
                    }
                    if (typeGraph == RectangleBas)
                    {
                        dc.DrawLine((wxCoord)(espaceBarre + largeurAxe + espaceRectangle + espaceGauche + i*(espaceRectangle + largeurColonne)),hauteur - espaceTexteCase - largeurFontMax - espaceBas,(wxCoord)(espaceBarre + largeurAxe + espaceRectangle + espaceGauche + i*(espaceRectangle + largeurColonne)),hauteur - espaceTexteCase - largeurFontMax - espaceBas - espaceRectangle);
                        dc.DrawLine((wxCoord)(espaceBarre + largeurAxe + espaceRectangle + espaceGauche + largeurColonne - 1 + i*(espaceRectangle + largeurColonne)),hauteur - espaceTexteCase - largeurFontMax - espaceBas,(wxCoord)(espaceBarre + largeurAxe + espaceRectangle + espaceGauche + largeurColonne - 1 + i*(espaceRectangle + largeurColonne)),hauteur - espaceTexteCase - largeurFontMax - espaceBas - espaceRectangle);
    	                dc.DrawRotatedText(asCommentaire.Item(i),(wxCoord)(espaceBarre + largeurAxe + espaceRectangle + espaceGauche + i*(espaceRectangle + largeurColonne) + largeurColonne/2 + hauteurFontMax/2),(wxCoord)(yComDeb),-90);
                    }
                } 
                if (typeGraph != RectangleBas)
                {
                    dc.SetBrush(wxBrush(listeCouleur.Item(i), wxSOLID));
    	            dc.DrawRectangle((wxCoord)(xComDeb),(wxCoord)(yComDeb + (hauteurFontMax + espaceCase)*i),hauteurFontMax,hauteurFontMax);
    	            dc.DrawText(asCommentaire.Item(i),(wxCoord)(xComDeb + espaceTexteCase + hauteurFontMax),(wxCoord)(yComDeb + (hauteurFontMax + espaceCase)*i));
                }
            }
            hauteurTexteMin = (int) (yComDeb + (hauteurFontMax + espaceCase)* iNb);
        }	
    }
    //EcrireFichier("fin draw cercle");
}


int MonCamembert::calc_hauteur_min() {
    //EcrireFichier("debut calcul hauteur min");
	int yComDeb=0;
	int iNb;
    int hauteurTitre=0,largeurTitre=0;
    wxScreenDC dc;
    //wxDC dc;
    int hauteurFont=0,largeurFont=0,hauteurFontMax=0,largeurFontMax=0;
    wxString mess;

    iNb = aiNbre.GetCount();
    if (iNb <=0)
        return 0;
    hauteurFontMax=0;
    largeurFontMax=0;    
    
    dc.SetFont(TitreFont);
    dc.GetTextExtent(Titre,&largeurTitre,&hauteurTitre);
    dc.SetFont(LaFont);
    for (int i=0;i < iNb;i++)
    {
        dc.GetTextExtent(asCommentaire.Item(i),&largeurFont,&hauteurFont);
        if (hauteurFont > hauteurFontMax)
            hauteurFontMax = hauteurFont;
        if (largeurFont > largeurFontMax)
            largeurFontMax = largeurFont;
        /*if (valeurMax<aiNbre.Item(i))
            valeurMax=aiNbre.Item(i);*/
        /*Total += aiNbre.Item(i);*/
    }
    yComDeb = (espaceHaut + hauteurTitre + espaceTitreDessin);
    //mess.Printf("espaceHaut %d,hauteurTitre %d, espaceTitreDessin %d, iNb:%d, hauteurFontMax; %d, espaceCase:%d",
    //        espaceHaut, hauteurTitre, espaceTitreDessin,iNb,hauteurFontMax,espaceCase);
    //wxMessageBox(mess,"Nombres/Commentaires", wxOK | wxICON_EXCLAMATION);
    if (typeGraph == RectangleBas)
    {
        //EcrireFichier("fin calcul hauteur min");
        return (int) (espaceTexteCase + largeurFontMax + yComDeb + 4*hauteurFontMax);
    } else 
    {
        //EcrireFichier("fin calcul hauteur min");
        return (int) (yComDeb + (hauteurFontMax + espaceCase)* iNb);
    }
    //return hauteurTexteMin;
}

int MonCamembert::calc_largeur_min() {
    //EcrireFichier("debut calcul largeur min");
	int iNb,valeurMax=0;
    int hauteurTitre=0,largeurTitre=0;
    wxScreenDC dc;
    //wxDC dc;
    int hauteurFont=0,largeurFont=0,hauteurFontMax=0,largeurFontMax=0;
    wxString mess;

    iNb = aiNbre.GetCount();
    if (iNb <=0)
        return 0;
    hauteurFontMax=0;
    largeurFontMax=0;    
    
    dc.SetFont(TitreFont);
    dc.GetTextExtent(Titre,&largeurTitre,&hauteurTitre);
    dc.SetFont(LaFont);
    for (int i=0;i < iNb;i++)
    {
        dc.GetTextExtent(asCommentaire.Item(i),&largeurFont,&hauteurFont);
        if (hauteurFont > hauteurFontMax)
            hauteurFontMax = hauteurFont;
        if (largeurFont > largeurFontMax)
            largeurFontMax = largeurFont;
        if (valeurMax<aiNbre.Item(i))
            valeurMax = aiNbre.Item(i);
    }
    
    int largeurAxe,hauteurAxe;
    wxString testValeur;
        
    testValeur.Printf("%d",valeurMax);
    dc.SetFont(AxeFont);
    dc.GetTextExtent(testValeur,&largeurAxe,&hauteurAxe);
        
    if (typeGraph == RectangleBas)
    {
        if (largeurTitre > espaceGauche + espaceDroit + espaceBarre + largeurAxe + espaceRectangle + iNb*(espaceRectangle + hauteurFontMax))
        {
            //EcrireFichier("fin calcul largeur min");
            return (int) largeurTitre;
        } else
        {
            //EcrireFichier("fin calcul largeur min");
            return (int) (espaceGauche + espaceDroit + espaceBarre + largeurAxe + espaceRectangle + iNb*(espaceRectangle + hauteurFontMax));
        }
    }
    if (typeGraph == Rectangle)
    {
        if (largeurTitre > espaceGauche + espaceDroit + espaceBarre + largeurAxe + espaceRectangle + iNb*(espaceRectangle + 5) + espaceCentre + largeurFontMax + espaceTexteCase + hauteurFontMax)
        {
            //EcrireFichier("fin calcul largeur min");
            return (int) largeurTitre;
        } else
        {
            //EcrireFichier("fin calcul largeur min");
            return (int) (espaceGauche + espaceDroit + espaceBarre + largeurAxe + espaceRectangle + iNb*(espaceRectangle + 5) + espaceCentre + largeurFontMax + espaceTexteCase + hauteurFontMax);
        }
    }
    if (typeGraph == Cercle) 
    {
        if (largeurTitre > 80 + espaceGauche + espaceDroit + espaceCentre + espaceTexteCase + hauteurFontMax + largeurFontMax)
        {
            //EcrireFichier("fin calcul largeur min");
            return (int) largeurTitre;
        } else {
            //EcrireFichier("fin calcul largeur min");
            return (int) 80 + espaceGauche + espaceDroit + espaceCentre + espaceTexteCase + hauteurFontMax + largeurFontMax;
        }
    }
    //return hauteurTexteMin;
    return 0;
}

// No description
void MonCamembert::dessiner_portion(wxDC &dc,wxRealPoint ptCentre,double rayon,wxRealPoint& point1,double angle2,wxColour couleur)
{
	/* TODO (#1#): Implement test2DFrm::dessiner_portion() */
	double x2,y2,xc,yc;
	double PI = 4 * atan(1);
	
	xc = ptCentre.x;
	yc = ptCentre.y;
	
	dc.SetBrush(wxBrush(couleur, wxSOLID));
	
	//x1 = xc + (double) (rayon*(double)cos(angle1*PI/180));
	//y1 = yc + (double) (rayon*(double)sin(angle1*PI/180));
	if (angle2==0)
	{
        x2 = xc + rayon;
        y2 = yc;
    } else {
	    x2 = xc + (double) (rayon*(double)cos(angle2*PI/180));
	    y2 = yc + (double) (rayon*(double)sin(angle2*PI/180));
    }
	
	dc.DrawArc((wxCoord)point1.x,(wxCoord)point1.y,(wxCoord)x2,(wxCoord)y2,(wxCoord)xc,(wxCoord)yc);
	
	point1.x = x2;
	point1.y = y2;
}

void MonCamembert::OnDraw(wxDC& dc)
{
    int i;
    
    if (estDessine)
    {
        int nbre_int,nbre_string;
    
        nbre_int = aiNbre.GetCount();
    	nbre_string = asCommentaire.GetCount();
    	
    	if (nbre_int <= 0)
        {
            estDessine = false;
            wxMessageBox("Il n'y a aucune donnée dans la liste des nombres","Nombres", wxOK | wxICON_EXCLAMATION);
            return;
        }
        if (nbre_string <= 0)
        {
            estDessine = false;
            wxMessageBox("Il n'y a aucune donnée dans la liste des commentaires","Commentaires", wxOK | wxICON_EXCLAMATION);
            return;
        }
        if (nbre_string != nbre_int)
        {
            estDessine = false;
            wxMessageBox("Le nombre de commentaires est différent de celui des nombres","Nombres/Commentaires", wxOK | wxICON_EXCLAMATION);
            return;
        }
        if ((int) listeCouleur.GetCount() < nbre_int)
        {
            srand(static_cast<unsigned>(time(0)));
            int test=nbre_int - listeCouleur.GetCount();
            for (i=0;i<test;i++) {
                listeCouleur.Add(wxColour(rand()%255,rand()%255,rand()%255));
            }
        }
    
        DrawCercle(dc);
     }
}

void MonCamembert::Dessiner()
{
    //EcrireFichier("debut dessiner");
    //wxClientDC dc(this);
    int i;
    
    int nbre_int,nbre_string;
    
    nbre_int = aiNbre.GetCount();
	nbre_string = asCommentaire.GetCount();
	
	if (nbre_int <= 0)
    {
        estDessine = false;
        wxMessageBox("Il n'y a aucune donnée dans la liste des nombres","Nombres", wxOK | wxICON_EXCLAMATION);
        return;
    }
    if (nbre_string <= 0)
    {
        estDessine = false;
        wxMessageBox("Il n'y a aucune donnée dans la liste des commentaires","Commentaires", wxOK | wxICON_EXCLAMATION);
        return;
    }
    if (nbre_string != nbre_int)
    {
        estDessine = false;
        wxMessageBox("Le nombre de commentaires est différent de celui des nombres","Nombres/Commentaires", wxOK | wxICON_EXCLAMATION);
        return;
    }
    if ((int) listeCouleur.GetCount() < nbre_int)
    {
        srand(static_cast<unsigned>(time(0)));
        int test=nbre_int - listeCouleur.GetCount();
        for (i=0;i<test;i++) {
            listeCouleur.Add(wxColour(rand()%255,rand()%255,rand()%255));
        }
    }
    
    estDessine = true;
    
    wxSize lataille;
    if (aiNbre.GetCount() >0) {
        SetSize(tailleDessin);
        SetScrollbars(0,0,0,0);
        if (tailleDessin.GetWidth()<calc_largeur_min() && tailleDessin.GetHeight()<calc_hauteur_min())
        {
            SetScrollbars(10,10,(calc_largeur_min()+9)/10,(calc_hauteur_min()+9)/10);
            tailleDessin=::wxSize(calc_largeur_min()+1,calc_hauteur_min()+1);
        } else {
            if (tailleDessin.GetHeight()<calc_hauteur_min()) {
                SetScrollbars(0,10,0,(calc_hauteur_min()+9)/10);
                tailleDessin=::wxSize(tailleDessin.GetWidth()-15,calc_hauteur_min()+1);
            }
            if (tailleDessin.GetWidth()<calc_largeur_min()) {
                SetScrollbars(10,0,(calc_largeur_min()+9)/10,0);
                tailleDessin=::wxSize(calc_largeur_min()+1,tailleDessin.GetHeight()-15);
            }
        }
    }
    //EcrireFichier("milieu dessiner");
    Refresh();
    //EcrireFichier("fin dessiner");
}

/*
 * wxButtonTitreClick
 */
void GestionCoul::wxButtonTitreClick(wxCommandEvent& event)
{
	// insert your code here
	wxFontData data;
    data.SetInitialFont(monTitreFontTmp);
    data.SetColour(monTitreCouleurTmp);
    wxFontDialog fontDialog(this,data);
    if ( fontDialog.ShowModal() == wxID_OK )
    {
        monTitreFontTmp = fontDialog.GetFontData().GetChosenFont();
        monTitreCouleurTmp = fontDialog.GetFontData().GetColour();
        TexteTitre->SetForegroundColour(monTitreCouleurTmp);
	    TexteTitre->SetFont(monTitreFontTmp);
        Refresh();
    }
	event.Skip();
}

/*
 * wxButtonTitreClick
 */
void GestionCoul::wxButtonTexteClick(wxCommandEvent& event)
{
	// insert your code here
	wxFontData data;
    data.SetInitialFont(maFontTmp);
    data.SetColour(maCouleurTmp);
    wxFontDialog fontDialog(this,data);
    if ( fontDialog.ShowModal() == wxID_OK )
    {
        maFontTmp = fontDialog.GetFontData().GetChosenFont();
        maCouleurTmp = fontDialog.GetFontData().GetColour();
        TexteTexte->SetForegroundColour(maCouleurTmp);
	    TexteTexte->SetFont(maFontTmp);
        Refresh();
    }
	event.Skip();
}

/*
 * wxButtonTitreClick
 */
void GestionCoul::wxButtonAxeClick(wxCommandEvent& event)
{
	// insert your code here
	wxFontData data;
    data.SetInitialFont(monAxeFontTmp);
    data.SetColour(monAxeCouleurTmp);
    wxFontDialog fontDialog(this,data);
    if ( fontDialog.ShowModal() == wxID_OK )
    {
        monAxeFontTmp = fontDialog.GetFontData().GetChosenFont();
        monAxeCouleurTmp = fontDialog.GetFontData().GetColour();
        TexteAxe->SetForegroundColour(monAxeCouleurTmp);
	    TexteAxe->SetFont(monAxeFontTmp);
        Refresh();
    }
	event.Skip();
}
