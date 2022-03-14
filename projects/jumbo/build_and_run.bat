@echo off

cl /nologo /Wall /wd4464 /wd4668 /wd4701 /wd4710 /wd4711 mk_int.c || exit /b
mk_int.exe

rem warning C4464: relative include path contains '..'
rem warning C4668: 'xxx' is not defined as a preprocessor macro, replacing with '0' for '#if/#elif'
rem warning C4701: potentially uninitialized local variable 'xxx' used
rem warning C4710: 'xxx': function not inlined
rem warning C4711: function 'xxx' selected for automatic inline expansion
