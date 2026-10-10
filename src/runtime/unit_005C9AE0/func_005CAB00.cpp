#include "types.h"
struct func_005CAB00_a0 {
    char pad0[0x31];
    s8 unk31;
};

extern "C" void func_005CAB00(struct func_005CAB00_a0 *a0, s8 a1) {
    a0->unk31 = a1;
}
