#include "types.h"
struct func_00601600_a0 {
    char pad0[0x12];
    u8 unk12;
};

extern "C" u8 func_00601600(struct func_00601600_a0 *a0) {
    return a0->unk12;
}
