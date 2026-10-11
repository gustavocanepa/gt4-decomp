#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void *CourseData__getRunway(s32);                           /* extern */

struct func_00395380_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0xA8];
    s32 unkB0;
};
struct func_00395380_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
struct func_00395380_temp_v0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

void func_00395380(struct func_00395380_arg0 *arg0, struct func_00395380_arg1 *arg1, s32 arg2) {
    struct func_00395380_temp_v0 *temp_v0;

    temp_v0 = M2C_FIELD((M2C_FIELD(CourseData__getRunway(arg0->unk4), s32 *, 0x9C) + (arg0->unkB0 << 5)), s32 *, 0x10) + (arg2 * 0x10);
    arg1->unk0 = (f32) temp_v0->unk0;
    arg1->unk4 = (f32) temp_v0->unk4;
    arg1->unk8 = (f32) temp_v0->unk8;
    arg1->unkC = (f32) temp_v0->unkC;
}
