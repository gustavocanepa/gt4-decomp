#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
s32 func_00575DA0(s32);                         /* extern */

struct func_00470D60_arg0 {
    char pad0[0x8];
    s32 unk8;
};

void func_00470D60(char *arg0) {
    s32 *var_s0;
    s32 temp_v0;
    s32 var_s1;

    var_s0 = (s32 *)(arg0 + 0x734);
    var_s1 = 2;
    do {
        temp_v0 = *var_s0;
        if (temp_v0 != 0) {
            func_00575DA0(temp_v0);
        }
        var_s1 -= 1;
        *var_s0 = 0;
        var_s0 += 1;
    } while (var_s1 >= 0);
    ((struct func_00470D60_arg0 *)arg0)->unk8 = 0;
}

}
