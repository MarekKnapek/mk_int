#include "mk_uint_fuzz_16.h"

#include "../utils/mk_inline.h"
#include "../exact/mk_uint_16.h"

#include <limits.h> /* CHAR_BIT */
#include <stddef.h> /* size_t NULL */
#include <stdint.h> /* uint16_t */
#include <string.h> /* memcpy memcmp */


#pragma warning(push)
#pragma warning(disable:4710) /* warning C4710: 'xxx': function not inlined */
#pragma warning(disable:4711) /* warning C4711: function 'xxx' selected for automatic inline expansion */


#define test(x) do{ if(!(x)){ int volatile* volatile ptr = NULL; *ptr = 0; } }while(0)


static mk_inline void mk_uint_fuzz_16_zero(void)
{
	uint16_t br;
	struct mk_uint16_s mr;

	br = 0;
	mk_uint16_zero(&mr);

	test(memcmp(&br, &mr, 16 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_16_one(void)
{
	uint16_t br;
	struct mk_uint16_s mr;

	br = 1;
	mk_uint16_one(&mr);

	test(memcmp(&br, &mr, 16 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_16_from_int(unsigned char const* data)
{
	unsigned n;
	uint16_t br;
	struct mk_uint16_s mr;
	
	memcpy(&n, data, sizeof(unsigned));

	br = (uint16_t)n;
	mk_uint16_from_int(&mr, n);

	test(memcmp(&br, &mr, 16 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_16_to_int(unsigned char const* data)
{
	uint16_t bx;
	unsigned br;
	struct mk_uint16_s mx;
	unsigned mr;

	memcpy(&bx, data, 16 / CHAR_BIT);
	br = (unsigned)bx;

	memcpy(&mx, data, 16 / CHAR_BIT);
	mr = mk_uint16_to_int(&mx);

	test(memcmp(&br, &mr, sizeof(unsigned)) == 0);
}

static mk_inline void mk_uint_fuzz_16_from_sizet(unsigned char const* data)
{
	size_t n;
	uint16_t br;
	struct mk_uint16_s mr;
	
	memcpy(&n, data, sizeof(size_t));

	br = (uint16_t)n;
	mk_uint16_from_sizet(&mr, n);

	test(memcmp(&br, &mr, 16 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_16_to_sizet(unsigned char const* data)
{
	uint16_t bx;
	size_t br;
	struct mk_uint16_s mx;
	size_t mr;

	memcpy(&bx, data, 16 / CHAR_BIT);
	br = (size_t)bx;

	memcpy(&mx, data, 16 / CHAR_BIT);
	mr = mk_uint16_to_sizet(&mx);

	test(memcmp(&br, &mr, sizeof(size_t)) == 0);
}


static mk_inline void mk_uint_fuzz_16_is_zero(unsigned char const* data)
{
	uint16_t bx;
	int br;
	struct mk_uint16_s mx;
	int mr;

	memcpy(&bx, data, 16 / CHAR_BIT);
	br = bx == 0;

	memcpy(&mx, data, 16 / CHAR_BIT);
	mr = mk_uint16_is_zero(&mx);

	test(memcmp(&br, &mr, sizeof(int)) == 0);
}

static mk_inline void mk_uint_fuzz_16_is_max(unsigned char const* data)
{
	uint16_t bx;
	int br;
	struct mk_uint16_s mx;
	int mr;

	memcpy(&bx, data, 16 / CHAR_BIT);
	br = bx == (uint16_t)((uint16_t)0 - (uint16_t)1);

	memcpy(&mx, data, 16 / CHAR_BIT);
	mr = mk_uint16_is_max(&mx);

	test(memcmp(&br, &mr, sizeof(int)) == 0);
}


static mk_inline void mk_uint_fuzz_16_cmplmnt(unsigned char const* data)
{
	uint16_t bx;
	uint16_t br;
	struct mk_uint16_s mx;
	struct mk_uint16_s mr;

	memcpy(&bx, data, 16 / CHAR_BIT);
	br = ~bx;

	memcpy(&mx, data, 16 / CHAR_BIT);
	mk_uint16_cmplmnt(&mr, &mx);

	test(memcmp(&br, &mr, 16 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_16_or(unsigned char const* data)
{
	uint16_t ba;
	uint16_t bb;
	uint16_t br;
	struct mk_uint16_s ma;
	struct mk_uint16_s mb;
	struct mk_uint16_s mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 16 / CHAR_BIT);
	memcpy(&bb, data + 16 / CHAR_BIT, 16 / CHAR_BIT);
	br = ba | bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 16 / CHAR_BIT);
	memcpy(&mb, data + 16 / CHAR_BIT, 16 / CHAR_BIT);
	mk_uint16_or(&mr, &ma, &mb);

	test(memcmp(&br, &mr, 16 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_16_and(unsigned char const* data)
{
	uint16_t ba;
	uint16_t bb;
	uint16_t br;
	struct mk_uint16_s ma;
	struct mk_uint16_s mb;
	struct mk_uint16_s mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 16 / CHAR_BIT);
	memcpy(&bb, data + 16 / CHAR_BIT, 16 / CHAR_BIT);
	br = ba & bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 16 / CHAR_BIT);
	memcpy(&mb, data + 16 / CHAR_BIT, 16 / CHAR_BIT);
	mk_uint16_and(&mr, &ma, &mb);

	test(memcmp(&br, &mr, 16 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_16_xor(unsigned char const* data)
{
	uint16_t ba;
	uint16_t bb;
	uint16_t br;
	struct mk_uint16_s ma;
	struct mk_uint16_s mb;
	struct mk_uint16_s mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 16 / CHAR_BIT);
	memcpy(&bb, data + 16 / CHAR_BIT, 16 / CHAR_BIT);
	br = ba ^ bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 16 / CHAR_BIT);
	memcpy(&mb, data + 16 / CHAR_BIT, 16 / CHAR_BIT);
	mk_uint16_xor(&mr, &ma, &mb);

	test(memcmp(&br, &mr, 16 / CHAR_BIT) == 0);
}


static mk_inline void mk_uint_fuzz_16_shl(unsigned char const* data)
{
	uint16_t bx;
	unsigned bn;
	uint16_t br;
	struct mk_uint16_s mx;
	unsigned mn;
	struct mk_uint16_s mr;

	memcpy(&bx, data + 0 / CHAR_BIT, 16 / CHAR_BIT);
	memcpy(&bn, data + 16 / CHAR_BIT, sizeof(bn));
	bn = bn % 16;
	br = bx << bn;

	memcpy(&mx, data + 0 / CHAR_BIT, 16 / CHAR_BIT);
	memcpy(&mn, data + 16 / CHAR_BIT, sizeof(mn));
	mn = mn % 16;
	mk_uint16_shl(&mr, &mx, mn);

	test(memcmp(&br, &mr, 16 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_16_shr(unsigned char const* data)
{
	uint16_t bx;
	unsigned bn;
	uint16_t br;
	struct mk_uint16_s mx;
	unsigned mn;
	struct mk_uint16_s mr;

	memcpy(&bx, data + 0 / CHAR_BIT, 16 / CHAR_BIT);
	memcpy(&bn, data + 16 / CHAR_BIT, sizeof(bn));
	bn = bn % 16;
	br = bx >> bn;

	memcpy(&mx, data + 0 / CHAR_BIT, 16 / CHAR_BIT);
	memcpy(&mn, data + 16 / CHAR_BIT, sizeof(mn));
	mn = mn % 16;
	mk_uint16_shr(&mr, &mx, mn);

	test(memcmp(&br, &mr, 16 / CHAR_BIT) == 0);
}


static mk_inline void mk_uint_fuzz_16_eq(unsigned char const* data)
{
	uint16_t ba;
	uint16_t bb;
	int br;
	struct mk_uint16_s ma;
	struct mk_uint16_s mb;
	int mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 16 / CHAR_BIT);
	memcpy(&bb, data + 16 / CHAR_BIT, 16 / CHAR_BIT);
	br = ba == bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 16 / CHAR_BIT);
	memcpy(&mb, data + 16 / CHAR_BIT, 16 / CHAR_BIT);
	mr = mk_uint16_eq(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}

static mk_inline void mk_uint_fuzz_16_neq(unsigned char const* data)
{
	uint16_t ba;
	uint16_t bb;
	int br;
	struct mk_uint16_s ma;
	struct mk_uint16_s mb;
	int mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 16 / CHAR_BIT);
	memcpy(&bb, data + 16 / CHAR_BIT, 16 / CHAR_BIT);
	br = ba != bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 16 / CHAR_BIT);
	memcpy(&mb, data + 16 / CHAR_BIT, 16 / CHAR_BIT);
	mr = mk_uint16_neq(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}

static mk_inline void mk_uint_fuzz_16_lt(unsigned char const* data)
{
	uint16_t ba;
	uint16_t bb;
	int br;
	struct mk_uint16_s ma;
	struct mk_uint16_s mb;
	int mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 16 / CHAR_BIT);
	memcpy(&bb, data + 16 / CHAR_BIT, 16 / CHAR_BIT);
	br = ba < bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 16 / CHAR_BIT);
	memcpy(&mb, data + 16 / CHAR_BIT, 16 / CHAR_BIT);
	mr = mk_uint16_lt(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}

static mk_inline void mk_uint_fuzz_16_le(unsigned char const* data)
{
	uint16_t ba;
	uint16_t bb;
	int br;
	struct mk_uint16_s ma;
	struct mk_uint16_s mb;
	int mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 16 / CHAR_BIT);
	memcpy(&bb, data + 16 / CHAR_BIT, 16 / CHAR_BIT);
	br = ba <= bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 16 / CHAR_BIT);
	memcpy(&mb, data + 16 / CHAR_BIT, 16 / CHAR_BIT);
	mr = mk_uint16_le(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}


static mk_inline void mk_uint_fuzz_16_inc(unsigned char const* data)
{
	uint16_t bx;
	struct mk_uint16_s mx;

	memcpy(&bx, data, 16 / CHAR_BIT);
	++bx;

	memcpy(&mx, data, 16 / CHAR_BIT);
	mk_uint16_inc(&mx);

	test(memcmp(&mx, &bx, 16 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_16_dec(unsigned char const* data)
{
	uint16_t bx;
	struct mk_uint16_s mx;

	memcpy(&bx, data, 16 / CHAR_BIT);
	--bx;

	memcpy(&mx, data, 16 / CHAR_BIT);
	mk_uint16_dec(&mx);

	test(memcmp(&mx, &bx, 16 / CHAR_BIT) == 0);
}


static mk_inline void mk_uint_fuzz_16_add(unsigned char const* data)
{
	uint16_t ba;
	uint16_t bb;
	uint16_t br;
	struct mk_uint16_s ma;
	struct mk_uint16_s mb;
	struct mk_uint16_s mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 16 / CHAR_BIT);
	memcpy(&bb, data + 16 / CHAR_BIT, 16 / CHAR_BIT);
	br = ba + bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 16 / CHAR_BIT);
	memcpy(&mb, data + 16 / CHAR_BIT, 16 / CHAR_BIT);
	mk_uint16_add(&mr, &ma, &mb);

	test(memcmp(&br, &mr, 16 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_16_sub(unsigned char const* data)
{
	uint16_t ba;
	uint16_t bb;
	uint16_t br;
	struct mk_uint16_s ma;
	struct mk_uint16_s mb;
	struct mk_uint16_s mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 16 / CHAR_BIT);
	memcpy(&bb, data + 16 / CHAR_BIT, 16 / CHAR_BIT);
	br = ba - bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 16 / CHAR_BIT);
	memcpy(&mb, data + 16 / CHAR_BIT, 16 / CHAR_BIT);
	mk_uint16_sub(&mr, &ma, &mb);

	test(memcmp(&br, &mr, 16 / CHAR_BIT) == 0);
}


void mk_uint_fuzz_16(unsigned char const* data)
{
	mk_uint_fuzz_16_zero();
	mk_uint_fuzz_16_one();
	mk_uint_fuzz_16_from_int(data);
	mk_uint_fuzz_16_to_int(data);
	mk_uint_fuzz_16_from_sizet(data);
	mk_uint_fuzz_16_to_sizet(data);

	mk_uint_fuzz_16_is_zero(data);
	mk_uint_fuzz_16_is_max(data);

	mk_uint_fuzz_16_cmplmnt(data);
	mk_uint_fuzz_16_or(data);
	mk_uint_fuzz_16_and(data);
	mk_uint_fuzz_16_xor(data);

	mk_uint_fuzz_16_shl(data);
	mk_uint_fuzz_16_shr(data);
	
	mk_uint_fuzz_16_eq(data);
	mk_uint_fuzz_16_neq(data);
	mk_uint_fuzz_16_lt(data);
	mk_uint_fuzz_16_le(data);

	mk_uint_fuzz_16_inc(data);
	mk_uint_fuzz_16_dec(data);

	mk_uint_fuzz_16_add(data);
	mk_uint_fuzz_16_sub(data);
}


#undef test


#pragma warning(pop)
