#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004D91A8();                                /* extern */

extern char D_004D84C8[];
extern char D_004D8718[];
s32 func_004D8548(s32 *arg0, s32 arg1) {
    switch (arg1) {                                 /* irregular */
    case 15:
        return 0x21;
    case 24:
        *arg0 = (s32)D_004D8718;
        return 0x21;
    case 21:
        *arg0 = (s32)D_004D84C8;
        return 0x21;
    default:
        return func_004D91A8();
    }
}
