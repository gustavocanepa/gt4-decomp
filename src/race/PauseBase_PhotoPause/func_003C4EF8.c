#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003EC0B0(s32, s32, s32, s32);  /* extern */

struct func_003C4EF8_arg0 {
    char pad0[0x10];
    s32 unk10;
    s32 unk14;
};

s32 func_003C4EF8(struct func_003C4EF8_arg0 *arg0) {
    s32 temp_v0;
    s32 temp_v1;

    temp_v1 = arg0->unk14;
    if (temp_v1 != 0) {
        temp_v0 = arg0->unk10;
        if (temp_v0 != 0) {
            func_003EC0B0(temp_v1, temp_v0, 0x80FFFFFF, 1);
        }
    }
}
