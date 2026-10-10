#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005041B0(void *, s32);             /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_00689770[];
struct func_00500E48_arg0 {
    char pad0[0x48];
    s32 unk48;
};

void func_00500E48(void *arg0, s32 arg1) {
    ((struct func_00500E48_arg0 *)arg0)->unk48 = (s32)D_00689770;
    func_005041B0(arg0 + 0xC, 2);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
