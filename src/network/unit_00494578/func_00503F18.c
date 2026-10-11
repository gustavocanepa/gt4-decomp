/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00503CC8(s32, s32);                    /* extern */
s32 func_00503ED0();                                /* extern */

void func_00503F18(s32 arg0) {
    func_00503CC8(arg0, func_00503ED0());
}
