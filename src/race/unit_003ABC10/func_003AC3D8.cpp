struct Obj {
    char pad0[0x18];
    int unk18;
    char pad1C[0x6C - 0x1C];
    int unk6C;
};

extern "C" void func_003AC3D8(Obj *arg0, int arg1) {
    arg0->unk6C = arg1;
    arg0->unk18 = 0;
}
