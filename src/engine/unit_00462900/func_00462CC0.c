#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 SeParam__operator_assign(void *, s32);                 /* extern */
s32 SePlayer__Stop(void *, s32);                     /* extern */

struct func_00462CC0_arg0 {
    char pad0[0x14];
    s32 unk14;
    s32 unk18;
};

void *func_00462CC0(struct func_00462CC0_arg0 *arg0, s32 arg1) {
    SePlayer__Stop(arg0, 0);
    SeParam__operator_assign(arg0, arg1);
    arg0->unk14 = 0;
    arg0->unk18 = 0;
    return arg0;
}
