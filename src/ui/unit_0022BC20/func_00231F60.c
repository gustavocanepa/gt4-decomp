#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00265D70(s32, s32);                /* extern */
s32 func_00265E50(s32, s32);                /* extern */

struct func_00231F60_arg0 {
    char pad0[0x1D10];
    s32 unk1D10;
};

s32 func_00231F60(struct func_00231F60_arg0 *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = arg0->unk1D10;
    if (temp_v0 != 0) {
        func_00265D70(temp_v0, 0);
    }
    arg0->unk1D10 = arg1;
    if (arg1 != 0) {
        func_00265E50(arg1, 0);
        func_00265D70(arg0->unk1D10, 1);
    }
}
