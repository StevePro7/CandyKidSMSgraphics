cd ..
cd gfx

:: Tiles
bmp2tile.exe raw\font_tiles.bmp -savetiles "font_tiles (tiles).psgcompr" -noremovedupes -planar -tileoffset  0 -savetilemap "font_tiles (tilemap).bin" -savepalette "font_tiles (palette).bin" -fullpalette -exit
bmp2tile.exe raw\apex_tiles.png -savetiles "apex_tiles (tiles).psgcompr" -noremovedupes -planar -tileoffset 64 -savetilemap "apex_tiles (tilemap).bin" -savepalette "apex_tiles (palette).bin" -fullpalette -exit
::bmp2tile.exe raw\data_tiles.bmp -savetiles "data_tiles (tiles).psgcompr" -noremovedupes -planar -tileoffset  64 -savetilemap "data_tiles (tilemap).bin" -savepalette "data_tiles (palette).bin" -fullpalette -exit

:: Sprites
bmp2tile.exe raw\sprites.bmp -savetiles "sprites (tiles).psgcompr" -noremovedupes -nomirror -planar -tileoffset 0 -savepalette "sprites (palette).bin" -fullpalette  -spritepalette -exit

cd ..
cd dev