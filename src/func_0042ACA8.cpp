typedef int s32;

struct S_0042ACA8 {
    s32 unk0;
    void *unk4;
    s32 unk8;
    s32 unkC;
};

extern "C" char D_00686F40[];

extern "C" void func_0042ACA8(S_0042ACA8 *arg0, s32 arg1) {
    arg0->unkC = arg1;
    arg0->unk8 = 0;
    arg0->unk4 = D_00686F40;
    arg0->unk0 = 0;
}
