#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00426A38_arg0 {
    char pad0[0x188];
    s32 unk188;
    char pad18C[0xC];
    s32 unk198;
    char pad19C[0x1C];
    s32 unk1B8;
};

s32 func_00426A38(struct func_00426A38_arg0 *arg0) {
    s32 temp_v1;

    if (arg0->unk198 & 2) {
        temp_v1 = arg0->unk1B8;
        return (temp_v1 ^ arg0->unk188) & temp_v1;
    }
    return 0;
}
