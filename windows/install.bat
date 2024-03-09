@echo off
set d=%cd%
rename *.exe apk_installer.exe
mkdir "%systemdrive%\Program Files\apk_installer\"
robocopy /mir . "%systemdrive%\Program Files\apk_installer"
setx path "%path%;%systemdrive%\Program Files\apk_installer\"