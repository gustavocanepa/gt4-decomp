/* Script module registration: creates the module object from its name, adds every class
   (func_003066F8 with each class getter), the three sub-modules (built by func_0030E100,
   func_00302110, func_00316EA8), three named functions and one method, then a global object. */
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
extern "C" void func_00306D98(void *, void *);
extern "C" void *func_0030E100(void *);
extern "C" void *func_00302110(void *);
extern "C" void *func_00316EA8(void *);
extern "C" s32 func_002ED768(void);
extern "C" s32 func_002F0F60(void);
extern "C" s32 func_002F2BB0(void);
extern "C" s32 func_002F43B8(void);
extern "C" s32 func_002F5650(void);
extern "C" s32 func_002F66E0(void);
extern "C" s32 func_002F7D10(void);
extern "C" s32 func_002F9CE0(void);
extern "C" s32 func_002FEC58(void);
extern "C" s32 func_002FCA18(void);
extern "C" s32 func_003013D0(void);
extern "C" s32 func_00302C28(void);
extern "C" s32 func_00304360(void);
extern "C" s32 func_003078D0(void);
extern "C" s32 func_00300780(void);
extern "C" s32 func_00308730(void);
extern "C" s32 func_00309CC0(void);
extern "C" s32 func_003124C0(void);
extern "C" s32 func_003186E0(void);
extern "C" s32 func_00322820(void);
extern "C" s32 func_00324618(void);

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

extern "C" s32 *func_002F1CB0(s32 *arg0) {
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
    ADD_CLASS(func_002ED768)
    ADD_CLASS(func_002F0F60)
    ADD_CLASS(func_002F2BB0)
    ADD_CLASS(func_002F43B8)
    ADD_CLASS(func_002F5650)
    ADD_CLASS(func_002F66E0)
    ADD_CLASS(func_002F7D10)
    ADD_CLASS(func_002F9CE0)
    ADD_CLASS(func_002FEC58)
    ADD_CLASS(func_002FCA18)
    ADD_CLASS(func_003013D0)
    ADD_CLASS(func_00302C28)
    ADD_CLASS(func_00304360)
    ADD_CLASS(func_003078D0)
    ADD_CLASS(func_00300780)
    ADD_CLASS(func_00308730)
    ADD_CLASS(func_00309CC0)
    ADD_CLASS(func_003124C0)
    ADD_CLASS(func_003186E0)
    ADD_CLASS(func_00322820)
    ADD_CLASS(func_00324618)
    ADD_MODULE(t1, func_0030E100)
    ADD_MODULE(t2, func_00302110)
    ADD_MODULE(t3, func_00316EA8)
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
    func_00306D98(&s, D_0083CC90);
    func_00306638(t4, buf0[0], &s);
    func_00323B60(t4, 2);
    func_003041A0(arg0, buf0);
    func_003041B8(&s, 2);
    func_003041B8(buf0, 2);
    return arg0;
}
