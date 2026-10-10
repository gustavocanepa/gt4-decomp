typedef int s32;

struct P {
    s32 a, b;
};

struct L {
    s32 x, y;
    s32 a, b;
};

struct Ret {
    s32 w[4];
};

extern "C" void func_004AE330(Ret *, void *, L *, s32);

extern "C" Ret *func_004AE2E8(Ret *ret, void *self, P *p, s32 arg) {
    L l;
    l.x = 0;
    l.y = 0;
    l.a = p->a;
    l.b = p->b;
    func_004AE330(ret, self, &l, arg);
    return ret;
}
