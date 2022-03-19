#include <limits.h> /* CHAR_BIT */


#if CHAR_BIT == 8
#ifdef __SIZEOF_INT128__
#include "../base/mk_uint_macro_base_128.h"
#else
#if __STDC_VERSION__ >= 199901L || __cplusplus >= 201103L
#include "../base/mk_uint_macro_base_llong.h"
#else
#include "../base/mk_uint_macro_base_long.h"
#endif
#endif
#endif


#define mk_uint_bits 128
#define mk_uint_t struct mk_uint128_s

#define mk_uint_zero mk_uint128_zero
#define mk_uint_one mk_uint128_one
#define mk_uint_from_int mk_uint128_from_int
#define mk_uint_to_int mk_uint128_to_int
#define mk_uint_from_sizet mk_uint128_from_sizet
#define mk_uint_to_sizet mk_uint128_to_sizet
#define mk_uint_from_buff_le mk_uint128_from_buff_le
#define mk_uint_to_buff_le mk_uint128_to_buff_le
#define mk_uint_to_buff_be mk_uint128_to_buff_be

#define mk_uint_is_zero mk_uint128_is_zero
#define mk_uint_is_max mk_uint128_is_max

#define mk_uint_cmplmnt mk_uint128_cmplmnt
#define mk_uint_or mk_uint128_or
#define mk_uint_and mk_uint128_and
#define mk_uint_xor mk_uint128_xor

#define mk_uint_shl mk_uint128_shl
#define mk_uint_shr mk_uint128_shr
#define mk_uint_rotl mk_uint128_rotl

#define mk_uint_eq mk_uint128_eq
#define mk_uint_neq mk_uint128_neq
#define mk_uint_lt mk_uint128_lt
#define mk_uint_le mk_uint128_le
#define mk_uint_gt mk_uint128_gt
#define mk_uint_ge mk_uint128_ge

#define mk_uint_inc mk_uint128_inc
#define mk_uint_dec mk_uint128_dec

#define mk_uint_add mk_uint128_add
#define mk_uint_sub mk_uint128_sub
