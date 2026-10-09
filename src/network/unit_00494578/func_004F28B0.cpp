typedef int s32;

struct S004F28B0 {
    char pad0[0x5A8];
    s32 unk5A8;
};

extern "C" s32 func_004F28B0(S004F28B0 *arg0, s32 arg1) {
    s32 v0 = arg0->unk5A8;
    if (arg1 >= 0x10) {
        arg1 = 0xF;
    }
    return v0 + (arg1 << 7) + 0x1D8;
}
