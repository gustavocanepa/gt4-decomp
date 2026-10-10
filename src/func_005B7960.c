/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005AD8C0(s32);                         /* extern */
s32 func_005B78A0();                            /* extern */

void func_005B7960(s32 arg0) {
    func_005B78A0();
    func_005AD8C0(arg0);
}
