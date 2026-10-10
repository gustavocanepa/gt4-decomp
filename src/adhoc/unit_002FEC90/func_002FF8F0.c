#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s8 func_002FF818();                                 /* extern */

s32 func_002FF8F0(s32 arg0, s8 *arg1) {
    *arg1 = func_002FF818();
    return arg0;
}
