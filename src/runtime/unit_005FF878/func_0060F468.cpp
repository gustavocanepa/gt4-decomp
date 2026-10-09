typedef int s32;

struct S_0060F468 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    char pad0xC[0x2010];
    void *unk201C;
};

extern "C" char D_006896E0[];

extern "C" void func_0060F468(struct S_0060F468 *arg0) {
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk201C = D_006896E0;
    arg0->unk8 = 0;
}
