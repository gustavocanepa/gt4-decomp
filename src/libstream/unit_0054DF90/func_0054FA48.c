#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00562A70(s32, s32, s32);               /* extern */
s32 func_00564888(s32);                             /* extern */
s32 func_00564910(s32);                         /* extern */

struct func_0054FA48_arg0 {
    char pad0[0xC];
    s32 unkC;
    char pad10[0x10];
    s32 unk20;
};

s32 func_0054FA48(struct func_0054FA48_arg0 *arg0, s32 arg1) {
    func_00562A70(func_00564888(arg0->unkC), arg1, arg0->unk20);
    func_00564910(arg0->unkC);
    return 0;
}
