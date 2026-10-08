typedef int s32;

struct VEntry {
    short delta;
    short index;
    s32 (*fn)(void *);
};

struct VObj {
    char pad0[4];
    VEntry *vtbl;
};

struct Pair2 {
    VObj *a;
    VObj *b;
};

struct S;

struct Handle {
    S *p;
    char pad[0xC];
};

extern "C" void func_0013BD68(void *arg0, int arg1);
extern "C" void func_0013BDC0(void *arg0, void *arg1);
extern "C" int func_00147D80(S *arg0);
extern "C" void func_0043EB38(s32 a, s32 b);

static inline s32 vcall(VObj *o) {
    VEntry *e = (VEntry *)((char *)o->vtbl + 0x58);
    return e->fn((char *)o + e->delta);
}

extern "C" void func_0014D8C8(void *arg0, void *arg1, s32 arg2, Pair2 *arg3) {
    Handle h;
    s32 a;
    s32 b;

    func_0013BDC0(&h, arg1);
    a = func_00147D80(h.p);
    func_0013BD68(&h, 2);
    b = vcall(arg3->b);
    if (vcall(arg3->a) == 0) {
        func_0043EB38(a, b);
    }
}
