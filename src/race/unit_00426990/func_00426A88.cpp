typedef int s32;

struct S { char pad[0x174]; s32 unk174; };

extern "C" s32 func_00426A88(S *arg0) {
    return arg0->unk174;
}
