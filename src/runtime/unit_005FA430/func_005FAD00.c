#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_005FAD00_arg0 {
    char pad0[0x14];
    s32 unk14;
    char pad18[0x180];
    s32 unk198;
};

void func_005FAD00(struct func_005FAD00_arg0 *arg0) {
    arg0->unk198 = (s32) (arg0->unk14 + 0x100);
}
