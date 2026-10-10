struct Obj {
    char pad0[0x148];
    int kind;
    char pad14C[0x1C0 - 0x14C];
    int a[3];
    int b[3];
};

extern "C" void func_00400C78(Obj *o);
extern "C" void func_005A48D8(void *p, int c, int n);

extern "C" void func_003843F0(Obj *o) {
    func_00400C78(o);
    o->kind = 0x11;
    func_005A48D8(o->a, 0, sizeof(o->a));
    func_005A48D8(o->b, 0, sizeof(o->b));
}
