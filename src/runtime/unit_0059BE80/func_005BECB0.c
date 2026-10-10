/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): a function of libgcc.a (libgcc2.c, config/fp-bit.c or frame.c), in libgcc.a's code at 0x5ba060-0x5c1ce0.
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00575DC8(s32);                         /* extern */
s32 func_005BEC48(s32, s32);                    /* extern */

void func_005BECB0(s32 arg0) {
    func_005BEC48(arg0, func_00575DC8(0x18));
}
