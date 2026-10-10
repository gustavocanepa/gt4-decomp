/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): a function of libgcc.a (libgcc2.c, config/fp-bit.c or frame.c), in libgcc.a's code at 0x5ba060-0x5c1ce0.
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

u8 *func_005BE538(u8 *arg0, s32 *arg1) {
    s32 var_a2;
    s32 var_a3;
    u8 *var_a0;
    u8 temp_v1;
    u8 temp_v1_2;

    temp_v1 = *arg0;
    var_a0 = arg0 + 1;
    var_a3 = 0;
    var_a2 = temp_v1 & 0x7F;
    if (temp_v1 & 0x80) {
        do {
            temp_v1_2 = *var_a0;
            var_a0 += 1;
            var_a3 += 7;
            var_a2 |= (temp_v1_2 & 0x7F) << var_a3;
        } while (temp_v1_2 & 0x80);
    }
    *arg1 = var_a2;
    return var_a0;
}
