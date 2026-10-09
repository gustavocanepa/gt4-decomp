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

struct Handle {
    void *p;
    char pad[0xC];
};

struct Obj;

extern Rep D_00659FA8;

extern "C" void func_0013BD68(void *arg0, int arg1);
extern "C" void func_0013BDC0(void *arg0, void *arg1);
extern "C" Obj *func_00147D80(void *arg0);
extern "C" s32 func_00441248(Obj *arg0);
extern "C" s32 func_00446038(s32 arg0);
extern "C" s32 func_00445D90(s32 arg0);
extern "C" void func_0057DA20(char *arg0, const char *arg1, ...);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00314B20(void *arg0, void *arg1);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);
extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_0057F260(const char *s);
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void MCarGarage__getCatLength(void **arg0, void *arg1) {
    Handle h;
    Obj *o;
    s32 n;
    func_0013BDC0(&h, arg1);
    o = func_00147D80(h.p);
    func_0013BD68(&h, 2);
    n = func_00446038(func_00441248(o));
    if (n == -1) {
        n = func_00445D90(func_00441248(o));
    }
    char buf[64] = "0";
    s32 spare[4];
    if (n != 0) {
        func_0057DA20(buf, "%d", n);
    }
    {
        Str s;
        Str *ps;
        Rep *r = &D_00659FA8;
        char *d;
        ps = &s;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        ps->p = d;
        func_005C2630(ps, 0, -1, buf, func_0057F260(buf));
        func_00314B20(&h, ps);
        if ((void *)arg0 != (void *)&h) {
            void *p = h.p;
            if (p != 0) {
                func_003285A8(p);
            }
            if (*arg0 != 0) {
                func_003285F8(*arg0);
            }
            *arg0 = p;
        }
        func_00312318(&h, 2);
        str_release(ps);
    }
}
