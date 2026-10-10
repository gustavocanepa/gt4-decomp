#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005CB808_arg0 {
    char pad0[0x4];
    s32 (*unk4)(s32);
    s32 unk8;
};

void func_005CB808(struct func_005CB808_arg0 *arg0) {
    s32 (*temp_v0)(s32);

    temp_v0 = arg0->unk4;
    if (temp_v0 != NULL) {
        temp_v0(arg0->unk8);
    }
}
