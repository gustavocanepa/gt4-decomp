struct Obj4735F8 {
    char pad[0x8];
    int unk8;
    char pad2[0x14 - 0x8 - 4];
    int unk14;
};

extern "C" void func_004735F8(Obj4735F8 *arg0) {
    arg0->unk8 = 0;
    arg0->unk14 = 0;
}
