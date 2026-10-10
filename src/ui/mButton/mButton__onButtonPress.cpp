/* mButton virtual 73 (event handler): forwards to mWidget__onButtonPress and keeps its result; on event kind 1 passes a basic_string<char>(D_0069A8B8) temporary to func_002308E8(a1, &s), calls mWidget__setActive(a0, 1) and returns 1 */
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
extern "C" void func_002308E8(void *a, String *s);
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

static inline StringRep *rep(const String *str) { return (StringRep *)str->dat - 1; }
static inline void deallocate(void *p, u32 n) { func_00326798(p, n, 4, func_005C11A8()->name); }
static inline void rep_delete(void *ptr) { deallocate(ptr, sizeof(StringRep) + ((StringRep *)ptr)->res); }
static inline void release(StringRep *r) { if (--r->ref == 0) rep_delete(r); }
static inline void destroy(String *str) { release(rep(str)); }
extern char D_0069A8B8[];
struct Event { char pad[0x20]; unsigned short kind; };
extern "C" s32 mWidget__onButtonPress(void *a, void *b, Event *c);
extern "C" void mWidget__setActive(void *a, s32 b);

extern "C" s32 mButton__onButtonPress(void *a0, void *a1, Event *a2) {
    s32 r = mWidget__onButtonPress(a0, a1, a2);
    if (a2->kind == 1) { String s; construct(&s, D_0069A8B8); func_002308E8(a1, &s); destroy(&s); mWidget__setActive(a0, 1); return 1; } return r; }
