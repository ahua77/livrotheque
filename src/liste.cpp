//---------------------------------------------------------------------------
//
// Name:        liste.cpp
// Author:      Fougny
// Created:     22/12/04 10:40:02
//
//Copyright  PE Epaillard, 22/12/04 
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
    #pragma implementation "liste.cpp"
#endif

/* for compilers that support precompilation
   includes "wx/wx.h" */

#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif


#include "liste.h"

////Header Include Start
////Header Include End


long liste::s_nbInstances = 0;

//----------------------------------------------------------------------------
// liste
//----------------------------------------------------------------------------

    ////Event Table Start
BEGIN_EVENT_TABLE(liste,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(liste::listeClose)
END_EVENT_TABLE()
    ////Event Table End



liste::liste( wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style )
    : wxDialog( parent, id, title, position, size, style)
{
    s_nbInstances++;
    wxLogMessage("liste::liste() - nbInstances = %ld", s_nbInstances);
    CreateGUIControls();
}

liste::~liste()
{
    s_nbInstances--;
    wxLogMessage("liste::~liste() - nbInstances = %ld", s_nbInstances);    
} 

void liste::CreateGUIControls(void)
{
    ////GUI Items Creation Start

	wxBoxSizer* WxBoxSizer_l = new wxBoxSizer(wxVERTICAL);
	this->SetSizer(WxBoxSizer_l);
	this->SetAutoLayout(TRUE);

	wxArrayString arrayStringFor_liste_combo;
	liste_combo =  new wxComboBox(this, ID_LISTE_COMBO ,_("liste_combo") ,wxPoint(5,5),wxSize(90,21), arrayStringFor_liste_combo   );
	WxBoxSizer_l->Add(liste_combo,0,wxALIGN_CENTER_HORIZONTAL | wxALL,5);

	liste_arbre =  new wxTreeCtrl(this, ID_LISTE_ARBRE, wxPoint(13,36),wxSize(73,200)  , wxTR_HAS_BUTTONS);
	WxBoxSizer_l->Add(liste_arbre,0,wxALIGN_CENTER_HORIZONTAL | wxALL,0);

	GetSizer()->Fit(this);
	GetSizer()->SetSizeHints(this);
	this->SetTitle(_("liste"));
	this->Center();
	this->SetIcon(wxNullIcon);
	
    ////GUI Items Creation End
}

void liste::listeClose(wxCloseEvent& event)
{
    // --> Don't use Close with a wxDialog,
    // use Destroy instead.
    Destroy();
}
 
