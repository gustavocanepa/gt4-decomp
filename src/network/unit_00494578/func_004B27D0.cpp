typedef unsigned char u8;

struct VEntry {
    short delta;
    short index;
    int (*fn)(void *);
};

struct Obj {
    char *vtbl;
};

struct Table {
    Obj *obj;
    int pad4;
    u8 *data;
};

extern "C" int func_004B2488(const void *key, int keylen, const u8 *str, int len);

static inline unsigned rd16(const u8 *p, int off)
{
    return p[off] | (p[off + 1] << 8);
}

extern "C" int func_004B27D0(Table *t, const void *key, int keylen, unsigned *out)
{
    unsigned lo = 0;
    unsigned hi;
    unsigned mid;
    unsigned n;
    int end;
    int r;
    VEntry *e;

    n = rd16(t->data, 2) >> 1;
    e = (VEntry *)(t->obj->vtbl + 0x10);
    end = e->fn((char *)t->obj + e->delta);
    hi = n - 1;
    r = func_004B2488(key, keylen, t->data + rd16(t->data, end - 8), rd16(t->data, end - 6));
    if (r < 0) {
        *out = 0;
        return 0;
    }
    while (hi - lo >= 8) {
        mid = (lo + hi) >> 1;
        r = func_004B2488(key, keylen, t->data + rd16(t->data, end - mid * 8 - 8),
                          rd16(t->data, end - mid * 8 - 6));
        if (r == 0) {
            *out = mid;
            return 1;
        }
        if (r < 0)
            hi = mid;
        else
            lo = mid;
    }
    for (; lo <= hi; lo++) {
        r = func_004B2488(key, keylen, t->data + rd16(t->data, end - lo * 8 - 8),
                          rd16(t->data, end - lo * 8 - 6));
        if (r <= 0) {
            *out = lo;
            return r == 0;
        }
    }
    return 0;
}
