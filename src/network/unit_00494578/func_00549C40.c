#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00549B48(void *);                          /* extern */

void func_00549C40(s32 *arg0) {
    s32 temp_v0;

    if (func_00549B48(arg0 + (*arg0 * 0x6F) + 1) != 0) {
        temp_v0 = *arg0 + 1;
        *arg0 = temp_v0;
        if (temp_v0 >= 2) {
            *arg0 = 0;
        }
    }
}
