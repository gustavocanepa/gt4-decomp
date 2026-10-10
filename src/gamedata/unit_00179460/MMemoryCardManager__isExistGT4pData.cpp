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

struct Obj;

struct H {
    char pad0[0x1C];
    Obj *p1C;
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
extern "C" void func_00179280(void *arg0, int arg1);
extern "C" void *func_001792D8(void *arg0);
extern "C" s32 func_001D4610(Obj *arg0);
extern "C" const char *GT4MC__getFileResultString(s32 arg0);

static inline H *get(H **p) {
    return *p;
}

extern "C" void MMemoryCardManager__isExistGT4pData(s32 *arg0) {
    H *buf[8];
    Str s;
    Str *ps;
    s32 newVal;
    s32 oldVal;
    s32 id;
    const char *src;
    func_001792D8(buf);
    id = func_001D4610(get(buf)->p1C);
    func_00179280(buf, 2);
    ps = &s;
    src = GT4MC__getFileResultString(id);
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
    func_00314B20(buf, ps);
    if ((void *)arg0 != (void *)buf) {
        newVal = (s32)buf[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *arg0 = newVal;
    }
    func_00312318(buf, 2);
    {
        Rep *q = (Rep *)(ps->p - 0x10);
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
    }
}
