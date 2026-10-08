typedef int s32;

struct Src {
    s32 unk0;
    s32 unk4;
};

struct Dst {
    char pad[0x1C];
    s32 unk1C;
    s32 unk20;
    s32 unk24;
};

extern "C" void func_00612DC8(Dst *arg0, Src *arg1) {
    s32 a = arg1->unk0;
    s32 sum = a + arg1->unk4;
    arg0->unk20 = a;
    arg0->unk24 = sum;
    arg0->unk1C = a;
}
