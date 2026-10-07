typedef int s32;

struct Obj {
    char pad[0x14];
    s32 unk14;
    char pad2[0x1C - 0x14 - 4];
    s32 unk1C;
    s32 unk20;
};

extern "C" void func_00473620(Obj *arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg0->unk1C = arg1;
    arg0->unk20 = arg3;
    arg0->unk14 = 0;
}
