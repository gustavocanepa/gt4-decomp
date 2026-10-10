#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

int func_0052EAF8(int, int, int, int, int, int, int);
extern char D_0064A150[];
s32 func_00505C00(s8 *arg0) {
    func_00506278(arg0, 0x15);
    return (func_0052EAF8(0x40, *(s32 *)D_0064A150, 0xFFFF, 3, 0xC, 0x16, (s32) arg0) == 0) ? 0 : -5;
}
