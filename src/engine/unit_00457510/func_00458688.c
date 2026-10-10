#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005A4724(s32, void *, s32);            /* extern */

struct func_00458688_arg0 {
    char pad0[0x8];
    s32 unk8;
};

s32 func_00458688(struct func_00458688_arg0 *arg0, s32 arg1) {
    func_005A4724(arg1, arg0, arg0->unk8);
    return arg1;
}
