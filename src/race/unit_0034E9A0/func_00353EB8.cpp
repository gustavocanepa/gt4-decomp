typedef int s32;
typedef unsigned char u8;

struct Obj00353EB8 {
    char pad0[4];
    s32 unk4;
    char pad8[0x544 - 8];
    u8 unk544;
};

extern "C" s32 func_00353EB8(struct Obj00353EB8 *arg0) {
    return arg0->unk4 + (arg0->unk544 * 0x10) + 0xCA58;
}
