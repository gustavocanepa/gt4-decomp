#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0055C758(s32, s64);                        /* extern */
s32 func_0055D148(void *, s32);             /* extern */

struct func_0055D1C0_arg0 {
    s32 unk0;
    char pad4[0x4];
    s64 unk8;
};

s32 func_0055D1C0(struct func_0055D1C0_arg0 *arg0) {
    if (func_0055C758(arg0->unk0, arg0->unk8) == 0) {
        func_0055D148(arg0, 1);
    }
}
