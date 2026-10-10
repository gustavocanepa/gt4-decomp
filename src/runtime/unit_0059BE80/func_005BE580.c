/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): a function of libgcc.a (libgcc2.c, config/fp-bit.c or frame.c), in libgcc.a's code at 0x5ba060-0x5c1ce0.
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

u8 *func_005BE580(u8 *arg0, s32 *arg1) {
    s32 temp_v0;
    s32 var_t0;
    u32 var_a3;
    u8 *var_a0;
    u8 temp_a2;

    var_a0 = arg0;
    var_a3 = 0;
    var_t0 = 0;
    do {
        temp_a2 = *var_a0;
        var_a0 += 1;
        temp_v0 = (temp_a2 & 0x7F) << var_a3;
        var_a3 += 7;
        var_t0 |= temp_v0;
    } while (temp_a2 & 0x80);
    if ((var_a3 < 0x20U) && (temp_a2 & 0x40)) {
        var_t0 |= -1 << var_a3;
    }
    *arg1 = var_t0;
    return var_a0;
}
