typedef int s32;

struct S_00600240 {
    s32 unk0;
    void *unk4;
    s32 unk8;
    s32 unkC;
};

extern "C" char D_00686690[];

extern "C" void func_00600240(struct S_00600240 *arg0, s32 arg1, s32 arg2) {
    arg0->unkC = arg2;
    arg0->unk8 = arg1;
    arg0->unk4 = D_00686690;
    arg0->unk0 = 0;
}
