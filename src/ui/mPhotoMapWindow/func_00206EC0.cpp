#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00206B60(s32, s32);                    /* extern */
s32 func_00206B80(s32, s32);                    /* extern */
s32 func_003285A8(s32);                         /* extern */
s32 func_003285F8(s32);                         /* extern */

void func_00206EC0(s32 arg0, s32 arg1) {
    func_003285A8(arg1);
    func_00206B80(arg0, arg1);
    func_00206B60(arg0, arg1);
    func_003285F8(arg1);
}
