/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0058CF88();                                /* extern */
s32 func_0058D040();                                /* extern */
s32 func_0058D3E8(s32, s32);                    /* extern */

void func_0058D480(s32 arg0) {
    s32 temp_s1;

    s32 t;
    temp_s1 = func_0058CF88();
    t = func_0058D040() * 0x3C - 0x21C;
    func_0058D3E8(arg0, temp_s1 + t);
}
