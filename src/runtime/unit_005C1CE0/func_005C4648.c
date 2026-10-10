#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_005C4648_temp_v0 {
    char pad0[0x494];
    s32 unk494;
};

void func_005C4648(s32 arg0, s32 arg1) {
    struct func_005C4648_temp_v0 *temp_v0;

    temp_v0 = *(void **)0x6187A8;
    if (temp_v0 != NULL) {
        temp_v0->unk494 = arg1;
    }
}
