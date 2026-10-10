#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00601D28_arg0 {
    char pad0[0x1140];
    s32 unk1140;
};

s32 func_00601D28(struct func_00601D28_arg0 *arg0) {
    return arg0->unk1140 & 1;
}
