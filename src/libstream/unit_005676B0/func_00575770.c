#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

u32 func_00575610(void *);                          /* extern */
u32 *func_005757E8();                               /* extern */

struct func_00575770_arg0 {
    char pad0[0x44];
    u32 *unk44;
};

u32 *func_00575770(struct func_00575770_arg0 *arg0, u32 arg1) {
    u32 *var_s0;

    var_s0 = func_005757E8();
    if ((var_s0 == NULL) && (func_00575610(arg0) >= (u32) (arg1 + 4))) {
        var_s0 = arg0->unk44;
        *var_s0 = arg1;
        arg0->unk44 = (u32 *) (&var_s0[arg1 >> 2] + 1);
    }
    return var_s0;
}
