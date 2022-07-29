set -e
gcc -std=c89 -Wall -Wextra -Wpedantic -Wno-unused-function -O3 -DNDEBUG -Dmk_want_jumbo=1 -o mk_int_gcc_release.exe mk_int.c
./mk_int_gcc_release.exe
