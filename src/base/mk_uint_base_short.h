#ifndef mk_include_guard_uint_base_short
#define mk_include_guard_uint_base_short


#include <stddef.h> /* size_t */


void mk_uint_short_zero(unsigned short* out);
void mk_uint_short_one(unsigned short* out);
void mk_uint_short_from_int(unsigned short* out, unsigned in);
unsigned mk_uint_short_to_int(unsigned short const* x);
void mk_uint_short_from_sizet(unsigned short* out, size_t in);
size_t mk_uint_short_to_sizet(unsigned short const* x);
void mk_uint_short_from_buff_le(unsigned short* out, void const* buff);
void mk_uint_short_to_buff_le(unsigned short const* x, void* buff);
void mk_uint_short_from_buff_be(unsigned short* out, void const* buff);
void mk_uint_short_to_buff_be(unsigned short const* x, void* buff);

int mk_uint_short_is_zero(unsigned short const* x);
int mk_uint_short_is_max(unsigned short const* x);

void mk_uint_short_cmplmnt(unsigned short* out, unsigned short const* x);
void mk_uint_short_or(unsigned short* out, unsigned short const* a, unsigned short const* b);
void mk_uint_short_and(unsigned short* out, unsigned short const* a, unsigned short const* b);
void mk_uint_short_xor(unsigned short* out, unsigned short const* a, unsigned short const* b);

void mk_uint_short_shl(unsigned short* out, unsigned short const* x, int n);
void mk_uint_short_shr(unsigned short* out, unsigned short const* x, int n);

int mk_uint_short_eq(unsigned short const* a, unsigned short const* b);
int mk_uint_short_neq(unsigned short const* a, unsigned short const* b);
int mk_uint_short_lt(unsigned short const* a, unsigned short const* b);
int mk_uint_short_le(unsigned short const* a, unsigned short const* b);
int mk_uint_short_gt(unsigned short const* a, unsigned short const* b);
int mk_uint_short_ge(unsigned short const* a, unsigned short const* b);

void mk_uint_short_inc(unsigned short* x);
void mk_uint_short_dec(unsigned short* x);

void mk_uint_short_add(unsigned short* out, unsigned short const* a, unsigned short const* b);
void mk_uint_short_sub(unsigned short* out, unsigned short const* a, unsigned short const* b);


#endif
