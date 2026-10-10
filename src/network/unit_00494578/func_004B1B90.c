#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004B1670(void *, s32);             /* extern */
s32 func_004B1AA8(s32, s32);                /* extern */
s32 func_004B3718(void *, s32);             /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_00689268[];
struct func_004B1B90_arg0 {
    char pad0[0xA4];
    s32 unkA4;
};

void func_004B1B90(void *arg0, s32 arg1) {
    ((struct func_004B1B90_arg0 *)arg0)->unkA4 = (s32)D_00689268;
    func_004B1AA8(arg0 + 0xE8, 2);
    func_004B3718(arg0 + 0xC4, 2);
    func_004B1670(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
