/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00574EE8(void *);                      /* extern */

struct func_004B06D0_arg0 {
    char pad0[0x3290];
    s32 unk3290;
};

void func_004B06D0(void *arg0) {
    ((struct func_004B06D0_arg0 *)arg0)->unk3290 = 0;
    func_00574EE8(arg0 + 0x3170);
    func_00574EE8(arg0 + 0x31D0);
}
