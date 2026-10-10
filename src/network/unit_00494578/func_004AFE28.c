#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004AEFF0(s32);                         /* extern */
s32 func_004AF6D0();                            /* extern */

extern char D_00688F80[];
struct func_004AFE28_arg0 {
    char pad0[0x20];
    s32 unk20;
};

void func_004AFE28(void *arg0) {
    func_004AF6D0();
    ((struct func_004AFE28_arg0 *)arg0)->unk20 = (s32)D_00688F80;
    func_004AEFF0(arg0 + 0x24);
}
