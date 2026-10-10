#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_001FD5E8(void *);                      /* extern */
s32 func_00575DA0(s32);                         /* extern */

struct func_001FD5A8_arg0 {
    char pad0[0xD4];
    s32 unkD4;
};

void func_001FD5A8(void *arg0) {
    s32 temp_v0;

    temp_v0 = ((struct func_001FD5A8_arg0 *)arg0)->unkD4;
    if (temp_v0 != 0) {
        ((struct func_001FD5A8_arg0 *)arg0)->unkD4 = 0;
        func_00575DA0(temp_v0);
    }
    func_001FD5E8(arg0);
}
