extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_00490FA0(char *arg0) {
    s32 temp_a0;
    s32 var_v0;

    temp_a0 = M2C_FIELD(arg0, s32 *, 0x90);
    var_v0 = 0;
    if (temp_a0 >= 0) {
        var_v0 = (M2C_FIELD(arg0, s32 *, 0x84) < temp_a0) == 0;
    }
    return var_v0;
}

}
