#include "../utils/mk_assert.h"

#include "../utils/maybe_initialize.h"

#include <limits.h> /* CHAR_BIT */
#include <stddef.h> /* size_t */


#pragma warning(push)
#pragma warning(disable:4711) /* warning C4711: function 'xxx' selected for automatic inline expansion */


#define mk_uint_small_bits ((int)(sizeof(mk_uint_small_t) * CHAR_BIT))
#define mk_uint_bits_to_words(x) (((x) + (mk_uint_small_bits - 1)) / mk_uint_small_bits)
#define mk_uint_parts (mk_uint_bits_to_words(mk_uint_bits))


void mk_uint_zero(mk_uint_t* out)
{
	int i;

	mk_assert(out);

	for(i = 0; i != mk_uint_parts; ++i)
	{
		mk_uint_small_zero(out->m_data + i);
	}
}

void mk_uint_one(mk_uint_t* out)
{
	int i;

	mk_assert(out);

	mk_uint_small_one(out->m_data + 0);
	for(i = 1; i != mk_uint_parts; ++i)
	{
		mk_uint_small_zero(out->m_data + i);
	}
}

void mk_uint_from_int(mk_uint_t* out, unsigned in)
{
	int parts;
	int i;

	mk_assert(out);

	parts = sizeof(in) / sizeof(mk_uint_small_t);
	parts = parts < mk_uint_parts ? parts : mk_uint_parts;
	parts = parts == 0 ? 1 : parts;
	for(i = 0; i != parts; ++i)
	{
		mk_uint_small_from_int(out->m_data + i, in >> (i * mk_uint_small_bits));
	}
	for(i = parts; i != mk_uint_parts; ++i)
	{
		mk_uint_small_zero(out->m_data + i);
	}
}

unsigned mk_uint_to_int(mk_uint_t const* x)
{
	unsigned r;
	int parts;
	int i;

	mk_assert(x);

	r = 0;
	parts = sizeof(unsigned) / sizeof(mk_uint_small_t);
	parts = parts < mk_uint_parts ? parts : mk_uint_parts;
	parts = parts == 0 ? 1 : parts;
	for(i = 0; i != parts; ++i)
	{
		r |= mk_uint_small_to_int(x->m_data + i) << (i * mk_uint_small_bits);
	}

	return r;
}

void mk_uint_from_sizet(mk_uint_t* out, size_t in)
{
	int parts;
	int i;

	mk_assert(out);

	parts = sizeof(in) / sizeof(mk_uint_small_t);
	parts = parts < mk_uint_parts ? parts : mk_uint_parts;
	parts = parts == 0 ? 1 : parts;
	for(i = 0; i != parts; ++i)
	{
		mk_uint_small_from_sizet(out->m_data + i, in >> (i * mk_uint_small_bits));
	}
	for(i = parts; i != mk_uint_parts; ++i)
	{
		mk_uint_small_zero(out->m_data + i);
	}
}

size_t mk_uint_to_sizet(mk_uint_t const* x)
{
	size_t r;
	int parts;
	int i;

	mk_assert(x);

	r = 0;
	parts = sizeof(size_t) / sizeof(mk_uint_small_t);
	parts = parts < mk_uint_parts ? parts : mk_uint_parts;
	parts = parts == 0 ? 1 : parts;
	for(i = 0; i != parts; ++i)
	{
		r |= mk_uint_small_to_sizet(x->m_data + i) << (i * mk_uint_small_bits);
	}

	return r;
}

void mk_uint_from_buff_le(mk_uint_t* out, void const* buff)
{
	int i;
	unsigned char const* input;

	mk_assert(out);
	mk_assert(buff);

	input = (unsigned char const*)buff;
	for(i = 0; i != mk_uint_parts; ++i)
	{
		mk_uint_small_from_buff_le(out->m_data + i, input + i * sizeof(mk_uint_small_t));
	}
}

void mk_uint_to_buff_le(mk_uint_t const* x, void* buff)
{
	int i;
	unsigned char* output;

	mk_assert(x);
	mk_assert(buff);

	output = (unsigned char*)buff;
	for(i = 0; i != mk_uint_parts; ++i)
	{
		mk_uint_small_to_buff_le(x->m_data + i, output + i * sizeof(mk_uint_small_t));
	}
}

