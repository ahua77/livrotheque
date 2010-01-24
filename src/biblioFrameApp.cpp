//---------------------------------------------------------------------------
//
// Name:        newProgramFrameApp.cpp
// Author:      PE ePAILLARD
// Created:     01/01/2004 9:47:07 PM
//
//Copyright  PE Epaillard, 01/01/04 
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
#include "biblioFrameApp.h"
#include "biblioFrame.h"

IMPLEMENT_APP(biblioFrameApp)

bool biblioFrameApp::OnInit()
{
    // créer un fichier log.ini dans le répertoire de démarrage pour activer les log
    // les traces vont dans %temp%\livrotheque_YYYY-MM-DD.log, avec YYYY-MM-DD la date de lancement du programme (pas de rotation si le programme n'est pas relancé)
    FILE* logIni = fopen(".\\log.ini", "rt");
    if (logIni != NULL) {
        fclose(logIni);
        wxDateTime now = wxDateTime::Now(); 
        wxString filename = gettempdir() + "\\livrotheque_" + now.FormatISODate() + ".log";
        FILE* fichier = fopen(filename, "at");
        wxLogStderr* log = new wxLogStderr(fichier);
        log->SetTimestamp("[%Y-%m-%d %H:%M:%S] ");
        wxLog::SetActiveTarget(log);
    } else {
        wxLogNull* log = new wxLogNull;
//        wxLog::SetActiveTarget(log); -- inutile avec wxLogNull
    }

    wxLogMessage("================================================================================");
    wxLogMessage("-->                     démarrage de livrotheque");
    wxLogMessage("================================================================================");
    
	biblioFrame *myFrame = new  biblioFrame(NULL);
	SetTopWindow(myFrame);
	myFrame->Show(TRUE);		
	return TRUE;
}
 
int biblioFrameApp::OnExit()
{
	return 0;
}
