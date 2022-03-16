set -e

gcc -std=c89 -Wall -Wextra -Wpedantic -o mk_int.exe mk_int.c
./mk_int.exe
