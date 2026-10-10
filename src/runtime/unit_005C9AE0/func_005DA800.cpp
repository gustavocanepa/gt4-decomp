#include "types.h"
struct func_005DA800_a0 {
    char pad0[0xF4];
    s32 unkF4;
};

extern "C" void func_005DA800(struct func_005DA800_a0 *a0, s32 a1) {
    a0->unkF4 = a1;
}
