#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0042F4C8();                                /* extern */

struct func_00435110_arg0 {
    char pad0[0x10];
    s32 unk10;
};

s32 func_00435110(struct func_00435110_arg0 *arg0) {
    return (arg0->unk10 & 0xFFFFFF) + func_0042F4C8();
}
