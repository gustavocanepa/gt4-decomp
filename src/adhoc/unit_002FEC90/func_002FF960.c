#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s16 func_002FF840();                                /* extern */

s32 func_002FF960(s32 arg0, s16 *arg1) {
    *arg1 = func_002FF840();
    return arg0;
}
