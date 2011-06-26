;NSIS Modern User Interface
;Header Bitmap Example Script
;Written by Joost Verburg

;--------------------------------
;Include Modern UI

  !include "MUI.nsh"

	!define LIVRODIR "D:\developpement\livrotheque"
  !define Uninst '$INSTDIR\uninstall.exe'
;--------------------------------
;General

  ;Name and file
  Name "Livrotheque"
  OutFile "setup_livrotheque.exe"

  ;Default installation folder
  InstallDir "$PROGRAMFILES\livrotheque"
  
  ;Get installation folder from registry if available
  InstallDirRegKey HKCU "Software\livrotheque" ""

;--------------------------------
;Interface Configuration

  !define MUI_HEADERIMAGE
  !define MUI_HEADERIMAGE_BITMAP "${LIVRODIR}\Include\Images\minisplash.bmp" ; optional
  !define MUI_ABORTWARNING

;--------------------------------
;Pages

  !insertmacro MUI_PAGE_LICENSE "${LIVRODIR}\src\license.txt"
  !insertmacro MUI_PAGE_COMPONENTS
  !insertmacro MUI_PAGE_DIRECTORY
  !insertmacro MUI_PAGE_INSTFILES
  
  !insertmacro MUI_UNPAGE_CONFIRM
  !insertmacro MUI_UNPAGE_INSTFILES
  
;--------------------------------
;Languages
 
  !insertmacro MUI_LANGUAGE "French"

;--------------------------------
;Installer Sections

Section "Le programme" SecProg
SectionIn RO

  SetOutPath "$INSTDIR"
  
  ;ADD YOUR OWN FILES HERE...
  File  "${LIVRODIR}\exe\livrotheque.exe"
  File  "${LIVRODIR}\exe\libcurl-4.dll"
  File  "${LIVRODIR}\liste_a_importer_exemple.txt"
  
  ;Store installation folder
  WriteRegStr HKCU "Software\livrotheque" "" $INSTDIR
  
  ;Create uninstaller
  WriteUninstaller "$INSTDIR\Uninstall.exe"

SectionEnd

Section "raccourcis menu démarrer" SecRacd

   CreateDirectory "$SMPROGRAMS\Livrotheque"
   createshortcut '$SMPROGRAMS\Livrotheque\uninstall.lnk' '${Uninst}'
  CreateShortCut "$SMPROGRAMS\Livrotheque\Livrotheque.lnk" "$INSTDIR\Livrotheque.exe" "" "$INSTDIR\Livrotheque.exe" 0

SectionEnd

Section "raccourcis Bureau" SecRacb
  CreateShortCut "$DESKTOP\Livrotheque.lnk" "$INSTDIR\Livrotheque.exe" "" "$INSTDIR\Livrotheque.exe" 0
SectionEnd

Section "-Lancement"
MessageBox MB_YESNO "Voulez vous lancer le programme Livrotheque maintenant?" IDYES true IDNO false
true:
	Exec '"$INSTDIR\livrotheque.exe"'
false:
SectionEnd
;--------------------------------
;Descriptions

  ;Language strings
  LangString DESC_SecProg ${LANG_FRENCH} "le programme Livrotheque."
  LangString DESC_SecRacd ${LANG_FRENCH} "Installer les raccourcis dans le menu démarrer."
  LangString DESC_SecRacb ${LANG_FRENCH} "Installer les raccourcis sur le bureau."

  ;Assign language strings to sections
  !insertmacro MUI_FUNCTION_DESCRIPTION_BEGIN
    !insertmacro MUI_DESCRIPTION_TEXT ${SecProg} $(DESC_SecProg)
    !insertmacro MUI_DESCRIPTION_TEXT ${SecRacd} $(DESC_SecRacd)
    !insertmacro MUI_DESCRIPTION_TEXT ${SecRacb} $(DESC_SecRacb)
  !insertmacro MUI_FUNCTION_DESCRIPTION_END
 
;--------------------------------
;Uninstaller Section

Section "Uninstall"

  ;ADD YOUR OWN FILES HERE...
 	Delete "$INSTDIR\livrotheque.exe"
 	Delete "$INSTDIR\libcurl-4.dll"
 	Delete "$INSTDIR\liste_a_importer_exemple.txt"
	RMDir $INSTDIR

  Delete "$INSTDIR\Uninstall.exe"

  RMDir "$INSTDIR"

  ; Remove shortcuts, if any
  Delete "$SMPROGRAMS\Livrotheque\*.*"
	Delete "$DESKTOP\Livrotheque.lnk"
  ; Remove directories used
  RMDir "$SMPROGRAMS\Livrotheque"

  DeleteRegKey /ifempty HKCU "Software\livrotheque"

SectionEnd