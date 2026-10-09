typedef int s32;
typedef unsigned char u8;

struct Struct_001CB378 {
    char pad0[4];
    s32 unk4;
    u8 *unk8;
    s32 unkC;
};

extern "C" s32 func_001CB378(struct Struct_001CB378 *arg0, s32 arg1, s32 arg2) {
    return arg0->unk4 + (arg0->unk8[arg1 * arg0->unkC + arg2] * 4);
}
