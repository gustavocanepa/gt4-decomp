#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004AA6B8(s32);                         /* extern */

struct func_001055C0_arg0 {
    s32 unk0;
    char pad4[0x2C];
    s32 unk30;
    s32 unk34;
};

void func_001055C0(struct func_001055C0_arg0 *arg0) {
    if (arg0->unk34 != 0) {
        func_004AA6B8(arg0->unk0);
    }
    arg0->unk30 = 0;
    arg0->unk34 = 0;
    arg0->unk0 = -1;
}
