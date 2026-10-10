/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): a function of the C++ runtime in libgcc.a (cp/tinfo.cc, tinfo2.cc, exception.cc, new*.cc), in libgcc.a's code at 0x5ba060-0x5c1ce0.
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 *exception__structor_3();                               /* extern */

s32 bad_typeid__virtual_01(void **arg0) {
    s32 *var_v0;

    if (arg0 != NULL) {
        var_v0 = M2C_FIELD(*arg0, s32 *(**)(), 4)();
    } else {
        var_v0 = exception__structor_3();
    }
    return *var_v0;
}
