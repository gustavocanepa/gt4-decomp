#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00463948(void *, s32, void *);         /* extern */

struct func_00343AB8_arg0 {
    s32 unk0;
    s32 unk4;
    char pad8[0x8];
    void *unk10;
};

void func_00343AB8(void *arg0, s32 arg1, s32 arg2, void *arg3) {
    func_005A48D8(arg0, 0, 0x10A0);
    func_005A48D8(arg3, 0, 0x1100);
    ((struct func_00343AB8_arg0 *)arg0)->unk4 = arg1;
    ((struct func_00343AB8_arg0 *)arg0)->unk0 = arg2;
    ((struct func_00343AB8_arg0 *)arg0)->unk10 = arg3;
    func_00463948(arg0 + 0x14, arg1, arg0);
}
