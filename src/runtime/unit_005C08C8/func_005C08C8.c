/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): a function of the C++ runtime in libgcc.a (cp/tinfo.cc, tinfo2.cc, exception.cc, new*.cc), in libgcc.a's code at 0x5ba060-0x5c1ce0.
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
#include "types.h"
void *memcpy(void *, const void *, unsigned int);

u32 func_0057F238(s32, s32);                        /* extern */

u32 func_005C08C8(s32 *arg0, s32 *arg1) {
    return func_0057F238(*arg0, *arg1) >> 0x1F;
}
