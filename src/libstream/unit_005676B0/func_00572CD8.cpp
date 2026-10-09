typedef int s32;

struct S00572CD8 {
    char pad0[0x14];
    s32 unk14;
    char pad18[0x28 - 0x18];
    s32 unk28;
    char pad2C[0x40 - 0x2C];
    s32 unk40;
    void *unk44;
};

extern "C" char D_00689D68[];

extern "C" void func_00572CD8(struct S00572CD8 *arg0) {
    arg0->unk40 = 0;
    arg0->unk28 = 0;
    arg0->unk44 = D_00689D68;
    arg0->unk14 = 0;
}
