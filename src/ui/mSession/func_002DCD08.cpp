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
};

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, Str *);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

extern Rep D_00659FA8;

extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_0057F260(const char *s);
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" int func_00309CC0(void);
extern "C" void func_002F3A30(Obj *arg0, s32 arg1);

extern "C" void func_002DCD08(Obj *arg0) {
    Str s;
    Str *ps = &s;
    const char *src = "MUpdateContextPS2";
    Rep *r = &D_00659FA8;
    char *d = (char *)(r + 1);
    if (r->sel != 0) {
        d = func_005C2560(r);
    } else {
        r->ref++;
    }
    ps->p = d;
    func_005C2630(ps, 0, -1, src, func_0057F260(src));
    {
        VEntry *e = (VEntry *)(arg0->vtbl + 0x190);
        e->fn((char *)arg0 + e->delta, &s);
    }
    {
        Rep *q = (Rep *)(s.p - 0x10);
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
    }
    func_002F3A30(arg0, func_00309CC0());
}
