#include "types.h"
struct func_00603500_a0 {
    char pad0[0x42];
    u8 unk42;
};

extern "C" u8 func_00603500(struct func_00603500_a0 *a0) {
    return a0->unk42;
}
