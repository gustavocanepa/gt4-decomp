/* mButton virtual 74 (release handler): keeps mWidget__onButtonRelease result; on event kind 1 sends a basic_string<char>(D_0069A8A0) through func_002308E8, and if func_00265FE0 (pressed) clears it, gets a handle via func_00277850(&h, a1, this), calls its vtable slot 0x190 and releases it (func_00277438(&h, 2)); string and handle share one stack slot (union) */
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
extern char D_0069A8A0[];
struct Event { char pad[0x20]; unsigned short kind; };
struct VObj { char pad0[4]; char *vtbl; };
struct VEntry { short delta; short index; s32 (*fn)(void *); };
extern "C" s32 mWidget__onButtonRelease(void *a, void *b, Event *c);
extern "C" s32 func_00265FE0(void *a);
extern "C" void mWidget__setActive(void *a, s32 b);
extern "C" void func_00277850(void *h, void *a, void *b);
extern "C" void func_00277438(void *h, s32 n);

static inline void vcall_190(VObj *o) {
    VEntry *e = (VEntry *)(o->vtbl + 0x190);
    e->fn((char *)o + e->delta);
}

extern "C" s32 mButton__onButtonRelease(void *a0, void *a1, Event *a2) {
    s32 r = mWidget__onButtonRelease(a0, a1, a2);
    if (a2->kind == 1) {
        union { String s; VObj *h; } u;
        construct(&u.s, D_0069A8A0);
        func_002308E8(a1, &u.s);
        destroy(&u.s);
        if (func_00265FE0(a0) != 0) {
            mWidget__setActive(a0, 0);
            func_00277850(&u.h, a1, a0);
            vcall_190(u.h);
            func_00277438(&u.h, 2);
        }
        return 1;
    }
    return r;
}
