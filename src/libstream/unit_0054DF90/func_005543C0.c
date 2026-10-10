#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00578168(void *, s32, s32, s32, s32); /* extern */
s32 func_00578500(s32);                         /* extern */

struct func_005543C0_arg0 {
    s32 unk0;
    char pad4[0x38];
    s32 unk3C;
};

s32 func_005543C0(struct func_005543C0_arg0 *arg0) {
    func_00578500(arg0->unk0);
    func_00578168(arg0, 1, 0, arg0->unk3C, 0x40);
    return arg0->unk3C + 8;
}
