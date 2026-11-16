/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; int pad[3]; };
struct Ref { char *p; int pad[7]; };
struct VE { s16 delta; s16 idx; char *(*fn)(void *); };

extern Rep D_00659FA8;
extern char D_005D15A8[];
extern char D_005D1260[];
extern char D_00690D18[];

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

extern "C" void MMemoryCardFile__get_racemode(Ref *out, void *a1) {
    char *obj;
    char *inst = 0;
    char *name;
    Ref a;
    func_00174148(&a, a1);
    obj = *(char **)(a.p + 0x10);
    if (obj) {
        char *desc = *(char **)(obj + 0x4C);
        inst = (char *)__dynamic_cast_2(*(void **)(desc + 4), D_005D15A8, 0,
                                     obj + *(s16 *)desc, D_005D1260, obj);
    }
    func_001740F0(&a, 2);
    Str s;
    Str *ps = &s;
    if (inst) {
        VE *e = (VE *)(*(char **)(inst + 0x4C) + 0xA8);
        name = e->fn(inst + e->delta);
    } else {
        name = D_00690D18;
    }
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
        func_005C2630(ps, 0, -1, name, func_0057F260(name));
    }
    func_00314B20(&a, ps);
    assign(out, &a);
    func_00312318(&a, 2);
    {
        Rep *q = (Rep *)(ps->p - 0x10);
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
    }
}
