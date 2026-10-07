typedef signed char s8;

struct S { char pad[0x18]; s8 unk18; };

extern "C" s8 func_004458C8(S *arg0) {
    return arg0->unk18;
}
