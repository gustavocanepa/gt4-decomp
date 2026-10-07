struct Obj {
    char pad0[0x1C];
    int unk1C;
    int unk20;
};

extern "C" void func_00565B88(Obj *arg0, int arg1, int arg2) {
    arg0->unk1C = arg1;
    arg0->unk20 = arg2;
}
