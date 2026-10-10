#include "types.h"
struct func_004CF500_a0 {
    char pad0[0x90];
    s32 unk90;
};

extern "C" void func_004CF500(struct func_004CF500_a0 *a0, s32 a1) {
    a0->unk90 = a1;
}
