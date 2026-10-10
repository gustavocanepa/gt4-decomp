#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00578168(void *, s32, s32, s32 *, s32); /* extern */
s32 func_00578500(s32);                         /* extern */

struct func_004ED1B0_arg0 {
    s32 unk0;
    char pad4[0x3C];
    s32 *unk40;
};

s32 func_004ED1B0(struct func_004ED1B0_arg0 *arg0) {
    func_00578500(arg0->unk0);
    func_00578168(arg0, 0, 0, arg0->unk40, 0x40);
    return *arg0->unk40;
}
