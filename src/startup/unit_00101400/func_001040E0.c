#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005C1628(void *);                      /* extern */

extern char D_00659DD0[];
void func_001040E0(void *arg0, void *arg1) {
    *(s32 *)arg0 = (s32)D_00659DD0;
    func_0010AA18(arg0, 0);
    if ((s32) arg1 & 1) {
        func_005C1628(arg0);
    }
}
