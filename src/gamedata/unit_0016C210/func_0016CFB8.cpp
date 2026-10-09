/* Returns basic_string<char>(obj + 0x10, 0x100) by value: the gcc 2.96 bastring.h constructor
 * from (const char *, size_type) = nilRep.grab() (clone when selfish, else ++ref) followed by
 * assign(s, n) = replace(0, npos, s, n) (func_005C2630). */
typedef unsigned int u32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; };

extern StringRep D_00659FA8;

extern "C" char *func_005C2560(StringRep *r);
extern "C" String *func_005C2630(String *str, u32 pos, u32 n1, const char *s, u32 n2);

static inline char *grab(StringRep *r) {
    if (r->selfish)
        return func_005C2560(r);
    ++r->ref;
    return (char *)(r + 1);
}

static inline String &assign(String *str, const char *s, u32 n) {
    return *func_005C2630(str, 0, (u32)-1, s, n);
}

static inline void construct(String *str, const char *s, u32 n) {
    str->dat = grab(&D_00659FA8);
    assign(str, s, n);
}

extern "C" String *func_0016CFB8(String *ret, char *obj) {
    construct(ret, obj + 0x10, 0x100);
    return ret;
}
