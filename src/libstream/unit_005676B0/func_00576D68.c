#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00576E10(s32, s32, s32, s32, s32, s32); /* extern */
s32 func_00577478(s32);                             /* extern */

void func_00576D68(s32 arg0, s32 arg1) {
    func_00576E10(arg0, 0, 0, func_00577478(arg1), arg1, 0);
}
