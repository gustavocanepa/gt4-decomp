#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005FD4A0_arg0 {
    char pad0[0x80];
    s32 unk80;
};

void *func_005FD4A0(void *arg0, void *arg1, void *arg2) {
    s32 temp_s0;
    void *temp_v0;
    void *temp_v1;
    void *var_a0;

    temp_s0 = (arg0 + (((struct func_005FD4A0_arg0 *)arg0)->unk80 * 4)) - arg2;
    func_005A47D4(arg1, arg2, temp_s0);
    temp_v1 = arg1 + temp_s0;
    temp_v0 = arg0 + (((struct func_005FD4A0_arg0 *)arg0)->unk80 * 4);
    var_a0 = temp_v1;
    if (temp_v1 != temp_v0) {
        do {
            var_a0 += 4;
        } while (var_a0 != temp_v0);
    }
    ((struct func_005FD4A0_arg0 *)arg0)->unk80 = (s32) ((s32) (temp_v1 - arg0) >> 2);
    return arg1;
}
