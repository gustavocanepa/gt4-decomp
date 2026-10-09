typedef unsigned char u8;
typedef int s32;

struct S { char pad[0x626]; u8 unk626; };

extern "C" s32 func_00343BE0(S *arg0) {
    return arg0->unk626 == 1;
}
