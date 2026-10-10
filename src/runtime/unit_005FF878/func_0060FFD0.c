#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00578500(s32);                         /* extern */

struct func_0060FFD0_arg0 {
    char pad0[0x40];
    s32 unk40;
    char pad44[0x7C];
    s32 unkC0;
};

s32 func_0060FFD0(struct func_0060FFD0_arg0 *arg0) {
    func_00578500(arg0->unk40);
    return arg0->unkC0 == 0;
}
