#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

char * func_005C2560(void *);
struct func_005DC3F8_temp_a1 {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
};

s8 **func_005DC3F8(s8 **arg0, s32 arg1, s8 **arg2) {
    s8 **var_s0;
    s8 **var_s1;
    s8 *temp_v0;
    s8 *var_a2;
    struct func_005DC3F8_temp_a1 *temp_a1;

    var_s1 = arg0;
    var_s0 = arg2;
    if (var_s1 != arg1) {
        do {
            if (var_s0 != NULL) {
                temp_v0 = *var_s1;
                temp_a1 = temp_v0 - 0x10;
                var_a2 = temp_v0;
                if (temp_a1->unkC != 0) {
                    var_a2 = func_005C2560(temp_a1);
                } else {
                    temp_a1->unk8 = (s32) (temp_a1->unk8 + 1);
                }
                *var_s0 = var_a2;
            }
            var_s1 += 1;
            var_s0 += 1;
        } while (var_s1 != arg1);
    }
    return var_s0;
}
