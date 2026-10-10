#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00343C20();                                /* extern */
s32 func_0035AE58(s32);                             /* extern */
s32 func_0035BBD8(s32);                             /* extern */

s32 func_003C9F38(s32 arg0) {
    if ((func_00343C20() != 1) && (func_0035AE58(arg0) != 0)) {
        return func_0035BBD8(arg0);
    }
    return 0;
}
