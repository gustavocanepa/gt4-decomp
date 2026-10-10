#include "types.h"
#include "gt4/RaceFreeRun.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_00359D40(s32, s32);                /* extern */
void *func_003EA908(void *);                        /* extern */
s32 RaceLicense__virtual_152();                            /* extern */

s32 RaceFreeRun__virtual_152(struct RaceFreeRun *arg0) {
    RaceLicense__virtual_152();
    func_00359D40(arg0->unk70, 0);
    if (M2C_FIELD(func_003EA908(arg0), s32 *, 0x1D0) == 0) {
        func_00359D40(arg0->unk70, 1);
    }
}
