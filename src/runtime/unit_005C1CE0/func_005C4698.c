#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005C4698_temp_v0 {
    char pad0[0x4A4];
    s32 unk4A4;
};

void func_005C4698(s32 arg0, s32 arg1) {
    struct func_005C4698_temp_v0 *temp_v0;

    temp_v0 = *(void **)0x6187A8;
    if (temp_v0 != NULL) {
        temp_v0->unk4A4 = arg1;
    }
}
