/* libio (GNU iostream library, gcc 2000-10-03 snapshot): ostream::do_osfx.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_00593020();                            /* extern */
s32 fflush(s32);                         /* extern */

extern char _impure_ptr[];
s32 func_00593370(void **arg0) {
    if (M2C_FIELD(*arg0, s64 *, 0x10) & 0x2000) {
        func_00593020();
    }
    if (M2C_FIELD(*arg0, s64 *, 0x10) & 0x4000) {
        fflush(M2C_FIELD(*(void **)(s32)_impure_ptr, s32 *, 8));
        fflush(M2C_FIELD(*(void **)(s32)_impure_ptr, s32 *, 0xC));
    }
}
