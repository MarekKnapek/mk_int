#ifndef mk_include_guard_uint_64
#define mk_include_guard_uint_64





#define mk_uint_small_t unsigned short


#define mk_uint_bits 64
#define mk_uint_t struct mk_uint64_s
#define mk_uint_zero mk_uint64_zero
#define mk_uint_one mk_uint64_one
#define mk_uint_from_int mk_uint64_from_int
#define mk_uint_to_int mk_uint64_to_int
#define mk_uint_from_sizet mk_uint64_from_sizet
#define mk_uint_to_sizet mk_uint64_to_sizet
#define mk_uint_from_buff_le mk_uint64_from_buff_le
#define mk_uint_is_zero mk_uint64_is_zero
#define mk_uint_is_max mk_uint64_is_max
#define mk_uint_cmplmnt mk_uint64_cmplmnt
#define mk_uint_or mk_uint64_or
#define mk_uint_and mk_uint64_and
#define mk_uint_xor mk_uint64_xor
#define mk_uint_shl mk_uint64_shl
#define mk_uint_shr mk_uint64_shr
#define mk_uint_rotl mk_uint64_rotl
#define mk_uint_eq mk_uint64_eq
#define mk_uint_neq mk_uint64_neq
#define mk_uint_lt mk_uint64_lt
#define mk_uint_le mk_uint64_le
#define mk_uint_inc mk_uint64_inc
#define mk_uint_dec mk_uint64_dec
#define mk_uint_add mk_uint64_add
#define mk_uint_sub mk_uint64_sub


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
