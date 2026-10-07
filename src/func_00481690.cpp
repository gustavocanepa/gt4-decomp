typedef int s32;

struct S { char pad[8]; s32 unk8; };

extern "C" s32 func_00481690(S *arg0) {
    return arg0->unk8;
}
