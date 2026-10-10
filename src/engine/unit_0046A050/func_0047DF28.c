#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0047DF28_arg0 {
    f32 unk0;
    f32 unk4;
};
struct func_0047DF28_arg1 {
    f32 unk0;
    f32 unk4;
};
struct func_0047DF28_arg2 {
    f32 unk0;
    f32 unk4;
};

void func_0047DF28(struct func_0047DF28_arg0 *arg0, struct func_0047DF28_arg1 *arg1, struct func_0047DF28_arg2 *arg2, f32 fparg0) {
    f32 temp_f2;

    temp_f2 = 1.0f - fparg0;
    arg0->unk0 = (f32) ((temp_f2 * arg1->unk0) + (fparg0 * arg2->unk0));
    arg0->unk4 = (f32) ((temp_f2 * arg1->unk4) + (fparg0 * arg2->unk4));
}
