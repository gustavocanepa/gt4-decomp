#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00579358();                                /* extern */

struct func_00434950_arg0 {
    char pad0[0x64];
    s32 unk64;
    s32 unk68;
};

void func_00434950(struct func_00434950_arg0 *arg0) {
    arg0->unk64 = 0;
    arg0->unk68 = func_00579358();
}
