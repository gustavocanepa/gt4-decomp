#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003A9640(s32, f32);                    /* extern */
s32 func_003A9780(s32);                         /* extern */

void RaceCarIconDisplay__virtual_09(s32 arg0, f32 fparg0) {
    func_003A9780(arg0 + 0x28);
    func_003A9640(arg0 + 0x44, fparg0);
}
