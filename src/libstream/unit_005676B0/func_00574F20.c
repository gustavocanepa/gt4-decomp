/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005769F0();                            /* extern */
s32 func_00576A28(void *);                      /* extern */

struct func_00574F20_arg0 {
    char pad0[0x28];
    s32 unk28;
    s32 unk2C;
};

void func_00574F20(struct func_00574F20_arg0 *arg0) {
    func_005769F0();
    arg0->unk28 = 0;
    arg0->unk2C = 0;
    func_00576A28(arg0);
}
