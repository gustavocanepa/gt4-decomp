/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004AF108();                            /* extern */
s32 func_004AF688(s32);                         /* extern */
s32 func_004AFDC8(s32);                         /* extern */

void func_004AF650(s32 arg0) {
    func_004AF108();
    func_004AFDC8(arg0 + 0xB0);
    func_004AF688(arg0);
}
