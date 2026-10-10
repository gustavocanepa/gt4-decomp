/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#include "gt4/RebuildPropagate.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00234798(s32, s32);                    /* extern */
s32 func_00255260();                                /* extern */
s32 func_00265FA8(s32);                             /* extern */
s32 func_0030AA08(s32, s32);                        /* extern */

void RebuildPropagate__virtual_01(struct RebuildPropagate *arg0, s32 arg1) {
    if ((func_0030AA08(arg1, func_00255260()) != 0) && (func_00265FA8(arg1) != 0)) {
        func_00234798(arg0->unk4, arg1);
    }
}
