#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0044AC28(s32);                         /* extern */
s32 func_005A48D8(void *, s32, s32);    /* extern */

struct func_0044AC98_arg0 {
    s32 unk0;
    char pad4[0x18];
    s32 unk1C;
};

void func_0044AC98(void *arg0, s32 arg1) {
    ((struct func_0044AC98_arg0 *)arg0)->unk0 = arg1;
    func_0044AC28(arg0 + 4);
    ((struct func_0044AC98_arg0 *)arg0)->unk1C = 0;
    func_005A48D8(arg0 + 0x14, 0, 8);
}
