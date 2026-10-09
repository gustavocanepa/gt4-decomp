typedef int s32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct S00659988 {
    const char *name;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct Obj {
    void *p;
    char pad[0xC];
};

struct Handle {
    s32 v;
    char pad[0xC];
};

extern Rep D_00659FA8;

extern "C" void func_0013BDC0(Obj *);
extern "C" void func_0013BD68(Obj *, s32);
extern "C" void *func_00147D80(void *);
extern "C" void *func_00441248(void *);
extern "C" const char *func_00445450(void *);
extern "C" const char *func_005A6CF8(const char *, s32);
extern "C" s32 func_0013FBE8(s32) throw();
extern "C" void func_005C5028(Str *, char *, char *, const char *, const char *);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00314B20(void *arg0, void *arg1);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);
extern "C" s32 func_0057F260(const char *s);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *r);
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);

static inline char *grab(void)
{
    Rep *r = &D_00659FA8;
    char *d;
    if (r->sel != 0) {
        d = func_005C2560(r);
    } else {
        d = (char *)(r + 1);
        r->ref++;
    }
    return d;
}

static inline void release(Str *ps)
{
    Rep *q = (Rep *)(ps->p - 0x10);
    if (--q->ref == 0) {
        s32 cap = q->cap + 0x10;
        func_00326798(q, cap, 4, func_005C11A8()->name);
    }
}

static inline void assign(s32 *dst, Handle *h)
{
    if (dst != &h->v) {
        s32 newVal = h->v;
        s32 oldVal;
        if (newVal != 0)
            func_003285A8(newVal);
        oldVal = *dst;
        if (oldVal != 0)
            func_003285F8(oldVal);
        *dst = newVal;
    }
}

extern "C" void MCarGarage__get_short_name_no_year(s32 *out)
{
    Obj obj;
    Handle tmp;
    Str s1;
    Str s2;
    const char *name;
    const char *sep;

    func_0013BDC0(&obj);
    name = func_00445450(func_00441248(func_00147D80(obj.p)));
    sep = func_005A6CF8(name, '`');
    if (sep != 0 && func_0013FBE8(sep[1]) && func_0013FBE8(sep[2])) {
        Str *ps;
        char *d;
        {
            Rep *r = &D_00659FA8;
            ps = &s1;
            if (r->sel != 0) {
                d = func_005C2560(r);
            } else {
                d = (char *)(r + 1);
                r->ref++;
            }
            *(s32 *)&ps->p = (s32)d;
        }
        func_005C5028(ps, d, d + ((Rep *)d)[-1].len, name, sep);
        Handle *ph = &tmp;
        func_00314B20(ph, ps);
        assign(out, ph);
        func_00312318(ph, 2);
        release(ps);
    } else {
        const char *src;
        Str *ps = &s2;
        src = func_00445450(func_00441248(func_00147D80(obj.p)));
        {
            Rep *r = &D_00659FA8;
            char *d;
            if (r->sel != 0) {
                d = func_005C2560(r);
            } else {
                d = (char *)(r + 1);
                r->ref++;
            }
            ps->p = d;
        }
        func_005C2630(ps, 0, -1, src, func_0057F260(src));
        Handle *ph = &tmp;
        func_00314B20(ph, ps);
        assign(out, ph);
        func_00312318(ph, 2);
        release(ps);
    }
    func_0013BD68(&obj, 2);
}
