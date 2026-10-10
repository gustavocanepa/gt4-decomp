/* mScrollPinch virtual 74 (release handler): keeps mWidget__onButtonRelease result; on event kind 1 clears pressed, releases the widget grab (func_0022F248(a1, 0), clears flag 0x10), sends one of two basic_string<char> names through one String local depending on whether func_0022F350(a1) is this, then forwards to the target (func_002D2DD8 / func_002D2F20) */
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
extern char D_0069CA98[];
extern char D_0069CAA8[];
struct Event { char pad[0x20]; unsigned short kind; char pad2[6]; float x; float y; };
struct Widget { char pad[0x6E8]; u32 flags; };
struct Pinch { char pad[0xB0]; void *target; s32 vertical; float offset; };
extern "C" s32 mWidget__onButtonRelease(Pinch *a, Widget *b, Event *c);
extern "C" void mWidget__setActive(Pinch *a, s32 b);
extern "C" void func_0022F248(Widget *a, Pinch *b);
extern "C" Pinch *func_0022F350(Widget *a);
extern "C" s32 func_002D2DD8(void *t, Widget *b, Event *c);
extern "C" s32 func_002D2F20(void *t, Widget *b, Event *c);

extern "C" s32 mScrollPinch__onButtonRelease(Pinch *a0, Widget *a1, Event *a2) {
    s32 r = mWidget__onButtonRelease(a0, a1, a2);
    if (a2->kind == 1) {
        mWidget__setActive(a0, 0);
        func_0022F248(a1, 0);
        a1->flags &= ~0x10;
        String s;
        if (func_0022F350(a1) == a0) {
            construct(&s, D_0069CA98);
            func_002308E8(a1, &s);
            destroy(&s);
        } else {
            construct(&s, D_0069CAA8);
            func_002308E8(a1, &s);
            destroy(&s);
        }
        if (a0->target == 0)
            return 1;
        if (a0->vertical != 0)
            return func_002D2DD8(a0->target, a1, a2);
        return func_002D2F20(a0->target, a1, a2);
    }
    return r;
}
