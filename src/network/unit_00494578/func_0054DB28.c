/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005632B8();                            /* extern */

extern char D_0064C4A8[];
void func_0054DB28(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    *(s32 *)D_0064C4A8 = 1;
    func_005632B8();
}
