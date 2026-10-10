#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004B29E0(s32 *, s32);              /* extern */
s32 func_004B3B58(s32, s32);                /* extern */
s32 func_005C1628(s32 *);                       /* extern */

extern char D_00689418[];
void func_004B3718(s32 *arg0, s32 arg1) {
    *arg0 = (s32)D_00689418;
    func_004B3B58(arg0 + 0x4, 2);
    func_004B29E0(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
