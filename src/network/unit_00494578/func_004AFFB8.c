#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004AF568(s32);                         /* extern */

struct func_004AFFB8_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_004AFFB8(struct func_004AFFB8_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk4;
    if (temp_v0 != 0) {
        func_004AF568(temp_v0);
        arg0->unk4 = 0;
    }
}
