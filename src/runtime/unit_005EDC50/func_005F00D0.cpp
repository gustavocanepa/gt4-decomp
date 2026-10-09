/* compiler: ee-gcc2.96-no-strict-aliasing */
/* basic_string<char>::find(const char *s, size_type pos, size_type n) const (gcc 2.96
 * libstdc++ v2, std/bastring.cc), with length()/data() and string_char_traits<char>::eq/compare
 * (memcmp = func_0057F188) inlined as in the headers. Returns the position or npos. */
typedef unsigned int u32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; };

extern "C" int func_0057F188(const void *s1, const void *s2, u32 n);

static inline struct StringRep *rep(const struct String *str) { return (struct StringRep *)str->dat - 1; }
static inline u32 length(const struct String *str) { return rep(str)->len; }
static inline const char *data(const struct String *str) { return str->dat; }

static inline bool traits_eq(const char &c1, const char &c2) { return c1 == c2; }
static inline int traits_compare(const char *s1, const char *s2, u32 n) { return func_0057F188(s1, s2, n); }

extern "C" u32 func_005F00D0(const struct String *str, const char *s, u32 pos, u32 n) {
    u32 xpos = pos;
    for (; xpos + n <= length(str); ++xpos)
        if (traits_eq(data(str)[xpos], *s)
            && traits_compare(data(str) + xpos, s, n) == 0)
            return xpos;
    return (u32)-1;
}
