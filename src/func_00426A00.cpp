typedef int s32;

struct S { char pad[0x188]; s32 unk188; };

extern "C" s32 func_00426A00(S *arg0) {
    return arg0->unk188;
}
