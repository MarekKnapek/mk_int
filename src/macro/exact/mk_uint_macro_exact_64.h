#include "../../mk_uint_setup.h"

#include <limits.h> /* CHAR_BIT ULLONG_MAX */


#if CHAR_BIT == 8
#if mk_uint_has_long_long
#if ULLONG_MAX == 0xffffffffffffffff
#include "../base/mk_uint_macro_base_llong.h"
#define mk_uint_small_bits 64
#define mk_uint64_c(a, b) {{(((unsigned long long)a) << 32) | (((unsigned long long)b) << 0)}}
#endif
#else
#if ULONG_MAX == 0xffffffff
#include "../base/mk_uint_macro_base_long.h"
#define mk_uint_small_bits 32
#define mk_uint64_c(a, b) {{a, b}}
#endif
#endif
#endif


#define mk_uint_bits 64
#define mk_uint_t struct mk_uint64_s

#define mk_uint_zero mk_uint64_zero
#define mk_uint_one mk_uint64_one
#define mk_uint_from_int mk_uint64_from_int
#define mk_uint_to_int mk_uint64_to_int
#define mk_uint_from_sizet mk_uint64_from_sizet
#define mk_uint_to_sizet mk_uint64_to_sizet
#define mk_uint_from_buff_le mk_uint64_from_buff_le
#define mk_uint_to_buff_le mk_uint64_to_buff_le
#define mk_uint_from_buff_be mk_uint64_from_buff_be
#define mk_uint_to_buff_be mk_uint64_to_buff_be

#define mk_uint_is_zero mk_uint64_is_zero
#define mk_uint_is_max mk_uint64_is_max

#define mk_uint_cmplmnt mk_uint64_cmplmnt
#define mk_uint_or mk_uint64_or
#define mk_uint_and mk_uint64_and
#define mk_uint_xor mk_uint64_xor

#define mk_uint_shl mk_uint64_shl
#define mk_uint_shr mk_uint64_shr
#define mk_uint_rotl mk_uint64_rotl
#define mk_uint_rotr mk_uint64_rotr

#define mk_uint_eq mk_uint64_eq
#define mk_uint_neq mk_uint64_neq
#define mk_uint_lt mk_uint64_lt
#define mk_uint_le mk_uint64_le
#define mk_uint_gt mk_uint64_gt
#define mk_uint_ge mk_uint64_ge

#define mk_uint_inc mk_uint64_inc
#define mk_uint_dec mk_uint64_dec

#define mk_uint_add mk_uint64_add
#define mk_uint_sub mk_uint64_sub
