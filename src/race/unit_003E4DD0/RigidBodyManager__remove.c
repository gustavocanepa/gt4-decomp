#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003E4F98_arg0 {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
};

s32 RigidBodyManager__remove(struct func_003E4F98_arg0 *arg0, s32 *arg1, s32 *arg2) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0_2 = *arg1;
    if (arg2 != NULL) {
        *arg2 = temp_v0_2;
    } else {
        arg0->unk8 = temp_v0_2;
    }
    temp_v0 = arg0->unkC;
    *arg1 = temp_v0;
    arg0->unkC = (s32) arg1;
    return temp_v0;
}
