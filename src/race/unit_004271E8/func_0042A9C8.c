#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0042A9C8_arg0 {
    char pad0[0x2C];
    s32 (*unk2C)(s32);
};

s32 func_0042A9C8(struct func_0042A9C8_arg0 *arg0, s32 arg1) {
    s32 (*temp_v0)(s32);

    temp_v0 = arg0->unk2C;
    if (temp_v0 != NULL) {
        return temp_v0(arg1);
    }
    return 0;
}
