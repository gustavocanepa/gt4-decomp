/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005A609C(void *);                      /* extern */

struct func_00557DD0_arg0 {
    char pad0[0x770];
    s32 unk770;
    s32 unk774;
};

void func_00557DD0(void *arg0) {
    if (((struct func_00557DD0_arg0 *)arg0)->unk770 == 0) {
        ((struct func_00557DD0_arg0 *)arg0)->unk770 = 0;
        ((struct func_00557DD0_arg0 *)arg0)->unk774 = 0;
        func_005A609C(arg0 + 0x65C);
    }
}
