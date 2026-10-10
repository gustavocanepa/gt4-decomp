#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void *func_002B49B8();                   /* extern */

struct func_002B20A0_arg0 {
    char pad0[0xB0];
    s32 unkB0;
};

void func_002B20A0(struct func_002B20A0_arg0 *arg0, s32 arg1, f32 fparg0, f32 fparg1) {
    if (arg0->unkB0 == 0) {
        M2C_FIELD(func_002B49B8(), f32 *, 0xC) = fparg0;
        M2C_FIELD(func_002B49B8(arg0, arg1), f32 *, 0x10) = fparg1;
        return;
    }
    M2C_FIELD(func_002B49B8(), f32 *, 0xC) = fparg1;
    M2C_FIELD(func_002B49B8(arg0, arg1), f32 *, 0x10) = fparg0;
}
