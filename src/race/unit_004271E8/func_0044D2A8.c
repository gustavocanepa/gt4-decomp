#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00579F38(void *, void *, s32);             /* extern */

struct func_0044D2A8_arg0 {
    s32 unk0;
    s32 unk4;
    char pad8[0x4];
    s32 unkC;
};

void func_0044D2A8(void *arg0) {
    void *temp_a0;

    temp_a0 = arg0 + ((struct func_0044D2A8_arg0 *)arg0)->unk0;
    ((struct func_0044D2A8_arg0 *)arg0)->unkC = func_00579F38(temp_a0, temp_a0, ((struct func_0044D2A8_arg0 *)arg0)->unk4);
}
