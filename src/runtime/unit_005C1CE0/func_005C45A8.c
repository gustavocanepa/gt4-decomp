#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005C45A8_temp_v0 {
    char pad0[0x49C];
    s32 unk49C;
};

void func_005C45A8(s32 arg0, s32 arg1) {
    struct func_005C45A8_temp_v0 *temp_v0;

    temp_v0 = *(void **)0x6187A8;
    if (temp_v0 != NULL) {
        temp_v0->unk49C = arg1;
    }
}
