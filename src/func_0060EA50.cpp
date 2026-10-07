typedef int s32;

struct S_0060EA50 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    char pad0xC[0x240];
    void *unk24C;
};

extern "C" char D_00689668[];

extern "C" void func_0060EA50(struct S_0060EA50 *arg0) {
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk24C = D_00689668;
    arg0->unk8 = 0;
}
