#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00208F00(void *, s32);                 /* extern */
s32 func_00208F18(void *, s32);             /* extern */
s32 func_0026CAE0(void *, s32, s32);            /* extern */

struct func_0026D2B8_arg0 {
    char pad0[0x410];
    s32 unk410;
};

void func_0026D2B8(struct func_0026D2B8_arg0 *arg0, s32 arg1, s32 arg2) {
    s8 sp[0x10];
    func_00208F00(sp, arg0->unk410 - 4);
    func_0026CAE0(arg0, arg1, arg2);
    func_00208F18(sp, 2);
}
