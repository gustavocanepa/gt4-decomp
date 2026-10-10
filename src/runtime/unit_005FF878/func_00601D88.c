#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00601D88_arg0 {
    char pad0[0x1140];
    s32 unk1140;
};

s32 func_00601D88(struct func_00601D88_arg0 *arg0) {
    return ((s32) arg0->unk1140 >> 1) & 1;
}
