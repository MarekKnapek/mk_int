#include "mk_uint_fuzz_8.h"


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4464) /* warning C4464: relative include path contains '..' */
#endif


#define mk_uint_n 8
#include "../inl/mk_uint_fuzz.inl.c"
#undef mk_uint_n


#if defined(_MSC_VER)
#pragma warning(pop)
#endif
