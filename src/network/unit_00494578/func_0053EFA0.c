#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00538C68(s32);                         /* extern */

struct func_0053EFA0_arg0 {
    char pad0[0x44];
    s32 unk44;
};

s32 func_0053EFA0(void *arg0) {
    func_00538C68(arg0 + 0x44);
    ((struct func_0053EFA0_arg0 *)arg0)->unk44 = 0;
    return 0;
}
