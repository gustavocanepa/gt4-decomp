typedef int s32;
typedef unsigned int u32;

struct Str {
    char *p;
};

extern "C" s32 func_0057F188(const char *a, const char *b, u32 n);

static inline u32 str_len(const struct Str *s) {
    return *(u32 *)(s->p - 0x10);
}

static inline u32 min_u(u32 a, u32 b) {
    return b < a ? b : a;
}

extern "C" s32 func_005C2A50(struct Str *self, struct Str *other, u32 pos, u32 n) {
    u32 len = str_len(self) - pos;
    u32 olen;
    s32 r;
    if (n < len) len = n;
    olen = str_len(other);
    if (olen < len) len = olen;
    r = func_0057F188(self->p + pos, other->p, len);
    if (r != 0) {
        return r;
    }
    if (len == n) {
        return r;
    }
    return (str_len(self) - pos) - str_len(other);
}
