#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_00686118[];
struct func_004009A8_arg0 {
    char pad0[0x24];
    s32 unk24;
};

s32 func_004009A8(struct func_004009A8_arg0 *arg0) {
    arg0->unk24 = (s32)D_00686118;
}
