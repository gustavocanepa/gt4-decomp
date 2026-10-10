#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00559C80(s32);                         /* extern */

struct func_00462960_arg0 {
    char pad0[0x20];
    s32 unk20;
};

void func_00462960(struct func_00462960_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk20;
    if (temp_v0 != 0) {
        func_00559C80(temp_v0);
        arg0->unk20 = 0;
    }
}
