#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0046E848();                            /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_00688930[];
struct func_0046E7E8_arg0 {
    char pad0[0x24];
    s32 unk24;
};

void func_0046E7E8(struct func_0046E7E8_arg0 *arg0, s32 arg1) {
    arg0->unk24 = (s32)D_00688930;
    func_0046E848();
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
