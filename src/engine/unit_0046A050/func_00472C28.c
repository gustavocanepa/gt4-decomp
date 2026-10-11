#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00472C28(s32 *arg0, f32 fparg0) {
    s32 temp_a0;

    temp_a0 = *arg0;
    switch (temp_a0) {                              /* irregular */
    case 0:
        return fparg0 * 0x1.0624dc0000000p-10f;
    case 1:
        return fparg0 * 0x1.45c98c0000000p-11f;
    default:
        return fparg0 * 0x1.0624dc0000000p-10f;
    }
}
