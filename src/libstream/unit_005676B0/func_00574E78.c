/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00576788();                            /* extern */
s32 func_005767C0(void *);                      /* extern */

struct func_00574E78_arg0 {
    char pad0[0x28];
    s32 unk28;
    s32 unk2C;
};

void func_00574E78(struct func_00574E78_arg0 *arg0) {
    func_00576788();
    arg0->unk28 = 0;
    arg0->unk2C = 0;
    func_005767C0(arg0);
}
