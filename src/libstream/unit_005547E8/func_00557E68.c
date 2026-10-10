#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00578480(s32);                         /* extern */

struct func_00557E68_arg0 {
    char pad0[0x770];
    s32 unk770;
    char pad774[0x4];
    s32 unk778;
    char pad77C[0xC];
    s32 unk788;
};

void func_00557E68(struct func_00557E68_arg0 *arg0, s32 arg1) {
    if (arg0->unk770 != 0) {
        if (arg1 == 0) {
            if (arg0->unk778 != 0) {
                arg0->unk778 = 0;
                func_00578480(arg0->unk788);
            }
        } else {
            arg0->unk778 = 1;
        }
    }
}
