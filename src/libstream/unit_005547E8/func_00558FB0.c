#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00558FB0_arg1 {
    char pad0[0x44];
    s32 unk44;
};

void func_00558FB0(s32 arg0, struct func_00558FB0_arg1 *arg1) {
    s32 *temp_a0;

    temp_a0 = arg0 + (arg1->unk44 * 0x18);
    if (*temp_a0 == arg1) {
        *temp_a0 = 0;
    }
}
