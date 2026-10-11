#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_00538C68(void **);                     /* extern */

struct func_0050A4E8_temp_a0 {
    char pad0[0x124];
    s32 unk124;
};

s32 func_0050A4E8(void **arg0) {
    void *temp_a0;

    temp_a0 = *arg0;
    if (temp_a0 != NULL) {
        if (((struct func_0050A4E8_temp_a0 *)temp_a0)->unk124 != 0) {
            func_00538C68(temp_a0 + 0x124);
            M2C_FIELD(*arg0, s32 *, 0x124) = 0;
        }
        if (M2C_FIELD(*arg0, s32 *, 0x12C) != 0) {
            func_00538C68(*arg0 + 0x12C);
            M2C_FIELD(*arg0, s32 *, 0x12C) = 0;
        }
        func_00538C68(arg0);
        *arg0 = NULL;
    }
    return 0;
}
