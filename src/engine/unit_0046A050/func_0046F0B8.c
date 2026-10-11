#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0046F118();                            /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_00688948[];
struct func_0046F0B8_arg0 {
    char pad0[0x1C];
    s32 unk1C;
};

void func_0046F0B8(struct func_0046F0B8_arg0 *arg0, s32 arg1) {
    arg0->unk1C = (s32)D_00688948;
    func_0046F118();
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
