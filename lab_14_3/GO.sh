MYMAIN=main
gcc -c main_funcs.c -o main_funcs.o
gcc -c memory.c -o memory.o
gcc -c io.c -o io.o
gcc -fdiagnostics-color=always -pipe -Wall -Winvalid-pch -Wextra -Wpedantic -std=c99 -g -Wno-unused-parameter -Wno-switch -D_UI_STATIC -MD -MQ -MF -c ${MYMAIN}.c -o ${MYMAIN}.obj

ECHO STAGE 1 COMPLETE -- HEIL TO THE KING!

D:/msys64/mingw64/bin/windres.EXE -D_UI_STATIC --preprocessor-arg=-MD resources.rc resources.o

ECHO STAGE 2 COMPLETE -- HEIL TO THE KING!

c++ -o ${MYMAIN}.exe resources.o main_funcs.o io.o memory.o ${MYMAIN}.obj -Wl,--allow-shlib-undefined -static -static-libgcc -static-libstdc++ -Wl,--start-group libui.a -luser32 -lkernel32 -lgdi32 -lcomctl32 -luxtheme -lmsimg32 -lcomdlg32 -ld2d1 -ldwrite -lole32 -loleaut32 -loleacc -luuid -lwindowscodecs -luser32 -lkernel32 -lgdi32 -lcomctl32 -luxtheme -lmsimg32 -lcomdlg32 -ld2d1 -ldwrite -lole32 -loleaut32 -loleacc -luuid -lwindowscodecs -Wl,--end-group -mconsole

ECHO STAGE 2 COMPLETE -- HEIL TO THE KING!

./${MYMAIN}.exe &