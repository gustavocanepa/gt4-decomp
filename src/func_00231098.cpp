typedef int s32;

struct S { char pad[0x6D8]; s32 unk6D8; };

extern "C" s32 func_00231098(S *arg0) {
    return arg0->unk6D8;
}
