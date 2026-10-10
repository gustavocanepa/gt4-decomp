#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004CFB08(s32 arg0) {
    if ((u32) (arg0 - 1) < 0x1BU) {
        return *(s32 *)(0x6452E0 + (arg0 * 4));
    }
    return 0;
}
