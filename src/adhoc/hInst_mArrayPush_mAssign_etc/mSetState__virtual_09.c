#include "types.h"
#include "gt4/mSetState.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_002FF818(s32);                             /* extern */

void mSetState__virtual_09(struct mSetState *arg0, s32 arg1) {
    arg0->unk8 = func_002FF818(arg1);
}
