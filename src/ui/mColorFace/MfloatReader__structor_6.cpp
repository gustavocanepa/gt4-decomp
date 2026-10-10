/* Returns 1 when mSlideShowFace__virtual_61(a0) is set; else tries 3 settings in turn, each passing basic_string<char>(name) and a callback object (vtable + a pointer into a0, or to a local value copied into a0 on success; its destructor resets the vtable and calls the base dtor MReaderBase__structor_0(&cb, 0)) to func_0020FD38(a1, &s, &cb), returning 1 at the first success. Each block's locals are one struct of a union laid out as in the original frame (bastring.h: (const char *) ctor = nilRep.grab() + assign(s, strlen(s)), dtor = rep()->release() -> func_00326798(p, sizeof(Rep) + res, 4, heap name)) */
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
extern char D_0069AC50[];
extern char D_0069AC58[];
extern char D_0069AC60[];
extern void *D_00669E18[];
extern void *MfloatReader__vtable[];
extern void *MintReader__vtable[];
struct Cb { void **vtbl; char *p; };
extern "C" s32 mSlideShowFace__virtual_61(void *a);
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

struct B0 {
    String s;
    char pad0[28];
    Cb cb;
};
struct B1 {
    String s;
    char pad0[60];
    Cb cb;
};
struct B2 {
    String s;
    char pad0[12];
    Cb cb;
    char pad1[56];
    s32 val;
};
struct MfloatReader__structor_6_pcb {
    char pad0[0x4];
    char *unk4;
};

extern "C" s32 MfloatReader__structor_6(char *a0, void *a1) {
    if (mSlideShowFace__virtual_61(a0))
        return 1;
    union { B0 b0; B1 b1; B2 b2; } u;
    s32 r;
    {
        construct(&u.b0.s, D_0069AC50);
        Cb *pcb = &u.b0.cb;
        char *p = a0 + 0xA0;
        pcb->vtbl = D_00669E18;
        ((struct MfloatReader__structor_6_pcb *)pcb)->unk4 = p;
        r = func_0020FD38(a1, &u.b0.s, pcb);
        pcb->vtbl = D_00669E18;
        MReaderBase__structor_0(pcb, 0);
        destroy(&u.b0.s);
    }
    if (r)
        return 1;
    {
        construct(&u.b1.s, D_0069AC58);
        Cb *pcb = &u.b1.cb;
        char *p = a0 + 0xB0;
        pcb->vtbl = MfloatReader__vtable;
        ((struct MfloatReader__structor_6_pcb *)pcb)->unk4 = p;
        r = func_0020FD38(a1, &u.b1.s, pcb);
        pcb->vtbl = MfloatReader__vtable;
        MReaderBase__structor_0(pcb, 0);
        destroy(&u.b1.s);
    }
    if (r)
        return 1;
    {
        construct(&u.b2.s, D_0069AC60);
        Cb *pcb = &u.b2.cb;
        pcb->vtbl = MintReader__vtable;
        pcb->p = (char *)&u.b2.val;
        r = func_0020FD38(a1, &u.b2.s, pcb);
        pcb->vtbl = MintReader__vtable;
        MReaderBase__structor_0(pcb, 0);
        destroy(&u.b2.s);
    }
    if (r) {
        *(s32 *)(a0 + 0xB4) = u.b2.val;
        return 1;
    }
    return 0;
}
