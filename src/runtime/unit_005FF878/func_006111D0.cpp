typedef int s32;

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    char pad0x10[0x1C - 0x10];
    s32 unk1C;
    s32 unk20;
};

extern "C" void func_006111D0(Obj *arg0) {
    s32 temp_v1;

    temp_v1 = arg0->unk0;
    arg0->unk8 = 0;
    arg0->unk1C = temp_v1;
    arg0->unkC = arg0->unk4;
    arg0->unk20 = temp_v1;
}
