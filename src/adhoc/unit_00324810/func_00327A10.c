#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002EC530(s32);                         /* extern */
s32 hADHOC__structor_0(s32);                         /* extern */
s32 func_00326750(s32, s32, s32);       /* extern */
s32 func_003285A8(s32);                         /* extern */

s32 func_00327A10(s32 *arg0) {
    s32 temp_v0;

    if (*arg0 == 0) {
        temp_v0 = func_00326750(0x78, 4, (s32)"RefCounter");
        hADHOC__structor_0(temp_v0);
        *arg0 = temp_v0;
        func_003285A8(temp_v0);
        func_002EC530(*arg0);
    }
    return *arg0;
}
