#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004AF0A0(void *, s32);             /* extern */
s32 func_004AF708(void *, s32);             /* extern */
s32 func_004AFF60();                            /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_00688F80[];
struct func_004AFE60_arg0 {
    char pad0[0x20];
    s32 unk20;
};

void func_004AFE60(void *arg0, s32 arg1) {
    ((struct func_004AFE60_arg0 *)arg0)->unk20 = (s32)D_00688F80;
    func_004AFF60();
    func_004AF0A0(arg0 + 0x24, 2);
    func_004AF708(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
