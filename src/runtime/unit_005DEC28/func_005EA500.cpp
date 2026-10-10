#include "types.h"
struct func_005EA500_a0 {
    char pad0[0x104];
    s32 unk104;
};

extern "C" void func_005EA500(struct func_005EA500_a0 *a0, s32 a1) {
    a0->unk104 = a1;
}
