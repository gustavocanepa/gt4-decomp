typedef int s32;

struct S_005FE1C8 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    void *unkC;
};

extern "C" char D_00683320[];

extern "C" void func_005FE1C8(struct S_005FE1C8 *arg0) {
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unkC = D_00683320;
    arg0->unk8 = 0;
}
