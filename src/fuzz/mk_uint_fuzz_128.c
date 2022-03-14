#include "mk_uint_fuzz_128.h"


#ifdef __SIZEOF_INT128__


#include "../exact/mk_uint_128.h"

#include <limits.h> /* CHAR_BIT */
#include <stddef.h> /* NULL */
#include <string.h> /* memcpy memcmp */


#define uint128_t __uint128_t
#define test(x) do{ if(!(x)){ int volatile* volatile ptr = NULL; *ptr = 0; } }while(0)


static inline void mk_uint_fuzz_128_zero(void)
{
	uint128_t br;
	br = 0;

	struct mk_uint128_s mr;
	mk_uint128_zero(&mr);

	test(memcmp(&br, &mr, 128 / CHAR_BIT) == 0);
}

static inline void mk_uint_fuzz_128_one(void)
{
	uint128_t br;
	br = 1;

	struct mk_uint128_s mr;
	mk_uint128_one(&mr);

	test(memcmp(&br, &mr, 128 / CHAR_BIT) == 0);
}

static inline void mk_uint_fuzz_128_from_int(unsigned char const* data)
{
	unsigned n;
	memcpy(&n, data, sizeof(unsigned));
	
	uint128_t br;
	br = (uint128_t)n;

	struct mk_uint128_s mr;
	mk_uint128_from_int(&mr, n);

	test(memcmp(&br, &mr, 128 / CHAR_BIT) == 0);
}

static inline void mk_uint_fuzz_128_to_int(unsigned char const* data)
{
	uint128_t bx;
	unsigned br;
	memcpy(&bx, data, 128 / CHAR_BIT);
	br = (unsigned)bx;

	struct mk_uint128_s mx;
	unsigned mr;
	memcpy(&mx, data, 128 / CHAR_BIT);
	mr = mk_uint128_to_int(&mx);

	test(memcmp(&br, &mr, sizeof(unsigned)) == 0);
}


static inline void mk_uint_fuzz_128_is_zero(unsigned char const* data)
{
	uint128_t bx;
	int br;
	memcpy(&bx, data, 128 / CHAR_BIT);
	br = bx == 0;

	struct mk_uint128_s mx;
	int mr;
	memcpy(&mx, data, 128 / CHAR_BIT);
	mr = mk_uint128_is_zero(&mx);

	test(memcmp(&br, &mr, sizeof(int)) == 0);
}

static inline void mk_uint_fuzz_128_is_max(unsigned char const* data)
{
	uint128_t bx;
	int br;
	memcpy(&bx, data, 128 / CHAR_BIT);
	br = bx == (uint128_t)((uint128_t)0 - (uint128_t)1);

	struct mk_uint128_s mx;
	int mr;
	memcpy(&mx, data, 128 / CHAR_BIT);
	mr = mk_uint128_is_max(&mx);

	test(memcmp(&br, &mr, sizeof(int)) == 0);
}


static inline void mk_uint_fuzz_128_or(unsigned char const* data)
{
	uint128_t ba;
	uint128_t bb;
	uint128_t br;
	memcpy(&ba, data + 0 / CHAR_BIT, 128 / CHAR_BIT);
	memcpy(&bb, data + 128 / CHAR_BIT, 128 / CHAR_BIT);
	br = ba | bb;

	struct mk_uint128_s ma;
	struct mk_uint128_s mb;
	struct mk_uint128_s mr;
	memcpy(&ma, data + 0 / CHAR_BIT, 128 / CHAR_BIT);
	memcpy(&mb, data + 128 / CHAR_BIT, 128 / CHAR_BIT);
	mk_uint128_or(&mr, &ma, &mb);

	test(memcmp(&br, &mr, 128 / CHAR_BIT) == 0);
}

static inline void mk_uint_fuzz_128_and(unsigned char const* data)
{
	uint128_t ba;
	uint128_t bb;
	uint128_t br;
	memcpy(&ba, data + 0 / CHAR_BIT, 128 / CHAR_BIT);
	memcpy(&bb, data + 128 / CHAR_BIT, 128 / CHAR_BIT);
	br = ba & bb;

	struct mk_uint128_s ma;
	struct mk_uint128_s mb;
	struct mk_uint128_s mr;
	memcpy(&ma, data + 0 / CHAR_BIT, 128 / CHAR_BIT);
	memcpy(&mb, data + 128 / CHAR_BIT, 128 / CHAR_BIT);
	mk_uint128_and(&mr, &ma, &mb);

	test(memcmp(&br, &mr, 128 / CHAR_BIT) == 0);
}

