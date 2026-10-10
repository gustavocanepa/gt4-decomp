#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004AEFF0();                            /* extern */
s32 func_0060A480(s32);                         /* extern */

extern char D_00688E78[];
struct func_004AEC68_arg0 {
    char pad0[0xA8];
    s32 unkA8;
};

void func_004AEC68(void *arg0) {
    func_004AEFF0();
    ((struct func_004AEC68_arg0 *)arg0)->unkA8 = (s32)D_00688E78;
    func_0060A480(arg0 + 0xAC);
}
