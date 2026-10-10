#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00575E60(s32, s32);                /* extern */

struct func_00393700_arg0 {
    s32 unk0;
    s32 unk4;
};

s32 func_00393700(struct func_00393700_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = func_00575E60(0x40, 0x4000);
    arg0->unk0 = temp_v0;
    arg0->unk4 = (s32) (temp_v0 + 0x3000);
}
