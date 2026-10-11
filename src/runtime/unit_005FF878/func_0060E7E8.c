#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0060E7E8_arg0 {
    char pad0[0x50];
    s32 unk50;
};

s32 func_0060E7E8(struct func_0060E7E8_arg0 *arg0) {
    return arg0->unk50 + 0x500;
}
