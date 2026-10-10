#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005A609C(void *, s32);                 /* extern */

struct func_004EE908_temp_v1 {
    char pad0[0x1320];
    s8 unk1320;
};

s32 func_004EE908(void **arg0, s32 arg1, s32 arg2) {
    struct func_004EE908_temp_v1 *temp_v1;

    temp_v1 = *arg0;
    if (arg1 != 0) {
        temp_v1->unk1320 = 1;
    } else {
        temp_v1->unk1320 = 0;
    }
    if (arg2 != 0) {
        func_005A609C(*arg0 + 0x200, arg2);
    }
}
