#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004D91A8();                                /* extern */

extern char D_004D7258[];
extern char D_004D7658[];
s32 func_004D7570(s32 *arg0, s32 arg1) {
    switch (arg1) {                                 /* irregular */
    case 15:
        return 3;
    case 25:
        *arg0 = (s32)D_004D7658;
        return 7;
    case 17:
        *arg0 = (s32)D_004D7258;
        return 8;
    default:
        return func_004D91A8();
    }
}
