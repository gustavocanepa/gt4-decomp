#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0051B8A8_temp_v0_2 {
    char pad0[0x118];
    s32 unk118;
};

s32 func_0051B8A8(s32 arg0, u32 arg1) {
    s32 temp_v0;
    struct func_0051B8A8_temp_v0_2 *temp_v0_2;

    temp_v0_2 = *(void **)0x64B4B4;
    if ((temp_v0_2 != NULL) && (arg0 != 0) && (arg0 == temp_v0_2->unk118) && (arg1 < 0x40U)) {
        temp_v0 = *(s32 *)0x863770;
        if (temp_v0 != 0) {
            return *(s32 *)((arg1 * 4) + temp_v0);
        }
    }
    return 0;
}
