/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_005F6350(s32 arg0) {
    s32 *var_a0;
    s32 var_v0;

    var_a0 = arg0 + 0x11C;
    var_v0 = 0x47;
    do {
        var_v0 -= 1;
        *var_a0 = 0;
        var_a0 -= 1;
    } while (var_v0 >= 0);
}
