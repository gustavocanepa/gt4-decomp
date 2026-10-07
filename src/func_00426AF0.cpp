typedef int s32;

struct S { char pad[0x18C]; s32 unk18C; };

extern "C" s32 func_00426AF0(S *arg0) {
    return arg0->unk18C;
}
