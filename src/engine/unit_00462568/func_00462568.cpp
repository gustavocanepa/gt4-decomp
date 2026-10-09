typedef int s32;

struct Obj {
    s32 unk0;
    s32 unk4;
    char pad8[0xC - 0x4 - 0x4];
    s32 unkC;
    s32 unk10;
    char pad14[0x18 - 0x10 - 0x4];
    s32 unk18;
};

extern "C" void func_00462568(Obj *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    arg0->unk0 = 1;
    arg0->unk4 = arg1;
    arg0->unkC = arg2;
    arg0->unk10 = arg3;
    arg0->unk18 = arg4;
}
