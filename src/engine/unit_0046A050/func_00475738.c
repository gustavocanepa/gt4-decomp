#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00480638(s32);                         /* extern */

struct func_00475738_arg0 {
    s32 unk0;
    char pad4[0x18];
    f32 unk1C;
};

void func_00475738(struct func_00475738_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk0;
    if (temp_v0 != 0) {
        func_00480638(temp_v0);
        arg0->unk1C = 1.0f;
    }
}
