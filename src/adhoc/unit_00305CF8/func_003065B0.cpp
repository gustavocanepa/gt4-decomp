typedef int s32;

struct Inner {
    char pad[0x8];
    s32 unk8;
};

struct Arg1 {
    char pad[0x1C];
    Inner *unk1C;
};

extern "C" s32 *func_003065B0(s32 *arg0, Arg1 *arg1) {
    *arg0 = arg1->unk1C->unk8;
    return arg0;
}
