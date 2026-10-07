typedef unsigned char u8;
typedef int s32;

struct S { char pad[0x12]; u8 unk12; };

extern "C" s32 func_003F1F88(S *arg0) {
    return arg0->unk12 == 2;
}
