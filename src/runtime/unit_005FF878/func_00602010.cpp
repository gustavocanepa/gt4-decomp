#include "types.h"
struct func_00602010_a0 {
    char pad0[0x11CC];
    s32 unk11CC;
};

extern "C" void func_00602010(struct func_00602010_a0 *a0, s32 a1) {
    a0->unk11CC = a1;
}
