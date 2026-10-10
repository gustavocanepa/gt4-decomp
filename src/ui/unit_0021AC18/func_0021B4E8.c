#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0021B4E8_arg0 {
    char pad0[0x8];
    s32 unk8;
};

s32 func_0021B4E8(struct func_0021B4E8_arg0 *arg0) {
    return arg0->unk8 != 0;
}
