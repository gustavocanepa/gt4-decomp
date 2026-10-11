#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00385BD8(s32);                             /* extern */
s32 func_00385BE8(s32);                             /* extern */
s32 func_00385BF8(s32);                             /* extern */
s32 func_00385C08(s32);                             /* extern */
s32 func_00385C18(s32);                             /* extern */
s32 func_00385C28(s32);                             /* extern */
s32 func_00385CB8(s32);                             /* extern */
s32 func_00385CC8(s32);                             /* extern */
s32 func_00385CD8(s32);                             /* extern */
s32 func_00385CE8(s32);                             /* extern */
s32 func_00385EE0(s32);                             /* extern */
s32 func_00385EE8(s32);                             /* extern */
s32 func_00386030(s32 *, s32, s32);         /* extern */
s32 func_003863D8(s32);                             /* extern */
s32 func_003863E8(s32);                             /* extern */
s32 func_00386418(s32);                             /* extern */
s32 func_00386428(s32);                             /* extern */
s32 func_0040FC78(s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32 *, s32 *); /* extern */

struct func_00410E60_arg0 {
    s32 unk0;
    char pad4[0x4];
    s32 unk8;
    s32 *unkC;
    char pad10[0x100];
    f32 unk110;
};

void func_00410E60(struct func_00410E60_arg0 *arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2) {
    s32 sp50;
    s32 sp54;
    s32 sp58;
    s32 sp5C;
    s32 sp60;
    s32 sp64;
    s32 sp68;
    s32 sp6C;
    s32 sp70;
    s32 sp74;
    s32 sp78;
    s32 sp7C;
    s32 sp80;
    f32 temp_f20;
    f32 temp_f20_2;
    s32 temp_fp;
    s32 temp_fp_2;
    s32 temp_s1;
    s32 temp_s1_2;
    s32 temp_s2;
    s32 temp_s2_2;
    s32 temp_s3;
    s32 temp_s3_2;
    s32 temp_s4;
    s32 temp_s4_2;
    s32 temp_s5;
    s32 temp_s5_2;
    s32 temp_s6;
    s32 temp_s6_2;
    s32 temp_s7;
    s32 temp_s7_2;

    sp58 = arg1;
    sp50 = func_00385EE0(*arg0->unkC);
    sp54 = func_00385EE8(*arg0->unkC);
    temp_f20 = arg0->unk110;
    sp5C = func_00385BD8(arg0->unk0);
    sp60 = func_00385BF8(arg0->unk0);
    sp64 = func_00385C18(arg0->unk0);
    sp68 = func_003863D8(arg0->unk8);
    temp_s7 = func_00385CB8(arg0->unk0);
    temp_s5 = func_00385CD8(arg0->unk0);
    sp6C = func_00386418(arg0->unk8);
    temp_fp = func_00385BE8(arg0->unk0);
    temp_s6 = func_00385C08(arg0->unk0);
    temp_s4 = func_00385C28(arg0->unk0);
    temp_s3 = func_003863E8(arg0->unk8);
    temp_s2 = func_00385CC8(arg0->unk0);
    temp_s1 = func_00385CE8(arg0->unk0);
    func_0040FC78(0, fparg0, fparg1, temp_f20, fparg2, arg1, sp5C, sp60, sp64, sp68, temp_s7, temp_s5, sp6C, temp_fp, temp_s6, temp_s4, temp_s3, temp_s2, temp_s1, func_00386428(arg0->unk8), &sp50, &sp54);
    temp_f20_2 = arg0->unk110;
    sp70 = func_00385BE8(arg0->unk0);
    sp74 = func_00385C08(arg0->unk0);
    sp78 = func_00385C28(arg0->unk0);
    sp7C = func_003863E8(arg0->unk8);
    sp80 = func_00385CC8(arg0->unk0);
    temp_fp_2 = func_00385CE8(arg0->unk0);
    temp_s7_2 = func_00386428(arg0->unk8);
    temp_s6_2 = func_00385BD8(arg0->unk0);
    temp_s5_2 = func_00385BF8(arg0->unk0);
    temp_s4_2 = func_00385C18(arg0->unk0);
    temp_s3_2 = func_003863D8(arg0->unk8);
    temp_s2_2 = func_00385CB8(arg0->unk0);
    temp_s1_2 = func_00385CD8(arg0->unk0);
    func_0040FC78(1, fparg0, fparg1, temp_f20_2, fparg2, sp58, sp70, sp74, sp78, sp7C, sp80, temp_fp_2, temp_s7_2, temp_s6_2, temp_s5_2, temp_s4_2, temp_s3_2, temp_s2_2, temp_s1_2, func_00386418(arg0->unk8), &sp54, &sp50);
    func_00386030(arg0->unkC, 0, sp50);
    func_00386030(arg0->unkC, 1, sp54);
}
