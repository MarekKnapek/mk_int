#include "mk_uint_32.h"


#include "mk_uint_16.h"


#define mk_uint_small_t struct mk_uint16_s
#define mk_uint_small_zero mk_uint16_zero
#define mk_uint_small_one mk_uint16_one
#define mk_uint_small_from_int mk_uint16_from_int
#define mk_uint_small_to_int mk_uint16_to_int
#define mk_uint_small_from_buff_le mk_uint16_from_buff_le
#define mk_uint_small_is_zero mk_uint16_is_zero
#define mk_uint_small_is_max mk_uint16_is_max
#define mk_uint_small_cmplmnt mk_uint16_cmplmnt
#define mk_uint_small_or mk_uint16_or
#define mk_uint_small_and mk_uint16_and
#define mk_uint_small_xor mk_uint16_xor
#define mk_uint_small_shl mk_uint16_shl
#define mk_uint_small_shr mk_uint16_shr
#define mk_uint_small_eq mk_uint16_eq
#define mk_uint_small_neq mk_uint16_neq
#define mk_uint_small_lt mk_uint16_lt
#define mk_uint_small_le mk_uint16_le
#define mk_uint_small_inc mk_uint16_inc
#define mk_uint_small_dec mk_uint16_dec
#define mk_uint_small_add mk_uint16_add
#define mk_uint_small_sub mk_uint16_sub


#define mk_uint_t struct mk_uint32_s
#define mk_uint_zero mk_uint32_zero
#define mk_uint_one mk_uint32_one
#define mk_uint_from_int mk_uint32_from_int
#define mk_uint_to_int mk_uint32_to_int
#define mk_uint_from_buff_le mk_uint32_from_buff_le
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
#define mk_uint_inc mk_uint32_inc
#define mk_uint_dec mk_uint32_dec
#define mk_uint_add mk_uint32_add
#define mk_uint_sub mk_uint32_sub


#include "../inl/mk_uint.c"


#undef mk_uint_t
#undef mk_uint_zero
#undef mk_uint_one
#undef mk_uint_from_int
#undef mk_uint_to_int
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


#undef mk_uint_small_t
#undef mk_uint_small_zero
#undef mk_uint_small_one
#undef mk_uint_small_from_int
#undef mk_uint_small_to_int
#undef mk_uint_small_from_buff_le
#undef mk_uint_small_is_zero
#undef mk_uint_small_is_max
#undef mk_uint_small_cmplmnt
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
