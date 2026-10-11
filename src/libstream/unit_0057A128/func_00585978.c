/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005B72A8();                                /* extern */
s32 func_005B72F8();                            /* extern */

extern void *D_008758B0;
struct func_00585978_var_s0 {
    void *unk0;
    char pad4[0x8];
    s32 unkC;
};

void *func_00585978(s32 arg0) {
    s32 temp_v1;
    struct func_00585978_var_s0 *var_s0;

    temp_v1 = func_005B72A8();
    for (var_s0 = D_008758B0; var_s0 != NULL; var_s0 = var_s0->unk0) {
        if (arg0 == var_s0->unkC) {
            if (temp_v1 != 0) {
                func_005B72F8();
            }
            return var_s0;
        }
    }
    if (temp_v1 != 0) {
        func_005B72F8();
    }
    return NULL;
}
