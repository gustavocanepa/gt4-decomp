#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005F0390_arg0 {
    char pad0[0x2C];
    void *unk2C;
};
struct func_005F0390_temp_s2 {
    char pad0[0x14];
    s32 unk14;
    char pad18[0x8];
    s32 unk20;
};

void func_005F0390(struct func_005F0390_arg0 *arg0, s32 *arg1) {
    s32 *temp_s1;
    s32 temp_s0;
    s32 temp_v0;
    struct func_005F0390_temp_s2 *temp_s2;

    temp_s2 = arg0->unk2C;
    temp_s1 = temp_s2->unk14 + (temp_s2->unk20 * 4);
    if (temp_s1 != arg1) {
        temp_s0 = *arg1;
        if (temp_s0 != 0) {
            func_003285A8(temp_s0);
        }
        temp_v0 = *temp_s1;
        if (temp_v0 != 0) {
            func_003285F8(temp_v0);
        }
        *temp_s1 = temp_s0;
    }
    temp_s2->unk20 = (s32) (temp_s2->unk20 + 1);
}
