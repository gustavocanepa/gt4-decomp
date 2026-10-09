typedef int s32;

struct S { char pad0[0xC]; s32 unkC; char pad1[0x38 - 0xC - 4]; s32 unk38; };

extern "C" s32 func_00105888(struct S *arg0) {
    s32 temp_v1 = arg0->unkC;
    return (arg0->unk38 == 0) ? temp_v1 : (temp_v1 * 2);
}