static inline void mk_uint_fuzz_128_xor(unsigned char const* data)
{
	uint128_t ba;
	uint128_t bb;
	uint128_t br;
	memcpy(&ba, data + 0 / CHAR_BIT, 128 / CHAR_BIT);
	memcpy(&bb, data + 128 / CHAR_BIT, 128 / CHAR_BIT);
	br = ba ^ bb;

	struct mk_uint128_s ma;
	struct mk_uint128_s mb;
	struct mk_uint128_s mr;
	memcpy(&ma, data + 0 / CHAR_BIT, 128 / CHAR_BIT);
	memcpy(&mb, data + 128 / CHAR_BIT, 128 / CHAR_BIT);
	mk_uint128_xor(&mr, &ma, &mb);

	test(memcmp(&br, &mr, 128 / CHAR_BIT) == 0);
}


static inline void mk_uint_fuzz_128_shl(unsigned char const* data)
{
	uint128_t bx;
	unsigned bn;
	uint128_t br;
	memcpy(&bx, data + 0 / CHAR_BIT, 128 / CHAR_BIT);
	memcpy(&bn, data + 128 / CHAR_BIT, sizeof(bn));
	bn = bn % 128;
	br = bx << bn;

	struct mk_uint128_s mx;
	unsigned mn;
	struct mk_uint128_s mr;
	memcpy(&mx, data + 0 / CHAR_BIT, 128 / CHAR_BIT);
	memcpy(&mn, data + 128 / CHAR_BIT, sizeof(mn));
	mn = mn % 128;
	mk_uint128_shl(&mr, &mx, mn);

	test(memcmp(&br, &mr, 128 / CHAR_BIT) == 0);
}

static inline void mk_uint_fuzz_128_shr(unsigned char const* data)
{
	uint128_t bx;
	unsigned bn;
	uint128_t br;
	memcpy(&bx, data + 0 / CHAR_BIT, 128 / CHAR_BIT);
	memcpy(&bn, data + 128 / CHAR_BIT, sizeof(bn));
	bn = bn % 128;
	br = bx >> bn;

	struct mk_uint128_s mx;
	unsigned mn;
	struct mk_uint128_s mr;
	memcpy(&mx, data + 0 / CHAR_BIT, 128 / CHAR_BIT);
	memcpy(&mn, data + 128 / CHAR_BIT, sizeof(mn));
	mn = mn % 128;
	mk_uint128_shr(&mr, &mx, mn);

	test(memcmp(&br, &mr, 128 / CHAR_BIT) == 0);
}


