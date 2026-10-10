#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 ModelSet2__DMAsafe(s32);                         /* extern */

struct func_00451200_temp_a0 {
    char pad0[0x18];
    s32 unk18;
};

s32 func_00451200(void **arg0) {
    s32 temp_v0;
    struct func_00451200_temp_a0 *temp_a0;

    temp_a0 = *arg0;
    if (temp_a0 != NULL) {
        temp_v0 = temp_a0->unk18;
        if (temp_v0 != 0) {
            ModelSet2__DMAsafe(temp_v0);
        }
    }
}
