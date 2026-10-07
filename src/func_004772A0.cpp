typedef int s32;

struct S { char pad[4]; s32 unk4; };

extern "C" s32 func_004772A0(S *arg0) {
    return arg0->unk4;
}
