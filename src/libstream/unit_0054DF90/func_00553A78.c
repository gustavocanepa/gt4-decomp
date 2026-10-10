/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00577FC8(void *, s32, s32);        /* extern */

struct func_00553A78_arg1 {
    char pad0[0x54];
    s32 unk54;
};

void func_00553A78(s32 arg0, void *arg1) {
    func_00577FC8(arg1 + 0x2C, ((struct func_00553A78_arg1 *)arg1)->unk54, 0);
}
