#include <limits.h> /* CHAR_BIT UCHAR_MAX */


#if CHAR_BIT == 8
#if UCHAR_MAX == 0xff
#include "../base/mk_uint_macro_base_char.h"
#endif
#endif


#define mk_uint_bits 8
#define mk_uint_t struct mk_uint8_s

#define mk_uint_zero mk_uint8_zero
#define mk_uint_one mk_uint8_one
#define mk_uint_from_int mk_uint8_from_int
#define mk_uint_to_int mk_uint8_to_int
#define mk_uint_from_sizet mk_uint8_from_sizet
#define mk_uint_to_sizet mk_uint8_to_sizet
#define mk_uint_from_buff_le mk_uint8_from_buff_le
#define mk_uint_to_buff_le mk_uint8_to_buff_le
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
#define mk_uint_gt mk_uint8_gt
#define mk_uint_ge mk_uint8_ge

#define mk_uint_inc mk_uint8_inc
#define mk_uint_dec mk_uint8_dec

#define mk_uint_add mk_uint8_add
#define mk_uint_sub mk_uint8_sub
