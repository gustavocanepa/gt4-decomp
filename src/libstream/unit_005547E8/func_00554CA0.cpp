struct Obj {
    char pad0[0x1C];
    int base;
    char pad20[0x2C - 0x20];
    int offset;
    int f30;
    int func_005AE360;
};

extern "C" int func_005B72A8(void);
extern "C" void func_005B72F8(void);

extern "C" int func_00554CA0(Obj *o) {
    func_005B72A8();
    if (o->func_005AE360 == 0) {
        func_005B72F8();
        return 0;
    }
    int pos = o->base + o->offset;
    func_005B72F8();
    return pos;
}
