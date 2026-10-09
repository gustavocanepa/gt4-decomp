typedef int s32;

struct Struct_001D1720 {
    char pad0[0x4];
    s32 unk4;
};

extern "C" s32 func_0054C7B0(s32 arg0);

extern "C" s32 func_001D1720(struct Struct_001D1720 *arg0) {
    return func_0054C7B0(arg0->unk4) == 2;
}
