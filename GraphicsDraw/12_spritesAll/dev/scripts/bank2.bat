REM bank2	Generic sprite tiles
@echo off

cd ..
cd banks
cd bank2

REM boss64
bmp2tile.exe raw\64\00.png -savetiles "boss64_pro01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -savepalette "boss64_pro01 (palette).bin" -fullpalette -spritepalette -exit
bmp2tile.exe raw\64\01.png -savetiles "boss64_pro02 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -savepalette "boss64_pro02 (palette).bin" -fullpalette -spritepalette -exit
bmp2tile.exe raw\64\02.png -savetiles "boss64_adi01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -savepalette "boss64_adi01 (palette).bin" -fullpalette -spritepalette -exit
bmp2tile.exe raw\64\03.png -savetiles "boss64_adi02 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -savepalette "boss64_adi02 (palette).bin" -fullpalette -spritepalette -exit
bmp2tile.exe raw\64\04.png -savetiles "boss64_suz01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -savepalette "boss64_suz01 (palette).bin" -fullpalette -spritepalette -exit
bmp2tile.exe raw\64\05.png -savetiles "boss64_suz02 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -savepalette "boss64_suz02 (palette).bin" -fullpalette -spritepalette -exit


REM boss32
bmp2tile.exe raw\32\00.png -savetiles "boss32_pro01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -savepalette "boss32_pro01 (palette).bin" -fullpalette -spritepalette -exit
bmp2tile.exe raw\32\01.png -savetiles "boss32_adi01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -savepalette "boss32_adi01 (palette).bin" -fullpalette -spritepalette -exit
bmp2tile.exe raw\32\02.png -savetiles "boss32_suz01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -savepalette "boss32_suz01 (palette).bin" -fullpalette -spritepalette -exit


cd ..
folder2c bank2 bank2 2

sdcc -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK2 bank2.c

del *.asm > nul
del *.lst > nul
del *.sym > nul

cd ..
cd scripts