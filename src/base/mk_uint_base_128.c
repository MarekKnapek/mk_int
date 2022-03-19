#include "mk_uint_base_128.h"


#ifdef __SIZEOF_INT128__


#include "../utils/mk_assert.h"

#include <stddef.h> /* size_t */
#include <limits.h> /* CHAR_BIT */


void mk_uint_128_zero(unsigned __int128* out)
{
	mk_assert(out);

	*out = 0;
}

void mk_uint_128_one(unsigned __int128* out)
{
	mk_assert(out);

	*out = 1;
}

void mk_uint_128_from_int(unsigned __int128* out, unsigned in)
{
	mk_assert(out);

	*out = (unsigned __int128)in;
}

unsigned mk_uint_128_to_int(unsigned __int128 const* x)
{
	mk_assert(x);

	return (unsigned)*x;
}

void mk_uint_128_from_sizet(unsigned __int128* out, size_t in)
{
	mk_assert(out);

	*out = (unsigned __int128)in;
}

size_t mk_uint_128_to_sizet(unsigned __int128 const* x)
{
	mk_assert(x);

	return (size_t)*x;
}

void mk_uint_128_from_buff_le(unsigned __int128* out, void const* buff)
{
	unsigned __int128 r;
	unsigned char const* input;
	int i;

	mk_assert(out);
	mk_assert(buff);

	r = 0;
	input = (unsigned char const*)buff;
	for(i = 0; i != sizeof(unsigned __int128); ++i)
	{
		r |= ((unsigned __int128)input[i]) << (i * CHAR_BIT);
	}

	*out = r;
}

void mk_uint_128_to_buff_be(unsigned __int128 const* x, void* buff)
{
	int i;
	unsigned char* output;

	mk_assert(x);
	mk_assert(buff);
	
	output = (unsigned char*)buff;
	for(i = 0; i != sizeof(unsigned __int128); ++i)
	{
		output[i] = (unsigned char)((*x >> ((sizeof(unsigned __int128) - 1 - i) * CHAR_BIT)) & 0xff);
	}
}


int mk_uint_128_is_zero(unsigned __int128 const* x)
{
	mk_assert(x);

	return *x == 0;
}

int mk_uint_128_is_max(unsigned __int128 const* x)
{
	mk_assert(x);

	return *x == (unsigned __int128)((unsigned __int128)0 - (unsigned __int128)1);
}


void mk_uint_128_cmplmnt(unsigned __int128* out, unsigned __int128 const* x)
{
	unsigned __int128 r;

	mk_assert(out);
	mk_assert(x);

	r = ~*x;

	*out = r;
}

void mk_uint_128_or(unsigned __int128* out, unsigned __int128 const* a, unsigned __int128 const* b)
{
	unsigned __int128 r;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	r = *a | *b;

	*out = r;
}

void mk_uint_128_and(unsigned __int128* out, unsigned __int128 const* a, unsigned __int128 const* b)
{
	unsigned __int128 r;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	r = *a & *b;

	*out = r;
}

void mk_uint_128_xor(unsigned __int128* out, unsigned __int128 const* a, unsigned __int128 const* b)
{
	unsigned __int128 r;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	r = *a ^ *b;

	*out = r;
}


void mk_uint_128_shl(unsigned __int128* out, unsigned __int128 const* x, int n)
{
	unsigned __int128 r;

	mk_assert(out);
	mk_assert(x);
	mk_assert(n >= 0 && n < (int)(sizeof(unsigned __int128) * CHAR_BIT));

	r = (unsigned __int128)(*x << n);

	*out = r;
}

void mk_uint_128_shr(unsigned __int128* out, unsigned __int128 const* x, int n)
{
	unsigned __int128 r;

	mk_assert(out);
	mk_assert(x);
	mk_assert(n >= 0 && n < (int)(sizeof(unsigned __int128) * CHAR_BIT));

	r = *x >> n;

	*out = r;
}


int mk_uint_128_eq(unsigned __int128 const* a, unsigned __int128 const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a == *b;
}

int mk_uint_128_neq(unsigned __int128 const* a, unsigned __int128 const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a != *b;
}

int mk_uint_128_lt(unsigned __int128 const* a, unsigned __int128 const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a < *b;
}

int mk_uint_128_le(unsigned __int128 const* a, unsigned __int128 const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a <= *b;
}

int mk_uint_128_gt(unsigned __int128 const* a, unsigned __int128 const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a > *b;
}

int mk_uint_128_ge(unsigned __int128 const* a, unsigned __int128 const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a >= *b;
}


void mk_uint_128_inc(unsigned __int128* x)
{
	mk_assert(x);

	++*x;
}

void mk_uint_128_dec(unsigned __int128* x)
{
	mk_assert(x);

	--*x;
}


void mk_uint_128_add(unsigned __int128* out, unsigned __int128 const* a, unsigned __int128 const* b)
{
	unsigned __int128 r;
	
	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	r = *a + *b;

	*out = r;
}

void mk_uint_128_sub(unsigned __int128* out, unsigned __int128 const* a, unsigned __int128 const* b)
{
	unsigned __int128 r;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	r = *a - *b;

	*out = r;
}


#endif
