#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

void func_00604B80(s32 arg0, s32 arg1, f32 fparg0) {
    M2C_FIELD(((arg1 * 0x10) + arg0), f32 *, 0x10) = fparg0;
}
