#ifndef mk_include_guard_uint_16
#define mk_include_guard_uint_16


#include "mk_uint_8.h"


#define mk_uint_small_t struct mk_uint8_s


#define mk_uint_bits 16
#define mk_uint_t struct mk_uint16_s
#define mk_uint_zero mk_uint16_zero
#define mk_uint_one mk_uint16_one
#define mk_uint_from_int mk_uint16_from_int
#define mk_uint_to_int mk_uint16_to_int
#define mk_uint_from_sizet mk_uint16_from_sizet
#define mk_uint_to_sizet mk_uint16_to_sizet
#define mk_uint_from_buff_le mk_uint16_from_buff_le
#define mk_uint_is_zero mk_uint16_is_zero
#define mk_uint_is_max mk_uint16_is_max
#define mk_uint_cmplmnt mk_uint16_cmplmnt
#define mk_uint_or mk_uint16_or
#define mk_uint_and mk_uint16_and
#define mk_uint_xor mk_uint16_xor
#define mk_uint_shl mk_uint16_shl
#define mk_uint_shr mk_uint16_shr
#define mk_uint_rotl mk_uint16_rotl
#define mk_uint_eq mk_uint16_eq
#define mk_uint_neq mk_uint16_neq
#define mk_uint_lt mk_uint16_lt
#define mk_uint_le mk_uint16_le
#define mk_uint_inc mk_uint16_inc
#define mk_uint_dec mk_uint16_dec
#define mk_uint_add mk_uint16_add
#define mk_uint_sub mk_uint16_sub


#include "../inl/mk_uint.h"


#undef mk_uint_small_t


#undef mk_uint_bits
#undef mk_uint_t
#undef mk_uint_zero
#undef mk_uint_one
#undef mk_uint_from_int
#undef mk_uint_to_int
#undef mk_uint_from_sizet
#undef mk_uint_to_sizet
#undef mk_uint_from_buff_le
#undef mk_uint_is_zero
#undef mk_uint_is_max
#undef mk_uint_cmplmnt
#undef mk_uint_or
#undef mk_uint_and
#undef mk_uint_xor
#undef mk_uint_shl
#undef mk_uint_shr
#undef mk_uint_rotl
#undef mk_uint_eq
#undef mk_uint_neq
#undef mk_uint_lt
#undef mk_uint_le
#undef mk_uint_inc
#undef mk_uint_dec
#undef mk_uint_add
#undef mk_uint_sub


#endif
