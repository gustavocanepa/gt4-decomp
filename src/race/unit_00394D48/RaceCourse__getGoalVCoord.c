#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void *CourseData__getRunway(s32);                           /* extern */

struct func_00395588_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0xA8];
    s32 unkB0;
};

f32 RaceCourse__getGoalVCoord(struct func_00395588_arg0 *arg0) {
    if (arg0->unkB0 < 0) {
        return M2C_FIELD(CourseData__getRunway(arg0->unk4), f32 *, 0x1C);
    }
    return M2C_FIELD((M2C_FIELD(CourseData__getRunway(arg0->unk4), s32 *, 0x9C) + (arg0->unkB0 << 5)), f32 *, 4);
}
