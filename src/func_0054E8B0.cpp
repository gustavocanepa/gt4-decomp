struct Obj {
    char pad0[0x198];
    int f198;
    char pad19C[0x2C0 - 0x19C];
    char sub2C0[0x404 - 0x2C0];
    int f404;
};

extern "C" void func_0054EA08(Obj *o);
extern "C" void func_0054E3D8(Obj *o);
extern "C" void func_00574EE8(void *p);

extern "C" void func_0054E8B0(Obj *o) {
    func_0054EA08(o);
    if (o->f198) {
        func_0054E3D8(o);
    }
    o->f404 = 0;
    func_00574EE8(o->sub2C0);
}
