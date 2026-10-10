#include "types.h"
struct func_00602FD8_a0 {
    char pad0[0x24];
    s32 unk24;
};

extern "C" void func_00602FD8(struct func_00602FD8_a0 *a0, s32 a1) {
    a0->unk24 = a1;
}
