#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0060EE40_arg0 {
    char pad0[0xFDC];
    s32 unkFDC;
};

u32 func_0060EE40(struct func_0060EE40_arg0 *arg0) {
    return (u32) ~arg0->unkFDC >> 0x1F;
}
