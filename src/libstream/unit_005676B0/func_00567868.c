#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_00567A28(s32);                         /* extern */
s32 func_00567D08(s32);                         /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_00689D10[];
struct func_00567868_arg0 {
    char pad0[0x554];
    s32 unk554;
    s32 unk558;
};

void func_00567868(void *arg0, s32 arg1) {
    s32 temp_v0;

    ((struct func_00567868_arg0 *)arg0)->unk558 = (s32)D_00689D10;
    func_00567A28(arg0 + 0x530);
    temp_v0 = ((struct func_00567868_arg0 *)arg0)->unk554;
    if (temp_v0 != 0) {
        func_00567D08(temp_v0);
        ((struct func_00567868_arg0 *)arg0)->unk554 = 0;
    }
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
