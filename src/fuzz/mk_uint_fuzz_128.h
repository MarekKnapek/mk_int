#ifndef mk_include_guard_uint_fuzz_128
#define mk_include_guard_uint_fuzz_128


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4464) /* warning C4464: relative include path contains '..' */
#endif


#define mk_uint_n 128
#include "../inl/mk_uint_fuzz.inl.h"
#undef mk_uint_n


#if defined(_MSC_VER)
#pragma warning(pop)
#endif


#endif
