@ECHO OFF
SET ENTRY=.\test\tmp_entry\tmpentry.cpp
for /f "usebackq delims=" %%A in (`"c:\01_add\005_dev\020_msys2\tools\msys64\usr\bin\find.exe" ./src/ -name *.cpp -print0 ^| xargs -0 echo`) do set SRCS=%%A
g++ %ENTRY% %SRCS% -o debug\test.out
