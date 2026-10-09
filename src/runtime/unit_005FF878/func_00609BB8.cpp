/* compiler: ee-gcc2.96-no-strict-aliasing */
/* basic_string<char>::replace(iterator i1, iterator i2, const char *j1, const char *j2), the member
 * template of gcc 2.96 libstdc++ v2 (std/bastring.h), for the second string instantiation
 * (allocator memalign(16, n) = func_00575E60, returning 0 for n == 0; deallocator
 * func_00575DA0(p)), with the library's inline helpers nested as in bastring.h: ibegin and
 * Rep::operator[], check_realloc, Rep::create/frob_size/operator new, Rep::copy/move,
 * traits::assign per character, repup and Rep::release/operator delete. Returns *this. */
typedef unsigned int u32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; };

extern "C" void *func_00575E60(u32 align, u32 size);
extern "C" void func_00575DA0(void *ptr);
extern "C" void *func_005A4724(void *dst, const void *src, u32 n);
extern "C" void *func_005A47D4(void *dst, const void *src, u32 n);

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
    func_00575DA0(p);
}

static inline struct StringRep *create(u32 extra) {
    struct StringRep *p;
    extra = frob_size(extra + 1);
    p = (struct StringRep *)rep_new(sizeof(struct StringRep) + extra);
    p->res = extra;
    p->ref = 1;
    p->selfish = 0;
    return p;
}

static inline void rep_copy(struct StringRep *r, u32 pos, const char *s, u32 n) {
    if (n)
        func_005A4724(rep_data(r) + pos, s, n);
}

static inline void rep_move(struct StringRep *r, u32 pos, const char *s, u32 n) {
    if (n)
        func_005A47D4(rep_data(r) + pos, s, n);
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

/* traits::assign */
static inline void traits_assign(char &c1, const char &c2) { c1 = c2; }

/* Rep::operator[] */
static inline char &rep_at(struct StringRep *r, u32 s) { return rep_data(r)[s]; }

static inline char *ibegin(struct String *str) { return &rep_at(rep(str), 0); }

extern "C" struct String *func_00609BB8(struct String *str, char *i1, char *i2, const char *j1, const char *j2) {
    const u32 len = rep(str)->len;
    u32 pos = i1 - ibegin(str);
    u32 n1 = i2 - i1;
    u32 n2 = j2 - j1;

    if (n1 > len - pos)
        n1 = len - pos;
    u32 newlen = len - n1 + n2;

    if (check_realloc(str, newlen)) {
        struct StringRep *p = create(newlen);
        rep_copy(p, 0, str->dat, pos);
        rep_copy(p, pos + n2, str->dat + pos + n1, len - (pos + n1));
        for (; j1 != j2; ++j1, ++pos)
            traits_assign(rep_at(p, pos), *j1);
        repup(str, p);
    } else {
        rep_move(rep(str), pos + n2, str->dat + pos + n1, len - (pos + n1));
        for (; j1 != j2; ++j1, ++pos)
            traits_assign(rep_at(rep(str), pos), *j1);
    }
    rep(str)->len = newlen;
    return str;
}
