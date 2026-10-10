#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

int func_0052EAF8(int, int, int, int, int, int, int);
extern char D_0064A150[];
s32 func_00505AD8(s8 *arg0) {
    func_00506278(arg0, 0x15);
    return (func_0052EAF8(0x40, *(s32 *)D_0064A150, 0xFFFF, 3, 8, 0x1C, (s32) arg0) == 0) ? 0 : -5;
}
