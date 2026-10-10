#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00398438(void *, f32, f32);            /* extern */

struct func_00398758_arg0 {
    char pad0[0xA70];
    f32 unkA70;
    f32 unkA74;
    f32 unkA78;
};
struct func_00398758_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

void *func_00398758(struct func_00398758_arg0 *arg0, struct func_00398758_arg1 *arg1) {
    f32 temp_f2;

    func_00398438(arg1, arg0->unkA70, arg0->unkA74);
    temp_f2 = arg0->unkA78;
    arg1->unk0 = (f32) (arg1->unk0 * temp_f2);
    arg1->unk4 = (f32) (arg1->unk4 * temp_f2);
    arg1->unk8 = (f32) (arg1->unk8 * temp_f2);
    return arg1;
}
