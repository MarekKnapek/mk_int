#include "mk_uint_base_int.h"

#include "../utils/mk_assert.h"

#include <stddef.h> /* size_t */
#include <limits.h> /* CHAR_BIT */


void mk_uint_int_zero(unsigned int* out)
{
	mk_assert(out);

	*out = 0;
}

void mk_uint_int_one(unsigned int* out)
{
	mk_assert(out);

	*out = 1;
}

void mk_uint_int_from_int(unsigned int* out, unsigned in)
{
	mk_assert(out);

	*out = (unsigned int)in;
}

unsigned mk_uint_int_to_int(unsigned int const* x)
{
	mk_assert(x);

	return (unsigned)*x;
}

void mk_uint_int_from_sizet(unsigned int* out, size_t in)
{
	mk_assert(out);

	*out = (unsigned int)in;
}

size_t mk_uint_int_to_sizet(unsigned int const* x)
{
	mk_assert(x);

	return (size_t)*x;
}

void mk_uint_int_from_buff_le(unsigned int* out, void const* buff)
{
	unsigned int r;
	unsigned char const* input;
	int i;

	mk_assert(out);
	mk_assert(buff);

	r = 0;
	input = (unsigned char const*)buff;
	for(i = 0; i != sizeof(unsigned int); ++i)
	{
		r |= ((unsigned int)input[i]) << (i * CHAR_BIT);
	}

	*out = r;
}

void mk_uint_int_to_buff_le(unsigned int const* x, void* buff)
{
	int i;
	unsigned char* output;

	mk_assert(x);
	mk_assert(buff);
	
	output = (unsigned char*)buff;
	for(i = 0; i != sizeof(unsigned int); ++i)
	{
		output[i] = (unsigned char)((*x >> (i * CHAR_BIT)) & 0xff);
	}
}

void mk_uint_int_from_buff_be(unsigned int* out, void const* buff)
{
	unsigned int r;
	unsigned char const* input;
	int i;

	mk_assert(out);
	mk_assert(buff);

	r = 0;
	input = (unsigned char const*)buff;
	for(i = 0; i != sizeof(unsigned int); ++i)
	{
		r |= ((unsigned int)input[i]) << ((sizeof(unsigned int) - 1 - i) * CHAR_BIT);
	}

	*out = r;
}

void mk_uint_int_to_buff_be(unsigned int const* x, void* buff)
{
	int i;
	unsigned char* output;

	mk_assert(x);
	mk_assert(buff);
	
	output = (unsigned char*)buff;
	for(i = 0; i != sizeof(unsigned int); ++i)
	{
		output[i] = (unsigned char)((*x >> ((sizeof(unsigned int) - 1 - i) * CHAR_BIT)) & 0xff);
	}
}


int mk_uint_int_is_zero(unsigned int const* x)
{
	mk_assert(x);

	return *x == 0;
}

int mk_uint_int_is_max(unsigned int const* x)
{
	mk_assert(x);

	return *x == (unsigned int)((unsigned int)0 - (unsigned int)1);
}


void mk_uint_int_cmplmnt(unsigned int* out, unsigned int const* x)
{
	unsigned int r;

	mk_assert(out);
	mk_assert(x);

	r = ~*x;

	*out = r;
}

void mk_uint_int_or(unsigned int* out, unsigned int const* a, unsigned int const* b)
{
	unsigned int r;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	r = *a | *b;

	*out = r;
}

void mk_uint_int_and(unsigned int* out, unsigned int const* a, unsigned int const* b)
{
	unsigned int r;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	r = *a & *b;

	*out = r;
}

void mk_uint_int_xor(unsigned int* out, unsigned int const* a, unsigned int const* b)
{
	unsigned int r;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	r = *a ^ *b;

	*out = r;
}


void mk_uint_int_shl(unsigned int* out, unsigned int const* x, int n)
{
	unsigned int r;

	mk_assert(out);
	mk_assert(x);
	mk_assert(n >= 0 && n < (int)(sizeof(unsigned int) * CHAR_BIT));

	r = (unsigned int)(*x << n);

	*out = r;
}

void mk_uint_int_shr(unsigned int* out, unsigned int const* x, int n)
{
	unsigned int r;

	mk_assert(out);
	mk_assert(x);
	mk_assert(n >= 0 && n < (int)(sizeof(unsigned int) * CHAR_BIT));

	r = *x >> n;

	*out = r;
}


int mk_uint_int_eq(unsigned int const* a, unsigned int const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a == *b;
}

int mk_uint_int_neq(unsigned int const* a, unsigned int const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a != *b;
}

int mk_uint_int_lt(unsigned int const* a, unsigned int const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a < *b;
}

int mk_uint_int_le(unsigned int const* a, unsigned int const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a <= *b;
}

int mk_uint_int_gt(unsigned int const* a, unsigned int const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a > *b;
}

int mk_uint_int_ge(unsigned int const* a, unsigned int const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a >= *b;
}


void mk_uint_int_inc(unsigned int* x)
{
	mk_assert(x);

	++*x;
}

void mk_uint_int_dec(unsigned int* x)
{
	mk_assert(x);

	--*x;
}


void mk_uint_int_add(unsigned int* out, unsigned int const* a, unsigned int const* b)
{
	unsigned int r;
	
	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	r = *a + *b;

	*out = r;
}

void mk_uint_int_sub(unsigned int* out, unsigned int const* a, unsigned int const* b)
{
	unsigned int r;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	r = *a - *b;

	*out = r;
}
