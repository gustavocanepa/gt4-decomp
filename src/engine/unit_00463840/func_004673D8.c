#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_00463BB8(void *);
struct func_004673D8_arg1 {
    char pad0[0x103C];
    f32 unk103C;
    char pad1040[0x2C];
    f32 unk106C;
    f32 unk1070;
    char pad1074[0x3];
    u8 unk1077;
    char pad1078[0xC];
    f32 unk1084;
};

struct func_004673D8_temp_v0 {
    f32 unk0;
};

void func_004673D8(void *arg0, struct func_004673D8_arg1 *arg1) {
    f32 *temp_v0;

    M2C_FIELD(func_00463BB8(arg0), f32 *, 0x70) = (f32) ((arg1->unk106C + arg1->unk1070) / arg1->unk103C);
    temp_v0 = (f32 *)(func_00463BB8(arg0) + 0x74);
    ((struct func_004673D8_temp_v0 *)temp_v0)->unk0 = 0x0.0p+0f;
    if (arg1->unk1077 == 7) {
        ((struct func_004673D8_temp_v0 *)temp_v0)->unk0 = (f32) ((arg1->unk1084 * 0x1.9999980000000p-1f) / arg1->unk103C);
    }
}
