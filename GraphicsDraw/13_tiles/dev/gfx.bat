cd ..
cd gfx

:: Tiles
::bmp2tile.exe raw\font_tiles.bmp -savetiles "font_tiles (tiles).psgcompr" -noremovedupes -planar -tileoffset 0  -savetilemap "font_tiles (tilemap).bin" -savepalette "font_tiles (palette).bin" -fullpalette -exit
::bmp2tile.exe raw\tree_avoid.bmp -savetiles "tree_avoid (tiles).psgcompr" -noremovedupes -planar -tileoffset 64 -savetilemap "tree_avoid (tilemap).bin" -savepalette "tree_avoid (palette).bin" -fullpalette -exit

bmp2tile.exe raw\data_tiles.bmp -savetiles "data_tiles (tiles).psgcompr" -noremovedupes -planar -tileoffset 64  -savetilemap "data_tiles (tilemap).bin" -savepalette "data_tiles (palette).bin" -fullpalette -exit


:: Sprites
:: https://github.com/maxim-zhao/bmp2tile
::bmp2tile.exe raw\candykids.bmp -savetiles "candykids (tiles).psgcompr" -noremovedupes -nomirror -planar -tileoffset 0  -savepalette "candykids (palette).bin" -fullpalette  -spritepalette -exit
::bmp2tile.exe raw\candymama.bmp -savetiles "candymama (tiles).psgcompr" -noremovedupes -nomirror -planar -tileoffset   0  -spritepalette -exit
::bmp2tile.exe raw\candykids.bmp -savetiles "candykids (tiles).psgcompr" -noremovedupes -nomirror -planar -tileoffset 128  -spritepalette -exit

::bmp2tile.exe raw\sprites.bmp -savetiles "sprites (tiles).psgcompr" -noremovedupes -nomirror -planar -tileoffset 0 -savepalette "sprites (palette).bin" -fullpalette  -spritepalette -exit

cd ..
cd dev