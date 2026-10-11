#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001C76C8(void *, s32);             /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_00660CC0[];
struct func_001C6B10_arg0 {
    char pad0[0x1DDC];
    s32 unk1DDC;
};

void func_001C6B10(void *arg0, s32 arg1) {
    ((struct func_001C6B10_arg0 *)arg0)->unk1DDC = (s32)D_00660CC0;
    func_001C76C8(arg0 + 0xBD8, 2);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
