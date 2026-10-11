#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 free(s32);                         /* extern */

struct func_0048F448_arg0 {
    s32 unk0;
    s32 unk4;
};

s32 func_0048F448(struct func_0048F448_arg0 *arg0) {
    s32 temp_a0;
    s32 temp_v0;

    temp_v0 = arg0->unk0;
    if (temp_v0 != 0) {
        arg0->unk0 = 0;
        free(temp_v0);
    }
    temp_a0 = arg0->unk4;
    if (temp_a0 != 0) {
        arg0->unk4 = 0;
        free(temp_a0);
    }
}
