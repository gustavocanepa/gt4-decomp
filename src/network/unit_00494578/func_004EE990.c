#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_005A609C(s32, s32);                    /* extern */

void func_004EE990(s32 *arg0, s32 arg1, s32 arg2) {
    switch (arg1) {                                 /* irregular */
    case 0:
        func_005A609C(*arg0 + 0x600, arg2);
        return;
    case 1:
        func_005A609C(*arg0 + 0x700, arg2);
        return;
    }
}
