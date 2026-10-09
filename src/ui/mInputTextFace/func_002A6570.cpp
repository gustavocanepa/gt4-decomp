typedef int s32;

struct S { char pad[0x164]; s32 unk164; };

extern "C" s32 func_002A6570(S *arg0) {
    return arg0->unk164 == 3;
}
