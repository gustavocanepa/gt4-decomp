#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_00432EB8(s32);
struct func_00433930_arg0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
};

void func_00433930(struct func_00433930_arg0 *arg0, s32 arg1, s32 arg2) {
    s32 temp_a0;
    s32 var_s1;
    s32 var_s2;
    var_s2 = 0;
    arg0->unk4 = arg1;
    arg0->unk8 = arg2;
    if (arg2 > 0) {
        var_s1 = 0;
        do {
            var_s2 += 1;
            temp_a0 = arg0->unk4 + var_s1;
            var_s1 += 0x238;
            func_00432EB8(temp_a0);
        } while (var_s2 < arg0->unk8);
    }
}
