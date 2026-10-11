#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00426B28_arg0 {
    char pad0[0x18C];
    s32 unk18C;
    char pad190[0x8];
    s32 unk198;
    char pad19C[0x20];
    s32 unk1BC;
};

s32 func_00426B28(struct func_00426B28_arg0 *arg0) {
    s32 temp_v1;

    if (arg0->unk198 & 2) {
        temp_v1 = arg0->unk1BC;
        return (temp_v1 ^ arg0->unk18C) & temp_v1;
    }
    return 0;
}
