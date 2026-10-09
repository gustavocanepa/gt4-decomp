typedef int s32;

struct S { char pad[0x77C]; s32 unk77C; };

extern "C" s32 func_00557EB8(S *arg0) {
    return arg0->unk77C;
}
