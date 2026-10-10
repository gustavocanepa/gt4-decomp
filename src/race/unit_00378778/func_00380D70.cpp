#include "types.h"
struct func_00380D70_a0 {
    char pad0[0x1BA];
    u8 unk1BA;
};

extern "C" u8 func_00380D70(struct func_00380D70_a0 *a0) {
    return a0->unk1BA;
}
