#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00577478(s32);                             /* extern */
s32 func_00577518(s32, s32, s32);               /* extern */

void func_005774D8(s32 arg0, s32 arg1) {
    func_00577518(arg0, func_00577478(arg1), arg1);
}
