#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00426AC0_arg0 {
    char pad0[0x174];
    s32 unk174;
    char pad178[0x20];
    s32 unk198;
    char pad19C[0x8];
    s32 unk1A4;
};

s32 func_00426AC0(struct func_00426AC0_arg0 *arg0) {
    s32 temp_v1;

    if (arg0->unk198 & 2) {
        temp_v1 = arg0->unk1A4;
        return (temp_v1 ^ arg0->unk174) & temp_v1;
    }
    return 0;
}
