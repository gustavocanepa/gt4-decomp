#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 free(s32);                         /* extern */

struct func_00447378_arg0 {
    char pad0[0xA8];
    s32 unkA8;
};

void func_00447378(struct func_00447378_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unkA8;
    if (temp_v0 != 0) {
        free(temp_v0);
        arg0->unkA8 = 0;
    }
}
