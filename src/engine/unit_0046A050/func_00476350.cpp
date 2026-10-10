#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00476790(s32);                         /* extern */
s32 func_004768C0(s32);                         /* extern */

void func_00476350(s32 arg0, s32 arg1) {
    func_00476790(arg0 + 0x18C);
    func_004768C0(arg1);
}
