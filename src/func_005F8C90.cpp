typedef int s32;

struct Obj {
    char pad[0x54];
    s32 unk54;
};

extern "C" void func_005F8C90(Obj *arg0, s32 arg1) {
    s32 v = arg0->unk54;
    v = v & 0xFFFFFF;
    v = v | (arg1 << 24);
    arg0->unk54 = v;
}
