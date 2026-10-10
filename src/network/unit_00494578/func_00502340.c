/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005017A8(s32);                         /* extern */
s32 func_00501A28(s32);                         /* extern */
s32 func_00501A58();                            /* extern */
s32 func_00502428(s32);                         /* extern */

void func_00502340(s32 arg0) {
    func_00501A58();
    func_00502428(arg0);
    func_005017A8(arg0);
    func_00501A28(arg0);
}
