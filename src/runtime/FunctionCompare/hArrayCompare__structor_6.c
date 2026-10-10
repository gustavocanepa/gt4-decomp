#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_002F9B38(s32, s32);                /* extern */
s32 func_005C1628(s32 *);                       /* extern */

extern char hArrayCompare__vtable[];
extern char FunctionCompare__vtable[];
void hArrayCompare__structor_6(s32 *arg0, s32 arg1) {
    *arg0 = (s32)FunctionCompare__vtable;
    func_002F9B38(arg0 + 1, 2);
    *arg0 = (s32)hArrayCompare__vtable;
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
