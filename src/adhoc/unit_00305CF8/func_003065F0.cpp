#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00306180(s32, s32, s32 *);             /* extern */
s32 func_00323CD0(s32);                             /* extern */

void func_003065F0(s32 arg0, s32 *arg1) {
    func_00306180(arg0, func_00323CD0(*arg1), arg1);
}
