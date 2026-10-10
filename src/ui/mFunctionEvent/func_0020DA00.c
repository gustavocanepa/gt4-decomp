#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_0020DA00_arg0 {
    char pad0[0x28];
    s32 unk28;
};

void func_0020DA00(struct func_0020DA00_arg0 *arg0, s32 arg1, s32 *arg2) {
    s32 *temp_s1;
    s32 temp_s0;
    s32 temp_v0;

    temp_s1 = arg0->unk28 + (arg1 * 4);
    if (temp_s1 != arg2) {
        temp_s0 = *arg2;
        if (temp_s0 != 0) {
            func_003285A8(temp_s0);
        }
        temp_v0 = *temp_s1;
        if (temp_v0 != 0) {
            func_003285F8(temp_v0);
        }
        *temp_s1 = temp_s0;
    }
}
