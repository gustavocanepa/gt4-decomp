typedef int s32;

struct S { char pad0[0x1C]; s32 unk1C; char pad1[0x38 - 0x1C - 4]; s32 unk38; };

extern "C" s32 func_001058A0(struct S *arg0) {
    s32 temp_v1 = arg0->unk1C;
    return (arg0->unk38 == 0) ? temp_v1 : (temp_v1 * 2);
}
