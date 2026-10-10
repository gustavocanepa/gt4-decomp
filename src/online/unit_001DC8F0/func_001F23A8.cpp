/* Waits (mUpdateContext__Sync(1)) until func_004F1D18(&D_00645570, a2 == 0) succeeds; returns an empty string when func_001F1368(a1) is 0, else basic_string<char>(buf) filled by func_004F1F70(&D_00645570, buf, 0x400) (bastring.h: default ctor = nilRep.grab(), (const char *) ctor = grab + assign(s, strlen(s)), copy ctor = rep()->grab(), dtor = rep()->release() -> func_00326798(p, sizeof(Rep) + res, 4, heap name)) */
typedef unsigned int u32;
typedef int s32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; };
struct Heap { const char *name; };

extern StringRep D_00659FA8;

extern "C" char *func_005C2560(StringRep *r);
extern "C" String *func_005C2630(String *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" u32 func_0057F260(const char *s);
extern "C" Heap *func_005C11A8(void);
extern "C" void func_00326798(void *p, u32 n, u32 align, const char *name);
extern char D_00645570[];
extern "C" void mUpdateContext__Sync(s32 a);
extern "C" s32 func_004F1D18(void *a, s32 b);
extern "C" s32 func_001F1368(void *a);
extern "C" void func_004F1F70(void *a, char *buf, s32 n);

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

static inline StringRep *rep(const String *str) { return (StringRep *)str->dat - 1; }
static inline void copy(String *str, const String *src) { str->dat = grab(rep(src)); }
static inline void deallocate(void *p, u32 n) { func_00326798(p, n, 4, func_005C11A8()->name); }
static inline void rep_delete(void *ptr) { deallocate(ptr, sizeof(StringRep) + ((StringRep *)ptr)->res); }
static inline void release(StringRep *r) { if (--r->ref == 0) rep_delete(r); }
static inline void destroy(String *str) { release(rep(str)); }

extern "C" String *func_001F23A8(String *ret, void *a1, s32 a2) {
    char buf[0x400];
    while (!func_004F1D18(D_00645570, a2 == 0))
        mUpdateContext__Sync(1);
    if (func_001F1368(a1) == 0) {
        construct(ret);
        return ret;
    }
    func_004F1F70(D_00645570, buf, 0x400);
    construct(ret, buf);
    return ret;
}
