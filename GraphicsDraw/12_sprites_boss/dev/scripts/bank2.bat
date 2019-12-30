REM bank2	Generic sprite tiles
@echo off

cd ..
cd banks
cd bank2

REM player

bmp2tile.exe raw\boss32_adi01.bmp -savetiles "boss32_adi01 (tiles).psgcompr" -noremovedupes -planar -tileoffset 0 -exit



cd ..
folder2c bank2 bank2 2

sdcc -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK2 bank2.c

del *.asm > nul
del *.lst > nul
del *.sym > nul

cd ..
cd scripts