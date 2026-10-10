#include "types.h"
struct func_004CF408_a0 {
    char pad0[0x40];
    s32 unk40;
};

extern "C" void func_004CF408(struct func_004CF408_a0 *a0, s32 a1) {
    a0->unk40 = a1;
}
