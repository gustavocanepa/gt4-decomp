struct Obj {
    char pad[0xC];
    int unkC;
    int unk10;
};

extern "C" void func_00453A48(Obj *arg0) {
    arg0->unkC = 0;
    arg0->unk10 = 0;
}
