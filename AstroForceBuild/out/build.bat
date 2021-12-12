
cd Enemies
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 enemy.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 enemyshoot.c
cd ..

cd Fortresses
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 fortresscannon.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 fortressdoor.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 fortressphantom.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 fortresssearcher.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 fortresswave.c
cd ..

cd General
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 barrom.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 bombship.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 explosion.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 finishstage.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 gameoverstage.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 jukeboxstage.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 logostage.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 map.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 mikgamesstage.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 powerup.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 rectship.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 rsgthing.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 scripter.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 scroller.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 selectorstage.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 skullbone.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 spreadship.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 timeredlabel.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 turnship.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 warning.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 waveship.c
cd ..

cd Intros
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 intro1stage.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 intro2stage.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 intro3object.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 intro3stage.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 intro4stage.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 introovni.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 introsideplayer.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 introstage.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 introstar.c
cd ..

cd Monsters
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 monsterblob.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 monsterhead.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 monstermissil.c
cd ..

cd Players
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 player.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 playershoot.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 playstage.c
cd ..

cd Spaces
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 spaceasteroid.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 spaceshooter.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 spacestation.c
cd ..

cd Stages
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage1.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage1endboss.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage1middleboss.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage1middlebossb.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage1middlebossc.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage2.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage2endboss.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage2object.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage3.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage3endboss.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage3laser.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage3star.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage4.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage4endboss.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage4endbossb.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage4middleboss.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage4object.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage5.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage5endboss.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage5missile.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage6.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage6endboss.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage6endbossb.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage6object.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage7.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage7endboss.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage7middleboss.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage7object.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage8.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage8bossa.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage8bossb.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage8bossc.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 stage8lateral.c
cd ..

cd Vulcans
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 vulcanbird.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 vulcanlaser.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 vulcanlava.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 vulcanstation.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 vulcantank.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 vulcanvulcan.c
cd ..

cd Wars
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 ww2plane.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 ww2planeb.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 ww2ship.c
sdcc --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 ww2zeppelin.c
cd ..


Enemies/enemy.rel ^
Enemies/enemyshoot.rel ^
Fortresses/fortresscannon.rel ^
Fortresses/fortressdoor.rel ^
Fortresses/fortressphantom.rel ^
Fortresses/fortresssearcher.rel ^
Fortresses/fortresswave.rel ^
General/barrom.rel ^
General/bombship.rel ^
General/explosion.rel ^
General/finishstage.rel ^
General/gameoverstage.rel ^
General/jukeboxstage.rel ^
General/logostage.rel ^
General/map.rel ^
General/mikgamesstage.rel ^
General/powerup.rel ^
General/rectship.rel ^
General/rsgthing.rel ^
General/scripter.rel ^
General/scroller.rel ^
General/selectorstage.rel ^
General/skullbone.rel ^
General/spreadship.rel ^
General/timeredlabel.rel ^
General/turnship.rel ^
General/warning.rel ^
General/waveship.rel ^
Intros/intro1stage.rel ^
Intros/intro2stage.rel ^
Intros/intro3object.rel ^
Intros/intro3stage.rel ^
Intros/intro4stage.rel ^
Intros/introovni.rel ^
Intros/introsideplayer.rel ^
Intros/introstage.rel ^
Intros/introstar.rel ^
Monsters/monsterblob.rel ^
Monsters/monsterhead.rel ^
Monsters/monstermissil.rel ^
Players/player.rel ^
Players/playershoot.rel ^
Players/playstage.rel ^
Spaces/spaceasteroid.rel ^
Spaces/spaceshooter.rel ^
Spaces/spacestation.rel ^
Stages/stage1.rel ^
Stages/stage1endboss.rel ^
Stages/stage1middleboss.rel ^
Stages/stage1middlebossb.rel ^
Stages/stage1middlebossc.rel ^
Stages/stage2.rel ^
Stages/stage2endboss.rel ^
Stages/stage2object.rel ^
Stages/stage3.rel ^
Stages/stage3endboss.rel ^
Stages/stage3laser.rel ^
Stages/stage3star.rel ^
Stages/stage4.rel ^
Stages/stage4endboss.rel ^
Stages/stage4endbossb.rel ^
Stages/stage4middleboss.rel ^
Stages/stage4object.rel ^
Stages/stage5.rel ^
Stages/stage5endboss.rel ^
Stages/stage5missile.rel ^
Stages/stage6.rel ^
Stages/stage6endboss.rel ^
Stages/stage6endbossb.rel ^
Stages/stage6object.rel ^
Stages/stage7.rel ^
Stages/stage7endboss.rel ^
Stages/stage7middleboss.rel ^
Stages/stage7object.rel ^
Stages/stage8.rel ^
Stages/stage8bossa.rel ^
Stages/stage8bossb.rel ^
Stages/stage8bossc.rel ^
Stages/stage8lateral.rel ^
Vulcans/vulcanbird.rel ^
Vulcans/vulcanlaser.rel ^
Vulcans/vulcanlava.rel ^
Vulcans/vulcanstation.rel ^
Vulcans/vulcantank.rel ^
Vulcans/vulcanvulcan.rel ^
Wars/ww2plane.rel ^
Wars/ww2planeb.rel ^
Wars/ww2ship.rel ^
Wars/ww2zeppelin.rel ^
