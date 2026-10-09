/* Returns 1 when MfloatReader__structor_6(a0) is set; else passes basic_string<char>(D_0069B698) and a callback object (vtable MintReader__vtable, pointing at a local value; its destructor resets the vtable and calls the base dtor MReaderBase__structor_0(&cb, 0)) to func_0020FD38(a1, &s, &cb); on success stores the value at a0 + 0xB8 and returns 1, else 0. The string slot is 0x20 bytes in the original frame (bastring.h: (const char *) ctor = nilRep.grab() + assign(s, strlen(s)), dtor = rep()->release() -> func_00326798(p, sizeof(Rep) + res, 4, heap name)) */
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
extern char D_0069B698[];
extern void *MintReader__vtable[];
struct Cb { void **vtbl; char *p; };
extern "C" s32 MfloatReader__structor_6(void *a);
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

extern "C" s32 MintReader__structor_9(char *a0, void *a1) {
    if (MfloatReader__structor_6(a0))
        return 1;
    s32 val[4];
    String s[8];
    Cb cb;
    construct(s, D_0069B698);
    Cb *pcb = &cb;
    pcb->vtbl = MintReader__vtable;
    pcb->p = (char *)val;
    s32 r = func_0020FD38(a1, s, pcb);
    pcb->vtbl = MintReader__vtable;
    MReaderBase__structor_0(pcb, 0);
    destroy(s);
    if (r) {
        *(s32 *)(a0 + 0xB8) = val[0];
        return 1;
    }
    return 0;
}
