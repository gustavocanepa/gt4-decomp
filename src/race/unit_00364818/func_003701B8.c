#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003701B8_arg0 {
    char pad0[0x2C];
    s8 unk2C;
};

f32 func_003701B8(struct func_003701B8_arg0 *arg0, f32 fparg0, f32 fparg1) {
    f32 var_f12;
    s8 temp_v0;

    var_f12 = fparg0;
    temp_v0 = arg0->unk2C;
    if (temp_v0 > 0) {
        var_f12 *= 0x1.11eb840000000p+0f;
    }
    if (temp_v0 < 0) {
        var_f12 /= 0x1.11eb840000000p+0f;
    }
    if (var_f12 < 0x1.4000000000000p+4f) {
        var_f12 = 0x1.4000000000000p+4f;
    }
    if (var_f12 > 0x1.f400000000000p+9f) {
        var_f12 = 0x1.f400000000000p+9f;
    }
    if (fparg1 < var_f12) {
        var_f12 = fparg1;
    }
    return var_f12;
}
