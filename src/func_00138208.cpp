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

extern Rep D_00659FA8;

extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_0057F260(const char *s);
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00314B20(void *arg0, void *arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);
extern "C" void func_00137D60(void *arg0, int arg1);
extern "C" void func_00137DB8(void *arg0);
extern "C" const char *func_0013A718(s32 arg0);

extern "C" void func_00138208(s32 *arg0) {
    s32 tmp[4];
    s32 buf0[4];
    Str s;
    Str *ps;
    s32 newVal;
    s32 oldVal;
    const char *src;
    s32 *pb;
    func_00137DB8(tmp);
    ps = &s;
    src = func_0013A718(tmp[0]);
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
    pb = buf0;
    func_00314B20(pb, ps);
    if (arg0 != pb) {
        newVal = *pb;
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *arg0 = newVal;
    }
    func_00312318(pb, 2);
    {
        Rep *q = (Rep *)(ps->p - 0x10);
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
    }
    func_00137D60(tmp, 2);
}
