typedef int s32;

struct Sub {
    char pad0[4];
    s32 unk4;
    s32 unk8;
};

extern "C" s32 func_005EE260(char *arg0) {
    Sub *p = (Sub *)(arg0 + 0x2C);
    return (s32)(p->unk8 - p->unk4) >> 2;
}
