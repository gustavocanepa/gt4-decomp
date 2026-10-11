#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004D91A8();                                /* extern */

extern char D_004D79A8[];
extern char D_004D7A00[];
s32 func_004D7918(s32 *arg0, s32 arg1) {
    switch (arg1) {                                 /* irregular */
    case 15:
        return 0xB;
    case 22:
        *arg0 = (s32)D_004D79A8;
        return 0xB;
    case 18:
        *arg0 = (s32)D_004D7A00;
        return 9;
    default:
        return func_004D91A8();
    }
}
