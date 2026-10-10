#include "types.h"
struct func_00602D40_a0 {
    char pad0[0x70];
    s64 unk70;
};

extern "C" s64 func_00602D40(struct func_00602D40_a0 *a0) {
    return a0->unk70;
}
