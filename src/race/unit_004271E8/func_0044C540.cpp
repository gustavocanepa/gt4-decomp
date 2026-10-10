typedef unsigned char u8;

static inline u8 merge(const u8 *p, int shift)
{
    u8 lo_mask = 0xFF << shift;
    u8 hi_mask = 0xFFu >> (8 - shift);
    return ((p[0] & lo_mask) >> shift) | ((p[1] & hi_mask) << (8 - shift));
}

extern "C" u8 func_0044C540(const u8 *buf, unsigned int bit)
{
    int shift = bit & 7;
    bit >>= 3;
    if (shift == 0)
        return buf[bit];
    return merge(buf + bit, shift);
}
