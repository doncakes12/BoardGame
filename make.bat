@ECHO OFF
ECHO:
ECHO Making Game outputing as a.exe
g++ -I ./headers/ ./files/*.cpp ./test/test.cpp -o a.exe
ECHO Done compiling!
@ECHO ON
