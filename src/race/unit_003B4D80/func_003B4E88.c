#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_003BB858(s32);                         /* extern */
s32 func_003BBA30(s32);                         /* extern */
s32 func_003DD778(s32);                         /* extern */

struct func_003B4E88_arg0 {
    char pad0[0x11E8];
    s32 unk11E8;
    s32 unk11EC;
};

s32 func_003B4E88(void *arg0, s32 arg1) {
    func_003BBA30(arg0 + 0x1A0);
    func_003BB858(arg0 + 0x119C);
    ((struct func_003B4E88_arg0 *)arg0)->unk11EC = 0;
    ((struct func_003B4E88_arg0 *)arg0)->unk11E8 = 0x157529FF;
    if (arg1 == 0) {
        func_003DD778(arg0 + 0x11E0);
    }
}
