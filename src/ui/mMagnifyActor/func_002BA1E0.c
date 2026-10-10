#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0025B500(s32, s32, s32, s32, s32);     /* extern */

struct func_002BA1E0_arg0 {
    char pad0[0x14];
    s32 unk14;
};

s32 func_002BA1E0(void *arg0, s32 arg1) {
    ((struct func_002BA1E0_arg0 *)arg0)->unk14 = arg1;
    if (arg1 != 0) {
        func_0025B500(arg1, arg0 + 0x1C, arg0 + 0x20, arg0 + 0x24, arg0 + 0x28);
    }
}
