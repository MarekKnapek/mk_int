#define mk_uint_concat_1(a, b) mk_uint_ ## a ## _ ## b
#define mk_uint_concat(a, b) mk_uint_concat_1(a, b)


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4464) /* warning C4464: relative include path contains '..' */
#endif


#include "../utils/mk_assert.h"

#include <stddef.h> /* size_t */
#include <limits.h> /* CHAR_BIT */


void mk_uint_concat(mk_uint_tn, zero)(mk_uint_t* out)
{
	mk_assert(out);

	*out = 0;
}

void mk_uint_concat(mk_uint_tn, one)(mk_uint_t* out)
{
	mk_assert(out);

	*out = 1;
}

void mk_uint_concat(mk_uint_tn, from_int)(mk_uint_t* out, unsigned in)
{
	mk_assert(out);

	*out = (mk_uint_t)in;
}

unsigned mk_uint_concat(mk_uint_tn, to_int)(mk_uint_t const* x)
{
	mk_assert(x);

	return (unsigned)*x;
}

void mk_uint_concat(mk_uint_tn, from_sizet)(mk_uint_t* out, size_t in)
{
	mk_assert(out);

	*out = (mk_uint_t)in;
}

size_t mk_uint_concat(mk_uint_tn, to_sizet)(mk_uint_t const* x)
{
	mk_assert(x);

	return (size_t)*x;
}

void mk_uint_concat(mk_uint_tn, from_buff_le)(mk_uint_t* out, void const* buff)
{
	mk_uint_t r;
	unsigned char const* input;
	int i;

	mk_assert(out);
	mk_assert(buff);

	r = 0;
	input = (unsigned char const*)buff;
	for(i = 0; i != sizeof(mk_uint_t); ++i)
	{
		r |= ((mk_uint_t)input[i]) << (i * CHAR_BIT);
	}

	*out = r;
}

void mk_uint_concat(mk_uint_tn, to_buff_le)(mk_uint_t const* x, void* buff)
{
	int i;
	unsigned char* output;

	mk_assert(x);
	mk_assert(buff);
	
	output = (unsigned char*)buff;
	for(i = 0; i != sizeof(mk_uint_t); ++i)
	{
		output[i] = (unsigned char)((*x >> (i * CHAR_BIT)) & 0xff);
	}
}

void mk_uint_concat(mk_uint_tn, from_buff_be)(mk_uint_t* out, void const* buff)
{
	mk_uint_t r;
	unsigned char const* input;
	int i;

	mk_assert(out);
	mk_assert(buff);

	r = 0;
	input = (unsigned char const*)buff;
	for(i = 0; i != sizeof(mk_uint_t); ++i)
	{
		r |= ((mk_uint_t)input[i]) << ((sizeof(mk_uint_t) - 1 - i) * CHAR_BIT);
	}

	*out = r;
}

void mk_uint_concat(mk_uint_tn, to_buff_be)(mk_uint_t const* x, void* buff)
{
	int i;
	unsigned char* output;

	mk_assert(x);
	mk_assert(buff);
	
	output = (unsigned char*)buff;
	for(i = 0; i != sizeof(mk_uint_t); ++i)
	{
		output[i] = (unsigned char)((*x >> ((sizeof(mk_uint_t) - 1 - i) * CHAR_BIT)) & 0xff);
	}
}


int mk_uint_concat(mk_uint_tn, is_zero)(mk_uint_t const* x)
{
	mk_assert(x);

	return *x == 0;
}

int mk_uint_concat(mk_uint_tn, is_max)(mk_uint_t const* x)
{
	mk_assert(x);

	return *x == (mk_uint_t)((mk_uint_t)0 - (mk_uint_t)1);
}


void mk_uint_concat(mk_uint_tn, cmplmnt)(mk_uint_t* out, mk_uint_t const* x)
{
	mk_uint_t r;

	mk_assert(out);
	mk_assert(x);

	r = (mk_uint_t)(~*x);

	*out = r;
}

void mk_uint_concat(mk_uint_tn, or)(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_t r;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	r = (mk_uint_t)(*a | *b);

	*out = r;
}

void mk_uint_concat(mk_uint_tn, and)(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_t r;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	r = (mk_uint_t)(*a & *b);

	*out = r;
}

void mk_uint_concat(mk_uint_tn, xor)(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_t r;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	r = (mk_uint_t)(*a ^ *b);

	*out = r;
}


void mk_uint_concat(mk_uint_tn, shl)(mk_uint_t* out, mk_uint_t const* x, int n)
{
	mk_uint_t r;

	mk_assert(out);
	mk_assert(x);
	mk_assert(n >= 0 && n < (int)(sizeof(mk_uint_t) * CHAR_BIT));

	r = (mk_uint_t)(*x << n);

	*out = r;
}

void mk_uint_concat(mk_uint_tn, shr)(mk_uint_t* out, mk_uint_t const* x, int n)
{
	mk_uint_t r;

	mk_assert(out);
	mk_assert(x);
	mk_assert(n >= 0 && n < (int)(sizeof(mk_uint_t) * CHAR_BIT));

	r = (mk_uint_t)(*x >> n);

	*out = r;
}


int mk_uint_concat(mk_uint_tn, eq)(mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a == *b;
}

int mk_uint_concat(mk_uint_tn, neq)(mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a != *b;
}

int mk_uint_concat(mk_uint_tn, lt)(mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a < *b;
}

int mk_uint_concat(mk_uint_tn, le)(mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a <= *b;
}

int mk_uint_concat(mk_uint_tn, gt)(mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a > *b;
}

int mk_uint_concat(mk_uint_tn, ge)(mk_uint_t const* a, mk_uint_t const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a >= *b;
}


void mk_uint_concat(mk_uint_tn, inc)(mk_uint_t* x)
{
	mk_assert(x);

	++*x;
}

void mk_uint_concat(mk_uint_tn, dec)(mk_uint_t* x)
{
	mk_assert(x);

	--*x;
}


void mk_uint_concat(mk_uint_tn, add)(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_t r;
	
	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	r = (mk_uint_t)(*a + *b);

	*out = r;
}

void mk_uint_concat(mk_uint_tn, sub)(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_t r;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	r = (mk_uint_t)(*a - *b);

	*out = r;
}


#if defined(_MSC_VER)
#pragma warning(pop)
#endif


#undef mk_uint_concat_1
#undef mk_uint_concat
