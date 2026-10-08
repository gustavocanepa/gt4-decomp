typedef int s32;

extern char D_00683288;

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    char pad10[0x54 - 0xC - 4];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    char pad60[0x64 - 0x5C - 4];
    s32 unk64;
};

extern "C" void func_003DEE70(Obj *arg0) {
    arg0->unk64 = -1;
    arg0->unkC = (s32)&D_00683288;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    arg0->unk54 = 0;
    arg0->unk58 = 0;
    arg0->unk5C = 0;
    arg0->unk0 = 0;
}
