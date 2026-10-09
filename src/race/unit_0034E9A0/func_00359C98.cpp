typedef int s32;
typedef unsigned char u8;

struct Inner_00359C98 {
    char pad[0x14C];
    s32 unk14C;
};

struct Obj_00359C98 {
    char pad0[4];
    s32 unk4;
    char pad8[0xC - 8];
    Inner_00359C98 *unkC;
    char pad10[0x544 - 0x10];
    u8 unk544;
};

extern "C" s32 func_0035ABA8(s32 arg0, u8 arg1, s32 arg2);

extern "C" s32 func_00359C98(Obj_00359C98 *arg0, s32 arg1) {
    return func_0035ABA8(arg0->unk4, arg0->unk544, arg0->unkC->unk14C + arg1 * 0x14F4);
}
