#include <limits.h> /* CHAR_BIT */
#include <stddef.h> /* size_t NULL */
#include <stdio.h> /* printf */
#include <stdlib.h> /* EXIT_SUCCESS srand rand */
#include <time.h> /* time */


int LLVMFuzzerTestOneInput(unsigned char const* data, size_t size);


int main(int argv, char** argc)
{
	unsigned buff[((2 * 16 * CHAR_BIT) + (sizeof(unsigned) * CHAR_BIT - 1)) / (sizeof(unsigned) * CHAR_BIT)];
	int n;
	int i;

	(void)argc;
	(void)argv;

	srand((unsigned)time(NULL));

	for(n = 0; n != 1000000; ++n)
	{
		for(i = 0; i != sizeof(buff); ++i)
		{
			((unsigned char*)buff)[i] = (unsigned char)(rand() & 0xff);
		}
		LLVMFuzzerTestOneInput((unsigned char*)&buff, sizeof(buff));
	}

	printf("%s\n", "Not crashed.");
	return EXIT_SUCCESS;
}


#include "../../src/base/mk_uint_char.c"
#include "../../src/base/mk_uint_int.c"
#include "../../src/base/mk_uint_llong.c"
#include "../../src/base/mk_uint_long.c"
#include "../../src/base/mk_uint_short.c"
#include "../../src/exact/mk_uint_128.c"
#include "../../src/exact/mk_uint_16.c"
#include "../../src/exact/mk_uint_32.c"
#include "../../src/exact/mk_uint_64.c"
#include "../../src/exact/mk_uint_8.c"
#include "../../src/fuzz/mk_uint_fuzz.c"
#include "../../src/fuzz/mk_uint_fuzz_128.c"
#include "../../src/fuzz/mk_uint_fuzz_16.c"
#include "../../src/fuzz/mk_uint_fuzz_32.c"
#include "../../src/fuzz/mk_uint_fuzz_64.c"
#include "../../src/fuzz/mk_uint_fuzz_8.c"
#include "../../src/utils/maybe_initialize.c"
