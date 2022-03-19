#include "mk_uint_base_short.h"

#include "../utils/mk_assert.h"

#include <stddef.h> /* size_t */
#include <limits.h> /* CHAR_BIT */


void mk_uint_short_zero(unsigned short* out)
{
	mk_assert(out);

	*out = 0;
}

void mk_uint_short_one(unsigned short* out)
{
	mk_assert(out);

	*out = 1;
}

void mk_uint_short_from_int(unsigned short* out, unsigned in)
{
	mk_assert(out);

	*out = (unsigned short)in;
}

unsigned mk_uint_short_to_int(unsigned short const* x)
{
	mk_assert(x);

	return (unsigned)*x;
}

void mk_uint_short_from_sizet(unsigned short* out, size_t in)
{
	mk_assert(out);

	*out = (unsigned short)in;
}

size_t mk_uint_short_to_sizet(unsigned short const* x)
{
	mk_assert(x);

	return (size_t)*x;
}

void mk_uint_short_from_buff_le(unsigned short* out, void const* buff)
{
	unsigned short r;
	unsigned char const* input;
	int i;

	mk_assert(out);
	mk_assert(buff);

	r = 0;
	input = (unsigned char const*)buff;
	for(i = 0; i != sizeof(unsigned short); ++i)
	{
		r |= ((unsigned short)input[i]) << (i * CHAR_BIT);
	}

	*out = r;
}

void mk_uint_short_to_buff_le(unsigned short const* x, void* buff)
{
	int i;
	unsigned char* output;

	mk_assert(x);
	mk_assert(buff);
	
	output = (unsigned char*)buff;
	for(i = 0; i != sizeof(unsigned short); ++i)
	{
		output[i] = (unsigned char)((*x >> (i * CHAR_BIT)) & 0xff);
	}
}

void mk_uint_short_from_buff_be(unsigned short* out, void const* buff)
{
	unsigned short r;
	unsigned char const* input;
	int i;

	mk_assert(out);
	mk_assert(buff);

	r = 0;
	input = (unsigned char const*)buff;
	for(i = 0; i != sizeof(unsigned short); ++i)
	{
		r |= ((unsigned short)input[i]) << ((sizeof(unsigned short) - 1 - i) * CHAR_BIT);
	}

	*out = r;
}

void mk_uint_short_to_buff_be(unsigned short const* x, void* buff)
{
	int i;
	unsigned char* output;

	mk_assert(x);
	mk_assert(buff);
	
	output = (unsigned char*)buff;
	for(i = 0; i != sizeof(unsigned short); ++i)
	{
		output[i] = (unsigned char)((*x >> ((sizeof(unsigned short) - 1 - i) * CHAR_BIT)) & 0xff);
	}
}


int mk_uint_short_is_zero(unsigned short const* x)
{
	mk_assert(x);

	return *x == 0;
}

int mk_uint_short_is_max(unsigned short const* x)
{
	mk_assert(x);

	return *x == (unsigned short)((unsigned short)0 - (unsigned short)1);
}


void mk_uint_short_cmplmnt(unsigned short* out, unsigned short const* x)
{
	unsigned short r;

	mk_assert(out);
	mk_assert(x);

	r = ~*x;

	*out = r;
}

void mk_uint_short_or(unsigned short* out, unsigned short const* a, unsigned short const* b)
{
	unsigned short r;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	r = *a | *b;

	*out = r;
}

void mk_uint_short_and(unsigned short* out, unsigned short const* a, unsigned short const* b)
{
	unsigned short r;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	r = *a & *b;

	*out = r;
}

void mk_uint_short_xor(unsigned short* out, unsigned short const* a, unsigned short const* b)
{
	unsigned short r;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	r = *a ^ *b;

	*out = r;
}


void mk_uint_short_shl(unsigned short* out, unsigned short const* x, int n)
{
	unsigned short r;

	mk_assert(out);
	mk_assert(x);
	mk_assert(n >= 0 && n < (int)(sizeof(unsigned short) * CHAR_BIT));

	r = (unsigned short)(*x << n);

	*out = r;
}

void mk_uint_short_shr(unsigned short* out, unsigned short const* x, int n)
{
	unsigned short r;

	mk_assert(out);
	mk_assert(x);
	mk_assert(n >= 0 && n < (int)(sizeof(unsigned short) * CHAR_BIT));

	r = *x >> n;

	*out = r;
}


int mk_uint_short_eq(unsigned short const* a, unsigned short const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a == *b;
}

int mk_uint_short_neq(unsigned short const* a, unsigned short const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a != *b;
}

int mk_uint_short_lt(unsigned short const* a, unsigned short const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a < *b;
}

int mk_uint_short_le(unsigned short const* a, unsigned short const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a <= *b;
}

int mk_uint_short_gt(unsigned short const* a, unsigned short const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a > *b;
}

int mk_uint_short_ge(unsigned short const* a, unsigned short const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a >= *b;
}


void mk_uint_short_inc(unsigned short* x)
{
	mk_assert(x);

	++*x;
}

void mk_uint_short_dec(unsigned short* x)
{
	mk_assert(x);

	--*x;
}


void mk_uint_short_add(unsigned short* out, unsigned short const* a, unsigned short const* b)
{
	unsigned short r;
	
	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	r = *a + *b;

	*out = r;
}

void mk_uint_short_sub(unsigned short* out, unsigned short const* a, unsigned short const* b)
{
	unsigned short r;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	r = *a - *b;

	*out = r;
}
