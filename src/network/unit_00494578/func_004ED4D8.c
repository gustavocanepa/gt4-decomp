#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00578168(void *, s32, s32, s32 *, s32); /* extern */
s32 func_00578500(s32);                         /* extern */
s32 func_005A48D8(s32 *, s32, s32);     /* extern */
s32 func_005A6AB0(s32 *, s32, s32);         /* extern */

struct func_004ED4D8_arg0 {
    s32 unk0;
    char pad4[0x3C];
    s32 *unk40;
};

s32 func_004ED4D8(struct func_004ED4D8_arg0 *arg0, s32 arg1, s32 arg2) {
    s32 frag0;
    func_00578500(arg0->unk0);
    func_005A48D8(arg0->unk40, 0, 0x20C);
    frag0 = arg0->unk40;
    func_005A6AB0(frag0 + 0x10, arg1, 0xB);
    func_005A6AB0(arg0->unk40 + 0x7, arg2, 0xFF);
    func_00578168(arg0, 9, 0, arg0->unk40, 0x40);
    return *arg0->unk40;
}
