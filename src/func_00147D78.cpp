typedef int s32;

struct S { char pad[0x14]; s32 unk14; };

extern "C" s32 func_00147D78(S *arg0) {
    return arg0->unk14;
}
