#define GT4_DECLS
#include "gt4/hObject.h"
/* Script module registration: creates the module object from its name, adds every class
   (func_003066F8 with each class getter), the three sub-modules (built by func_0030E100,
   func_00302110, HSystemModule__Get), three named functions and one method, then a global object. */
typedef int s32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

extern Rep D_00659FA8;
extern "C" char *func_005C2560(Rep *);
extern "C" s32 func_0057F260(void *);
extern "C" void *func_005C2630(void *, s32, s32, void *, s32);
extern "C" void *func_00306E00(void *, void *);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003066F8(s32, s32);
extern "C" void func_00306638(void *, s32, void *);
extern "C" void func_00323B60(void *, s32);
extern "C" void func_003041B8(void *, s32);
extern "C" void func_003041A0(void *, void *);
extern "C" void func_00306980(s32, void *, s32, void *);
extern "C" void func_003068A8(s32, void *, void *);
extern "C" void HModule__dynamicAssign(void *, void *);
extern "C" void *func_0030E100(void *);
extern "C" void *func_00302110(void *);
extern "C" void *HSystemModule__Get(void *);
extern "C" s32 hArray__GetClassID(void);
extern "C" s32 hArrayElement__GetClassID(void);
extern "C" s32 hClass__GetClassID(void);
extern "C" s32 hCode__GetClassID(void);
extern "C" s32 hException__GetClassID(void);
extern "C" s32 hFileIO__GetClassID(void);
extern "C" s32 hFloat__GetClassID(void);
extern "C" s32 hFunctionObject__GetClassID(void);
extern "C" s32 hIO__GetClassID(void);
extern "C" s32 hInt__GetClassID(void);
extern "C" s32 hLocalVariable__GetClassID(void);
extern "C" s32 hMethodObject__GetClassID(void);
extern "C" s32 hModule__GetClassID(void);
extern "C" s32 hModuleVariable__GetClassID(void);
extern "C" s32 hNil__GetClassID(void);
extern "C" s32 hNumeric__GetClassID(void);
extern "C" s32 hString__GetClassID(void);
extern "C" s32 hThread__GetClassID(void);
extern "C" s32 hThreadGroup__GetClassID(void);
extern "C" s32 hVariable__GetClassID(void);

extern char D_0069D6A8[];
extern char D_0069D6B8[];
extern char D_0069D6D0[];
extern char D_0069D6E8[];
extern char D_0069D700[];
extern char func_002F1C98[];
extern char func_002F1CA0[];
extern char func_002F1CA8[];
extern char adhoc__nilp[];
extern char D_0083CC90[];

#define STR_INIT(p, v)                                  \
    {                                                   \
        Rep *r = &D_00659FA8;                           \
        char *d;                                        \
        if (r->sel != 0) {                              \
            d = func_005C2560(r);                       \
        } else {                                        \
            d = (char *)(r + 1);                        \
            r->ref++;                                   \
        }                                               \
        p->p = d;                                       \
    }                                                   \
    func_005C2630(p, 0, -0x1, v, func_0057F260(v));

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

#define ADD_CLASS(getter) { s32 h = buf0[0]; func_003066F8(h, getter()); }

#define ADD_MODULE(t, make)                             \
    {                                                   \
        s32 h = buf0[0];                                \
        Str *v = &s;                                    \
        make(t);                                        \
        func_00306638(v, h, t);                         \
        func_00323B60(v, 2);                            \
        func_003041B8(t, 2);                            \
    }

#define ADD_FUNCTION(name, fn)                          \
    {                                                   \
        char *v = name;                                 \
        s32 h = buf0[0];                                \
        Str *p = &s;                                    \
        STR_INIT(p, v)                                  \
        func_00306980(h, p, 0, fn);                     \
        str_release(p);                                 \
    }

extern "C" s32 *HBuiltinModule__Get(s32 *arg0) {
    s32 buf0[4];
    Str s;
    Str name;
    s32 t1[4];
    s32 t2[4];
    s32 t3[4];
    s32 t4[4];
    {
        Str *p = &name;
        char *v = D_0069D6A8;
        STR_INIT(p, v)
        func_00306E00(buf0, p);
        str_release(p);
    }
    ADD_CLASS(hArray__GetClassID)
    ADD_CLASS(hArrayElement__GetClassID)
    ADD_CLASS(hClass__GetClassID)
    ADD_CLASS(hCode__GetClassID)
    ADD_CLASS(hException__GetClassID)
    ADD_CLASS(hFileIO__GetClassID)
    ADD_CLASS(hFloat__GetClassID)
    ADD_CLASS(hFunctionObject__GetClassID)
    ADD_CLASS(hIO__GetClassID)
    ADD_CLASS(hInt__GetClassID)
    ADD_CLASS(hLocalVariable__GetClassID)
    ADD_CLASS(hMethodObject__GetClassID)
    ADD_CLASS(hModule__GetClassID)
    ADD_CLASS(hModuleVariable__GetClassID)
    ADD_CLASS(hNil__GetClassID)
    ADD_CLASS(hNumeric__GetClassID)
    ADD_CLASS(hObject__GetClassID)
    ADD_CLASS(hString__GetClassID)
    ADD_CLASS(hThread__GetClassID)
    ADD_CLASS(hThreadGroup__GetClassID)
    ADD_CLASS(hVariable__GetClassID)
    ADD_MODULE(t1, func_0030E100)
    ADD_MODULE(t2, func_00302110)
    ADD_MODULE(t3, HSystemModule__Get)
    ADD_FUNCTION(D_0069D6B8, func_002F1C98)
    ADD_FUNCTION(D_0069D6D0, func_002F1CA0)
    ADD_FUNCTION(D_0069D6E8, func_002F1CA8)
    {
        char *v = D_0069D700;
        s32 h = buf0[0];
        Str *p = &s;
        STR_INIT(p, v)
        func_003068A8(h, p, adhoc__nilp);
        str_release(p);
    }
    HModule__dynamicAssign(&s, D_0083CC90);
    func_00306638(t4, buf0[0], &s);
    func_00323B60(t4, 2);
    func_003041A0(arg0, buf0);
    func_003041B8(&s, 2);
    func_003041B8(buf0, 2);
    return arg0;
}
