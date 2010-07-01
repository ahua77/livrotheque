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
 
