#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00575DA0(s32);                         /* extern */

struct func_0046F688_arg0 {
    s32 unk0;
    s32 unk4;
    char pad8[0xA60];
    s32 unkA68;
};

void func_0046F688(struct func_0046F688_arg0 *arg0) {
    s32 temp_v0;

    arg0->unk4 = 0;
    temp_v0 = arg0->unkA68;
    arg0->unk0 = 0;
    if (temp_v0 != 0) {
        func_00575DA0(temp_v0);
    }
    arg0->unkA68 = 0;
}
