#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004AFE60(void *, s32);             /* extern */
s32 func_00557EC0();                            /* extern */
s32 func_00567868(void *, s32);             /* extern */
s32 func_005C1628(void *);                      /* extern */
s32 func_006110B0(void *, s32);             /* extern */

extern char D_00689A60[];
struct func_00557D48_arg0 {
    char pad0[0x79C];
    s32 unk79C;
};

void func_00557D48(void *arg0, s32 arg1) {
    ((struct func_00557D48_arg0 *)arg0)->unk79C = (s32)D_00689A60;
    func_00557EC0();
    func_006110B0(arg0 + 0x630, 2);
    func_00567868(arg0 + 0xD0, 2);
    func_004AFE60(arg0, 2);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
