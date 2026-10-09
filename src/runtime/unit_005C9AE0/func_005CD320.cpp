typedef int s32;
typedef unsigned int u32;

struct Str {
    char *p;
};

extern "C" s32 func_0057F188(const char *a, const char *b, u32 n);

static inline u32 str_len(const struct Str *s) {
    return *(u32 *)(s->p - 0x10);
}

extern "C" s32 func_005CD320(struct Str *self, const char *s, u32 pos, u32 n) {
    u32 len = str_len(self) - pos;
    s32 r;
    if (n < len) len = n;
    r = func_0057F188(self->p + pos, s, len);
    if (r != 0) {
        return r;
    }
    if (len == n) {
        return r;
    }
    return (str_len(self) - pos) - n;
}
