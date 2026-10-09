/* compiler: ee-gcc2.96-no-strict-aliasing */
/* basic_string<char>::resize(size_type n, char c) (gcc 2.96 libstdc++ v2, std/bastring.cc):
 * append(n - length(), c) and erase(n) are bastring.h's inline forwarders to
 * replace(pos, n1, n2, c) (func_005CB368). */
typedef unsigned int u32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; };

extern "C" struct String *func_005CB368(struct String *str, u32 pos, u32 n1, u32 n2, char c);

static inline struct StringRep *rep(const struct String *str) { return (struct StringRep *)str->dat - 1; }
static inline u32 length(const struct String *str) { return rep(str)->len; }

static inline struct String &append(struct String *str, u32 n, char c) {
    return *func_005CB368(str, length(str), 0, n, c);
}

static inline struct String &erase(struct String *str, u32 pos = 0, u32 n = (u32)-1) {
    return *func_005CB368(str, pos, n, (u32)0, (char)0);
}

extern "C" void func_005EE900(struct String *str, u32 n, char c) {
    if (n > length(str))
        append(str, n - length(str), c);
    else
        erase(str, n);
}
