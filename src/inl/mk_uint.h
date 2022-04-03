#define mk_uint_parts ((mk_uint_bits + (mk_uint_small_bits - 1)) / mk_uint_small_bits)


#if mk_uint_parts == 1


mk_uint_t
{
	mk_uint_small_t m_data;
};


#else


mk_uint_t
{
	mk_uint_small_t m_data[mk_uint_parts];
};


#endif


void mk_uint_zero(mk_uint_t* out);
void mk_uint_one(mk_uint_t* out);
void mk_uint_from_int(mk_uint_t* out, unsigned in);
unsigned mk_uint_to_int(mk_uint_t const* x);
void mk_uint_from_sizet(mk_uint_t* out, size_t in);
size_t mk_uint_to_sizet(mk_uint_t const* x);
void mk_uint_from_buff_le(mk_uint_t* out, void const* buff);
void mk_uint_to_buff_le(mk_uint_t const* x, void* buff);
void mk_uint_from_buff_be(mk_uint_t* out, void const* buff);
void mk_uint_to_buff_be(mk_uint_t const* x, void* buff);

int mk_uint_is_zero(mk_uint_t const* x);
int mk_uint_is_max(mk_uint_t const* x);

void mk_uint_cmplmnt(mk_uint_t* out, mk_uint_t const* x);
void mk_uint_or(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b);
void mk_uint_and(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b);
void mk_uint_xor(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b);

void mk_uint_shl(mk_uint_t* out, mk_uint_t const* x, int n);
void mk_uint_shr(mk_uint_t* out, mk_uint_t const* x, int n);
void mk_uint_rotl(mk_uint_t* out, mk_uint_t const* x, int n);
void mk_uint_rotr(mk_uint_t* out, mk_uint_t const* x, int n);

int mk_uint_eq(mk_uint_t const* a, mk_uint_t const* b);
int mk_uint_neq(mk_uint_t const* a, mk_uint_t const* b);
int mk_uint_lt(mk_uint_t const* a, mk_uint_t const* b);
int mk_uint_le(mk_uint_t const* a, mk_uint_t const* b);
int mk_uint_gt(mk_uint_t const* a, mk_uint_t const* b);
int mk_uint_ge(mk_uint_t const* a, mk_uint_t const* b);

void mk_uint_inc(mk_uint_t* x);
void mk_uint_dec(mk_uint_t* x);

void mk_uint_add(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b);
void mk_uint_sub(mk_uint_t* out, mk_uint_t const* a, mk_uint_t const* b);


#undef mk_uint_parts
