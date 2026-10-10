#include "types.h"
#include "gt4/mColorTransition.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 mTransition__panIn();                            /* extern */

void mColorTransition__panIn(struct mColorTransition *arg0) {
    mTransition__panIn();
    arg0->unk20 = 1.0f;
}
