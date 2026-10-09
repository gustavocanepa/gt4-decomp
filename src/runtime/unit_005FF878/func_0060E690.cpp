/* compiler: ee-gcc2.96-no-strict-aliasing */
/* basic_string<char>::rfind(char c, size_type pos) const of the second string
 * instantiation (the same code as func_005DACE0) (gcc 2.96 libstdc++ v2,
 * std/bastring.cc), with length()/data() and string_char_traits<char>::eq inlined as in the
 * headers. Returns the position or npos. */
typedef unsigned int u32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; };

static inline struct StringRep *rep(const struct String *str) { return (struct StringRep *)str->dat - 1; }
static inline u32 length(const struct String *str) { return rep(str)->len; }
static inline const char *data(const struct String *str) { return str->dat; }

static inline bool traits_eq(const char &c1, const char &c2) { return c1 == c2; }

extern "C" u32 func_0060E690(const struct String *str, char c, u32 pos) {
    if (1 > length(str))
        return (u32)-1;

    u32 xpos = length(str) - 1;
    if (xpos > pos)
        xpos = pos;

    for (++xpos; xpos-- > 0;)
        if (traits_eq(data(str)[xpos], c))
            return xpos;
    return (u32)-1;
}
