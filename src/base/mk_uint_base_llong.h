#ifndef mk_include_guard_uint_base_llong
#define mk_include_guard_uint_base_llong


#if __STDC_VERSION__ >= 199901L || __cplusplus >= 201103L


#include <stddef.h> /* size_t */


void mk_uint_llong_zero(unsigned long long* out);
void mk_uint_llong_one(unsigned long long* out);
void mk_uint_llong_from_int(unsigned long long* out, unsigned in);
unsigned mk_uint_llong_to_int(unsigned long long const* x);
void mk_uint_llong_from_sizet(unsigned long long* out, size_t in);
size_t mk_uint_llong_to_sizet(unsigned long long const* x);
void mk_uint_llong_from_buff_le(unsigned long long* out, void const* buff);
void mk_uint_llong_to_buff_le(unsigned long long const* x, void* buff);
void mk_uint_llong_to_buff_be(unsigned long long const* x, void* buff);

int mk_uint_llong_is_zero(unsigned long long const* x);
int mk_uint_llong_is_max(unsigned long long const* x);

void mk_uint_llong_cmplmnt(unsigned long long* out, unsigned long long const* x);
void mk_uint_llong_or(unsigned long long* out, unsigned long long const* a, unsigned long long const* b);
void mk_uint_llong_and(unsigned long long* out, unsigned long long const* a, unsigned long long const* b);
void mk_uint_llong_xor(unsigned long long* out, unsigned long long const* a, unsigned long long const* b);

void mk_uint_llong_shl(unsigned long long* out, unsigned long long const* x, int n);
void mk_uint_llong_shr(unsigned long long* out, unsigned long long const* x, int n);

int mk_uint_llong_eq(unsigned long long const* a, unsigned long long const* b);
int mk_uint_llong_neq(unsigned long long const* a, unsigned long long const* b);
int mk_uint_llong_lt(unsigned long long const* a, unsigned long long const* b);
int mk_uint_llong_le(unsigned long long const* a, unsigned long long const* b);
int mk_uint_llong_gt(unsigned long long const* a, unsigned long long const* b);
int mk_uint_llong_ge(unsigned long long const* a, unsigned long long const* b);

void mk_uint_llong_inc(unsigned long long* x);
void mk_uint_llong_dec(unsigned long long* x);

void mk_uint_llong_add(unsigned long long* out, unsigned long long const* a, unsigned long long const* b);
void mk_uint_llong_sub(unsigned long long* out, unsigned long long const* a, unsigned long long const* b);


#endif


#endif
