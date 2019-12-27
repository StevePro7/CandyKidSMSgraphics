@echo off

:: Time build START
:: Reference: https://stackoverflow.com/questions/673523/how-do-i-measure-execution-time-of-a-command-on-the-windows-command-line
set _time=%time: =0%
set /a _hours=100%_time:~0,2%%%100,_min=100%_time:~3,2%%%100,_sec=100%_time:~6,2%%%100,_cs=%_time:~9,2%
set /a _started=_hours*60*60*100+_min*60*100+_sec*100+_cs


:: Content
::folder2c ..\gfx gfx
::sdcc -c -mz80 --opt-code-speed --peep-file peep-rules.txt --std-c99 gfx.c

:: Compile
cd devkit
sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 _sms_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 _snd_manager.c
cd ..

cd engine
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 asm_manager.c
sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 command_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 content_manager.c
sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 enemy_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 enum_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 event_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 font_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 hack_manager.c
sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 gamer_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 global_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 input_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 level_manager.
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 mask_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 screen_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 sprite_manager.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 tile_manager.c
cd ..

cd object
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 enemy_object.c
sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 gamer_object.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 hack_object.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 level_object.c
cd ..

cd screen
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 none_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 splash_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 intro_screen.c
::sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 load_screen.c
sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 test_screen.c
sdcc -c -mz80 --opt-code-speed --peep-file ..\peep-rules.txt --std-c99 func_screen.c
cd ..

sdcc -c -mz80 --opt-code-speed --peep-file peep-rules.txt --std-c99 main.c


:: Time build -END-
set _time=%time: =0%
set /a _hours=100%_time:~0,2%%%100,_min=100%_time:~3,2%%%100,_sec=100%_time:~6,2%%%100,_cs=%_time:~9,2%
set /a _duration=_hours*60*60*100+_min*60*100+_sec*100+_cs-_started
set /a _hours=_duration/60/60/100,_min=100+_duration/60/100%%60,_sec=100+(_duration/100%%60%%60),_cs=100+_duration%%100
echo.
echo Time taken: %_sec:~-2%.%_cs:~-2% secs
echo.


:: Link
sdcc -o output.ihx --Werror --opt-code-speed -mz80 --no-std-crt0 --data-loc 0xC000 ^
-Wl-b_BANK2=0x8000 ^
-Wl-b_BANK3=0x8000 ^
..\crt0\crt0_sms.rel main.rel ^
..\lib\SMSlib.lib ^
..\lib\PSGlib.rel ^
banks\bank2.rel ^
banks\bank3.rel ^
devkit\_sms_manager.rel ^
devkit\_snd_manager.rel ^
engine\asm_manager.rel ^
engine\command_manager.rel ^
engine\content_manager.rel ^
engine\enum_manager.rel ^
engine\event_manager.rel ^
engine\font_manager.rel ^
engine\hack_manager.rel ^
engine\gamer_manager.rel ^
engine\global_manager.rel ^
engine\input_manager.rel ^
engine\level_manager.rel ^
engine\mask_manager.rel ^
engine\screen_manager.rel ^
engine\sprite_manager.rel ^
engine\tile_manager.rel ^
object\enemy_object.rel ^
object\gamer_object.rel ^
object\hack_object.rel ^
object\level_object.rel ^
screen\none_screen.rel ^
screen\splash_screen.rel ^
screen\intro_screen.rel ^
screen\load_screen.rel ^
screen\test_screen.rel ^
screen\func_screen.rel ^
gfx.rel

:: Execute
ihx2sms output.ihx output.sms


:: Delete
cd devkit
if exist "*.asm" del "*.asm" > nul
if exist "*.lst" del "*.lst" > nul
if exist "*.sym" del "*.sym" > nul
cd ..

cd engine
if exist "*.asm" del "*.asm" > nul
if exist "*.lst" del "*.lst" > nul
if exist "*.sym" del "*.sym" > nul
cd ..

cd object
if exist "*.asm" del "*.asm" > nul
if exist "*.lst" del "*.lst" > nul
if exist "*.sym" del "*.sym" > nul
cd ..

cd screen
if exist "*.asm" del "*.asm" > nul
if exist "*.lst" del "*.lst" > nul
if exist "*.sym" del "*.sym" > nul
cd ..


if exist "*.asm" del "*.asm" > nul
if exist "*.ihx" del "*.ihx" > nul
if exist "*.lk"  del "*.lk"  > nul
if exist "*.lst" del "*.lst" > nul
if exist "*.noi" del "*.noi" > nul
if exist "*.sym" del "*.sym" > nul

:: Run
::java -jar C:\SEGA\Emulicious\Emulicious.jar output.sms
::C:\SEGA\meka\mekaw.exe output.sms
output.sms