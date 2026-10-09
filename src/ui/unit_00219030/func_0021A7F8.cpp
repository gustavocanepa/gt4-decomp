typedef int s32;

struct S { char pad[0x28]; s32 unk28; };

extern "C" s32 func_0021A7F8(S *arg0) {
    return arg0->unk28;
}
