typedef int s32;

struct S { char pad[0xA4]; s32 unkA4; };

extern "C" s32 func_00206860(S *arg0) {
    return arg0->unkA4;
}
