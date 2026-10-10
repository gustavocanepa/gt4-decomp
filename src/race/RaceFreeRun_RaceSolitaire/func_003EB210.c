#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00346BB8(s32, s32, s32);               /* extern */
void *func_003EA8C8();                              /* extern */

struct func_003EB210_temp_v0 {
    char pad0[0x1D0];
    s32 unk1D0;
};

void func_003EB210(s32 arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = func_003EA8C8();
    func_00346BB8(temp_v0 + 0xD4, arg1 + 0x1AA4, arg2);
    ((struct func_003EB210_temp_v0 *)temp_v0)->unk1D0 = 0;
}
