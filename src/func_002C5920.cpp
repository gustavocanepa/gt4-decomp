typedef int s32;

struct S { char pad[8]; s32 unk8; };

extern "C" s32 func_002C5920(S *arg0) {
    return arg0->unk8;
}
