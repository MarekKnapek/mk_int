#ifndef mk_include_guard_uint_base_128
#define mk_include_guard_uint_base_128


#ifdef __SIZEOF_INT128__


#include <stddef.h> /* size_t */


void mk_uint_128_zero(unsigned __int128* out);
void mk_uint_128_one(unsigned __int128* out);
void mk_uint_128_from_int(unsigned __int128* out, unsigned in);
unsigned mk_uint_128_to_int(unsigned __int128 const* x);
void mk_uint_128_from_sizet(unsigned __int128* out, size_t in);
size_t mk_uint_128_to_sizet(unsigned __int128 const* x);
void mk_uint_128_from_buff_le(unsigned __int128* out, void const* buff);
void mk_uint_128_to_buff_be(unsigned __int128 const* x, void* buff);

int mk_uint_128_is_zero(unsigned __int128 const* x);
int mk_uint_128_is_max(unsigned __int128 const* x);

void mk_uint_128_cmplmnt(unsigned __int128* out, unsigned __int128 const* x);
void mk_uint_128_or(unsigned __int128* out, unsigned __int128 const* a, unsigned __int128 const* b);
void mk_uint_128_and(unsigned __int128* out, unsigned __int128 const* a, unsigned __int128 const* b);
void mk_uint_128_xor(unsigned __int128* out, unsigned __int128 const* a, unsigned __int128 const* b);

void mk_uint_128_shl(unsigned __int128* out, unsigned __int128 const* x, int n);
void mk_uint_128_shr(unsigned __int128* out, unsigned __int128 const* x, int n);

int mk_uint_128_eq(unsigned __int128 const* a, unsigned __int128 const* b);
int mk_uint_128_neq(unsigned __int128 const* a, unsigned __int128 const* b);
int mk_uint_128_lt(unsigned __int128 const* a, unsigned __int128 const* b);
int mk_uint_128_le(unsigned __int128 const* a, unsigned __int128 const* b);
int mk_uint_128_gt(unsigned __int128 const* a, unsigned __int128 const* b);
int mk_uint_128_ge(unsigned __int128 const* a, unsigned __int128 const* b);

void mk_uint_128_inc(unsigned __int128* x);
void mk_uint_128_dec(unsigned __int128* x);

void mk_uint_128_add(unsigned __int128* out, unsigned __int128 const* a, unsigned __int128 const* b);
void mk_uint_128_sub(unsigned __int128* out, unsigned __int128 const* a, unsigned __int128 const* b);


#endif


#endif
