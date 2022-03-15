#include "mk_uint_long.h"

#include "../utils/mk_assert.h"

#include <stddef.h> /* size_t */
#include <limits.h> /* CHAR_BIT */


void mk_uint_long_zero(unsigned long* out)
{
	mk_assert(out);

	*out = 0;
}

void mk_uint_long_one(unsigned long* out)
{
	mk_assert(out);

	*out = 1;
}

void mk_uint_long_from_int(unsigned long* out, unsigned in)
{
	mk_assert(out);

	*out = (unsigned long)in;
}

unsigned mk_uint_long_to_int(unsigned long const* x)
{
	mk_assert(x);

	return (unsigned)*x;
}

void mk_uint_long_from_sizet(unsigned long* out, size_t in)
{
	mk_assert(out);

	*out = (unsigned long)in;
}

size_t mk_uint_long_to_sizet(unsigned long const* x)
{
	mk_assert(x);

	return (size_t)*x;
}

void mk_uint_long_from_buff_le(unsigned long* out, void const* buff)
{
	mk_assert(out);
	mk_assert(buff);

	unsigned long r;
	unsigned char const* input;
	int i;

	r = 0;
	input = (unsigned char const*)buff;
	for(i = 0; i != sizeof(unsigned long); ++i)
	{
		r |= ((unsigned long)input[i]) << (i * CHAR_BIT);
	}

	*out = r;
}

void mk_uint_long_to_buff_be(unsigned long const* x, void* buff)
{
	mk_assert(x);
	mk_assert(buff);
	
	int i;
	unsigned char* output;

	output = (unsigned char*)buff;
	for(i = 0; i != sizeof(unsigned long); ++i)
	{
		output[i] = (unsigned char)((*x >> ((sizeof(unsigned long) - 1 - i) * CHAR_BIT)) & 0xff);
	}
}


int mk_uint_long_is_zero(unsigned long const* x)
{
	mk_assert(x);

	return *x == 0;
}

int mk_uint_long_is_max(unsigned long const* x)
{
	mk_assert(x);

	return *x == (unsigned long)((unsigned long)0 - (unsigned long)1);
}


void mk_uint_long_cmplmnt(unsigned long* out, unsigned long const* x)
{
	mk_assert(out);
	mk_assert(x);

	unsigned long r;

	r = ~*x;

	*out = r;
}

void mk_uint_long_or(unsigned long* out, unsigned long const* a, unsigned long const* b)
{
	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	unsigned long r;

	r = *a | *b;

	*out = r;
}

void mk_uint_long_and(unsigned long* out, unsigned long const* a, unsigned long const* b)
{
	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	unsigned long r;

	r = *a & *b;

	*out = r;
}

void mk_uint_long_xor(unsigned long* out, unsigned long const* a, unsigned long const* b)
{
	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	unsigned long r;

	r = *a ^ *b;

	*out = r;
}


void mk_uint_long_shl(unsigned long* out, unsigned long const* x, int n)
{
	mk_assert(out);
	mk_assert(x);
	mk_assert(n >= 0 && n < (int)(sizeof(unsigned long) * CHAR_BIT));

	unsigned long r;

	r = (unsigned long)(*x << n);

	*out = r;
}

void mk_uint_long_shr(unsigned long* out, unsigned long const* x, int n)
{
	mk_assert(out);
	mk_assert(x);
	mk_assert(n >= 0 && n < (int)(sizeof(unsigned long) * CHAR_BIT));

	unsigned long r;

	r = *x >> n;

	*out = r;
}


int mk_uint_long_eq(unsigned long const* a, unsigned long const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a == *b;
}

int mk_uint_long_neq(unsigned long const* a, unsigned long const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a != *b;
}

int mk_uint_long_lt(unsigned long const* a, unsigned long const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a < *b;
}

int mk_uint_long_le(unsigned long const* a, unsigned long const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a <= *b;
}

int mk_uint_long_gt(unsigned long const* a, unsigned long const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a > *b;
}

int mk_uint_long_ge(unsigned long const* a, unsigned long const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a >= *b;
}


void mk_uint_long_inc(unsigned long* x)
{
	mk_assert(x);

	++*x;
}

void mk_uint_long_dec(unsigned long* x)
{
	mk_assert(x);

	--*x;
}


void mk_uint_long_add(unsigned long* out, unsigned long const* a, unsigned long const* b)
{
	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	unsigned long r;
	
	r = *a + *b;

	*out = r;
}

void mk_uint_long_sub(unsigned long* out, unsigned long const* a, unsigned long const* b)
{
	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	unsigned long r;
	
	r = *a - *b;

	*out = r;
}
