#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00536B40_temp_v0_2 {
    char pad0[0x118];
    void *unk118;
};
struct func_00536B40_temp_v0 {
    char pad0[0x148];
    s32 unk148;
};

s32 func_00536B40(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    struct func_00536B40_temp_v0 *temp_v0;
    struct func_00536B40_temp_v0_2 *temp_v0_2;

    temp_v0_2 = *(void **)0x64B4B4;
    if (temp_v0_2 != NULL) {
        temp_v0 = temp_v0_2->unk118;
        if (temp_v0 != NULL) {
            return temp_v0->unk148;
        }
    }
    return -1;
}
