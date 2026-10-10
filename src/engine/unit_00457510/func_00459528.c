#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_004594D0(f32, f32, f32);                   /* extern */

struct func_00459528_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};
struct func_00459528_arg2 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};
struct func_00459528_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

void *func_00459528(struct func_00459528_arg0 *arg0, struct func_00459528_arg1 *arg1, struct func_00459528_arg2 *arg2, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f21;
    f32 temp_f22;

    temp_f22 = func_004594D0(arg1->unk0, arg2->unk0, fparg0);
    temp_f21 = func_004594D0(arg1->unk4, arg2->unk4, fparg0);
    temp_f0 = func_004594D0(arg1->unk8, arg2->unk8, fparg0);
    arg0->unk0 = temp_f22;
    arg0->unk4 = temp_f21;
    arg0->unk8 = temp_f0;
    return arg0;
}
