typedef int s32;
typedef unsigned short u16;

struct S0050F3A8 {
    char pad0[0x64];
    u16 unk64;
};

extern "C" s32 func_00510C38(struct S0050F3A8 *arg0, u16 arg1, s32 arg2);

extern "C" s32 func_0050F3A8(s32 arg0, struct S0050F3A8 *arg1) {
    return func_00510C38(arg1, arg1->unk64, arg0);
}
