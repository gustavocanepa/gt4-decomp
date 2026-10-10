#include "types.h"
struct func_00602D80_a0 {
    char pad0[0x88];
    u8 unk88;
};

extern "C" u8 func_00602D80(struct func_00602D80_a0 *a0) {
    return a0->unk88;
}
