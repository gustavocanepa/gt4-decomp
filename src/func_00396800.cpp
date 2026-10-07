typedef int s32;

struct S { char pad[0xDC]; s32 unkDC; };

extern "C" s32 func_00396800(S *arg0) {
    return arg0->unkDC;
}
