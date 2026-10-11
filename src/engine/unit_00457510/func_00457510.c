/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004543E0();                                /* extern */

extern char D_008465E0[];
void func_00457510(s32 arg0, s32 arg1) {
    if (arg1 == 0xFFFF) {
        if (arg0 == 1) {
            *(s32 *)D_008465E0 = func_004543E0();
        }
    }
}
