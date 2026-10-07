typedef int s32;

struct S { char pad[0x1C]; s32 unk1C; };

extern "C" s32 func_0021A7C8(S *arg0) {
    return arg0->unk1C;
}
