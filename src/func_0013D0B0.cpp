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

extern Rep D_00659FA8;

extern "C" void func_0013BD68(void *arg0, int arg1);
extern "C" void func_0013BDC0(void *arg0, void *arg1);
extern "C" void func_00146278(void *arg0, const char *arg1, char *arg2);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00312370(void *arg0, void *arg1);
extern "C" Str *func_00314920(void *arg0);
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

extern "C" void func_0013D0B0(void **arg0, void *arg1, s32 arg2, void *arg3) {
    if (arg2 > 0) {
        Handle h0;
        Handle o;
        char buf[0x80];
        Handle h;
        Str s;
        Handle *po;

        func_00312370(&h0, arg3);
        po = &o;
        func_0013BDC0(po, arg1);
        {
            void *op = po->p;
            Str *t = func_00314920(h0.p);
            const char *c;
            s32 len = *(s32 *)(t->p - 0x10);
            if (len == 0) {
                c = "";
            } else {
                t->p[len] = 0;
                c = t->p;
            }
            func_00146278(op, c, buf);
        }
        {
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
            {
                Handle *ph = &h;
                func_00314B20(ph, ps);
                if ((void *)arg0 != (void *)ph) {
                    void *p = ph->p;
                    if (p != 0) {
                        func_003285A8(p);
                    }
                    if (*arg0 != 0) {
                        func_003285F8(*arg0);
                    }
                    *arg0 = p;
                }
                func_00312318(ph, 2);
            }
            str_release(ps);
        }
        func_0013BD68(po, 2);
        func_00312318(&h0, 2);
    }
}
