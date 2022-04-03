#define mk_uint_parts ((mk_uint_bits + (mk_uint_small_bits - 1)) / mk_uint_small_bits)


#if mk_uint_parts == 1


#include "mk_uint_1.c"


#elif mk_uint_parts == 2


#include "mk_uint_2.c"


#else


#include "mk_uint_n.c"


#endif


#undef mk_uint_parts
