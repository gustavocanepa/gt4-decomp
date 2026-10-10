#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004D91A8();                                /* extern */

extern char D_004D8950[];
s32 func_004D88D8(s32 *arg0, s32 arg1) {
    switch (arg1) {                                 /* irregular */
    case 15:
        return 0x27;
    case 18:
    case 41:
        *arg0 = (s32)D_004D8950;
        return 0x28;
    default:
        return func_004D91A8();
    }
}
