/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00556298();                            /* extern */
s32 func_00561288(s32);                         /* extern */

struct func_00556268_arg1 {
    char pad0[0x3C];
    s32 unk3C;
};

void func_00556268(s32 arg0, struct func_00556268_arg1 *arg1) {
    func_00556298();
    func_00561288(arg1->unk3C);
}
