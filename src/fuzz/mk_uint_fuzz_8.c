#include "mk_uint_fuzz_8.h"

#include "../exact/mk_uint_8.h"

#include <limits.h> /* CHAR_BIT */
#include <stddef.h> /* NULL */
#include <stdint.h> /* uint8_t */
#include <string.h> /* memcpy memcmp */


#define test(x) do{ if(!(x)){ int volatile* volatile ptr = NULL; *ptr = 0; } }while(0)


static inline void mk_uint_fuzz_8_zero(void)
{
	uint8_t br;
	br = 0;

	struct mk_uint8_s mr;
	mk_uint8_zero(&mr);

	test(memcmp(&br, &mr, 8 / CHAR_BIT) == 0);
}

static inline void mk_uint_fuzz_8_one(void)
{
	uint8_t br;
	br = 1;

	struct mk_uint8_s mr;
	mk_uint8_one(&mr);

	test(memcmp(&br, &mr, 8 / CHAR_BIT) == 0);
}

static inline void mk_uint_fuzz_8_from_int(unsigned char const* data)
{
	unsigned n;
	memcpy(&n, data, sizeof(unsigned));
	
	uint8_t br;
	br = (uint8_t)n;

	struct mk_uint8_s mr;
	mk_uint8_from_int(&mr, n);

	test(memcmp(&br, &mr, 8 / CHAR_BIT) == 0);
}

static inline void mk_uint_fuzz_8_to_int(unsigned char const* data)
{
	uint8_t bx;
	unsigned br;
	memcpy(&bx, data, 8 / CHAR_BIT);
	br = (unsigned)bx;

	struct mk_uint8_s mx;
	unsigned mr;
	memcpy(&mx, data, 8 / CHAR_BIT);
	mr = mk_uint8_to_int(&mx);

	test(memcmp(&br, &mr, sizeof(unsigned)) == 0);
}


static inline void mk_uint_fuzz_8_is_zero(unsigned char const* data)
{
	uint8_t bx;
	int br;
	memcpy(&bx, data, 8 / CHAR_BIT);
	br = bx == 0;

	struct mk_uint8_s mx;
	int mr;
	memcpy(&mx, data, 8 / CHAR_BIT);
	mr = mk_uint8_is_zero(&mx);

	test(memcmp(&br, &mr, sizeof(int)) == 0);
}

static inline void mk_uint_fuzz_8_is_max(unsigned char const* data)
{
	uint8_t bx;
	int br;
	memcpy(&bx, data, 8 / CHAR_BIT);
	br = bx == (uint8_t)((uint8_t)0 - (uint8_t)1);

	struct mk_uint8_s mx;
	int mr;
	memcpy(&mx, data, 8 / CHAR_BIT);
	mr = mk_uint8_is_max(&mx);

	test(memcmp(&br, &mr, sizeof(int)) == 0);
}


