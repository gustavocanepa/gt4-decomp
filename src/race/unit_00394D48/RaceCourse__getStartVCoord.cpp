#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#define M2C_MEMCPY_ALIGNED memcpy
#define M2C_MEMCPY_UNALIGNED memcpy
#define M2C_STRUCT_COPY memcpy
#include "m2c_macros.h"

void *CourseData__getRunway(s32);                           /* extern */

struct func_00395528_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0xA8];
    s32 unkB0;
};

f32 RaceCourse__getStartVCoord(void *arg0) {
    if (((struct func_00395528_arg0 *)arg0)->unkB0 < 0) {
        return M2C_FIELD(CourseData__getRunway(((struct func_00395528_arg0 *)arg0)->unk4), f32 *, 0x18);
    }
    return M2C_FIELD((M2C_FIELD(CourseData__getRunway(((struct func_00395528_arg0 *)arg0)->unk4), s32 *, 0x9C) + (((struct func_00395528_arg0 *)arg0)->unkB0 << 5)), f32 *, 0x0);
}
