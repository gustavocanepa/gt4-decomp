#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00612A68(s32, void *, s32);        /* extern */

struct func_005678E8_arg0 {
    char pad0[0x28];
    s32 unk28;
};

s32 func_005678E8(struct func_005678E8_arg0 *arg0, s32 arg1) {
    func_00612A68(arg1, arg0, 0x2C);
    return arg0->unk28;
}
