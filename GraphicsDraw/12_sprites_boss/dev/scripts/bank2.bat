REM bank2	Generic sprite tiles
@echo off

cd ..
cd banks
cd bank2

REM boss32
bmp2tile.exe raw\boss32_adi01.bmp -savetiles "boss32_adi01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\boss32_pro01.bmp -savetiles "boss32_pro01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\boss32_suz01.bmp -savetiles "boss32_suz01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\boss32_adi02.bmp -savetiles "boss32_adi02 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\boss32_pro02.bmp -savetiles "boss32_pro02 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\boss32_suz02.bmp -savetiles "boss32_suz02 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit

REM boss64
bmp2tile.exe raw\boss64_adi01.bmp -savetiles "boss64_adi01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\boss64_pro01.bmp -savetiles "boss64_pro01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\boss64_suz01.bmp -savetiles "boss64_suz01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\boss64_adi02.bmp -savetiles "boss64_adi02 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\boss64_pro02.bmp -savetiles "boss64_pro02 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit
bmp2tile.exe raw\boss64_suz02.bmp -savetiles "boss64_suz02 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit

cd ..
folder2c bank2 bank2 2

sdcc -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK2 bank2.c

del *.asm > nul
del *.lst > nul
del *.sym > nul

cd ..
cd scripts