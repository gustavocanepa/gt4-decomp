/* Returns basic_string<char>(buf) by value, buf filled by func_004F1460(table, buf, 0x400): the
 * gcc 2.96 bastring.h constructor from const char * = nilRep.grab() + assign(s, traits::length(s))
 * (strlen = func_0057F260, replace = func_005C2630). */
typedef unsigned int u32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; };

extern StringRep D_00659FA8;
extern char D_00645570[];

extern "C" char *func_005C2560(StringRep *r);
extern "C" String *func_005C2630(String *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" u32 func_0057F260(const char *s);
extern "C" void func_004F1460(void *table, char *buf, u32 size);

static inline char *grab(StringRep *r) {
    if (r->selfish)
        return func_005C2560(r);
    ++r->ref;
    return (char *)(r + 1);
}

static inline String &assign(String *str, const char *s, u32 n) {
    return *func_005C2630(str, 0, (u32)-1, s, n);
}

static inline String &assign(String *str, const char *s) {
    return assign(str, s, func_0057F260(s));
}

static inline void construct(String *str, const char *s) {
    str->dat = grab(&D_00659FA8);
    assign(str, s);
}

extern "C" String *func_001F2028(String *ret) {
    char buf[0x400];
    func_004F1460(D_00645570, buf, 0x400);
    construct(ret, buf);
    return ret;
}
