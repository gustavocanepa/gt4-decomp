#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004EF1F0();                            /* extern */
s32 func_004EF510(void *, s32);             /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_006895D8[];
struct func_004EEA40_arg0 {
    char pad0[0x90];
    s32 unk90;
};

void func_004EEA40(struct func_004EEA40_arg0 *arg0, s32 arg1) {
    arg0->unk90 = (s32)D_006895D8;
    func_004EF1F0();
    func_004EF510(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
