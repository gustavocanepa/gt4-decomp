typedef int s32;

struct Obj {
    char pad0[0xE8];
    s32 unkE8;
};

struct Sub {
    char pad0[4];
    s32 unk4;
    s32 unk8;
};

extern "C" s32 func_002B49D8(char *arg0) {
    s32 n = ((Obj *)arg0)->unkE8;
    arg0 = arg0 + (n * 0x10);
    arg0 = arg0 + 0xC8;
    Sub *p = (Sub *)arg0;
    return (s32)(p->unk8 - p->unk4) >> 2;
}
