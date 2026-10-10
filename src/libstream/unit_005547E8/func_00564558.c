/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00563198(s32);                         /* extern */
s32 func_00563258(s32);                     /* extern */
s32 func_00563868();                            /* extern */
s32 func_00563A60();                            /* extern */
s32 func_00568568();                                /* extern */

extern char D_00654D80[];
s32 func_00564558(s32 *arg0, s32 *arg1) {
    s32 temp_v0;
    s32 temp_v0_2;

    func_00563868();
    temp_v0 = func_00563198(0x20);
    if ((u32) (temp_v0 - 0x101) >= 0xAFU) {
        func_00563258(0x20);
        return -1;
    }
    func_00563258(0x20);
    func_00563A60();
    temp_v0_2 = func_00568568();
    *arg1 = temp_v0_2;
    *arg0 = ((((temp_v0 & 0xFF) - 1) * *(s32 *)D_00654D80) + temp_v0_2) - 1;
    *arg1 = 1;
    return 1;
}
