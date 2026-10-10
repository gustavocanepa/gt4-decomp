#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00574D78();                            /* extern */
s32 func_005A48D8(s32, s32, s32);       /* extern */

void func_005474C8(s32 arg0) {
    func_00574D78();
    func_005A48D8(arg0 + 0x30, 0, 0x120);
}
