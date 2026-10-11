#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00579E00(void *, void *, s32, s32);    /* extern */

struct func_0044D278_arg0 {
    s32 unk0;
    s32 unk4;
    char pad8[0x4];
    s32 unkC;
};

void func_0044D278(void *arg0) {
    void *temp_v0;

    temp_v0 = arg0 + ((struct func_0044D278_arg0 *)arg0)->unk0;
    func_00579E00(temp_v0, temp_v0, ((struct func_0044D278_arg0 *)arg0)->unk4, ((struct func_0044D278_arg0 *)arg0)->unkC);
}
