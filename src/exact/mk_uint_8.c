#include "mk_uint_8.h"


#include "../base/mk_uint_char.h"


#define mk_uint_small_t unsigned char
#define mk_uint_small_zero mk_uint_char_zero
#define mk_uint_small_one mk_uint_char_one
#define mk_uint_small_from_int mk_uint_char_from_int
#define mk_uint_small_to_int mk_uint_char_to_int
#define mk_uint_small_from_sizet mk_uint_char_from_sizet
#define mk_uint_small_to_sizet mk_uint_char_to_sizet
#define mk_uint_small_from_buff_le mk_uint_char_from_buff_le
#define mk_uint_small_to_buff_be mk_uint_char_to_buff_be
#define mk_uint_small_is_zero mk_uint_char_is_zero
#define mk_uint_small_is_max mk_uint_char_is_max
#define mk_uint_small_cmplmnt mk_uint_char_cmplmnt
#define mk_uint_small_or mk_uint_char_or
#define mk_uint_small_and mk_uint_char_and
#define mk_uint_small_xor mk_uint_char_xor
#define mk_uint_small_shl mk_uint_char_shl
#define mk_uint_small_shr mk_uint_char_shr
#define mk_uint_small_eq mk_uint_char_eq
#define mk_uint_small_neq mk_uint_char_neq
#define mk_uint_small_lt mk_uint_char_lt
#define mk_uint_small_le mk_uint_char_le
#define mk_uint_small_inc mk_uint_char_inc
#define mk_uint_small_dec mk_uint_char_dec
#define mk_uint_small_add mk_uint_char_add
#define mk_uint_small_sub mk_uint_char_sub


#define mk_uint_t struct mk_uint8_s
#define mk_uint_zero mk_uint8_zero
#define mk_uint_one mk_uint8_one
#define mk_uint_from_int mk_uint8_from_int
#define mk_uint_to_int mk_uint8_to_int
#define mk_uint_from_sizet mk_uint8_from_sizet
#define mk_uint_to_sizet mk_uint8_to_sizet
#define mk_uint_from_buff_le mk_uint8_from_buff_le
#define mk_uint_to_buff_be mk_uint8_to_buff_be
#define mk_uint_is_zero mk_uint8_is_zero
#define mk_uint_is_max mk_uint8_is_max
#define mk_uint_cmplmnt mk_uint8_cmplmnt
#define mk_uint_or mk_uint8_or
#define mk_uint_and mk_uint8_and
#define mk_uint_xor mk_uint8_xor
#define mk_uint_shl mk_uint8_shl
#define mk_uint_shr mk_uint8_shr
#define mk_uint_rotl mk_uint8_rotl
#define mk_uint_eq mk_uint8_eq
#define mk_uint_neq mk_uint8_neq
#define mk_uint_lt mk_uint8_lt
#define mk_uint_le mk_uint8_le
#define mk_uint_inc mk_uint8_inc
#define mk_uint_dec mk_uint8_dec
#define mk_uint_add mk_uint8_add
#define mk_uint_sub mk_uint8_sub


#include "../inl/mk_uint.c"


#undef mk_uint_t
#undef mk_uint_zero
#undef mk_uint_one
#undef mk_uint_from_int
#undef mk_uint_to_int
#undef mk_uint_from_sizet
#undef mk_uint_to_sizet
#undef mk_uint_from_buff_le
#undef mk_uint_to_buff_be
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
#undef mk_uint_small_from_sizet
#undef mk_uint_small_to_sizet
#undef mk_uint_small_from_buff_le
#undef mk_uint_small_to_buff_be
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
