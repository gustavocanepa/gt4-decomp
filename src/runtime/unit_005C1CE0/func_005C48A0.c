#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_005C48A0_temp_v0 {
    char pad0[0x4F0];
    s32 unk4F0;
};

void func_005C48A0(s32 arg0, s32 arg1) {
    struct func_005C48A0_temp_v0 *temp_v0;

    temp_v0 = *(void **)0x6187A8;
    if (temp_v0 != NULL) {
        temp_v0->unk4F0 = arg1;
    }
}
