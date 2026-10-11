#include "types.h"
#include "gt4/mSetState.h"
void *memcpy(void *, const void *, unsigned int);

s32 HIO__read8(s32);                             /* extern */

void mSetState__read(struct mSetState *arg0, s32 arg1) {
    arg0->unk8 = HIO__read8(arg1);
}
