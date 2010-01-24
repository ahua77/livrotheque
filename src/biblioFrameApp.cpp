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
#include "biblioFrameApp.h"
#include "biblioFrame.h"

IMPLEMENT_APP(biblioFrameApp)

bool biblioFrameApp::OnInit()
{
    // cr�er un fichier log.ini dans le r�pertoire de d�marrage pour activer les log
    // les traces vont dans %temp%\livrotheque_YYYY-MM-DD.log, avec YYYY-MM-DD la date de lancement du programme (pas de rotation si le programme n'est pas relanc�)
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
    wxLogMessage("-->                     d�marrage de livrotheque");
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
