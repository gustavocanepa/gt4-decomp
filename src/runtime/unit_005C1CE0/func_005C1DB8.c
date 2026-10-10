/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00574E78(s32);                         /* extern */
s32 func_00576788();                            /* extern */
s32 func_005767C0(void *);                      /* extern */

struct func_005C1DB8_arg0 {
    char pad0[0x9C];
    s32 unk9C;
    s32 unkA0;
};

void func_005C1DB8(void *arg0, s32 arg1) {
    func_00576788();
    func_00574E78(arg0 + 0x6C);
    ((struct func_005C1DB8_arg0 *)arg0)->unk9C = arg1;
    ((struct func_005C1DB8_arg0 *)arg0)->unkA0 = 1;
    func_005767C0(arg0);
}
