#include "types.h"
#include "gt4/hArray.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

u32 func_002EF9B0();                                /* extern */
s32 func_005DB110(s32, u32, u32);           /* extern */

extern char D_0069D5C0[];
s32 hArray__virtual_12(struct hArray *arg0, u32 arg1) {
    u32 temp_v0;

    temp_v0 = func_002EF9B0();
    if (arg1 >= temp_v0) {
        func_005DB110((s32)D_0069D5C0, arg1, temp_v0);
    }
    return arg0->unk14 + (arg1 * 4);
}
