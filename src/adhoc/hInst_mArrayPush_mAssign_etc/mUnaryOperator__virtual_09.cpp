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

struct W {
    s32 v;
};

struct P8 {
    s32 a;
    s32 b;
};

struct Self {
    char pad0[8];
    W m8;
    P8 mC;
};

struct WTmp {
    W w;
    char pad[0xC];
};

extern Rep D_00659FA8;

extern "C" void func_002FFA40(void *arg0, Str *s);
extern "C" P8 func_0030B358(W *w);
extern "C" s32 func_003166B8(Str *s);
extern "C" char *func_005C2560(Rep *r);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);

extern "C" void mUnaryOperator__virtual_09(Self *self, void *arg1) {
    Str s;
    WTmp t;
    W *dst = &self->m8;
    W *pt;
    {
        Rep *r = &D_00659FA8;
        char *d = (char *)(r + 1);
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            r->ref++;
        }
        s.p = d;
    }
    func_002FFA40(arg1, &s);
    pt = &t.w;
    pt->v = func_003166B8(&s);
    if (dst != pt) {
        dst->v = pt->v;
    }
    {
        P8 r = func_0030B358(dst);
        self->mC = r;
    }
    {
        Rep *q = (Rep *)(s.p - 0x10);
        if (--q->ref == 0) {
            s32 size = q->cap + 0x10;
            func_00326798(q, size, 4, func_005C11A8()->name);
        }
    }
}