void mk_uint_from_buff_be(mk_uint_t* out, void const* buff)
{
	int i;
	unsigned char const* input;

	mk_assert(out);
	mk_assert(buff);

	input = (unsigned char const*)buff;
	for(i = 0; i != mk_uint_parts; ++i)
	{
		mk_uint_small_from_buff_be(out->m_data + mk_uint_parts - 1 - i, input + i * sizeof(mk_uint_small_t));
	}
}

void mk_uint_to_buff_be(mk_uint_t const* x, void* buff)
{
	int i;
	unsigned char* output;

	mk_assert(x);
	mk_assert(buff);

	output = (unsigned char*)buff;
	for(i = 0; i != mk_uint_parts; ++i)
	{
		mk_uint_small_to_buff_be(x->m_data + mk_uint_parts - 1 - i, output + i * sizeof(mk_uint_small_t));
	}
}


int mk_uint_is_zero(mk_uint_t const* x)
{
	int i;
	int r;

	mk_assert(x);

	for(i = 0; i != mk_uint_parts - 1; ++i)
	{
		r = mk_uint_small_is_zero(x->m_data + i);
		if(!r)
		{
			return r;
		}
	}
	r = mk_uint_small_is_zero(x->m_data + mk_uint_parts - 1);
	return r;
}

int mk_uint_is_max(mk_uint_t const* x)
{
	int i;
	int r;

	mk_assert(x);

	for(i = 0; i != mk_uint_parts - 1; ++i)
	{
		r = mk_uint_small_is_max(x->m_data + i);
		if(!r)
		{
			return r;
		}
	}
	r = mk_uint_small_is_max(x->m_data + mk_uint_parts - 1);
	return r;
}


void mk_uint_cmplmnt(mk_uint_t* out, mk_uint_t const* x)
{
	int i;

	mk_assert(out);
	mk_assert(x);

	for(i = 0; i != mk_uint_parts; ++i)
	{
		mk_uint_small_cmplmnt(out->m_data + i, x->m_data + i);
	}
}

void mk_uint_or(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_t r;
	int i;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	maybe_initialize(&r);
	
	for(i = 0; i != mk_uint_parts; ++i)
	{
		mk_uint_small_or(r.m_data + i, a->m_data + i, b->m_data + i);
	}

	*out = r;
}

void mk_uint_and(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_t r;
	int i;
	
	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	maybe_initialize(&r);

	for(i = 0; i != mk_uint_parts; ++i)
	{
		mk_uint_small_and(r.m_data + i, a->m_data + i, b->m_data + i);
	}

	*out = r;
}

void mk_uint_xor(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_t r;
	int i;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	maybe_initialize(&r);
	
	for(i = 0; i != mk_uint_parts; ++i)
	{
		mk_uint_small_xor(r.m_data + i, a->m_data + i, b->m_data + i);
	}

	*out = r;
}


void mk_uint_shl(mk_uint_t* out, mk_uint_t const* x, int n)
{
	mk_uint_t r;
	int big_shl;
	int small_shl;
	int i;
	mk_uint_small_t tmp;

	maybe_initialize(&r);

	big_shl = n / mk_uint_small_bits;
	small_shl = n % mk_uint_small_bits;
	for(i = 0; i != big_shl; ++i)
	{
		mk_uint_small_zero(r.m_data + i);
	}
	if(small_shl == 0)
	{
		r.m_data[big_shl] = x->m_data[0];
		for(i = big_shl + 1; i != mk_uint_parts; ++i)
		{
			r.m_data[i] = x->m_data[i - big_shl];
		}
	}
	else
	{
		mk_uint_small_shl(r.m_data + big_shl, x->m_data + 0, small_shl);
		for(i = big_shl + 1; i != mk_uint_parts; ++i)
		{
			mk_uint_small_shl(r.m_data + i, x->m_data + i - big_shl, small_shl);
			mk_uint_small_shr(&tmp, x->m_data + i - big_shl - 1, mk_uint_small_bits - small_shl);
			mk_uint_small_or(r.m_data + i, r.m_data + i, &tmp);
		}
	}

	*out = r;
}

