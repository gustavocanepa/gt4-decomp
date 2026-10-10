#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_002A3860_arg0 {
    char pad0[0xED];
    u8 unkED;
};

f32 func_002A3860(struct func_002A3860_arg0 *arg0, s32 arg1) {
    f32 temp_f0;

    temp_f0 = (f32) arg1 / (f32) arg0->unkED;
    return (temp_f0 + 1.0f) / temp_f0;
}
