#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003EC0B0(s32, s32, s32, s32);  /* extern */

struct func_003DD690_arg0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
    char padC[0xD0];
    s32 unkDC;
};

s32 func_003DD690(struct func_003DD690_arg0 *arg0) {
    s32 temp_v0;

    if (arg0->unkDC != 0) {
        temp_v0 = arg0->unk8;
        if (temp_v0 != 0) {
            func_003EC0B0(temp_v0, arg0->unk4, 0x80FFFFFF, 0);
        }
    }
}
