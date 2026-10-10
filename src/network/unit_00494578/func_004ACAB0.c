#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004B1B90(void *, s32);                     /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_00688C58[];
struct func_004ACAB0_arg0 {
    char pad0[0xA4];
    s32 unkA4;
};

void func_004ACAB0(struct func_004ACAB0_arg0 *arg0, s32 arg1) {
    arg0->unkA4 = (s32)D_00688C58;
    func_004B1B90(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
