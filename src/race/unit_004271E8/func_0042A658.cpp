typedef int s32;

struct S { char pad[0xC]; s32 unkC; };

extern "C" s32 func_0042A658(S *arg0) {
    return arg0->unkC;
}
