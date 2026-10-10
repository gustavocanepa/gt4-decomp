#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_002A3820_arg0 {
    char pad0[0xEC];
    u8 unkEC;
};

f32 func_002A3820(struct func_002A3820_arg0 *arg0, s32 arg1) {
    f32 temp_f0;

    temp_f0 = (f32) arg1 / (f32) arg0->unkEC;
    return (temp_f0 + 1.0f) / temp_f0;
}
