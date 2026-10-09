typedef int s32;

struct S { char pad[0x54]; s32 unk54; };

extern "C" s32 func_0025C2A0(S *arg0) {
    return arg0->unk54;
}
