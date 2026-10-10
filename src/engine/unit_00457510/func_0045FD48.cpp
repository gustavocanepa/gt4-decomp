#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern "C" {
struct func_0045FD48_arg0 {
    char pad0[0x4];
    void *unk4;
};

void func_0045FD48(char *arg0) {
    s32 *var_v1;
    s32 var_a1;
    char *temp_v0;

    temp_v0 = (char *)(((struct func_0045FD48_arg0 *)arg0)->unk4);
    var_v1 = (s32 *)(arg0 + 0x90);
    ((struct func_0045FD48_arg0 *)arg0)->unk4 = arg0;
    var_a1 = 0x1F;
    do {
        var_a1 -= 1;
        *var_v1 += arg0 - temp_v0;
        var_v1 += 1;
    } while (var_a1 >= 0);
}

}
