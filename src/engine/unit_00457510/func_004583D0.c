/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00458400(void *, s32, s32);                /* extern */

struct func_004583D0_arg0 {
    char pad0[0x4];
    void *unk4;
};

void func_004583D0(void *arg0) {
    void *temp_a2;

    temp_a2 = ((struct func_004583D0_arg0 *)arg0)->unk4;
    ((struct func_004583D0_arg0 *)arg0)->unk4 = arg0;
    func_00458400(arg0, 0, arg0 - temp_a2);
}
