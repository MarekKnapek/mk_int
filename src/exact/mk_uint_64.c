#include "mk_uint_64.h"


#include "../base/mk_uint_short.h"


#define mk_uint_small_t unsigned short
#define mk_uint_small_zero mk_uint_short_zero
#define mk_uint_small_one mk_uint_short_one
#define mk_uint_small_from_int mk_uint_short_from_int
#define mk_uint_small_to_int mk_uint_short_to_int
#define mk_uint_small_is_zero mk_uint_short_is_zero
#define mk_uint_small_is_max mk_uint_short_is_max
#define mk_uint_small_or mk_uint_short_or
#define mk_uint_small_and mk_uint_short_and
#define mk_uint_small_xor mk_uint_short_xor
#define mk_uint_small_shl mk_uint_short_shl
#define mk_uint_small_shr mk_uint_short_shr
#define mk_uint_small_eq mk_uint_short_eq
#define mk_uint_small_neq mk_uint_short_neq
#define mk_uint_small_lt mk_uint_short_lt
#define mk_uint_small_le mk_uint_short_le
#define mk_uint_small_inc mk_uint_short_inc
#define mk_uint_small_dec mk_uint_short_dec
#define mk_uint_small_add mk_uint_short_add
#define mk_uint_small_sub mk_uint_short_sub


#define mk_uint_t struct mk_uint64_s
#define mk_uint_zero mk_uint64_zero
#define mk_uint_one mk_uint64_one
#define mk_uint_from_int mk_uint64_from_int
#define mk_uint_to_int mk_uint64_to_int
#define mk_uint_is_zero mk_uint64_is_zero
#define mk_uint_is_max mk_uint64_is_max
#define mk_uint_or mk_uint64_or
#define mk_uint_and mk_uint64_and
#define mk_uint_xor mk_uint64_xor
#define mk_uint_shl mk_uint64_shl
#define mk_uint_shr mk_uint64_shr
#define mk_uint_eq mk_uint64_eq
#define mk_uint_neq mk_uint64_neq
#define mk_uint_lt mk_uint64_lt
#define mk_uint_le mk_uint64_le
#define mk_uint_inc mk_uint64_inc
#define mk_uint_dec mk_uint64_dec
#define mk_uint_add mk_uint64_add
#define mk_uint_sub mk_uint64_sub


#include "../inl/mk_uint.c"


#undef mk_uint_t
#undef mk_uint_zero
#undef mk_uint_one
#undef mk_uint_from_int
#undef mk_uint_to_int
#undef mk_uint_is_zero
#undef mk_uint_is_max
#undef mk_uint_or
#undef mk_uint_and
#undef mk_uint_xor
#undef mk_uint_shl
#undef mk_uint_shr
#undef mk_uint_eq
#undef mk_uint_neq
#undef mk_uint_lt
#undef mk_uint_le
#undef mk_uint_inc
#undef mk_uint_dec
#undef mk_uint_add
#undef mk_uint_sub


#undef mk_uint_small_t
#undef mk_uint_small_zero
#undef mk_uint_small_one
#undef mk_uint_small_from_int
#undef mk_uint_small_to_int
#undef mk_uint_small_is_zero
#undef mk_uint_small_is_max
#undef mk_uint_small_or
#undef mk_uint_small_and
#undef mk_uint_small_xor
#undef mk_uint_small_shl
#undef mk_uint_small_shr
#undef mk_uint_small_eq
#undef mk_uint_small_neq
#undef mk_uint_small_lt
#undef mk_uint_small_le
#undef mk_uint_small_inc
#undef mk_uint_small_dec
#undef mk_uint_small_add
#undef mk_uint_small_sub
