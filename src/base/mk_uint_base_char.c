#include "mk_uint_base_char.h"

#include "../utils/mk_assert.h"

#include <stddef.h> /* size_t */
#include <limits.h> /* CHAR_BIT */


void mk_uint_char_zero(unsigned char* out)
{
	mk_assert(out);

	*out = 0;
}

void mk_uint_char_one(unsigned char* out)
{
	mk_assert(out);

	*out = 1;
}

void mk_uint_char_from_int(unsigned char* out, unsigned in)
{
	mk_assert(out);

	*out = (unsigned char)in;
}

unsigned mk_uint_char_to_int(unsigned char const* x)
{
	mk_assert(x);

	return (unsigned)*x;
}

void mk_uint_char_from_sizet(unsigned char* out, size_t in)
{
	mk_assert(out);

	*out = (unsigned char)in;
}

size_t mk_uint_char_to_sizet(unsigned char const* x)
{
	mk_assert(x);

	return (size_t)*x;
}

void mk_uint_char_from_buff_le(unsigned char* out, void const* buff)
{
	unsigned char r;
	unsigned char const* input;
	int i;

	mk_assert(out);
	mk_assert(buff);

	r = 0;
	input = (unsigned char const*)buff;
	for(i = 0; i != sizeof(unsigned char); ++i)
	{
		r |= ((unsigned char)input[i]) << (i * CHAR_BIT);
	}

	*out = r;
}

void mk_uint_char_to_buff_le(unsigned char const* x, void* buff)
{
	int i;
	unsigned char* output;

	mk_assert(x);
	mk_assert(buff);
	
	output = (unsigned char*)buff;
	for(i = 0; i != sizeof(unsigned char); ++i)
	{
		output[i] = (unsigned char)((*x >> (i * CHAR_BIT)) & 0xff);
	}
}

void mk_uint_char_to_buff_be(unsigned char const* x, void* buff)
{
	int i;
	unsigned char* output;

	mk_assert(x);
	mk_assert(buff);
	
	output = (unsigned char*)buff;
	for(i = 0; i != sizeof(unsigned char); ++i)
	{
		output[i] = (unsigned char)((*x >> ((sizeof(unsigned char) - 1 - i) * CHAR_BIT)) & 0xff);
	}
}


int mk_uint_char_is_zero(unsigned char const* x)
{
	mk_assert(x);

	return *x == 0;
}

int mk_uint_char_is_max(unsigned char const* x)
{
	mk_assert(x);

	return *x == (unsigned char)((unsigned char)0 - (unsigned char)1);
}


void mk_uint_char_cmplmnt(unsigned char* out, unsigned char const* x)
{
	unsigned char r;

	mk_assert(out);
	mk_assert(x);

	r = ~*x;

	*out = r;
}

void mk_uint_char_or(unsigned char* out, unsigned char const* a, unsigned char const* b)
{
	unsigned char r;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	r = *a | *b;

	*out = r;
}

void mk_uint_char_and(unsigned char* out, unsigned char const* a, unsigned char const* b)
{
	unsigned char r;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	r = *a & *b;

	*out = r;
}

void mk_uint_char_xor(unsigned char* out, unsigned char const* a, unsigned char const* b)
{
	unsigned char r;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	r = *a ^ *b;

	*out = r;
}


void mk_uint_char_shl(unsigned char* out, unsigned char const* x, int n)
{
	unsigned char r;

	mk_assert(out);
	mk_assert(x);
	mk_assert(n >= 0 && n < (int)(sizeof(unsigned char) * CHAR_BIT));

	r = (unsigned char)(*x << n);

	*out = r;
}

void mk_uint_char_shr(unsigned char* out, unsigned char const* x, int n)
{
	unsigned char r;

	mk_assert(out);
	mk_assert(x);
	mk_assert(n >= 0 && n < (int)(sizeof(unsigned char) * CHAR_BIT));

	r = *x >> n;

	*out = r;
}


int mk_uint_char_eq(unsigned char const* a, unsigned char const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a == *b;
}

int mk_uint_char_neq(unsigned char const* a, unsigned char const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a != *b;
}

int mk_uint_char_lt(unsigned char const* a, unsigned char const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a < *b;
}

int mk_uint_char_le(unsigned char const* a, unsigned char const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a <= *b;
}

int mk_uint_char_gt(unsigned char const* a, unsigned char const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a > *b;
}

int mk_uint_char_ge(unsigned char const* a, unsigned char const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a >= *b;
}


void mk_uint_char_inc(unsigned char* x)
{
	mk_assert(x);

	++*x;
}

void mk_uint_char_dec(unsigned char* x)
{
	mk_assert(x);

	--*x;
}


void mk_uint_char_add(unsigned char* out, unsigned char const* a, unsigned char const* b)
{
	unsigned char r;
	
	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	r = *a + *b;

	*out = r;
}

void mk_uint_char_sub(unsigned char* out, unsigned char const* a, unsigned char const* b)
{
	unsigned char r;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	r = *a - *b;

	*out = r;
}
