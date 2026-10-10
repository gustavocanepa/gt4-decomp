/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00437408(s32, s32, s32);           /* extern */

struct func_005CCBF0_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void func_005CCBF0(struct func_005CCBF0_arg0 *arg0, s32 arg1) {
    func_00437408(arg0->unk10, 0x200, arg1);
}
