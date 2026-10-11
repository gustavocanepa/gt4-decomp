#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00491C10(s32, u8);                         /* extern */

struct func_00490180_arg0 {
    char pad0[0x14];
    void *unk14;
    s32 unk18;
};
struct func_00490180_temp_v0 {
    char pad0[0x16];
    u8 unk16;
};

void func_00490180(struct func_00490180_arg0 *arg0, s32 arg1) {
    u8 var_a1;
    struct func_00490180_temp_v0 *temp_v0;

    if (arg1 != 0) {
        temp_v0 = arg0->unk14;
        var_a1 = 0;
        if (temp_v0 != NULL) {
            var_a1 = temp_v0->unk16;
        }
        arg0->unk18 = func_00491C10(arg1, var_a1);
    }
}
