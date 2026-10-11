/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00578480(s32);                         /* extern */

struct func_005554B0_arg0 {
    char pad0[0x4F8];
    s32 unk4F8;
    char pad4FC[0x8];
    s32 unk504;
};

void func_005554B0(struct func_005554B0_arg0 *arg0) {
    if (arg0->unk504 != 0) {
        arg0->unk504 = 0;
        func_00578480(arg0->unk4F8);
    }
}
