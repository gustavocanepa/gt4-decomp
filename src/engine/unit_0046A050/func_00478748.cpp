#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00476B78(s32, f32);                    /* extern */
f32 func_00477460();                                /* extern */

void func_00478748(s32 arg0) {
    func_00476B78(arg0, func_00477460() + 0x1.0000000000000p+0f);
}
