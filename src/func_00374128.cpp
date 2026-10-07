typedef int s32;

struct S { char pad[0xC10]; s32 unkC10; };

extern "C" s32 func_00374128(S *arg0) {
    return arg0->unkC10;
}
