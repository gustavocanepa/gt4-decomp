/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_0057F238(s32, s32);                        /* extern */
void *func_0058B198(s32);                       /* extern */
s32 func_005B72A8();                                /* extern */
s32 func_005B72F8();                            /* extern */

extern s32 D_00657A80;
struct func_00585868_var_s0 {
    void *unk0;
    s32 unk4;
    char pad8[0x4];
    s32 unkC;
};

s32 func_00585868(s32 arg0) {
    s32 temp_s3;
    s32 temp_v1;
    s32 var_s1;
    struct func_00585868_var_s0 *var_s0;

    if (D_00657A80 == 0) {
        return 0x81058001;
    }
    var_s1 = -1;
    temp_s3 = func_005B72A8();
    var_s0 = M2C_FIELD(func_0058B198(0), void **, 0x18);
    if (var_s0 != NULL) {
        do {
            if (func_0057F238(arg0, var_s0->unk4) == 0) {
                temp_v1 = var_s0->unkC;
                var_s1 = (var_s1 < temp_v1) ? temp_v1 : var_s1;
            }
            var_s0 = var_s0->unk0;
        } while (var_s0 != NULL);
    }
    if (temp_s3 != 0) {
        func_005B72F8();
    }
    return (~var_s1 != 0) ? var_s1 : 0x8105902D;
}
