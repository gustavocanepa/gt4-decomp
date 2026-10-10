#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0044A2A8();                            /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_00688338[];
struct func_00449D78_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void func_00449D78(struct func_00449D78_arg0 *arg0, s32 arg1) {
    arg0->unk10 = (s32)D_00688338;
    func_0044A2A8();
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
