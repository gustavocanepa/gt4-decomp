#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00105830();                                /* extern */
s32 func_0049B220(s32, s32, s32, s32);      /* extern */

struct func_00105848_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x4];
    s32 unkC;
};

void func_00105848(struct func_00105848_arg0 *arg0) {
    s32 temp_s0;

    temp_s0 = arg0->unk4;
    func_0049B220(temp_s0, func_00105830(), arg0->unkC, 0);
}
