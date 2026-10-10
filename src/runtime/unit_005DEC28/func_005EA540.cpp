#include "types.h"
struct func_005EA540_a0 {
    char pad0[0xE8];
    s32 unkE8;
};

extern "C" void func_005EA540(struct func_005EA540_a0 *a0, s32 a1) {
    a0->unkE8 = a1;
}
