#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004B3E50(s32);                     /* extern */
s32 func_0057F238(s32, s32);                /* extern */

extern char D_0068BB20[];
extern char D_0068CC60[];
extern char D_0068CD18[];
void func_00108E88(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    if (func_0057F238((s32)D_0068BB20, (s32)D_0068CC60) == 0) {
        func_004B3E50((s32)D_0068CD18);
    }
}
