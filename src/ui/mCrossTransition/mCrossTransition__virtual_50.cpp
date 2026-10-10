#include "gt4/mCrossTransition.h"
typedef int s32;
typedef float f32;

extern "C" void mTransition__virtual_50(struct mCrossTransition *arg0);

extern "C" void mCrossTransition__virtual_50(struct mCrossTransition *arg0) {
    mTransition__virtual_50(arg0);
    arg0->unk3C = 0;
    arg0->unk24 = 1.0f;
}
