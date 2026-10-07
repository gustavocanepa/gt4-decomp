typedef int s32;

struct S_0060EAA0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    char pad0xC[0x280];
    void *unk28C;
};

extern "C" char D_00689650[];

extern "C" void func_0060EAA0(struct S_0060EAA0 *arg0) {
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk28C = D_00689650;
    arg0->unk8 = 0;
}
