/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Reads the next character of a string-backed reader (string at +0, read position at +4), or -1 at
 * the end. The read goes through basic_string<char>'s non-const operator[] (gcc 2.96 bastring.h):
 * selfish() -> unique() -> alloc(length(), true) (func_005CB5A0) when the text is shared, then
 * rep()->selfish = true. Matches only with -fno-strict-aliasing (dat is reloaded after each store
 * through the Rep), like the library itself. */
typedef unsigned int u32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; };
struct Reader { struct String str; u32 pos; };

extern "C" void func_005CB5A0(struct String *str, u32 size, int save);

static inline struct StringRep *rep(const struct String *str) { return (struct StringRep *)str->dat - 1; }
static inline u32 length(const struct String *str) { return rep(str)->len; }
static inline void unique(struct String *str) {
    if (rep(str)->ref > 1)
        func_005CB5A0(str, length(str), 1);
}
static inline void selfish(struct String *str) {
    unique(str);
    rep(str)->selfish = 1;
}
static inline char &at(struct String *str, u32 pos) {
    selfish(str);
    return str->dat[pos];
}

extern "C" int func_0032B928(struct Reader *r) {
    if (r->pos < length(&r->str))
        return at(&r->str, r->pos++);
    return -1;
}
