#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0030A798();                            /* extern */
s32 func_005EC640(s32, s32);                    /* extern */

struct func_002EF7A0_arg0 {
    u8 pad0[0x20];
    s32 unk20;
};

void *func_002EF7A0(void *arg0, s32 arg1) {
    s32 temp_v0;
    s32 temp_v1;

    if (arg0 != arg1) {
        func_0030A798();
        temp_v1 = arg1 + 0x10;
        temp_v0 = arg0 + 0x10;
        if (temp_v0 != temp_v1) {
            func_005EC640(temp_v0, temp_v1);
        }
        ((struct func_002EF7A0_arg0 *)arg0)->unk20 = 0;
    }
    return arg0;
}
