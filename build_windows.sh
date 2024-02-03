x86_64-w64-mingw32-g++ ./windows/$1 -static-libstdc++ -static-libgcc $2 $3 $4 $5 $6 $7 $8 $9
i686-w64-mingw32-g++ ./windows/$1 -static-libstdc++ -static-libgcc $2 $3 $4 $5 $6 $7 $8 $9
arm-none-eabi-gcc ./windows/$1 -static-libstdc++ -static-libgcc $2 $3 $4 $5 $6 $7 $8 $9 -march=armv7-a -mfloat-abi=hard -mfpu=neon