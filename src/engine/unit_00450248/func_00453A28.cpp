typedef int s32;

struct Obj00453A28 {
    char pad[8];
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
};

extern "C" void func_00453A28(Obj00453A28 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    arg0->unk8 = arg1;
    arg0->unkC = arg2;
    arg0->unk10 = arg3;
    arg0->unk14 = arg4;
    arg0->unk18 = 0;
    arg0->unk1C = 0;
}
