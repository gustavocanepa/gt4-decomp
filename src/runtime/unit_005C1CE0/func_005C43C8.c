#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005C43C8_temp_v0 {
    char pad0[0x474];
    s32 unk474;
};

void func_005C43C8(s32 arg0, s32 arg1) {
    struct func_005C43C8_temp_v0 *temp_v0;

    temp_v0 = *(void **)0x6187A8;
    if (temp_v0 != NULL) {
        temp_v0->unk474 = arg1;
    }
}
