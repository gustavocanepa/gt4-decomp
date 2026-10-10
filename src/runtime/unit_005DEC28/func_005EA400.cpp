#include "types.h"
struct func_005EA400_a0 {
    char pad0[0xE0];
    s32 unkE0;
};

extern "C" void func_005EA400(struct func_005EA400_a0 *a0, s32 a1) {
    a0->unkE0 = a1;
}
