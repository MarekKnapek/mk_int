#if __STDC_VERSION__ >= 199901L || __cplusplus >= 201103L


#include "mk_uint_llong.h"

#include "../utils/mk_assert.h"

#include <stddef.h> /* size_t */
#include <limits.h> /* CHAR_BIT */


void mk_uint_llong_zero(unsigned long long* out)
{
	mk_assert(out);

	*out = 0;
}

void mk_uint_llong_one(unsigned long long* out)
{
	mk_assert(out);

	*out = 1;
}

void mk_uint_llong_from_int(unsigned long long* out, unsigned in)
{
	mk_assert(out);

	*out = (unsigned long long)in;
}

unsigned mk_uint_llong_to_int(unsigned long long const* x)
{
	mk_assert(x);

	return (unsigned)*x;
}

void mk_uint_llong_from_sizet(unsigned long long* out, size_t in)
{
	mk_assert(out);

	*out = (unsigned long long)in;
}

size_t mk_uint_llong_to_sizet(unsigned long long const* x)
{
	mk_assert(x);

	return (size_t)*x;
}

void mk_uint_llong_from_buff_le(unsigned long long* out, void const* buff)
{
	mk_assert(out);
	mk_assert(buff);

	unsigned long long r;
	unsigned char const* input;
	int i;

	r = 0;
	input = (unsigned char const*)buff;
	for(i = 0; i != sizeof(unsigned long long); ++i)
	{
		r |= ((unsigned long long)input[i]) << (i * CHAR_BIT);
	}

	*out = r;
}

void mk_uint_llong_to_buff_be(unsigned long long const* x, void* buff)
{
	mk_assert(x);
	mk_assert(buff);
	
	int i;
	unsigned char* output;

	output = (unsigned char*)buff;
	for(i = 0; i != sizeof(unsigned long long); ++i)
	{
		output[i] = (unsigned char)((*x >> ((sizeof(unsigned long long) - 1 - i) * CHAR_BIT)) & 0xff);
	}
}


int mk_uint_llong_is_zero(unsigned long long const* x)
{
	mk_assert(x);

	return *x == 0;
}

int mk_uint_llong_is_max(unsigned long long const* x)
{
	mk_assert(x);

	return *x == (unsigned long long)((unsigned long long)0 - (unsigned long long)1);
}


void mk_uint_llong_cmplmnt(unsigned long long* out, unsigned long long const* x)
{
	mk_assert(out);
	mk_assert(x);

	unsigned long long r;

	r = ~*x;

	*out = r;
}

void mk_uint_llong_or(unsigned long long* out, unsigned long long const* a, unsigned long long const* b)
{
	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	unsigned long long r;

	r = *a | *b;

	*out = r;
}

void mk_uint_llong_and(unsigned long long* out, unsigned long long const* a, unsigned long long const* b)
{
	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	unsigned long long r;

	r = *a & *b;

	*out = r;
}

void mk_uint_llong_xor(unsigned long long* out, unsigned long long const* a, unsigned long long const* b)
{
	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	unsigned long long r;

	r = *a ^ *b;

	*out = r;
}


void mk_uint_llong_shl(unsigned long long* out, unsigned long long const* x, int n)
{
	mk_assert(out);
	mk_assert(x);
	mk_assert(n >= 0 && n < (int)(sizeof(unsigned long long) * CHAR_BIT));

	unsigned long long r;

	r = (unsigned long long)(*x << n);

	*out = r;
}

void mk_uint_llong_shr(unsigned long long* out, unsigned long long const* x, int n)
{
	mk_assert(out);
	mk_assert(x);
	mk_assert(n >= 0 && n < (int)(sizeof(unsigned long long) * CHAR_BIT));

	unsigned long long r;

	r = *x >> n;

	*out = r;
}


int mk_uint_llong_eq(unsigned long long const* a, unsigned long long const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a == *b;
}

int mk_uint_llong_neq(unsigned long long const* a, unsigned long long const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a != *b;
}

int mk_uint_llong_lt(unsigned long long const* a, unsigned long long const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a < *b;
}

int mk_uint_llong_le(unsigned long long const* a, unsigned long long const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a <= *b;
}

int mk_uint_llong_gt(unsigned long long const* a, unsigned long long const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a > *b;
}

int mk_uint_llong_ge(unsigned long long const* a, unsigned long long const* b)
{
	mk_assert(a);
	mk_assert(b);

	return *a >= *b;
}


void mk_uint_llong_inc(unsigned long long* x)
{
	mk_assert(x);

	++*x;
}

void mk_uint_llong_dec(unsigned long long* x)
{
	mk_assert(x);

	--*x;
}


void mk_uint_llong_add(unsigned long long* out, unsigned long long const* a, unsigned long long const* b)
{
	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	unsigned long long r;
	
	r = *a + *b;

	*out = r;
}

void mk_uint_llong_sub(unsigned long long* out, unsigned long long const* a, unsigned long long const* b)
{
	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	unsigned long long r;
	
	r = *a - *b;

	*out = r;
}


#endif
