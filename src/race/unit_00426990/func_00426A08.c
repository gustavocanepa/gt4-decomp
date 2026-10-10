#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00426A08_arg0 {
    char pad0[0x188];
    s32 unk188;
    char pad18C[0xC];
    s32 unk198;
    char pad19C[0x1C];
    s32 unk1B8;
};

s32 func_00426A08(struct func_00426A08_arg0 *arg0) {
    s32 temp_v1;

    if (arg0->unk198 & 1) {
        temp_v1 = arg0->unk188;
        return (arg0->unk1B8 ^ temp_v1) & temp_v1;
    }
    return 0;
}
