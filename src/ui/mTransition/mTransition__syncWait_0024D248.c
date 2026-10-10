#include "types.h"
#include "gt4/mTransition.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void mUpdateContext__Sync(s32);
void mTransition__syncWait(struct mTransition *arg0) {
    while (arg0->unk18 == 1) {
        mUpdateContext__Sync(1);
    }
}
