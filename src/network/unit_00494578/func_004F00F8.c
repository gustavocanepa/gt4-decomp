#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00572738(s32, s32, s32, s32);  /* extern */

extern char D_006454F0[];
void func_004F00F8(s32 arg0, s32 arg1) {
    func_00572738((s32)D_006454F0, arg0, arg1, 0x10);
}
