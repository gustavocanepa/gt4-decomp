/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_0064B70C[];
struct func_00538988_var_v1 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x8];
    s32 unk10;
};

s32 func_00538988(s32 arg0) {
    s32 temp_v1;
    void *temp_a1;
    struct func_00538988_var_v1 *var_v1;

    var_v1 = **(void ***)D_0064B70C;
    if ((var_v1 != NULL) && (var_v1->unk10 != arg0)) {
        temp_a1 = var_v1;
loop_3:
        temp_v1 = var_v1->unk4;
        var_v1 = (void *) (((temp_v1 ^ (s32) temp_a1) == 0) ? 0 : temp_v1);
        if (var_v1 != NULL) {
            if (var_v1->unk10 != arg0) {
                goto loop_3;
            }
        }
    }
    return (s32) var_v1;
}
