typedef int s32;

struct S { char pad[0xBC]; s32 unkBC; };

extern "C" s32 func_002B50F0(S *arg0) {
    return arg0->unkBC;
}
