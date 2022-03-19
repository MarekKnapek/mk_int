#ifndef mk_include_guard_uint_base_int
#define mk_include_guard_uint_base_int


#include <stddef.h> /* size_t */


void mk_uint_int_zero(unsigned int* out);
void mk_uint_int_one(unsigned int* out);
void mk_uint_int_from_int(unsigned int* out, unsigned in);
unsigned mk_uint_int_to_int(unsigned int const* x);
void mk_uint_int_from_sizet(unsigned int* out, size_t in);
size_t mk_uint_int_to_sizet(unsigned int const* x);
void mk_uint_int_from_buff_le(unsigned int* out, void const* buff);
void mk_uint_int_to_buff_le(unsigned int const* x, void* buff);
void mk_uint_int_from_buff_be(unsigned int* out, void const* buff);
void mk_uint_int_to_buff_be(unsigned int const* x, void* buff);

int mk_uint_int_is_zero(unsigned int const* x);
int mk_uint_int_is_max(unsigned int const* x);

void mk_uint_int_cmplmnt(unsigned int* out, unsigned int const* x);
void mk_uint_int_or(unsigned int* out, unsigned int const* a, unsigned int const* b);
void mk_uint_int_and(unsigned int* out, unsigned int const* a, unsigned int const* b);
void mk_uint_int_xor(unsigned int* out, unsigned int const* a, unsigned int const* b);

void mk_uint_int_shl(unsigned int* out, unsigned int const* x, int n);
void mk_uint_int_shr(unsigned int* out, unsigned int const* x, int n);

int mk_uint_int_eq(unsigned int const* a, unsigned int const* b);
int mk_uint_int_neq(unsigned int const* a, unsigned int const* b);
int mk_uint_int_lt(unsigned int const* a, unsigned int const* b);
int mk_uint_int_le(unsigned int const* a, unsigned int const* b);
int mk_uint_int_gt(unsigned int const* a, unsigned int const* b);
int mk_uint_int_ge(unsigned int const* a, unsigned int const* b);

void mk_uint_int_inc(unsigned int* x);
void mk_uint_int_dec(unsigned int* x);

void mk_uint_int_add(unsigned int* out, unsigned int const* a, unsigned int const* b);
void mk_uint_int_sub(unsigned int* out, unsigned int const* a, unsigned int const* b);


#endif
