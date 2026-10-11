/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00574EE8(s32);                         /* extern */
s32 func_00578908(s32);                         /* extern */

struct func_004AD8C0_arg0 {
    char pad0[0x94];
    s32 unk94;
    char pad98[0x8];
    s32 unkA0;
};

void func_004AD8C0(void *arg0) {
    ((struct func_004AD8C0_arg0 *)arg0)->unkA0 = 1;
    func_00574EE8(arg0 + 0x64);
    func_00578908(((struct func_004AD8C0_arg0 *)arg0)->unk94);
}
