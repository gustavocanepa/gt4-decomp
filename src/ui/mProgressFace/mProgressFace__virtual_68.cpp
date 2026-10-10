#include "types.h"
#include "gt4/mProgressFace.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0025B3A0(void *, f32);                 /* extern */
s32 mImageFace__virtual_68();                            /* extern */

void mProgressFace__virtual_68(void *arg0) {
    mImageFace__virtual_68();
    func_0025B3A0(arg0, ((struct mProgressFace *)arg0)->unkFC);
}
