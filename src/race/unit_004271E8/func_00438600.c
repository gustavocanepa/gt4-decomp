#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00438340(s32);                             /* extern */

struct func_00438600_arg0 {
    char pad0[0x8];
    s32 unk8;
};

u32 func_00438600(struct func_00438600_arg0 *arg0) {
    return (u32) ~func_00438340(arg0->unk8) >> 0x1F;
}
