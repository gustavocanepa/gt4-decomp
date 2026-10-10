#include "types.h"
struct func_005DA808_a0 {
    char pad0[0xF8];
    s32 unkF8;
};

extern "C" void func_005DA808(struct func_005DA808_a0 *a0, s32 a1) {
    a0->unkF8 = a1;
}