static inline void mk_uint_fuzz_8_or(unsigned char const* data)
{
	uint8_t ba;
	uint8_t bb;
	uint8_t br;
	memcpy(&ba, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&bb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	br = ba | bb;

	struct mk_uint8_s ma;
	struct mk_uint8_s mb;
	struct mk_uint8_s mr;
	memcpy(&ma, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&mb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	mk_uint8_or(&mr, &ma, &mb);

	test(memcmp(&br, &mr, 8 / CHAR_BIT) == 0);
}

static inline void mk_uint_fuzz_8_and(unsigned char const* data)
{
	uint8_t ba;
	uint8_t bb;
	uint8_t br;
	memcpy(&ba, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&bb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	br = ba & bb;

	struct mk_uint8_s ma;
	struct mk_uint8_s mb;
	struct mk_uint8_s mr;
	memcpy(&ma, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&mb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	mk_uint8_and(&mr, &ma, &mb);

	test(memcmp(&br, &mr, 8 / CHAR_BIT) == 0);
}

static inline void mk_uint_fuzz_8_xor(unsigned char const* data)
{
	uint8_t ba;
	uint8_t bb;
	uint8_t br;
	memcpy(&ba, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&bb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	br = ba ^ bb;

	struct mk_uint8_s ma;
	struct mk_uint8_s mb;
	struct mk_uint8_s mr;
	memcpy(&ma, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&mb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	mk_uint8_xor(&mr, &ma, &mb);

	test(memcmp(&br, &mr, 8 / CHAR_BIT) == 0);
}


static inline void mk_uint_fuzz_8_shl(unsigned char const* data)
{
	uint8_t bx;
	unsigned bn;
	uint8_t br;
	memcpy(&bx, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&bn, data + 8 / CHAR_BIT, sizeof(bn));
	bn = bn % 8;
	br = bx << bn;

	struct mk_uint8_s mx;
	unsigned mn;
	struct mk_uint8_s mr;
	memcpy(&mx, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&mn, data + 8 / CHAR_BIT, sizeof(mn));
	mn = mn % 8;
	mk_uint8_shl(&mr, &mx, mn);

	test(memcmp(&br, &mr, 8 / CHAR_BIT) == 0);
}

static inline void mk_uint_fuzz_8_shr(unsigned char const* data)
{
	uint8_t bx;
	unsigned bn;
	uint8_t br;
	memcpy(&bx, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&bn, data + 8 / CHAR_BIT, sizeof(bn));
	bn = bn % 8;
	br = bx >> bn;

	struct mk_uint8_s mx;
	unsigned mn;
	struct mk_uint8_s mr;
	memcpy(&mx, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&mn, data + 8 / CHAR_BIT, sizeof(mn));
	mn = mn % 8;
	mk_uint8_shr(&mr, &mx, mn);

	test(memcmp(&br, &mr, 8 / CHAR_BIT) == 0);
}


static inline void mk_uint_fuzz_8_eq(unsigned char const* data)
{
	uint8_t ba;
	uint8_t bb;
	int br;
	memcpy(&ba, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&bb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	br = ba == bb;

	struct mk_uint8_s ma;
	struct mk_uint8_s mb;
	int mr;
	memcpy(&ma, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&mb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	mr = mk_uint8_eq(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}

static inline void mk_uint_fuzz_8_neq(unsigned char const* data)
{
	uint8_t ba;
	uint8_t bb;
	int br;
	memcpy(&ba, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&bb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	br = ba != bb;

	struct mk_uint8_s ma;
	struct mk_uint8_s mb;
	int mr;
	memcpy(&ma, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&mb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	mr = mk_uint8_neq(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}

static inline void mk_uint_fuzz_8_lt(unsigned char const* data)
{
	uint8_t ba;
	uint8_t bb;
	int br;
	memcpy(&ba, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&bb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	br = ba < bb;

	struct mk_uint8_s ma;
	struct mk_uint8_s mb;
	int mr;
	memcpy(&ma, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&mb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	mr = mk_uint8_lt(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}

static inline void mk_uint_fuzz_8_le(unsigned char const* data)
{
	uint8_t ba;
	uint8_t bb;
	int br;
	memcpy(&ba, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&bb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	br = ba <= bb;

	struct mk_uint8_s ma;
	struct mk_uint8_s mb;
	int mr;
	memcpy(&ma, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&mb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	mr = mk_uint8_le(&ma, &mb);

	test(memcmp(&br, &mr, sizeof(br)) == 0);
}


static inline void mk_uint_fuzz_8_inc(unsigned char const* data)
{
	uint8_t bx;
	memcpy(&bx, data, 8 / CHAR_BIT);
	++bx;

	struct mk_uint8_s mx;
	memcpy(&mx, data, 8 / CHAR_BIT);
	mk_uint8_inc(&mx);

	test(memcmp(&mx, &bx, 8 / CHAR_BIT) == 0);
}

static inline void mk_uint_fuzz_8_dec(unsigned char const* data)
{
	uint8_t bx;
	memcpy(&bx, data, 8 / CHAR_BIT);
	--bx;

	struct mk_uint8_s mx;
	memcpy(&mx, data, 8 / CHAR_BIT);
	mk_uint8_dec(&mx);

	test(memcmp(&mx, &bx, 8 / CHAR_BIT) == 0);
}


static inline void mk_uint_fuzz_8_add(unsigned char const* data)
{
	uint8_t ba;
	uint8_t bb;
	uint8_t br;
	memcpy(&ba, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&bb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	br = ba + bb;

	struct mk_uint8_s ma;
	struct mk_uint8_s mb;
	struct mk_uint8_s mr;
	memcpy(&ma, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&mb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	mk_uint8_add(&mr, &ma, &mb);

	test(memcmp(&br, &mr, 8 / CHAR_BIT) == 0);
}

static inline void mk_uint_fuzz_8_sub(unsigned char const* data)
{
	uint8_t ba;
	uint8_t bb;
	uint8_t br;
	memcpy(&ba, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&bb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	br = ba - bb;

	struct mk_uint8_s ma;
	struct mk_uint8_s mb;
	struct mk_uint8_s mr;
	memcpy(&ma, data + 0 / CHAR_BIT, 8 / CHAR_BIT);
	memcpy(&mb, data + 8 / CHAR_BIT, 8 / CHAR_BIT);
	mk_uint8_sub(&mr, &ma, &mb);

	test(memcmp(&br, &mr, 8 / CHAR_BIT) == 0);
}


void mk_uint_fuzz_8(unsigned char const* data)
{
	mk_uint_fuzz_8_zero();
	mk_uint_fuzz_8_one();
	mk_uint_fuzz_8_from_int(data);
	mk_uint_fuzz_8_to_int(data);

	mk_uint_fuzz_8_is_zero(data);
	mk_uint_fuzz_8_is_max(data);

	mk_uint_fuzz_8_or(data);
	mk_uint_fuzz_8_and(data);
	mk_uint_fuzz_8_xor(data);

	mk_uint_fuzz_8_shl(data);
	mk_uint_fuzz_8_shr(data);
	
	mk_uint_fuzz_8_eq(data);
	mk_uint_fuzz_8_neq(data);
	mk_uint_fuzz_8_lt(data);
	mk_uint_fuzz_8_le(data);

	mk_uint_fuzz_8_inc(data);
	mk_uint_fuzz_8_dec(data);

	mk_uint_fuzz_8_add(data);
	mk_uint_fuzz_8_sub(data);
}


#undef test