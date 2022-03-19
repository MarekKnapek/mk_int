#include <limits.h> /* CHAR_BIT UINT_MAX ULONG_MAX */


#if CHAR_BIT == 8
#if UINT_MAX == 0xffffffff
#include "../base/mk_uint_macro_base_int.h"
#elif ULONG_MAX == 0xffffffff
#include "../base/mk_uint_macro_base_long.h"
#endif
#endif


#define mk_uint_bits 32
#define mk_uint_t struct mk_uint32_s

#define mk_uint_zero mk_uint32_zero
#define mk_uint_one mk_uint32_one
#define mk_uint_from_int mk_uint32_from_int
#define mk_uint_to_int mk_uint32_to_int
#define mk_uint_from_sizet mk_uint32_from_sizet
#define mk_uint_to_sizet mk_uint32_to_sizet
#define mk_uint_from_buff_le mk_uint32_from_buff_le
#define mk_uint_to_buff_be mk_uint32_to_buff_be

#define mk_uint_is_zero mk_uint32_is_zero
#define mk_uint_is_max mk_uint32_is_max

#define mk_uint_cmplmnt mk_uint32_cmplmnt
#define mk_uint_or mk_uint32_or
#define mk_uint_and mk_uint32_and
#define mk_uint_xor mk_uint32_xor

#define mk_uint_shl mk_uint32_shl
#define mk_uint_shr mk_uint32_shr
#define mk_uint_rotl mk_uint32_rotl

#define mk_uint_eq mk_uint32_eq
#define mk_uint_neq mk_uint32_neq
#define mk_uint_lt mk_uint32_lt
#define mk_uint_le mk_uint32_le
#define mk_uint_gt mk_uint32_gt
#define mk_uint_ge mk_uint32_ge

#define mk_uint_inc mk_uint32_inc
#define mk_uint_dec mk_uint32_dec

#define mk_uint_add mk_uint32_add
#define mk_uint_sub mk_uint32_sub
