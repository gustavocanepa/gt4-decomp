typedef unsigned char u8;
typedef int s32;

struct S { char pad[0x1C]; u8 unk1C; };

extern "C" s32 func_00463BA8(S *arg0) {
    return arg0->unk1C == 4;
}
