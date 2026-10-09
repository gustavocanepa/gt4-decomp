/* compiler: ee-gcc2.96-no-strict-aliasing */
/* basic_string<char>::find(char c, size_type pos) const of the second string instantiation
 * (gcc 2.96 libstdc++ v2, std/bastring.cc): the inline _find over data() and length(), with
 * string_char_traits<char>::eq. Returns the position or npos. */
typedef unsigned int u32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; };

static inline struct StringRep *rep(const struct String *str) { return (struct StringRep *)str->dat - 1; }
static inline u32 length(const struct String *str) { return rep(str)->len; }
static inline const char *data(const struct String *str) { return str->dat; }

static inline bool traits_eq(const char &c1, const char &c2) { return c1 == c2; }

static inline u32 _find(const char *ptr, char c, u32 xpos, u32 len) {
    for (; xpos < len; ++xpos)
        if (traits_eq(ptr[xpos], c))
            return xpos;
    return (u32)-1;
}

extern "C" u32 func_0060E700(const struct String *str, char c, u32 pos) {
    return _find(data(str), c, pos, length(str));
}
