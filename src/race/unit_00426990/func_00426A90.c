#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00426A90_arg0 {
    char pad0[0x174];
    s32 unk174;
    char pad178[0x20];
    s32 unk198;
    char pad19C[0x8];
    s32 unk1A4;
};

s32 func_00426A90(struct func_00426A90_arg0 *arg0) {
    s32 temp_v1;

    if (arg0->unk198 & 1) {
        temp_v1 = arg0->unk174;
        return (arg0->unk1A4 ^ temp_v1) & temp_v1;
    }
    return 0;
}
