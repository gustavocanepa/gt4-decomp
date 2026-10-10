#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0055F4C0(s32 *, s32);              /* extern */
s32 func_00574DA8(s32, s32);                /* extern */
s32 func_005C1628(s32 *);                       /* extern */

extern char D_00689CA8[];
void func_005663E8(s32 *arg0, s32 arg1) {
    *arg0 = (s32)D_00689CA8;
    func_00574DA8(arg0 + 1, 2);
    func_0055F4C0(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
