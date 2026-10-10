#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00489300(void *, s32);                 /* extern */

struct func_00418818_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

struct func_00418818_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

void func_00418818(void *arg0, struct func_00418818_arg1 *arg1) {
    func_00489300(arg1, arg0 + 0x10);
    arg1->unk0 = (f32) (arg1->unk0 + ((struct func_00418818_arg0 *)arg0)->unk0);
    arg1->unk4 = (f32) (arg1->unk4 + ((struct func_00418818_arg0 *)arg0)->unk4);
    arg1->unk8 = (f32) (arg1->unk8 + ((struct func_00418818_arg0 *)arg0)->unk8);
}
