/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; int pad[3]; };
struct Ref { char *p; int pad[3]; };
struct VE { s16 delta; s16 idx; void (*fn)(void *, char *, s32); };

extern Rep D_00659FA8;
extern char D_005D15A8[];
extern char D_005D1260[];

extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_0057F260(const char *s) throw();
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_001740F0(void *arg0, int arg1) throw();
extern "C" void func_00174148(void *arg0, void *arg1) throw();
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00314B20(void *arg0, void *arg1);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);
extern "C" s32 __dynamic_cast_2(void *a, void *b, s32 c, void *d, void *e, void *f);

static inline void assign(Ref *d, Ref *s) {
    if (d != s) {
        char *q = s->p;
        if (q) func_003285A8(q);
        if (d->p) func_003285F8(d->p);
        d->p = q;
    }
}

extern "C" void MMemoryCardFile__get_time(Ref *out, void *a1) {
    Ref a;
    char buf[16];
    Ref r;
    Str s;
    char *obj;
    char *inst = 0;
    func_00174148(&a, a1);
    obj = *(char **)(a.p + 0x10);
    if (obj) {
        char *desc = *(char **)(obj + 0x4C);
        inst = (char *)__dynamic_cast_2(*(void **)(desc + 4), D_005D15A8, 0,
                                     obj + *(s16 *)desc, D_005D1260, obj);
    }
    buf[0] = 0;
    if (inst) {
        VE *e = (VE *)(*(char **)(inst + 0x4C) + 0xC0);
        e->fn(inst + e->delta, buf, 16);
    }
    Str *ps = &s;
    {
        Rep *rp = &D_00659FA8;
        char *d;
        if (rp->sel != 0) {
            d = func_005C2560(rp);
        } else {
            d = (char *)(rp + 1);
            rp->ref++;
        }
        ps->p = d;
        func_005C2630(ps, 0, -1, buf, func_0057F260(buf));
    }
    func_00314B20(&r, ps);
    assign(out, &r);
    func_00312318(&r, 2);
    {
        Rep *q = (Rep *)(ps->p - 0x10);
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
    }
    func_001740F0(&a, 2);
}
