#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00434FD0(void *, s32);                 /* extern */

struct func_00435630_arg0 {
    char pad0[0x81C8];
    s32 unk81C8;
};

s32 func_00435630(void *arg0) {
    s32 temp_v0;

    temp_v0 = ((struct func_00435630_arg0 *)arg0)->unk81C8;
    if (temp_v0 >= 0) {
        func_00434FD0(arg0 + (temp_v0 << 5) + 8, arg0 + 0x7D08);
    }
}
