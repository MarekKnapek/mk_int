#include "mk_uint_fuzz_8.h"


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4464) /* warning C4464: relative include path contains '..' */
#endif


#include "../utils/mk_inline.h"
#include "../exact/mk_uint_8.h"

#include <limits.h> /* CHAR_BIT */
#include <stddef.h> /* size_t NULL */
#include <stdint.h> /* uint8_t */
#include <string.h> /* memcpy memcmp */


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4710) /* warning C4710: 'xxx': function not inlined */
#pragma warning(disable:4711) /* warning C4711: function 'xxx' selected for automatic inline expansion */
#endif


#define test(x) do{ if(!(x)){ int volatile* volatile ptr = NULL; *ptr = 0; } }while(0)


static mk_inline void mk_uint_fuzz_8_zero(void)
{
	uint8_t br;
	struct mk_uint8_s mr;

	br = 0;
	mk_uint8_zero(&mr);

	test(memcmp(&br, &mr, 8 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_8_one(void)
{
	uint8_t br;
	struct mk_uint8_s mr;

	br = 1;
	mk_uint8_one(&mr);

	test(memcmp(&br, &mr, 8 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_8_from_int(unsigned char const* data)
{
	unsigned n;
	uint8_t br;
	struct mk_uint8_s mr;
	
	memcpy(&n, data, sizeof(unsigned));

	br = (uint8_t)n;
	mk_uint8_from_int(&mr, n);

	test(memcmp(&br, &mr, 8 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_8_to_int(unsigned char const* data)
{
	uint8_t bx;
	unsigned br;
	struct mk_uint8_s mx;
	unsigned mr;

	memcpy(&bx, data, 8 / CHAR_BIT);
	br = (unsigned)bx;

	memcpy(&mx, data, 8 / CHAR_BIT);
	mr = mk_uint8_to_int(&mx);

	test(memcmp(&br, &mr, sizeof(unsigned)) == 0);
}

static mk_inline void mk_uint_fuzz_8_from_long(unsigned char const* data)
{
	unsigned long n;
	uint8_t br;
	struct mk_uint8_s mr;
	
	memcpy(&n, data, sizeof(unsigned long));

	br = (uint8_t)n;
	mk_uint8_from_long(&mr, n);

	test(memcmp(&br, &mr, 8 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_8_to_long(unsigned char const* data)
{
	uint8_t bx;
	unsigned long br;
	struct mk_uint8_s mx;
	unsigned long mr;

	memcpy(&bx, data, 8 / CHAR_BIT);
	br = (unsigned long)bx;

	memcpy(&mx, data, 8 / CHAR_BIT);
	mr = mk_uint8_to_long(&mx);

	test(memcmp(&br, &mr, sizeof(unsigned long)) == 0);
}

static mk_inline void mk_uint_fuzz_8_from_sizet(unsigned char const* data)
{
	size_t n;
	uint8_t br;
	struct mk_uint8_s mr;
	
	memcpy(&n, data, sizeof(size_t));

	br = (uint8_t)n;
	mk_uint8_from_sizet(&mr, n);

	test(memcmp(&br, &mr, 8 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_8_to_sizet(unsigned char const* data)
{
	uint8_t bx;
	size_t br;
	struct mk_uint8_s mx;
	size_t mr;

	memcpy(&bx, data, 8 / CHAR_BIT);
	br = (size_t)bx;

	memcpy(&mx, data, 8 / CHAR_BIT);
	mr = mk_uint8_to_sizet(&mx);

	test(memcmp(&br, &mr, sizeof(size_t)) == 0);
}


static mk_inline void mk_uint_fuzz_8_is_zero(unsigned char const* data)
{
	uint8_t bx;
	int br;
	struct mk_uint8_s mx;
	int mr;

	memcpy(&bx, data, 8 / CHAR_BIT);
	br = bx == 0;

	memcpy(&mx, data, 8 / CHAR_BIT);
	mr = mk_uint8_is_zero(&mx);

	test(memcmp(&br, &mr, sizeof(int)) == 0);
}

static mk_inline void mk_uint_fuzz_8_is_max(unsigned char const* data)
{
	uint8_t bx;
	int br;
	struct mk_uint8_s mx;
	int mr;

	memcpy(&bx, data, 8 / CHAR_BIT);
	br = bx == (uint8_t)((uint8_t)0 - (uint8_t)1);

	memcpy(&mx, data, 8 / CHAR_BIT);
	mr = mk_uint8_is_max(&mx);

	test(memcmp(&br, &mr, sizeof(int)) == 0);
}


static mk_inline void mk_uint_fuzz_8_cmplmnt(unsigned char const* data)
{
	uint8_t bx;
	uint8_t br;
	struct mk_uint8_s mx;
	struct mk_uint8_s mr;

	memcpy(&bx, data, 8 / CHAR_BIT);
	br = ~bx;

	memcpy(&mx, data, 8 / CHAR_BIT);
	mk_uint8_cmplmnt(&mr, &mx);

	test(memcmp(&br, &mr, 8 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_8_or(unsigned char const* data)
{
	uint8_t ba;
	uint8_t bb;
	uint8_t br;
	struct mk_uint8_s ma;
	struct mk_uint8_s mb;
	struct mk_uint8_s mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&bb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	br = ba | bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&mb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	mk_uint8_or(&mr, &ma, &mb);

	test(memcmp(&br, &mr, 8 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_8_and(unsigned char const* data)
{
	uint8_t ba;
	uint8_t bb;
	uint8_t br;
	struct mk_uint8_s ma;
	struct mk_uint8_s mb;
	struct mk_uint8_s mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&bb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	br = ba & bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&mb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	mk_uint8_and(&mr, &ma, &mb);

	test(memcmp(&br, &mr, 8 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_8_xor(unsigned char const* data)
{
	uint8_t ba;
	uint8_t bb;
	uint8_t br;
	struct mk_uint8_s ma;
	struct mk_uint8_s mb;
	struct mk_uint8_s mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&bb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	br = ba ^ bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&mb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	mk_uint8_xor(&mr, &ma, &mb);

	test(memcmp(&br, &mr, 8 / CHAR_BIT) == 0);
}


static mk_inline void mk_uint_fuzz_8_shl(unsigned char const* data)
{
	uint8_t bx;
	unsigned bn;
	uint8_t br;
	struct mk_uint8_s mx;
	unsigned mn;
	struct mk_uint8_s mr;

	memcpy(&bx, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&bn, data + 8 / CHAR_BIT, sizeof(bn));
	bn = bn % 8;
	br = bx << bn;

	memcpy(&mx, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&mn, data + 8 / CHAR_BIT, sizeof(mn));
	mn = mn % 8;
	mk_uint8_shl(&mr, &mx, mn);

	test(memcmp(&br, &mr, 8 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_8_shr(unsigned char const* data)
{
	uint8_t bx;
	unsigned bn;
	uint8_t br;
	struct mk_uint8_s mx;
	unsigned mn;
	struct mk_uint8_s mr;

	memcpy(&bx, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&bn, data + 8 / CHAR_BIT, sizeof(bn));
	bn = bn % 8;
	br = bx >> bn;

	memcpy(&mx, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&mn, data + 8 / CHAR_BIT, sizeof(mn));
	mn = mn % 8;
	mk_uint8_shr(&mr, &mx, mn);

	test(memcmp(&br, &mr, 8 / CHAR_BIT) == 0);
}


static mk_inline void mk_uint_fuzz_8_eq(unsigned char const* data)
{
	uint8_t ba;
	uint8_t bb;
	int br;
	struct mk_uint8_s ma;
	struct mk_uint8_s mb;
	int mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&bb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	br = ba == bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&mb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	mr = mk_uint8_eq(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}

static mk_inline void mk_uint_fuzz_8_neq(unsigned char const* data)
{
	uint8_t ba;
	uint8_t bb;
	int br;
	struct mk_uint8_s ma;
	struct mk_uint8_s mb;
	int mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&bb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	br = ba != bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&mb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	mr = mk_uint8_neq(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}

static mk_inline void mk_uint_fuzz_8_lt(unsigned char const* data)
{
	uint8_t ba;
	uint8_t bb;
	int br;
	struct mk_uint8_s ma;
	struct mk_uint8_s mb;
	int mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&bb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	br = ba < bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&mb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	mr = mk_uint8_lt(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}

static mk_inline void mk_uint_fuzz_8_le(unsigned char const* data)
{
	uint8_t ba;
	uint8_t bb;
	int br;
	struct mk_uint8_s ma;
	struct mk_uint8_s mb;
	int mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&bb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	br = ba <= bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&mb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	mr = mk_uint8_le(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}

static mk_inline void mk_uint_fuzz_8_gt(unsigned char const* data)
{
	uint8_t ba;
	uint8_t bb;
	int br;
	struct mk_uint8_s ma;
	struct mk_uint8_s mb;
	int mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&bb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	br = ba > bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&mb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	mr = mk_uint8_gt(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}

static mk_inline void mk_uint_fuzz_8_ge(unsigned char const* data)
{
	uint8_t ba;
	uint8_t bb;
	int br;
	struct mk_uint8_s ma;
	struct mk_uint8_s mb;
	int mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&bb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	br = ba >= bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&mb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	mr = mk_uint8_ge(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}


static mk_inline void mk_uint_fuzz_8_inc(unsigned char const* data)
{
	uint8_t bx;
	struct mk_uint8_s mx;

	memcpy(&bx, data, 8 / CHAR_BIT);
	++bx;

	memcpy(&mx, data, 8 / CHAR_BIT);
	mk_uint8_inc(&mx);

	test(memcmp(&mx, &bx, 8 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_8_dec(unsigned char const* data)
{
	uint8_t bx;
	struct mk_uint8_s mx;

	memcpy(&bx, data, 8 / CHAR_BIT);
	--bx;

	memcpy(&mx, data, 8 / CHAR_BIT);
	mk_uint8_dec(&mx);

	test(memcmp(&mx, &bx, 8 / CHAR_BIT) == 0);
}


static mk_inline void mk_uint_fuzz_8_add(unsigned char const* data)
{
	uint8_t ba;
	uint8_t bb;
	uint8_t br;
	struct mk_uint8_s ma;
	struct mk_uint8_s mb;
	struct mk_uint8_s mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&bb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	br = ba + bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&mb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	mk_uint8_add(&mr, &ma, &mb);

	test(memcmp(&br, &mr, 8 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_8_sub(unsigned char const* data)
{
	uint8_t ba;
	uint8_t bb;
	uint8_t br;
	struct mk_uint8_s ma;
	struct mk_uint8_s mb;
	struct mk_uint8_s mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&bb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	br = ba - bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&mb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	mk_uint8_sub(&mr, &ma, &mb);

	test(memcmp(&br, &mr, 8 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_8_mul(unsigned char const* data)
{
	uint8_t ba;
	uint8_t bb;
	uint8_t br;
	struct mk_uint8_s ma;
	struct mk_uint8_s mb;
	struct mk_uint8_s mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&bb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	br = ba * bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&mb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	mk_uint8_mul(&mr, &ma, &mb);

	test(memcmp(&br, &mr, 8 / CHAR_BIT) == 0);
}


void mk_uint_fuzz_8(unsigned char const* data)
{
	mk_uint_fuzz_8_zero();
	mk_uint_fuzz_8_one();
	mk_uint_fuzz_8_from_int(data);
	mk_uint_fuzz_8_to_int(data);
	mk_uint_fuzz_8_from_long(data);
	mk_uint_fuzz_8_to_long(data);
	mk_uint_fuzz_8_from_sizet(data);
	mk_uint_fuzz_8_to_sizet(data);

	mk_uint_fuzz_8_is_zero(data);
	mk_uint_fuzz_8_is_max(data);

	mk_uint_fuzz_8_cmplmnt(data);
	mk_uint_fuzz_8_or(data);
	mk_uint_fuzz_8_and(data);
	mk_uint_fuzz_8_xor(data);

	mk_uint_fuzz_8_shl(data);
	mk_uint_fuzz_8_shr(data);
	
	mk_uint_fuzz_8_eq(data);
	mk_uint_fuzz_8_neq(data);
	mk_uint_fuzz_8_lt(data);
	mk_uint_fuzz_8_le(data);
	mk_uint_fuzz_8_gt(data);
	mk_uint_fuzz_8_ge(data);

	mk_uint_fuzz_8_inc(data);
	mk_uint_fuzz_8_dec(data);

	mk_uint_fuzz_8_add(data);
	mk_uint_fuzz_8_sub(data);
	mk_uint_fuzz_8_mul(data);
}


#undef test


#if defined(_MSC_VER)
#pragma warning(pop)
#endif


#if defined(_MSC_VER)
#pragma warning(pop)
#endif
