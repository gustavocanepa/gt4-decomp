#include "gt4/mProgressFace.h"
typedef int s32;
typedef float f32;

struct C;

extern "C" f32 func_0025B370(struct C *arg0);
extern "C" void mImageFace__virtual_67(struct mProgressFace *arg0);

extern "C" void mProgressFace__virtual_67(struct mProgressFace *arg0) {
    f32 temp_f0;

    mImageFace__virtual_67(arg0);
    temp_f0 = func_0025B370((struct C *)arg0);
    arg0->unkF8 = 0;
    arg0->unkFC = temp_f0;
}
