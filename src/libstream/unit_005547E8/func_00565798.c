/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005654E0(void *);                      /* extern */
s32 func_00578480(s32);                         /* extern */
s32 func_00578500(s32);                         /* extern */

struct func_00565798_arg0 {
    char pad0[0x48];
    s32 unk48;
    char pad4C[0x10];
    s32 unk5C;
};

void func_00565798(struct func_00565798_arg0 *arg0, s32 arg1) {
    func_00578500(arg0->unk5C);
    arg0->unk48 = arg1;
    func_005654E0(arg0);
    func_00578480(arg0->unk5C);
}
