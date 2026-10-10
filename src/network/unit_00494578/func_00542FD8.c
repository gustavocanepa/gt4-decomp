#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void *func_00538988();                              /* extern */

struct func_00542FD8_temp_v0 {
    char pad0[0x14];
    s32 unk14;
};

void func_00542FD8(s32 arg0, s32 arg1) {
    struct func_00542FD8_temp_v0 *temp_v0;

    temp_v0 = func_00538988();
    if (temp_v0 != NULL) {
        temp_v0->unk14 = arg1;
    }
}
