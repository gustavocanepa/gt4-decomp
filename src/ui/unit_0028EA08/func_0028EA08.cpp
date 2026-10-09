typedef int s32;

struct S { char pad[0x18]; s32 unk18; };

extern "C" s32 func_0028EA08(S *arg0) {
    return arg0->unk18;
}
