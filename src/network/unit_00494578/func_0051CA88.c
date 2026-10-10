/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0051BE28();                                /* extern */
s32 func_0051BE60();                            /* extern */
s32 func_0051DD88(s32);                             /* extern */

struct func_0051CA88_temp_v0_2 {
    char pad0[0x40];
    s32 unk40;
};

s32 func_0051CA88(s32 arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_s0;
    s32 var_v0;
    u32 var_a0;
    void **var_v1;
    struct func_0051CA88_temp_v0_2 *temp_v0_2;

    var_v0 = func_0051BE28();
    if (var_v0 == 0) {
        var_s0 = 2;
        temp_v0 = func_0051DD88(arg0);
        var_v1 = temp_v0 + 0x78;
        if (temp_v0 != 0) {
            var_a0 = 0;
            do {
                temp_v0_2 = *var_v1;
                var_v1 += 1;
                if (temp_v0_2 != NULL) {
                    temp_v0_2->unk40 = arg1;
                }
                var_a0 += 1;
            } while (var_a0 < 2U);
            var_s0 = 0;
        }
        func_0051BE60();
        var_v0 = var_s0;
    }
    return var_v0;
}
