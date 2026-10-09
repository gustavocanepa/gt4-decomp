typedef int s32;

struct S { char pad[0xA0]; s32 unkA0; };

extern "C" s32 func_00206880(S *arg0) {
    return arg0->unkA0;
}
