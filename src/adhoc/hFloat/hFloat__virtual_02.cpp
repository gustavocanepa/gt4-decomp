/* Returns basic_string<char>(a float formatted with sprintf (func_0057DA20) into a local buffer) by value: the gcc 2.96 bastring.h constructor from
 * const char * = nilRep.grab() (clone when selfish, else ++ref) + assign(s, strlen(s))
 * = replace(0, npos, s, n) (func_005C2630).
 * Written with the promotion as an explicit fptodp call (fmt loaded first, kept in $s0); passing
 * the float straight to the variadic call also matches but leaves the libcall unchecked. */
typedef unsigned int u32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; };

extern StringRep D_00659FA8;

extern "C" char *func_005C2560(StringRep *r);
extern "C" String *func_005C2630(String *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" u32 func_0057F260(const char *s);
struct Obj { char pad[0x10]; float value; };
extern char D_0069D850[];
extern "C" double func_0057FB50(float f); /* fptodp: the float -> double vararg promotion */
extern "C" int func_0057DA20(char *buf, const char *fmt, ...);

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

extern "C" String *hFloat__virtual_02(String *ret, Obj *obj) {
    char buf[0x20];
    const char *fmt = D_0069D850;
    double d = func_0057FB50(obj->value);
    func_0057DA20(buf, fmt, d);
    construct(ret, buf);
    return ret;
}