static inline void mk_uint_fuzz_128_eq(unsigned char const* data)
{
	uint128_t ba;
	uint128_t bb;
	int br;
	memcpy(&ba, data + 0 / CHAR_BIT, 128 / CHAR_BIT);
	memcpy(&bb, data + 128 / CHAR_BIT, 128 / CHAR_BIT);
	br = ba == bb;

	struct mk_uint128_s ma;
	struct mk_uint128_s mb;
	int mr;
	memcpy(&ma, data + 0 / CHAR_BIT, 128 / CHAR_BIT);
	memcpy(&mb, data + 128 / CHAR_BIT, 128 / CHAR_BIT);
	mr = mk_uint128_eq(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}

static inline void mk_uint_fuzz_128_neq(unsigned char const* data)
{
	uint128_t ba;
	uint128_t bb;
	int br;
	memcpy(&ba, data + 0 / CHAR_BIT, 128 / CHAR_BIT);
	memcpy(&bb, data + 128 / CHAR_BIT, 128 / CHAR_BIT);
	br = ba != bb;

	struct mk_uint128_s ma;
	struct mk_uint128_s mb;
	int mr;
	memcpy(&ma, data + 0 / CHAR_BIT, 128 / CHAR_BIT);
	memcpy(&mb, data + 128 / CHAR_BIT, 128 / CHAR_BIT);
	mr = mk_uint128_neq(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}

static inline void mk_uint_fuzz_128_lt(unsigned char const* data)
{
	uint128_t ba;
	uint128_t bb;
	int br;
	memcpy(&ba, data + 0 / CHAR_BIT, 128 / CHAR_BIT);
	memcpy(&bb, data + 128 / CHAR_BIT, 128 / CHAR_BIT);
	br = ba < bb;

	struct mk_uint128_s ma;
	struct mk_uint128_s mb;
	int mr;
	memcpy(&ma, data + 0 / CHAR_BIT, 128 / CHAR_BIT);
	memcpy(&mb, data + 128 / CHAR_BIT, 128 / CHAR_BIT);
	mr = mk_uint128_lt(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}

static inline void mk_uint_fuzz_128_le(unsigned char const* data)
{
	uint128_t ba;
	uint128_t bb;
	int br;
	memcpy(&ba, data + 0 / CHAR_BIT, 128 / CHAR_BIT);
	memcpy(&bb, data + 128 / CHAR_BIT, 128 / CHAR_BIT);
	br = ba <= bb;

	struct mk_uint128_s ma;
	struct mk_uint128_s mb;
	int mr;
	memcpy(&ma, data + 0 / CHAR_BIT, 128 / CHAR_BIT);
	memcpy(&mb, data + 128 / CHAR_BIT, 128 / CHAR_BIT);
	mr = mk_uint128_le(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}


static inline void mk_uint_fuzz_128_inc(unsigned char const* data)
{
	uint128_t bx;
	memcpy(&bx, data, 128 / CHAR_BIT);
	++bx;

	struct mk_uint128_s mx;
	memcpy(&mx, data, 128 / CHAR_BIT);
	mk_uint128_inc(&mx);

	test(memcmp(&mx, &bx, 128 / CHAR_BIT) == 0);
}

static inline void mk_uint_fuzz_128_dec(unsigned char const* data)
{
	uint128_t bx;
	memcpy(&bx, data, 128 / CHAR_BIT);
	--bx;

	struct mk_uint128_s mx;
	memcpy(&mx, data, 128 / CHAR_BIT);
	mk_uint128_dec(&mx);

	test(memcmp(&mx, &bx, 128 / CHAR_BIT) == 0);
}


static inline void mk_uint_fuzz_128_add(unsigned char const* data)
{
	uint128_t ba;
	uint128_t bb;
	uint128_t br;
	memcpy(&ba, data + 0 / CHAR_BIT, 128 / CHAR_BIT);
	memcpy(&bb, data + 128 / CHAR_BIT, 128 / CHAR_BIT);
	br = ba + bb;

	struct mk_uint128_s ma;
	struct mk_uint128_s mb;
	struct mk_uint128_s mr;
	memcpy(&ma, data + 0 / CHAR_BIT, 128 / CHAR_BIT);
	memcpy(&mb, data + 128 / CHAR_BIT, 128 / CHAR_BIT);
	mk_uint128_add(&mr, &ma, &mb);

	test(memcmp(&br, &mr, 128 / CHAR_BIT) == 0);
}

static inline void mk_uint_fuzz_128_sub(unsigned char const* data)
{
	uint128_t ba;
	uint128_t bb;
	uint128_t br;
	memcpy(&ba, data + 0 / CHAR_BIT, 128 / CHAR_BIT);
	memcpy(&bb, data + 128 / CHAR_BIT, 128 / CHAR_BIT);
	br = ba - bb;

	struct mk_uint128_s ma;
	struct mk_uint128_s mb;
	struct mk_uint128_s mr;
	memcpy(&ma, data + 0 / CHAR_BIT, 128 / CHAR_BIT);
	memcpy(&mb, data + 128 / CHAR_BIT, 128 / CHAR_BIT);
	mk_uint128_sub(&mr, &ma, &mb);

	test(memcmp(&br, &mr, 128 / CHAR_BIT) == 0);
}


void mk_uint_fuzz_128(unsigned char const* data)
{
	mk_uint_fuzz_128_zero();
	mk_uint_fuzz_128_one();
	mk_uint_fuzz_128_from_int(data);
	mk_uint_fuzz_128_to_int(data);

	mk_uint_fuzz_128_is_zero(data);
	mk_uint_fuzz_128_is_max(data);

	mk_uint_fuzz_128_or(data);
	mk_uint_fuzz_128_and(data);
	mk_uint_fuzz_128_xor(data);

	mk_uint_fuzz_128_shl(data);
	mk_uint_fuzz_128_shr(data);
	
	mk_uint_fuzz_128_eq(data);
	mk_uint_fuzz_128_neq(data);
	mk_uint_fuzz_128_lt(data);
	mk_uint_fuzz_128_le(data);

	mk_uint_fuzz_128_inc(data);
	mk_uint_fuzz_128_dec(data);

	mk_uint_fuzz_128_add(data);
	mk_uint_fuzz_128_sub(data);
}


#undef test


#else


void mk_uint_fuzz_128(unsigned char const* data)
{
	(void)data;
}


#endif
