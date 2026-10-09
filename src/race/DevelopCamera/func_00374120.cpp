typedef int s32;

struct S { char pad[0xC08]; s32 unkC08; };

extern "C" s32 func_00374120(S *arg0) {
    return arg0->unkC08;
}
