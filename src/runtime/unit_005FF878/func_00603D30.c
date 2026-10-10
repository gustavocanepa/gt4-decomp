/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0044EF18(f32, f32, f32);               /* extern */

struct func_00603D30_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

void func_00603D30(s32 arg0, struct func_00603D30_arg1 *arg1) {
    func_0044EF18(arg1->unk0, arg1->unk4, arg1->unk8);
}
