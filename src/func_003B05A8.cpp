struct Obj {
    int unk0;
    char pad4[4];
    int unk8;
    char pad54[0x54 - 0xC];
    int unk54;
};

extern "C" void func_003B05A8(Obj *arg0) {
    arg0->unk0 = 0;
    arg0->unk8 = 0;
    arg0->unk54 = 0;
}
