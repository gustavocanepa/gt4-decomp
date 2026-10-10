#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00575DA0(s32);                         /* extern */

struct func_0044A760_arg0 {
    char pad0[0xC];
    s32 unkC;
};

s32 func_0044A760(struct func_0044A760_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unkC;
    if (temp_v0 != 0) {
        func_00575DA0(temp_v0);
    }
}
