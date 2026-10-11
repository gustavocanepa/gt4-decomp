#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct NormalCarGeometry {
    void * unk0;
    s32 unk4;
    s32 unk8;
};
s32 func_0038D0C0(void *);
struct func_0038CDE8_temp_s0 {
    char pad0[0xC4];
    f32 unkC4;
};

f32 func_0038CDE8(struct NormalCarGeometry *arg0) {
    s32 temp_s0;

    if ((M2C_FIELD(func_0038D0C0(arg0), f32 *, 0xC4) == 0x0.0p+0f) && (M2C_FIELD(func_0038D0C0(arg0), f32 *, 0xC8) == 0x0.0p+0f) && (M2C_FIELD(func_0038D0C0(arg0), f32 *, 0xCC) == 0x0.0p+0f)) {
        return 0x1.0000000000000p+1f * -M2C_FIELD(func_0038D0C0(arg0), f32 *, 0x34);
    }
    temp_s0 = func_0038D0C0(arg0);
    return ((struct func_0038CDE8_temp_s0 *)temp_s0)->unkC4 - M2C_FIELD(func_0038D0C0(arg0), f32 *, 0x34);
}
