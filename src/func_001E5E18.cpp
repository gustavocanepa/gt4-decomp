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

struct Big {
    void *p;
    char pad[0x1C];
};

struct VEntry {
    short delta;
    short index;
    s32 (*fn)(void *);
};

struct VObj {
    char pad0[4];
    VEntry *vtbl;
};

extern Rep D_00659FA8;

extern "C" void func_001DC5F8(void *arg0, int arg1);
extern "C" void func_001DC650(void *arg0, void *arg1);
extern "C" void func_001F6B90(void *a, s32 b, char *buf);
extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_0057F260(const char *s);
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00314B20(void *arg0, void *arg1);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);

static inline s32 vcall(VObj *o) {
    VEntry *e = (VEntry *)((char *)o->vtbl + 0x58);
    return e->fn((char *)o + e->delta);
}

extern "C" void func_001E5E18(void **arg0, void *arg1, s32 arg2, VObj **arg3) {
    if (arg2 > 0) {
        char buf[0x80];
        Big h;
        Str s;
        Big *ph;
        Str *ps;
        const char *src;
        s32 v = vcall(*arg3);
        ph = &h;
        func_001DC650(ph, arg1);
        func_001F6B90(ph->p, v, buf);
        func_001DC5F8(ph, 2);
        {
            Rep *r = &D_00659FA8;
            char *d;
            ps = &s;
            src = buf;
            if (r->sel != 0) {
                d = func_005C2560(r);
            } else {
                d = (char *)(r + 1);
                r->ref++;
            }
            ps->p = d;
        }
        func_005C2630(ps, 0, -1, src, func_0057F260(src));
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
        {
            Rep *q = (Rep *)(ps->p - 0x10);
            if (--q->ref == 0) {
                s32 size = q->cap + 0x10;
                func_00326798(q, size, 4, func_005C11A8()->name);
            }
        }
    }
}
