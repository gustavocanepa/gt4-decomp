typedef int s32;

struct S_0060EA00 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    char pad0xC[0x400];
    void *unk40C;
};

extern "C" char D_00689680[];

extern "C" void func_0060EA00(struct S_0060EA00 *arg0) {
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk40C = D_00689680;
    arg0->unk8 = 0;
}
