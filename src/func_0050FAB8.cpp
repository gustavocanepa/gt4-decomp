typedef int s32;
typedef unsigned short u16;

struct S0050F3C8 {
    char pad0[0x64];
    u16 unk64;
};

extern "C" s32 func_0057F188(s32 arg0, struct S0050F3C8 *arg1, u16 arg2);

extern "C" s32 func_0050FAB8(s32 arg0, struct S0050F3C8 *arg1) {
    return func_0057F188(arg0, arg1, arg1->unk64) == 0;
}
