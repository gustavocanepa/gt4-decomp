/* Returns basic_string<char>(func_004472A0(G->p6C->p70)) by value, or an empty string when the global G (D_00618710) is null: the gcc 2.96 bastring.h
 * constructors from const char * (nilRep.grab() + assign(s, strlen(s)) = replace(0, npos, s, n),
 * func_005C2630) and the default one (nilRep.grab() alone). */
typedef unsigned int u32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; };

extern StringRep D_00659FA8;

extern "C" char *func_005C2560(StringRep *r);
extern "C" String *func_005C2630(String *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" u32 func_0057F260(const char *s);
struct Inner { char pad[0x70]; void *p70; };
struct Global { char pad[0x6C]; Inner *p6C; };
extern Global *D_00618710;
extern "C" const char *func_004472A0(void *p);

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

static inline void construct(String *str, const char *s, u32 n) {
    str->dat = grab(&D_00659FA8);
    assign(str, s, n);
}

static inline void construct(String *str, const char *s) {
    str->dat = grab(&D_00659FA8);
    assign(str, s);
}

static inline void construct(String *str) {
    str->dat = grab(&D_00659FA8);
}

extern "C" String *func_00120020(String *ret) {
    Global *g = D_00618710;
    if (g) {
        construct(ret, func_004472A0(g->p6C->p70));
        return ret;
    }
    construct(ret);
    return ret;
}
