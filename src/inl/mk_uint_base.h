#define mk_uint_concat_1(a, b) mk_uint_ ## a ## _ ## b
#define mk_uint_concat(a, b) mk_uint_concat_1(a, b)


#include <stddef.h> /* size_t */


void mk_uint_concat(mk_uint_tn, zero)(mk_uint_t* out);
void mk_uint_concat(mk_uint_tn, one)(mk_uint_t* out);
void mk_uint_concat(mk_uint_tn, from_int)(mk_uint_t* out, unsigned in);
unsigned mk_uint_concat(mk_uint_tn, to_int)(mk_uint_t const* x);
void mk_uint_concat(mk_uint_tn, from_sizet)(mk_uint_t* out, size_t in);
size_t mk_uint_concat(mk_uint_tn, to_sizet)(mk_uint_t const* x);
void mk_uint_concat(mk_uint_tn, from_buff_le)(mk_uint_t* out, void const* buff);
void mk_uint_concat(mk_uint_tn, to_buff_le)(mk_uint_t const* x, void* buff);
void mk_uint_concat(mk_uint_tn, from_buff_be)(mk_uint_t* out, void const* buff);
void mk_uint_concat(mk_uint_tn, to_buff_be)(mk_uint_t const* x, void* buff);

int mk_uint_concat(mk_uint_tn, is_zero)(mk_uint_t const* x);
int mk_uint_concat(mk_uint_tn, is_max)(mk_uint_t const* x);

void mk_uint_concat(mk_uint_tn, cmplmnt)(mk_uint_t* out, mk_uint_t const* x);
void mk_uint_concat(mk_uint_tn, or)(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b);
void mk_uint_concat(mk_uint_tn, and)(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b);
void mk_uint_concat(mk_uint_tn, xor)(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b);

void mk_uint_concat(mk_uint_tn, shl)(mk_uint_t* out, mk_uint_t const* x, int n);
void mk_uint_concat(mk_uint_tn, shr)(mk_uint_t* out, mk_uint_t const* x, int n);

int mk_uint_concat(mk_uint_tn, eq)(mk_uint_t const* a, mk_uint_t const* b);
int mk_uint_concat(mk_uint_tn, neq)(mk_uint_t const* a, mk_uint_t const* b);
int mk_uint_concat(mk_uint_tn, lt)(mk_uint_t const* a, mk_uint_t const* b);
int mk_uint_concat(mk_uint_tn, le)(mk_uint_t const* a, mk_uint_t const* b);
int mk_uint_concat(mk_uint_tn, gt)(mk_uint_t const* a, mk_uint_t const* b);
int mk_uint_concat(mk_uint_tn, ge)(mk_uint_t const* a, mk_uint_t const* b);

void mk_uint_concat(mk_uint_tn, inc)(mk_uint_t* x);
void mk_uint_concat(mk_uint_tn, dec)(mk_uint_t* x);

void mk_uint_concat(mk_uint_tn, add)(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b);
void mk_uint_concat(mk_uint_tn, sub)(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b);


#undef mk_uint_concat_1
#undef mk_uint_concat
