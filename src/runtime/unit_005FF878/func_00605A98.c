/* compiler: ee-gcc2.96-no-strict-aliasing */
/* basic_string<char>::alloc(size_type size, bool save) (gcc 2.96 libstdc++ v2, std/bastring.cc):
 * reallocates when check_realloc says so, keeping the text when save is set; the library's inline
 * helpers are nested as in bastring.h (check_realloc, Rep::create/frob_size/operator new,
 * Rep::copy, repup/Rep::release/operator delete) for the second string instantiation (allocator memalign(16, n) = func_00575E60, returning
 * 0 for n == 0; deallocator free(p)). */
typedef unsigned int u32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; };

extern void *func_00575E60(u32 align, u32 size);
extern void free(void *ptr);
extern void *memcpy(void *dst, const void *src, u32 n);

static inline char *rep_data(struct StringRep *r) { return (char *)(r + 1); }
static inline struct StringRep *rep(struct String *str) { return (struct StringRep *)str->dat - 1; }

static inline u32 frob_size(u32 s) {
    u32 i = 16;
    while (i < s)
        i *= 2;
    return i;
}

static inline void *rep_new(u32 n) {
    if (n)
        return func_00575E60(16, n);
    return 0;
}

static inline void rep_delete(struct StringRep *p) {
    free(p);
}

static inline struct StringRep *create(u32 extra) {
    struct StringRep *p;
    extra = frob_size(extra + 1);
    p = rep_new(sizeof(struct StringRep) + extra);
    p->res = extra;
    p->ref = 1;
    p->selfish = 0;
    return p;
}

static inline void rep_copy(struct StringRep *r, u32 pos, const char *s, u32 n) {
    if (n)
        memcpy(rep_data(r) + pos, s, n);
}

static inline void release(struct StringRep *r) {
    if (--r->ref == 0)
        rep_delete(r);
}

static inline void repup(struct String *str, struct StringRep *p) {
    release(rep(str));
    str->dat = rep_data(p);
}

static inline int excess_slop(u32 s, u32 r) {
    return 2 * (s <= 16 ? 16 : s) < r;
}

static inline int check_realloc(struct String *str, u32 s) {
    s += 1;
    rep(str)->selfish = 0;
    return rep(str)->ref > 1 || s > rep(str)->res || excess_slop(s, rep(str)->res);
}

void func_00605A98(struct String *str, u32 size, int save) {
    struct StringRep *p;

    if (!check_realloc(str, size))
        return;

    p = create(size);

    if (save) {
        rep_copy(p, 0, str->dat, rep(str)->len);
        p->len = rep(str)->len;
    } else
        p->len = 0;

    repup(str, p);
}