void mk_uint_shr(mk_uint_t* out, mk_uint_t const* x, int n)
{
	mk_uint_t r;
	int big_shr;
	int small_shr;
	int i;
	mk_uint_small_t tmp;

	maybe_initialize(&r);

	big_shr = n / mk_uint_small_bits;
	small_shr = n % mk_uint_small_bits;
	for(i = 0; i != big_shr; ++i)
	{
		mk_uint_small_zero(r.m_data + mk_uint_parts - 1 - i);
	}
	if(small_shr == 0)
	{
		r.m_data[mk_uint_parts - 1 - big_shr] = x->m_data[mk_uint_parts - 1];
		for(i = big_shr + 1; i != mk_uint_parts; ++i)
		{
			r.m_data[mk_uint_parts - 1 - i] = x->m_data[mk_uint_parts - 1 - i + big_shr];
		}
	}
	else
	{
		mk_uint_small_shr(r.m_data + mk_uint_parts - 1 - big_shr, x->m_data + mk_uint_parts - 1, small_shr);
		for(i = big_shr + 1; i != mk_uint_parts; ++i)
		{
			mk_uint_small_shr(r.m_data + mk_uint_parts - 1 - i, x->m_data + mk_uint_parts - 1 - i + big_shr, small_shr);
			mk_uint_small_shl(&tmp, x->m_data + mk_uint_parts - 1 - i + big_shr + 1, mk_uint_small_bits - small_shr);
			mk_uint_small_or(r.m_data + mk_uint_parts - 1 - i, r.m_data + mk_uint_parts - 1 - i, &tmp);
		}
	}

	*out = r;
}

void mk_uint_rotl(mk_uint_t* out, mk_uint_t const* x, int n)
{
	mk_uint_t r;
	mk_uint_t tmp;

	mk_assert(out);
	mk_assert(x);
	mk_assert(n > 0 && n < mk_uint_bits);

	mk_uint_shl(&r, x, n);
	mk_uint_shr(&tmp, x, mk_uint_bits - n);
	mk_uint_or(&r, &r, &tmp);

	*out = r;
}

void mk_uint_rotr(mk_uint_t* out, mk_uint_t const* x, int n)
{
	mk_uint_t r;
	mk_uint_t tmp;

	mk_assert(out);
	mk_assert(x);
	mk_assert(n > 0 && n < mk_uint_bits);

	mk_uint_shr(&r, x, n);
	mk_uint_shl(&tmp, x, mk_uint_bits - n);
	mk_uint_or(&r, &r, &tmp);

	*out = r;
}


int mk_uint_eq(mk_uint_t const* a, mk_uint_t const* b)
{
	int r;
	int i;

	mk_assert(a);
	mk_assert(b);

	for(i = 0; i != mk_uint_parts - 1; ++i)
	{
		r = mk_uint_small_eq(a->m_data + i, b->m_data + i);
		if(!r)
		{
			return r;
		}
	}
	r = mk_uint_small_eq(a->m_data + mk_uint_parts - 1, b->m_data + mk_uint_parts - 1);
	return r;
}

int mk_uint_neq(mk_uint_t const* a, mk_uint_t const* b)
{
	int r;
	int i;

	mk_assert(a);
	mk_assert(b);

	for(i = 0; i != mk_uint_parts - 1; ++i)
	{
		r = mk_uint_small_neq(a->m_data + i, b->m_data + i);
		if(r)
		{
			return r;
		}
	}
	r = mk_uint_small_neq(a->m_data + mk_uint_parts - 1, b->m_data + mk_uint_parts - 1);
	return r;
}

