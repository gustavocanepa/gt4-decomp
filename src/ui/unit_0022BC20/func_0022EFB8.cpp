typedef int s32;

struct Sub {
    char pad0[4];
    s32 unk4;
    s32 unk8;
};

extern "C" s32 func_0022EFB8(char *arg0) {
    Sub *p0 = (Sub *)(arg0 + 0x14);
    Sub *p1 = (Sub *)(arg0 + 0x34);

    return ((s32)(p0->unk8 - p0->unk4) >> 2) + ((s32)(p1->unk8 - p1->unk4) >> 2);
}
