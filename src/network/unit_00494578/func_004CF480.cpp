#include "types.h"
struct func_004CF480_a0 {
    char pad0[0x60];
    s32 unk60;
};

extern "C" void func_004CF480(struct func_004CF480_a0 *a0, s32 a1) {
    a0->unk60 = a1;
}
