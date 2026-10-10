#include "types.h"
struct func_004CF400_a0 {
    char pad0[0x3C];
    s32 unk3C;
};

extern "C" void func_004CF400(struct func_004CF400_a0 *a0, s32 a1) {
    a0->unk3C = a1;
}
