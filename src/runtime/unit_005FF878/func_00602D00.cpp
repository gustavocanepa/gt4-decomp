#include "types.h"
struct func_00602D00_a0 {
    char pad0[0x40];
    s64 unk40;
};

extern "C" s64 func_00602D00(struct func_00602D00_a0 *a0) {
    return a0->unk40;
}
