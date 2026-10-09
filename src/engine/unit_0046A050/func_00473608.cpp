typedef int s32;

struct Obj {
    char pad[0x14];
    s32 unk14;
    s32 unk18;
    char pad3[0x8];
    s32 unk24;
};

extern "C" void func_00473608(Obj *arg0, s32 arg1, s32 arg2) {
    arg0->unk18 = arg1;
    arg0->unk24 = arg2;
    arg0->unk14 = 0;
}
