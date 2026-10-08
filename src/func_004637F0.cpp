typedef int s32;

struct S004637F0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    void *unk18;
};

extern "C" char D_006888A8[];

extern "C" void func_004637F0(struct S004637F0 *arg0) {
    arg0->unk0 = 0;
    arg0->unk18 = D_006888A8;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    arg0->unkC = 0;
    arg0->unk10 = 0;
    arg0->unk14 = 0;
}
