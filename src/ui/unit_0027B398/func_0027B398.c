#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0024D1B0();                                /* extern */
s32 func_0027AE48(s32);                         /* extern */

s32 func_0027B398(s32 arg0) {
    if (func_0024D1B0() == 0) {
        func_0027AE48(arg0);
        return 1;
    }
    return 0;
}
