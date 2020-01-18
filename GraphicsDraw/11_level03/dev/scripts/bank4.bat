REM bank2	Generic sprite tiles
@echo off

cd ..
cd banks
cd bank4

REM boss32
bmp2tile.exe raw\boss32_00.png -savetiles "boss32_00 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\boss32_01.png -savetiles "boss32_01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\boss32_02.png -savetiles "boss32_02 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit

REM boss64
bmp2tile.exe raw\boss64_00.png -savetiles "boss64_00 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\boss64_01.png -savetiles "boss64_01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\boss64_02.png -savetiles "boss64_02 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\boss64_03.png -savetiles "boss64_03 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\boss64_04.png -savetiles "boss64_04 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\boss64_05.png -savetiles "boss64_05 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit

cd ..
folder2c bank2 bank2 2

sdcc -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK2 bank2.c

del *.asm > nul
del *.lst > nul
del *.sym > nul

cd ..
cd scripts