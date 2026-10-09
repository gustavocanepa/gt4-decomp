typedef int s32;

struct Inner {
    char pad[4];
    s32 unk4;
    s32 unk8;
};

extern "C" s32 func_001D0678(s32 arg0, char *arg1) {
    Inner *p = (Inner *)(arg1 + 0xF8);
    return ((p->unk8 - p->unk4) + 0x47) & ~0x3F;
}
