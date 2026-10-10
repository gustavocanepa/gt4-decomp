#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00460A90(s32);                         /* extern */

struct func_002C3C70_arg0 {
    char pad0[0x10];
    s32 unk10;
    s32 unk14;
};

void func_002C3C70(struct func_002C3C70_arg0 *arg0) {
    if (arg0->unk10 != 0) {
        func_00460A90(arg0->unk14);
        arg0->unk14 = 0;
    }
}
