#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00601DE8_arg0 {
    char pad0[0x1140];
    s32 unk1140;
};

s32 func_00601DE8(struct func_00601DE8_arg0 *arg0) {
    return ((s32) arg0->unk1140 >> 3) & 1;
}
