#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004A4100(s32, s32, s32, s32);  /* extern */
s32 func_004A4418(s32, s32);                    /* extern */
s32 func_004A4550(s32, s32);            /* extern */
s32 func_004A4810(s32, s32, s32);       /* extern */
void func_004A4910();                            /* extern */

void func_00497200(s32 arg0, s32 arg1, s32 arg2) {
    func_004A4910();
    func_004A4100(0, arg0, 0, (arg1 + 0x3F) & ~0x3F);
    func_004A4418(arg1, arg2);
    func_004A4810(0, 0, arg1);
    func_004A4810(1, 0, arg2);
    func_004A4550(4, 1);
    func_004A4550(5, 1);
}
