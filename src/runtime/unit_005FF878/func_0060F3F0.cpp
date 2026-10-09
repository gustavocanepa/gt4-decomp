typedef int s32;
typedef unsigned int u32;

struct S {
    u32 unk0;
    char pad4[4];
    s32 unk8;
};

extern "C" void func_0060F3F0(S *arg0, s32 arg1) {
    u32 v0;
    s32 a2;
    s32 lt4;
    u32 sub;

    v0 = arg0->unk0;
    a2 = arg0->unk8;
    v0 = v0 + arg1;
    lt4 = (v0 < 4U);
    sub = v0 - 4U;
    v0 = lt4 ? v0 : sub;
    a2 = a2 + arg1;
    arg0->unk8 = a2;
    arg0->unk0 = v0;
}
