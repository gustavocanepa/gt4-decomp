#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_003C6598(s32);                             /* extern */
s32 func_003C65D0(s32);                         /* extern */
s32 func_00426A08(s32);                             /* extern */

s32 SimplePause__virtual_03(s32 arg0, s32 arg1) {
    if ((func_00426A08(arg1) & 0x80) || (func_00426A08(arg1) & 0x20)) {
        func_003C65D0(arg0);
        return 3;
    }
    return (func_003C6598(arg0) == 0) ? 0 : 2;
}
