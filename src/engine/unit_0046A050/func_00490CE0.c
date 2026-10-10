#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004924B8();                            /* extern */

struct func_00490CE0_arg0 {
    char pad0[0x7C];
    s32 unk7C;
};

s32 func_00490CE0(struct func_00490CE0_arg0 *arg0) {
    if (arg0->unk7C != 0) {
        arg0->unk7C = 0;
        func_004924B8();
    }
}
