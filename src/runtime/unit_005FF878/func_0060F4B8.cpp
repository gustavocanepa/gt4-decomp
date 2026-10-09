typedef int s32;

struct S_0060F4B8 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    char pad0xC[0x40];
    void *unk4C;
};

extern "C" char D_006896B0[];

extern "C" void func_0060F4B8(struct S_0060F4B8 *arg0) {
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk4C = D_006896B0;
    arg0->unk8 = 0;
}
