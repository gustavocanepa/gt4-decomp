typedef int s32;

struct S_0060EBF0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    char pad0xC[0x1000];
    void *unk100C;
};

extern "C" char D_00689620[];

extern "C" void func_0060EBF0(struct S_0060EBF0 *arg0) {
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk100C = D_00689620;
    arg0->unk8 = 0;
}
