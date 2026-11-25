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

#define PHT(x, y) do { y += x; x += y; } while (0)

/* SAFER block encryption: key[0] is the round count, then 16 key bytes per round and 8 for the
   output transform. */
extern "C" void func_0044B900(u8 *out, u8 *in, SaferTables *tbl, u8 *key) {
    u8 a, b, c, d, e, f, g, h, t;
    unsigned int rounds;
    unsigned int i;
    unsigned int k;

    rounds = key[0];
    if (rounds > 13) rounds = 13;
    a = in[0]; b = in[1]; c = in[2]; d = in[3];
    e = in[4]; f = in[5]; g = in[6]; h = in[7];
    k = 1;
    for (i = 0; i < rounds; i++, k += 16) {
        a ^= key_byte(key, k);
        b += key_byte(key, k + 1);
        c += key_byte(key, k + 2);
        d ^= key_byte(key, k + 3);
        e ^= key_byte(key, k + 4);
        f += key_byte(key, k + 5);
        g += key_byte(key, k + 6);
        h ^= key_byte(key, k + 7);
        a = safer_exp(tbl, a) + key_byte(key, k + 8);
        b = safer_log(tbl, b) ^ key_byte(key, k + 9);
        c = safer_log(tbl, c) ^ key_byte(key, k + 10);
        d = safer_exp(tbl, d) + key_byte(key, k + 11);
        e = safer_exp(tbl, e) + key_byte(key, k + 12);
        f = safer_log(tbl, f) ^ key_byte(key, k + 13);
        g = safer_log(tbl, g) ^ key_byte(key, k + 14);
        h = safer_exp(tbl, h) + key_byte(key, k + 15);
        PHT(a, b); PHT(c, d); PHT(e, f); PHT(g, h);
        PHT(a, c); PHT(e, g); PHT(b, d); PHT(f, h);
        PHT(a, e); PHT(b, f); PHT(c, g); PHT(d, h);
        t = b; b = e; e = c; c = t; t = d; d = f; f = g; g = t;
    }
    a ^= key_byte(key, k);
    b += key_byte(key, k + 1);
    c += key_byte(key, k + 2);
    d ^= key_byte(key, k + 3);
    e ^= key_byte(key, k + 4);
    f += key_byte(key, k + 5);
    g += key_byte(key, k + 6);
    h ^= key_byte(key, k + 7);
    out[0] = a; out[1] = b; out[2] = c; out[3] = d;
    out[4] = e; out[5] = f; out[6] = g; out[7] = h;
}
