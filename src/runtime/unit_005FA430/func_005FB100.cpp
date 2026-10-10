#include "types.h"
struct func_005FB100_a0 {
    char pad0[0x80];
    s32 unk80;
};

extern "C" void func_005FB100(struct func_005FB100_a0 *a0, s32 a1) {
    a0->unk80 = a1;
}
