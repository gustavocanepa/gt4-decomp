#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00386610(s32);                             /* extern */
s32 func_00412018(void *);                      /* extern */

struct func_00411FB0_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void func_00411FB0(struct func_00411FB0_arg0 *arg0) {
    if (func_00386610(arg0->unk10) == 1) {
        func_00412018(arg0);
        return;
    }
    if (func_00386610(arg0->unk10) == 4) {
        func_00412018(arg0);
    }
}
