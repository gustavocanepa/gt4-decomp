#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 HIO__operator_shr(s32, s32);                    /* extern */
s32 HScopePath__read(s32);                         /* extern */

void mVariablePush__read(s32 arg0, s32 arg1) {
    HScopePath__read(arg0 + 8);
    HIO__operator_shr(arg1, arg0 + 0x18);
}
