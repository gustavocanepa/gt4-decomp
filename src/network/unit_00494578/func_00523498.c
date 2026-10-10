#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00522480(void *);                          /* extern */
s32 func_0056FF88(s32, s32, s32 *, s32, void *, s32); /* extern */
s32 func_005A48D8(void *, s32, s32);    /* extern */

extern char D_00863EC0[];
extern char D_00863F00[];
s32 func_00523498(s32 *arg0) {
    s8 sp[0x10];
    s32 sp10;

    func_005A48D8(sp, 0, 0x10);
    if (func_0056FF88((s32)D_00863EC0, (s32)D_00863F00, &sp10, 1, sp, 2) < 0) {
        return 0xC350;
    }
    *arg0 = func_00522480(sp);
    return 0;
}
