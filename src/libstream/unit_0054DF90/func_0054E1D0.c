#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 free(s32);                         /* extern */

struct func_0054E1D0_arg0 {
    char pad0[0x190];
    s32 unk190;
};

void func_0054E1D0(struct func_0054E1D0_arg0 *arg0) {
    free(arg0->unk190);
    arg0->unk190 = 0;
}
