/* Returns 1 when MWidgetReader__structor_0(a0) is set; else passes basic_string<char>(D_0069ADE0) and a callback object (vtable D_00669E18, a0 + 0xB0) to func_0020FD38(a1, &s, &cb) and returns 1 on success; else passes basic_string<char>(D_0069ADE8) and a callback object (vtable MintReader__vtable, pointing at a local value) and on success stores the value at a0 + 0xC0 and returns 1, else 0. Each callback destructor resets the vtable and calls the base dtor MReaderBase__structor_0(&cb, 0); the two blocks' locals overlap in one union (bastring.h: (const char *) ctor = nilRep.grab() + assign(s, strlen(s)), dtor = rep()->release() -> func_00326798(p, sizeof(Rep) + res, 4, heap name)) */
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
extern char D_0069ADE0[];
extern char D_0069ADE8[];
extern void *D_00669E18[];
extern void *MintReader__vtable[];
struct Cb { void **vtbl; char *p; };
extern "C" s32 MWidgetReader__structor_0(void *a);
extern "C" s32 func_0020FD38(void *a, String *s, Cb *cb);
extern "C" void MReaderBase__structor_0(Cb *cb, s32 flags);

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

struct A { String s[8]; Cb cb; };
struct B { Cb cb; s32 pad[10]; s32 val[4]; String s; };
struct MintReader__structor_8_pcb {
    char pad0[0x4];
    char *unk4;
};

extern "C" s32 MintReader__structor_8(char *a0, void *a1) {
    if (MWidgetReader__structor_0(a0))
        return 1;
    union { A a; B b; } u;
    s32 r;
    {
        construct(u.a.s, D_0069ADE0);
        Cb *pcb = &u.a.cb;
        char *p = a0 + 0xB0;
        pcb->vtbl = D_00669E18;
        ((struct MintReader__structor_8_pcb *)pcb)->unk4 = p;
        r = func_0020FD38(a1, u.a.s, pcb);
        pcb->vtbl = D_00669E18;
        MReaderBase__structor_0(pcb, 0);
        destroy(u.a.s);
    }
    if (r)
        return 1;
    {
        String *ps = &u.b.s;
        construct(ps, D_0069ADE8);
        u.b.cb.vtbl = MintReader__vtable;
        u.b.cb.p = (char *)u.b.val;
        r = func_0020FD38(a1, ps, &u.b.cb);
        u.b.cb.vtbl = MintReader__vtable;
        MReaderBase__structor_0(&u.b.cb, 0);
        destroy(ps);
    }
    if (r) {
        *(s32 *)(a0 + 0xC0) = u.b.val[0];
        return 1;
    }
    return 0;
}
