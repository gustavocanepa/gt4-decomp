#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00565338(s32, void *, s32);            /* extern */

struct func_00565310_arg0 {
    char pad0[0x60];
    s32 unk60;
};

void func_00565310(struct func_00565310_arg0 *arg0, s32 arg1) {
    func_00565338(arg0->unk60, arg0, arg1);
}
