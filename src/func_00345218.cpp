typedef unsigned char u8;
typedef int s32;

struct S { char pad[0x30]; u8 unk30; };

extern "C" s32 func_00345218(S *arg0) {
    return arg0->unk30 == 7;
}
