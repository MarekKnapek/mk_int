#ifndef mk_include_guard_uint_base_char
#define mk_include_guard_uint_base_char


#include <stddef.h> /* size_t */


void mk_uint_char_zero(unsigned char* out);
void mk_uint_char_one(unsigned char* out);
void mk_uint_char_from_int(unsigned char* out, unsigned in);
unsigned mk_uint_char_to_int(unsigned char const* x);
void mk_uint_char_from_sizet(unsigned char* out, size_t in);
size_t mk_uint_char_to_sizet(unsigned char const* x);
void mk_uint_char_from_buff_le(unsigned char* out, void const* buff);
void mk_uint_char_to_buff_le(unsigned char const* x, void* buff);
void mk_uint_char_from_buff_be(unsigned char* out, void const* buff);
void mk_uint_char_to_buff_be(unsigned char const* x, void* buff);

int mk_uint_char_is_zero(unsigned char const* x);
int mk_uint_char_is_max(unsigned char const* x);

void mk_uint_char_cmplmnt(unsigned char* out, unsigned char const* x);
void mk_uint_char_or(unsigned char* out, unsigned char const* a, unsigned char const* b);
void mk_uint_char_and(unsigned char* out, unsigned char const* a, unsigned char const* b);
void mk_uint_char_xor(unsigned char* out, unsigned char const* a, unsigned char const* b);

void mk_uint_char_shl(unsigned char* out, unsigned char const* x, int n);
void mk_uint_char_shr(unsigned char* out, unsigned char const* x, int n);

int mk_uint_char_eq(unsigned char const* a, unsigned char const* b);
int mk_uint_char_neq(unsigned char const* a, unsigned char const* b);
int mk_uint_char_lt(unsigned char const* a, unsigned char const* b);
int mk_uint_char_le(unsigned char const* a, unsigned char const* b);
int mk_uint_char_gt(unsigned char const* a, unsigned char const* b);
int mk_uint_char_ge(unsigned char const* a, unsigned char const* b);

void mk_uint_char_inc(unsigned char* x);
void mk_uint_char_dec(unsigned char* x);

void mk_uint_char_add(unsigned char* out, unsigned char const* a, unsigned char const* b);
void mk_uint_char_sub(unsigned char* out, unsigned char const* a, unsigned char const* b);


#endif