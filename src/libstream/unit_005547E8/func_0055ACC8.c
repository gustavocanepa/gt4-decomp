#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_0055ACC8_arg0 {
    char pad0[0x28];
    s64 unk28;
    char pad30[0x30];
    s32 unk60;
};

void func_0055ACC8(struct func_0055ACC8_arg0 *arg0, s64 *arg1) {
    if (arg0->unk60 != 0) {
        arg0->unk28 = (s64) (arg0->unk28 & ~*arg1);
    }
}
