typedef int s32;

struct S { char pad0[4]; s32 unk4; };

extern "C" s32 func_0042A3C8(S *arg0, s32 arg1) {
    return arg0->unk4 + (arg1 << 5);
}
