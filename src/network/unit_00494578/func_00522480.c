#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00522480_arg0 {
    char pad0[0x4];
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
};

s32 func_00522480(struct func_00522480_arg0 *arg0) {
    return (((((arg0->unk4 << 8) + arg0->unk5) << 8) + arg0->unk6) << 8) + arg0->unk7;
}
