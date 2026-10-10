#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_006025B8_arg0 {
    char pad0[0x6];
    u8 unk6;
};

s32 func_006025B8(struct func_006025B8_arg0 *arg0) {
    return arg0->unk6 != 0;
}
