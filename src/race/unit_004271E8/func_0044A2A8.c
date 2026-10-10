#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00575DA0(s32);                         /* extern */

struct func_0044A2A8_arg0 {
    s64 unk0;
    s32 unk8;
    s32 unkC;
};

void func_0044A2A8(struct func_0044A2A8_arg0 *arg0) {
    arg0->unk0 = -1;
    func_00575DA0(arg0->unk8);
    arg0->unk8 = 0;
    arg0->unkC = 0;
}
