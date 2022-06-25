@echo off

cl /nologo /Wall /D __STDC_WANT_SECURE_LIB__=0 mk_int.c || exit /b
mk_int.exe
