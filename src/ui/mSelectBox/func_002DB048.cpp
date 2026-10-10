#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002DA5D0(s32);                         /* extern */
s32 func_002DB148(s32);                         /* extern */
s32 func_0057CE40(s32);                         /* extern */

void func_002DB048(s32 arg0) {
    func_0057CE40(arg0 + 0xBC);
    func_002DB148(arg0);
    func_002DA5D0(arg0);
}
