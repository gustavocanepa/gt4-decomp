#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004EF608();                            /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_006895F0[];
struct func_004EF510_arg0 {
    char pad0[0x90];
    s32 unk90;
};

void func_004EF510(struct func_004EF510_arg0 *arg0, s32 arg1) {
    arg0->unk90 = (s32)D_006895F0;
    func_004EF608();
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
