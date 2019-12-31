cd ..
cd gfx

:: Tiles
bmp2tile.exe raw\font_tiles.bmp -savetiles "font_tiles (tiles).psgcompr" -noremovedupes -planar -tileoffset   0  -savetilemap "font_tiles (tilemap).bin" -savepalette "font_tiles (palette).bin" -fullpalette -exit
bmp2tile.exe raw\data_tiles.bmp -savetiles "data_tiles (tiles).psgcompr" -noremovedupes -planar -tileoffset  64  -savetilemap "data_tiles (tilemap).bin" -savepalette "data_tiles (palette).bin" -fullpalette -exit
bmp2tile.exe raw\game_title.bmp -savetiles "game_title (tiles).psgcompr" -noremovedupes -planar -tileoffset 160 -savetilemap "game_title (tilemap).bin" -savepalette "game_title (palette).bin" -fullpalette -exit

cd ..
cd dev