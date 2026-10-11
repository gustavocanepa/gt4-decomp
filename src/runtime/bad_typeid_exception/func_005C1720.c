/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): a function of the C++ runtime in libgcc.a (cp/tinfo.cc, tinfo2.cc, exception.cc, new*.cc), in libgcc.a's code at 0x5ba060-0x5c1ce0.
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
#include "types.h"
void *memcpy(void *, const void *, unsigned int);

void **func_005BC6E8();                             /* extern */

struct func_005C1720_temp_a0 {
    char pad0[0x14];
    s32 unk14;
    char pad18[0x8];
    s64 unk20;
};

void *func_005C1720(void) {
    struct func_005C1720_temp_a0 *temp_a0;

    temp_a0 = *func_005BC6E8();
    temp_a0->unk14 = 1;
    temp_a0->unk20 = (s64) (temp_a0->unk20 + 1);
    return temp_a0;
}
