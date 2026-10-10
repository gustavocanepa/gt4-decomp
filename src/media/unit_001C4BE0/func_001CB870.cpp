#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_001CB850();                            /* extern */
s32 func_0057DA20(s32, s32, s32);           /* extern */
s32 func_0057F260(s32);                             /* extern */

extern char D_00694C68[];
void func_001CB870(s32 arg0, s32 arg1) {
    func_001CB850();
    func_0057DA20(arg0 + func_0057F260(arg0), (s32)D_00694C68, arg1);
}
