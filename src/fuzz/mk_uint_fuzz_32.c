#include "mk_uint_fuzz_32.h"

#include "../utils/mk_inline.h"
#include "../exact/mk_uint_32.h"

#include <limits.h> /* CHAR_BIT */
#include <stddef.h> /* size_t NULL */
#include <stdint.h> /* uint32_t */
#include <string.h> /* memcpy memcmp */


#define test(x) do{ if(!(x)){ int volatile* volatile ptr = NULL; *ptr = 0; } }while(0)


static mk_inline void mk_uint_fuzz_32_zero(void)
{
	uint32_t br;
	struct mk_uint32_s mr;

	br = 0;
	mk_uint32_zero(&mr);

	test(memcmp(&br, &mr, 32 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_32_one(void)
{
	uint32_t br;
	struct mk_uint32_s mr;

	br = 1;
	mk_uint32_one(&mr);

	test(memcmp(&br, &mr, 32 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_32_from_int(unsigned char const* data)
{
	unsigned n;
	uint32_t br;
	struct mk_uint32_s mr;
	
	memcpy(&n, data, sizeof(unsigned));

	br = (uint32_t)n;
	mk_uint32_from_int(&mr, n);

	test(memcmp(&br, &mr, 32 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_32_to_int(unsigned char const* data)
{
	uint32_t bx;
	unsigned br;
	struct mk_uint32_s mx;
	unsigned mr;

	memcpy(&bx, data, 32 / CHAR_BIT);
	br = (unsigned)bx;

	memcpy(&mx, data, 32 / CHAR_BIT);
	mr = mk_uint32_to_int(&mx);

	test(memcmp(&br, &mr, sizeof(unsigned)) == 0);
}

static mk_inline void mk_uint_fuzz_32_from_sizet(unsigned char const* data)
{
	size_t n;
	uint32_t br;
	struct mk_uint32_s mr;
	
	memcpy(&n, data, sizeof(size_t));

	br = (uint32_t)n;
	mk_uint32_from_sizet(&mr, n);

	test(memcmp(&br, &mr, 32 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_32_to_sizet(unsigned char const* data)
{
	uint32_t bx;
	size_t br;
	struct mk_uint32_s mx;
	size_t mr;

	memcpy(&bx, data, 32 / CHAR_BIT);
	br = (size_t)bx;

	memcpy(&mx, data, 32 / CHAR_BIT);
	mr = mk_uint32_to_sizet(&mx);

	test(memcmp(&br, &mr, sizeof(size_t)) == 0);
}


static mk_inline void mk_uint_fuzz_32_is_zero(unsigned char const* data)
{
	uint32_t bx;
	int br;
	struct mk_uint32_s mx;
	int mr;

	memcpy(&bx, data, 32 / CHAR_BIT);
	br = bx == 0;

	memcpy(&mx, data, 32 / CHAR_BIT);
	mr = mk_uint32_is_zero(&mx);

	test(memcmp(&br, &mr, sizeof(int)) == 0);
}

static mk_inline void mk_uint_fuzz_32_is_max(unsigned char const* data)
{
	uint32_t bx;
	int br;
	struct mk_uint32_s mx;
	int mr;

	memcpy(&bx, data, 32 / CHAR_BIT);
	br = bx == (uint32_t)((uint32_t)0 - (uint32_t)1);

	memcpy(&mx, data, 32 / CHAR_BIT);
	mr = mk_uint32_is_max(&mx);

	test(memcmp(&br, &mr, sizeof(int)) == 0);
}


static mk_inline void mk_uint_fuzz_32_cmplmnt(unsigned char const* data)
{
	uint32_t bx;
	uint32_t br;
	struct mk_uint32_s mx;
	struct mk_uint32_s mr;

	memcpy(&bx, data, 32 / CHAR_BIT);
	br = ~bx;

	memcpy(&mx, data, 32 / CHAR_BIT);
	mk_uint32_cmplmnt(&mr, &mx);

	test(memcmp(&br, &mr, 32 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_32_or(unsigned char const* data)
{
	uint32_t ba;
	uint32_t bb;
	uint32_t br;
	struct mk_uint32_s ma;
	struct mk_uint32_s mb;
	struct mk_uint32_s mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 32 / CHAR_BIT);
	memcpy(&bb, data + 32 / CHAR_BIT, 32 / CHAR_BIT);
	br = ba | bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 32 / CHAR_BIT);
	memcpy(&mb, data + 32 / CHAR_BIT, 32 / CHAR_BIT);
	mk_uint32_or(&mr, &ma, &mb);

	test(memcmp(&br, &mr, 32 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_32_and(unsigned char const* data)
{
	uint32_t ba;
	uint32_t bb;
	uint32_t br;
	struct mk_uint32_s ma;
	struct mk_uint32_s mb;
	struct mk_uint32_s mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 32 / CHAR_BIT);
	memcpy(&bb, data + 32 / CHAR_BIT, 32 / CHAR_BIT);
	br = ba & bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 32 / CHAR_BIT);
	memcpy(&mb, data + 32 / CHAR_BIT, 32 / CHAR_BIT);
	mk_uint32_and(&mr, &ma, &mb);

	test(memcmp(&br, &mr, 32 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_32_xor(unsigned char const* data)
{
	uint32_t ba;
	uint32_t bb;
	uint32_t br;
	struct mk_uint32_s ma;
	struct mk_uint32_s mb;
	struct mk_uint32_s mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 32 / CHAR_BIT);
	memcpy(&bb, data + 32 / CHAR_BIT, 32 / CHAR_BIT);
	br = ba ^ bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 32 / CHAR_BIT);
	memcpy(&mb, data + 32 / CHAR_BIT, 32 / CHAR_BIT);
	mk_uint32_xor(&mr, &ma, &mb);

	test(memcmp(&br, &mr, 32 / CHAR_BIT) == 0);
}


static mk_inline void mk_uint_fuzz_32_shl(unsigned char const* data)
{
	uint32_t bx;
	unsigned bn;
	uint32_t br;
	struct mk_uint32_s mx;
	unsigned mn;
	struct mk_uint32_s mr;

	memcpy(&bx, data + 0 / CHAR_BIT, 32 / CHAR_BIT);
	memcpy(&bn, data + 32 / CHAR_BIT, sizeof(bn));
	bn = bn % 32;
	br = bx << bn;

	memcpy(&mx, data + 0 / CHAR_BIT, 32 / CHAR_BIT);
	memcpy(&mn, data + 32 / CHAR_BIT, sizeof(mn));
	mn = mn % 32;
	mk_uint32_shl(&mr, &mx, mn);

	test(memcmp(&br, &mr, 32 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_32_shr(unsigned char const* data)
{
	uint32_t bx;
	unsigned bn;
	uint32_t br;
	struct mk_uint32_s mx;
	unsigned mn;
	struct mk_uint32_s mr;

	memcpy(&bx, data + 0 / CHAR_BIT, 32 / CHAR_BIT);
	memcpy(&bn, data + 32 / CHAR_BIT, sizeof(bn));
	bn = bn % 32;
	br = bx >> bn;

	memcpy(&mx, data + 0 / CHAR_BIT, 32 / CHAR_BIT);
	memcpy(&mn, data + 32 / CHAR_BIT, sizeof(mn));
	mn = mn % 32;
	mk_uint32_shr(&mr, &mx, mn);

	test(memcmp(&br, &mr, 32 / CHAR_BIT) == 0);
}


static mk_inline void mk_uint_fuzz_32_eq(unsigned char const* data)
{
	uint32_t ba;
	uint32_t bb;
	int br;
	struct mk_uint32_s ma;
	struct mk_uint32_s mb;
	int mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 32 / CHAR_BIT);
	memcpy(&bb, data + 32 / CHAR_BIT, 32 / CHAR_BIT);
	br = ba == bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 32 / CHAR_BIT);
	memcpy(&mb, data + 32 / CHAR_BIT, 32 / CHAR_BIT);
	mr = mk_uint32_eq(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}

static mk_inline void mk_uint_fuzz_32_neq(unsigned char const* data)
{
	uint32_t ba;
	uint32_t bb;
	int br;
	struct mk_uint32_s ma;
	struct mk_uint32_s mb;
	int mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 32 / CHAR_BIT);
	memcpy(&bb, data + 32 / CHAR_BIT, 32 / CHAR_BIT);
	br = ba != bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 32 / CHAR_BIT);
	memcpy(&mb, data + 32 / CHAR_BIT, 32 / CHAR_BIT);
	mr = mk_uint32_neq(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}

static mk_inline void mk_uint_fuzz_32_lt(unsigned char const* data)
{
	uint32_t ba;
	uint32_t bb;
	int br;
	struct mk_uint32_s ma;
	struct mk_uint32_s mb;
	int mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 32 / CHAR_BIT);
	memcpy(&bb, data + 32 / CHAR_BIT, 32 / CHAR_BIT);
	br = ba < bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 32 / CHAR_BIT);
	memcpy(&mb, data + 32 / CHAR_BIT, 32 / CHAR_BIT);
	mr = mk_uint32_lt(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}

static mk_inline void mk_uint_fuzz_32_le(unsigned char const* data)
{
	uint32_t ba;
	uint32_t bb;
	int br;
	struct mk_uint32_s ma;
	struct mk_uint32_s mb;
	int mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 32 / CHAR_BIT);
	memcpy(&bb, data + 32 / CHAR_BIT, 32 / CHAR_BIT);
	br = ba <= bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 32 / CHAR_BIT);
	memcpy(&mb, data + 32 / CHAR_BIT, 32 / CHAR_BIT);
	mr = mk_uint32_le(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}


static mk_inline void mk_uint_fuzz_32_inc(unsigned char const* data)
{
	uint32_t bx;
	struct mk_uint32_s mx;

	memcpy(&bx, data, 32 / CHAR_BIT);
	++bx;

	memcpy(&mx, data, 32 / CHAR_BIT);
	mk_uint32_inc(&mx);

	test(memcmp(&mx, &bx, 32 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_32_dec(unsigned char const* data)
{
	uint32_t bx;
	struct mk_uint32_s mx;

	memcpy(&bx, data, 32 / CHAR_BIT);
	--bx;

	memcpy(&mx, data, 32 / CHAR_BIT);
	mk_uint32_dec(&mx);

	test(memcmp(&mx, &bx, 32 / CHAR_BIT) == 0);
}


static mk_inline void mk_uint_fuzz_32_add(unsigned char const* data)
{
	uint32_t ba;
	uint32_t bb;
	uint32_t br;
	struct mk_uint32_s ma;
	struct mk_uint32_s mb;
	struct mk_uint32_s mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 32 / CHAR_BIT);
	memcpy(&bb, data + 32 / CHAR_BIT, 32 / CHAR_BIT);
	br = ba + bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 32 / CHAR_BIT);
	memcpy(&mb, data + 32 / CHAR_BIT, 32 / CHAR_BIT);
	mk_uint32_add(&mr, &ma, &mb);

	test(memcmp(&br, &mr, 32 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_32_sub(unsigned char const* data)
{
	uint32_t ba;
	uint32_t bb;
	uint32_t br;
	struct mk_uint32_s ma;
	struct mk_uint32_s mb;
	struct mk_uint32_s mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 32 / CHAR_BIT);
	memcpy(&bb, data + 32 / CHAR_BIT, 32 / CHAR_BIT);
	br = ba - bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 32 / CHAR_BIT);
	memcpy(&mb, data + 32 / CHAR_BIT, 32 / CHAR_BIT);
	mk_uint32_sub(&mr, &ma, &mb);

	test(memcmp(&br, &mr, 32 / CHAR_BIT) == 0);
}


void mk_uint_fuzz_32(unsigned char const* data)
{
	mk_uint_fuzz_32_zero();
	mk_uint_fuzz_32_one();
	mk_uint_fuzz_32_from_int(data);
	mk_uint_fuzz_32_to_int(data);
	mk_uint_fuzz_32_from_sizet(data);
	mk_uint_fuzz_32_to_sizet(data);

	mk_uint_fuzz_32_is_zero(data);
	mk_uint_fuzz_32_is_max(data);

	mk_uint_fuzz_32_cmplmnt(data);
	mk_uint_fuzz_32_or(data);
	mk_uint_fuzz_32_and(data);
	mk_uint_fuzz_32_xor(data);

	mk_uint_fuzz_32_shl(data);
	mk_uint_fuzz_32_shr(data);
	
	mk_uint_fuzz_32_eq(data);
	mk_uint_fuzz_32_neq(data);
	mk_uint_fuzz_32_lt(data);
	mk_uint_fuzz_32_le(data);

	mk_uint_fuzz_32_inc(data);
	mk_uint_fuzz_32_dec(data);

	mk_uint_fuzz_32_add(data);
	mk_uint_fuzz_32_sub(data);
}


#undef test