int mk_uint_lt(mk_uint_t const* a, mk_uint_t const* b)
{
	int r;
	int i;
	int lt;
	int gt;

	mk_assert(a);
	mk_assert(b);

	for(i = 0; i != mk_uint_parts - 1; ++i)
	{
		lt = mk_uint_small_lt(a->m_data + mk_uint_parts - 1 - i, b->m_data + mk_uint_parts - 1 - i);
		if(lt)
		{
			return lt;
		}
		gt = mk_uint_small_lt(b->m_data + mk_uint_parts - 1 - i, a->m_data + mk_uint_parts - 1 - i);
		if(gt)
		{
			return !gt;
		}
	}
	r = mk_uint_small_lt(a->m_data + 0, b->m_data + 0);

	return r;
}

int mk_uint_le(mk_uint_t const* a, mk_uint_t const* b)
{
	int r;
	int i;
	int lt;
	int gt;

	mk_assert(a);
	mk_assert(b);

	for(i = 0; i != mk_uint_parts - 1; ++i)
	{
		lt = mk_uint_small_lt(a->m_data + mk_uint_parts - 1 - i, b->m_data + mk_uint_parts - 1 - i);
		if(lt)
		{
			return lt;
		}
		gt = mk_uint_small_lt(b->m_data + mk_uint_parts - 1 - i, a->m_data + mk_uint_parts - 1 - i);
		if(gt)
		{
			return !gt;
		}
	}
	r = mk_uint_small_le(a->m_data + 0, b->m_data + 0);

	return r;
}


void mk_uint_inc(mk_uint_t* x)
{
	int i;
	int o;

	mk_assert(x);

	mk_uint_small_inc(x->m_data + 0);
	for(i = 1; i != mk_uint_parts; ++i)
	{
		o = mk_uint_small_is_zero(x->m_data + i - 1);
		if(o)
		{
			mk_uint_small_inc(x->m_data + i);
		}
		else
		{
			break;
		}
	}
}

void mk_uint_dec(mk_uint_t* x)
{
	int i;
	int u;

	mk_assert(x);

	mk_uint_small_dec(x->m_data + 0);
	for(i = 1; i != mk_uint_parts; ++i)
	{
		u = mk_uint_small_is_max(x->m_data + i - 1);
		if(u)
		{
			mk_uint_small_dec(x->m_data + i);
		}
		else
		{
			break;
		}
	}
}


void mk_uint_add(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_t r;
	int i;
	int overflow;
	mk_uint_small_t one;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	overflow = 0;
	mk_uint_small_add(r.m_data + 0, a->m_data + 0, b->m_data + 0);
	for(i = 1; i != mk_uint_parts; ++i)
	{
		overflow =
			overflow == 0 ?
			(
				mk_uint_small_lt(r.m_data + i - 1, a->m_data + i - 1) ||
				mk_uint_small_lt(r.m_data + i - 1, b->m_data + i - 1)
			) :
			(
				mk_uint_small_le(r.m_data + i - 1, a->m_data + i - 1) ||
				mk_uint_small_le(r.m_data + i - 1, b->m_data + i - 1)
			);
		mk_uint_small_add(r.m_data + i, a->m_data + i, b->m_data + i);
		if(overflow)
		{
			mk_uint_small_one(&one);
			mk_uint_small_add(r.m_data + i, r.m_data + i, &one);
		}
	}

	*out = r;
}

void mk_uint_sub(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b)
{
	mk_uint_t r;
	int i;
	int overflow;
	mk_uint_small_t one;

	mk_assert(out);
	mk_assert(a);
	mk_assert(b);

	overflow = 0;
	mk_uint_small_sub(r.m_data + 0, a->m_data + 0, b->m_data + 0);
	for(i = 1; i != mk_uint_parts; ++i)
	{
		overflow =
			overflow == 0 ?
			mk_uint_small_lt(a->m_data + i - 1, b->m_data + i - 1) :
			mk_uint_small_le(a->m_data + i - 1, b->m_data + i - 1);
		mk_uint_small_sub(r.m_data + i, a->m_data + i, b->m_data + i);
		if(overflow)
		{
			mk_uint_small_one(&one);
			mk_uint_small_sub(r.m_data + i, r.m_data + i, &one);
		}
	}

	*out = r;
}


#undef mk_uint_bits
#undef mk_uint_small_bits
#undef mk_uint_bits_to_words
#undef mk_uint_parts


#pragma warning(pop)
