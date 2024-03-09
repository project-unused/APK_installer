@echo off
set d=%cd%
rename *.exe apk_installer.exe
mkdir "%systemdrive%\Program Files\apt_installer\"
robocopy /mir . "%systemdrive%\Program Files\apt_installer\"
setx path=%path%;"%systemdrive%\Program Files\apt_installer\"