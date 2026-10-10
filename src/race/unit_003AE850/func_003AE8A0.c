#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003AE970();                            /* extern */
s32 func_003AEAC0();                            /* extern */
s32 func_005C1628(s32);                         /* extern */

extern char D_00621874[];
void func_003AE8A0(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = *(s32 *)(s32)D_00621874 - 1;
    *(s32 *)(s32)D_00621874 = temp_v0;
    if (temp_v0 == 0) {
        func_003AE970();
        func_003AEAC0();
    }
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
