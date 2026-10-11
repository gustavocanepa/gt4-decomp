#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 AutomobileControlRecord__Manager__reset(s32);                         /* extern */

struct func_00426C10_arg0 {
    char pad0[0x148];
    s32 unk148;
};

s32 func_00426C10(struct func_00426C10_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk148;
    if (temp_v0 != 0) {
        AutomobileControlRecord__Manager__reset(temp_v0);
    }
}
