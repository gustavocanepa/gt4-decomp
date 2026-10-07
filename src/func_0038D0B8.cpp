typedef int s32;

struct S { char pad[0x8]; s32 unk8; };

extern "C" s32 func_0038D0B8(S *arg0) {
    return arg0->unk8;
}
