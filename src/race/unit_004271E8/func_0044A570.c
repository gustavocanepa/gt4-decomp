#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0044A548();                                /* extern */

s32 func_0044A570(s32 *arg0) {
    return *arg0 + (func_0044A548() * 0x10) + 8;
}
