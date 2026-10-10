#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0047E5D0();                            /* extern */
s32 func_0047E768(s32);                         /* extern */

struct func_00474ED0_arg0 {
    char pad0[0x20];
    s32 unk20;
};

void func_00474ED0(void *arg0) {
    func_0047E5D0();
    func_0047E768(arg0 + 0x18);
    ((struct func_00474ED0_arg0 *)arg0)->unk20 = 0;
}
