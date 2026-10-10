/* mScrollPinch virtual 73 (press handler): keeps mWidget__onButtonPress result; on event kind 1 sets pressed, grabs the widget (func_0022F248, flag 0x10), passes a basic_string<char>(D_0069CAB0) temporary to func_002308E8, stores the press offset along the scroll axis and forwards to the target (func_002D2DC0 / func_002D2F08) */
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
extern char D_0069CAB0[];
struct Event { char pad[0x20]; unsigned short kind; char pad2[6]; float x; float y; };
struct Widget { char pad[0x6E8]; u32 flags; };
struct Pinch { char pad[0xB0]; void *target; s32 vertical; float offset; };
extern "C" s32 mWidget__onButtonPress(Pinch *a, Widget *b, Event *c);
extern "C" void mWidget__setActive(Pinch *a, s32 b);
extern "C" void func_0022F248(Widget *a, Pinch *b);
extern "C" void func_0025BA38(Pinch *a, float *x, float *y);
extern "C" s32 func_002D2DC0(void *t, Widget *b, Event *c);
extern "C" s32 func_002D2F08(void *t, Widget *b, Event *c);

extern "C" s32 mScrollPinch__onButtonPress(Pinch *a0, Widget *a1, Event *a2) {
    s32 r = mWidget__onButtonPress(a0, a1, a2);
    if (a2->kind == 1) {
        mWidget__setActive(a0, 1);
        func_0022F248(a1, a0);
        a1->flags |= 0x10;
        {
            String s;
            construct(&s, D_0069CAB0);
            func_002308E8(a1, &s);
            destroy(&s);
        }
        float p[2];
        func_0025BA38(a0, &p[0], &p[1]);
        if (a0->vertical != 0)
            a0->offset = a2->x - p[0];
        else
            a0->offset = a2->y - p[1];
        if (a0->target == 0)
            return 1;
        if (a0->vertical != 0)
            return func_002D2DC0(a0->target, a1, a2);
        return func_002D2F08(a0->target, a1, a2);
    }
    return r;
}
