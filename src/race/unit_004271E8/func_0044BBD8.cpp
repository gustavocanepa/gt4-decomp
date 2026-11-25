typedef unsigned char u8;

struct SaferTables {
    u8 log[256];
    u8 exp[256];
};

static inline u8 key_byte(const u8 *key, unsigned int index) {
    return key[index];
}

static inline u8 safer_exp(const SaferTables *tbl, unsigned int x) {
    return tbl->exp[x & 0xFF];
}

static inline u8 safer_log(const SaferTables *tbl, unsigned int x) {
    return tbl->log[x & 0xFF];
}

#define IPHT(x, y) do { x -= y; y -= x; } while (0)

/* SAFER block decryption: walks the expanded key backwards from the output transform. */
extern "C" void func_0044BBD8(u8 *out, u8 *in, SaferTables *tbl, u8 *key) {
    u8 a, b, c, d, e, f, g, h, t;
    unsigned int rounds;
    unsigned int i;
    unsigned int k;

    rounds = key[0];
    if (rounds > 13) rounds = 13;
    a = in[0]; b = in[1]; c = in[2]; d = in[3];
    e = in[4]; f = in[5]; g = in[6]; h = in[7];
    k = 16 * rounds + 8;
    h ^= key_byte(key, k);
    g -= key_byte(key, k - 1);
    f -= key_byte(key, k - 2);
    e ^= key_byte(key, k - 3);
    d ^= key_byte(key, k - 4);
    c -= key_byte(key, k - 5);
    b -= key_byte(key, k - 6);
    a ^= key_byte(key, k - 7);
    k -= 8;
    for (i = 0; i < rounds; i++, k -= 16) {
        t = e; e = b; b = c; c = t; t = f; f = d; d = g; g = t;
        IPHT(a, e); IPHT(b, f); IPHT(c, g); IPHT(d, h);
        IPHT(a, c); IPHT(e, g); IPHT(b, d); IPHT(f, h);
        IPHT(a, b); IPHT(c, d); IPHT(e, f); IPHT(g, h);
        h -= key_byte(key, k);
        g ^= key_byte(key, k - 1);
        f ^= key_byte(key, k - 2);
        e -= key_byte(key, k - 3);
        d -= key_byte(key, k - 4);
        c ^= key_byte(key, k - 5);
        b ^= key_byte(key, k - 6);
        a -= key_byte(key, k - 7);
        h = safer_log(tbl, h) ^ key_byte(key, k - 8);
        g = safer_exp(tbl, g) - key_byte(key, k - 9);
        f = safer_exp(tbl, f) - key_byte(key, k - 10);
        e = safer_log(tbl, e) ^ key_byte(key, k - 11);
        d = safer_log(tbl, d) ^ key_byte(key, k - 12);
        c = safer_exp(tbl, c) - key_byte(key, k - 13);
        b = safer_exp(tbl, b) - key_byte(key, k - 14);
        a = safer_log(tbl, a) ^ key_byte(key, k - 15);
    }
    out[0] = a; out[1] = b; out[2] = c; out[3] = d;
    out[4] = e; out[5] = f; out[6] = g; out[7] = h;
}
