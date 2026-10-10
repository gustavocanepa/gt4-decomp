/* compiler: ee-gcc2.96-nosched1 */
#include "types.h"
#define NULL 0
#include "m2c_macros.h"

void func_003BC5A8(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x10360) = arg1;
    M2C_FIELD(arg0, s32 *, 0x24EE0) = arg1;
    M2C_FIELD(arg0, s32 *, 0x24EE4) = 0;
}
