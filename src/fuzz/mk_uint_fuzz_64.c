#include "mk_uint_fuzz_64.h"


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4464) /* warning C4464: relative include path contains '..' */
#endif


#include "../utils/mk_inline.h"
#include "../exact/mk_uint_64.h"

#include <limits.h> /* CHAR_BIT */
#include <stddef.h> /* size_t NULL */
#include <stdint.h> /* uint64_t */
#include <string.h> /* memcpy memcmp */


#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4710) /* warning C4710: 'xxx': function not inlined */
#pragma warning(disable:4711) /* warning C4711: function 'xxx' selected for automatic inline expansion */
#endif


#define test(x) do{ if(!(x)){ int volatile* volatile ptr = NULL; *ptr = 0; } }while(0)


static mk_inline void mk_uint_fuzz_64_zero(void)
{
	uint64_t br;
	struct mk_uint64_s mr;

	br = 0;
	mk_uint64_zero(&mr);

	test(memcmp(&br, &mr, 64 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_64_one(void)
{
	uint64_t br;
	struct mk_uint64_s mr;

	br = 1;
	mk_uint64_one(&mr);

	test(memcmp(&br, &mr, 64 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_64_from_int(unsigned char const* data)
{
	unsigned n;
	uint64_t br;
	struct mk_uint64_s mr;
	
	memcpy(&n, data, sizeof(unsigned));

	br = (uint64_t)n;
	mk_uint64_from_int(&mr, n);

	test(memcmp(&br, &mr, 64 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_64_to_int(unsigned char const* data)
{
	uint64_t bx;
	unsigned br;
	struct mk_uint64_s mx;
	unsigned mr;

	memcpy(&bx, data, 64 / CHAR_BIT);
	br = (unsigned)bx;

	memcpy(&mx, data, 64 / CHAR_BIT);
	mr = mk_uint64_to_int(&mx);

	test(memcmp(&br, &mr, sizeof(unsigned)) == 0);
}

static mk_inline void mk_uint_fuzz_64_from_sizet(unsigned char const* data)
{
	size_t n;
	uint64_t br;
	struct mk_uint64_s mr;
	
	memcpy(&n, data, sizeof(size_t));

	br = (uint64_t)n;
	mk_uint64_from_sizet(&mr, n);

	test(memcmp(&br, &mr, 64 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_64_to_sizet(unsigned char const* data)
{
	uint64_t bx;
	size_t br;
	struct mk_uint64_s mx;
	size_t mr;

	memcpy(&bx, data, 64 / CHAR_BIT);
	br = (size_t)bx;

	memcpy(&mx, data, 64 / CHAR_BIT);
	mr = mk_uint64_to_sizet(&mx);

	test(memcmp(&br, &mr, sizeof(size_t)) == 0);
}


static mk_inline void mk_uint_fuzz_64_is_zero(unsigned char const* data)
{
	uint64_t bx;
	int br;
	struct mk_uint64_s mx;
	int mr;

	memcpy(&bx, data, 64 / CHAR_BIT);
	br = bx == 0;

	memcpy(&mx, data, 64 / CHAR_BIT);
	mr = mk_uint64_is_zero(&mx);

	test(memcmp(&br, &mr, sizeof(int)) == 0);
}

static mk_inline void mk_uint_fuzz_64_is_max(unsigned char const* data)
{
	uint64_t bx;
	int br;
	struct mk_uint64_s mx;
	int mr;

	memcpy(&bx, data, 64 / CHAR_BIT);
	br = bx == (uint64_t)((uint64_t)0 - (uint64_t)1);

	memcpy(&mx, data, 64 / CHAR_BIT);
	mr = mk_uint64_is_max(&mx);

	test(memcmp(&br, &mr, sizeof(int)) == 0);
}


static mk_inline void mk_uint_fuzz_64_cmplmnt(unsigned char const* data)
{
	uint64_t bx;
	uint64_t br;
	struct mk_uint64_s mx;
	struct mk_uint64_s mr;

	memcpy(&bx, data, 64 / CHAR_BIT);
	br = ~bx;

	memcpy(&mx, data, 64 / CHAR_BIT);
	mk_uint64_cmplmnt(&mr, &mx);

	test(memcmp(&br, &mr, 64 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_64_or(unsigned char const* data)
{
	uint64_t ba;
	uint64_t bb;
	uint64_t br;
	struct mk_uint64_s ma;
	struct mk_uint64_s mb;
	struct mk_uint64_s mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 64 / CHAR_BIT);
	memcpy(&bb, data + 64 / CHAR_BIT, 64 / CHAR_BIT);
	br = ba | bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 64 / CHAR_BIT);
	memcpy(&mb, data + 64 / CHAR_BIT, 64 / CHAR_BIT);
	mk_uint64_or(&mr, &ma, &mb);

	test(memcmp(&br, &mr, 64 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_64_and(unsigned char const* data)
{
	uint64_t ba;
	uint64_t bb;
	uint64_t br;
	struct mk_uint64_s ma;
	struct mk_uint64_s mb;
	struct mk_uint64_s mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 64 / CHAR_BIT);
	memcpy(&bb, data + 64 / CHAR_BIT, 64 / CHAR_BIT);
	br = ba & bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 64 / CHAR_BIT);
	memcpy(&mb, data + 64 / CHAR_BIT, 64 / CHAR_BIT);
	mk_uint64_and(&mr, &ma, &mb);

	test(memcmp(&br, &mr, 64 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_64_xor(unsigned char const* data)
{
	uint64_t ba;
	uint64_t bb;
	uint64_t br;
	struct mk_uint64_s ma;
	struct mk_uint64_s mb;
	struct mk_uint64_s mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 64 / CHAR_BIT);
	memcpy(&bb, data + 64 / CHAR_BIT, 64 / CHAR_BIT);
	br = ba ^ bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 64 / CHAR_BIT);
	memcpy(&mb, data + 64 / CHAR_BIT, 64 / CHAR_BIT);
	mk_uint64_xor(&mr, &ma, &mb);

	test(memcmp(&br, &mr, 64 / CHAR_BIT) == 0);
}


static mk_inline void mk_uint_fuzz_64_shl(unsigned char const* data)
{
	uint64_t bx;
	unsigned bn;
	uint64_t br;
	struct mk_uint64_s mx;
	unsigned mn;
	struct mk_uint64_s mr;

	memcpy(&bx, data + 0 / CHAR_BIT, 64 / CHAR_BIT);
	memcpy(&bn, data + 64 / CHAR_BIT, sizeof(bn));
	bn = bn % 64;
	br = bx << bn;

	memcpy(&mx, data + 0 / CHAR_BIT, 64 / CHAR_BIT);
	memcpy(&mn, data + 64 / CHAR_BIT, sizeof(mn));
	mn = mn % 64;
	mk_uint64_shl(&mr, &mx, mn);

	test(memcmp(&br, &mr, 64 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_64_shr(unsigned char const* data)
{
	uint64_t bx;
	unsigned bn;
	uint64_t br;
	struct mk_uint64_s mx;
	unsigned mn;
	struct mk_uint64_s mr;

	memcpy(&bx, data + 0 / CHAR_BIT, 64 / CHAR_BIT);
	memcpy(&bn, data + 64 / CHAR_BIT, sizeof(bn));
	bn = bn % 64;
	br = bx >> bn;

	memcpy(&mx, data + 0 / CHAR_BIT, 64 / CHAR_BIT);
	memcpy(&mn, data + 64 / CHAR_BIT, sizeof(mn));
	mn = mn % 64;
	mk_uint64_shr(&mr, &mx, mn);

	test(memcmp(&br, &mr, 64 / CHAR_BIT) == 0);
}


static mk_inline void mk_uint_fuzz_64_eq(unsigned char const* data)
{
	uint64_t ba;
	uint64_t bb;
	int br;
	struct mk_uint64_s ma;
	struct mk_uint64_s mb;
	int mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 64 / CHAR_BIT);
	memcpy(&bb, data + 64 / CHAR_BIT, 64 / CHAR_BIT);
	br = ba == bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 64 / CHAR_BIT);
	memcpy(&mb, data + 64 / CHAR_BIT, 64 / CHAR_BIT);
	mr = mk_uint64_eq(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}

static mk_inline void mk_uint_fuzz_64_neq(unsigned char const* data)
{
	uint64_t ba;
	uint64_t bb;
	int br;
	struct mk_uint64_s ma;
	struct mk_uint64_s mb;
	int mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 64 / CHAR_BIT);
	memcpy(&bb, data + 64 / CHAR_BIT, 64 / CHAR_BIT);
	br = ba != bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 64 / CHAR_BIT);
	memcpy(&mb, data + 64 / CHAR_BIT, 64 / CHAR_BIT);
	mr = mk_uint64_neq(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}

static mk_inline void mk_uint_fuzz_64_lt(unsigned char const* data)
{
	uint64_t ba;
	uint64_t bb;
	int br;
	struct mk_uint64_s ma;
	struct mk_uint64_s mb;
	int mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 64 / CHAR_BIT);
	memcpy(&bb, data + 64 / CHAR_BIT, 64 / CHAR_BIT);
	br = ba < bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 64 / CHAR_BIT);
	memcpy(&mb, data + 64 / CHAR_BIT, 64 / CHAR_BIT);
	mr = mk_uint64_lt(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}

static mk_inline void mk_uint_fuzz_64_le(unsigned char const* data)
{
	uint64_t ba;
	uint64_t bb;
	int br;
	struct mk_uint64_s ma;
	struct mk_uint64_s mb;
	int mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 64 / CHAR_BIT);
	memcpy(&bb, data + 64 / CHAR_BIT, 64 / CHAR_BIT);
	br = ba <= bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 64 / CHAR_BIT);
	memcpy(&mb, data + 64 / CHAR_BIT, 64 / CHAR_BIT);
	mr = mk_uint64_le(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}


static mk_inline void mk_uint_fuzz_64_inc(unsigned char const* data)
{
	uint64_t bx;
	struct mk_uint64_s mx;

	memcpy(&bx, data, 64 / CHAR_BIT);
	++bx;

	memcpy(&mx, data, 64 / CHAR_BIT);
	mk_uint64_inc(&mx);

	test(memcmp(&mx, &bx, 64 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_64_dec(unsigned char const* data)
{
	uint64_t bx;
	struct mk_uint64_s mx;

	memcpy(&bx, data, 64 / CHAR_BIT);
	--bx;

	memcpy(&mx, data, 64 / CHAR_BIT);
	mk_uint64_dec(&mx);

	test(memcmp(&mx, &bx, 64 / CHAR_BIT) == 0);
}


static mk_inline void mk_uint_fuzz_64_add(unsigned char const* data)
{
	uint64_t ba;
	uint64_t bb;
	uint64_t br;
	struct mk_uint64_s ma;
	struct mk_uint64_s mb;
	struct mk_uint64_s mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 64 / CHAR_BIT);
	memcpy(&bb, data + 64 / CHAR_BIT, 64 / CHAR_BIT);
	br = ba + bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 64 / CHAR_BIT);
	memcpy(&mb, data + 64 / CHAR_BIT, 64 / CHAR_BIT);
	mk_uint64_add(&mr, &ma, &mb);

	test(memcmp(&br, &mr, 64 / CHAR_BIT) == 0);
}

static mk_inline void mk_uint_fuzz_64_sub(unsigned char const* data)
{
	uint64_t ba;
	uint64_t bb;
	uint64_t br;
	struct mk_uint64_s ma;
	struct mk_uint64_s mb;
	struct mk_uint64_s mr;

	memcpy(&ba, data + 0 / CHAR_BIT, 64 / CHAR_BIT);
	memcpy(&bb, data + 64 / CHAR_BIT, 64 / CHAR_BIT);
	br = ba - bb;

	memcpy(&ma, data + 0 / CHAR_BIT, 64 / CHAR_BIT);
	memcpy(&mb, data + 64 / CHAR_BIT, 64 / CHAR_BIT);
	mk_uint64_sub(&mr, &ma, &mb);

	test(memcmp(&br, &mr, 64 / CHAR_BIT) == 0);
}


void mk_uint_fuzz_64(unsigned char const* data)
{
	mk_uint_fuzz_64_zero();
	mk_uint_fuzz_64_one();
	mk_uint_fuzz_64_from_int(data);
	mk_uint_fuzz_64_to_int(data);
	mk_uint_fuzz_64_from_sizet(data);
	mk_uint_fuzz_64_to_sizet(data);

	mk_uint_fuzz_64_is_zero(data);
	mk_uint_fuzz_64_is_max(data);

	mk_uint_fuzz_64_cmplmnt(data);
	mk_uint_fuzz_64_or(data);
	mk_uint_fuzz_64_and(data);
	mk_uint_fuzz_64_xor(data);

	mk_uint_fuzz_64_shl(data);
	mk_uint_fuzz_64_shr(data);
	
	mk_uint_fuzz_64_eq(data);
	mk_uint_fuzz_64_neq(data);
	mk_uint_fuzz_64_lt(data);
	mk_uint_fuzz_64_le(data);

	mk_uint_fuzz_64_inc(data);
	mk_uint_fuzz_64_dec(data);

	mk_uint_fuzz_64_add(data);
	mk_uint_fuzz_64_sub(data);
}


#undef test


#if defined(_MSC_VER)
#pragma warning(pop)
#endif


#if defined(_MSC_VER)
#pragma warning(pop)
#endif
