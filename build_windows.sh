x86_64-w64-mingw32-g++ ./windows/$1 -static-libstdc++ -static-libgcc $2 $3 $4 $5 $6 $7 $8 $9 -o apk_installer_Win_amd64.exe
i686-w64-mingw32-g++ ./windows/$1 -static-libstdc++ -static-libgcc $2 $3 $4 $5 $6 $7 $8 $9 -o apk_installer_Win_i386.exe
arm-none-eabi-gcc ./windows/$1 -static-libstdc++ -static-libgcc $2 $3 $4 $5 $6 $7 $8 $9 -o apk_installer_Win_arm64.exe