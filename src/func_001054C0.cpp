typedef int s32;

struct Obj {
    char pad[0x10];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
};

extern "C" void func_001054C0(Obj *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    arg0->unk10 = arg1;
    arg0->unk14 = arg2;
    arg0->unk18 = arg3;
    arg0->unk1C = arg4;
}
