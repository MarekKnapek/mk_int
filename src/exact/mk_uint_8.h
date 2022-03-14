#ifndef mk_include_guard_uint_8
#define mk_include_guard_uint_8





#define mk_uint_small_t unsigned char


#define mk_uint_bits 8
#define mk_uint_t struct mk_uint8_s
#define mk_uint_zero mk_uint8_zero
#define mk_uint_one mk_uint8_one
#define mk_uint_from_int mk_uint8_from_int
#define mk_uint_to_int mk_uint8_to_int
#define mk_uint_is_zero mk_uint8_is_zero
#define mk_uint_is_max mk_uint8_is_max
#define mk_uint_or mk_uint8_or
#define mk_uint_and mk_uint8_and
#define mk_uint_xor mk_uint8_xor
#define mk_uint_shl mk_uint8_shl
#define mk_uint_shr mk_uint8_shr
#define mk_uint_eq mk_uint8_eq
#define mk_uint_neq mk_uint8_neq
#define mk_uint_lt mk_uint8_lt
#define mk_uint_le mk_uint8_le
#define mk_uint_inc mk_uint8_inc
#define mk_uint_dec mk_uint8_dec
#define mk_uint_add mk_uint8_add
#define mk_uint_sub mk_uint8_sub


#include "../inl/mk_uint.h"


#undef mk_uint_small_t


#undef mk_uint_bits
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


#endif