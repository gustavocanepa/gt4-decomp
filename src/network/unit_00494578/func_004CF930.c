#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_004CF930_arg0 {
    char pad0[0x8];
    s32 unk8;
    char padC[0x10];
    s32 unk1C;
    char pad20[0x108];
    s32 unk128;
};

s32 func_004CF930(struct func_004CF930_arg0 *arg0, s32 *arg1, s32 *arg2) {
    s32 temp_v0;
    s32 temp_v1;

    temp_v1 = arg0->unk128;
    if (temp_v1 != 0) {
        temp_v0 = arg0->unk8;
        if (temp_v0 != 0) {
            *arg1 = temp_v1 - temp_v0;
            *arg2 = arg0->unk1C - arg0->unk8;
            return arg0->unk8;
        }
    }
    return 0;
}
