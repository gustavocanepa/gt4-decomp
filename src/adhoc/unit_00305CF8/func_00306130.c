#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00305FB0(s32, s32);                    /* extern */
s32 func_005EEE58(void *);                      /* extern */

struct func_00306130_temp_v1 {
    u8 pad0[0x8];
    s32 unk8;
};

s32 func_00306130(s32 arg0, s32 arg1) {
    struct func_00306130_temp_v1 *temp_v1;

    temp_v1 = arg0 + 0x18;
    if (temp_v1->unk8 != 0) {
        func_005EEE58(temp_v1);
        func_00305FB0(arg0, arg1);
    }
}
