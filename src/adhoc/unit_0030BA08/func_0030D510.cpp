/* Returns a copy of s when it is empty, else basic_string<char>(buf) with buf = func_0030D110(s.c_str())
 * (0x400 bytes): bastring.h's copy constructor (rep()->grab()), c_str() ("" when empty, else
 * terminate() and data()) and the constructor from const char * (nilRep.grab() + assign(s, strlen(s))). */
typedef unsigned int u32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; };

extern StringRep D_00659FA8;

extern "C" char *func_005C2560(StringRep *r);
extern "C" String *func_005C2630(String *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" u32 func_0057F260(const char *s);

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

extern char D_0069DED8[]; /* "" */
extern "C" void func_0030D110(char *buf, const char *s);

static inline StringRep *rep(const String *str) { return (StringRep *)str->dat - 1; }
static inline u32 length(const String *str) { return rep(str)->len; }
static inline char *data(const String *str) { return str->dat; }
static inline u32 size(const String *str) { return rep(str)->len; }
static inline bool empty(const String *str) { return size(str) == 0; }
static inline char *rep_data(StringRep *r) { return (char *)(r + 1); }
static inline char &rep_at(StringRep *r, u32 i) { return rep_data(r)[i]; }
static inline void traits_assign(char &c1, const char &c2) { c1 = c2; }
static inline char eos() { return 0; }
static inline void terminate(const String *str) { traits_assign(rep_at(rep(str), length(str)), eos()); }
static inline const char *c_str(const String *str) {
    if (length(str) == 0)
        return D_0069DED8;
    terminate(str);
    return rep_data(rep(str));
}
static inline void copy(String *str, const String *src) {
    str->dat = grab(rep(src));
}

extern "C" String *func_0030D510(String *ret, const String *s) {
    if (!empty(s)) {
        char buf[0x400];
        func_0030D110(buf, c_str(s));
        construct(ret, buf);
        return ret;
    }
    copy(ret, s);
    return ret;
}
