#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 free(s32);                         /* extern */

struct func_001C5128_arg0 {
    char pad0[0x25C];
    s32 unk25C;
    s32 unk260;
};

void func_001C5128(struct func_001C5128_arg0 *arg0) {
    s32 temp_a0;
    s32 temp_v0;

    temp_v0 = arg0->unk25C;
    if (temp_v0 != 0) {
        free(temp_v0);
        arg0->unk25C = 0;
    }
    temp_a0 = arg0->unk260;
    if (temp_a0 != 0) {
        free(temp_a0);
        arg0->unk260 = 0;
    }
}
