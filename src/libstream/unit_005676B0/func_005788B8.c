#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00574C30(s32);                     /* extern */
s32 func_00578618(s32);                             /* extern */
s32 func_005AEDE0(s32, void *);                     /* extern */

struct func_005788B8_arg0 {
    char pad0[0x30];
    s32 unk30;
};

s32 func_005788B8(struct func_005788B8_arg0 *arg0) {
    if (func_005AEDE0(func_00578618(arg0->unk30), arg0) == -1) {
        func_00574C30((s32)"EE StartThread failed.");
    }
}
