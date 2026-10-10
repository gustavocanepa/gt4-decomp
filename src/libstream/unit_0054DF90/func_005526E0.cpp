struct Obj {
    int f0;
    int f4;
    int f8;
    int fC;
    char a[0x40];
    char b[0x40];
};

extern "C" void func_005A48D8(void *p, int c, int n);

extern "C" void func_005526E0(Obj *o) {
    o->f0 = 0;
    o->f4 = 0;
    o->f8 = 0;
    o->fC = 0;
    func_005A48D8(o->a, 0, sizeof(o->a));
    func_005A48D8(o->b, 0, sizeof(o->b));
}
