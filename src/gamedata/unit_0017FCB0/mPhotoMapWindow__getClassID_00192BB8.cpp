#include "gt4/mPhotoMapWindow.h"
typedef int s32;

extern "C" int mPhotoMapWindow__GetClassID(void) throw();

extern "C" void mPhotoMapWindow__getClassID(struct mPhotoMapWindow *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mPhotoMapWindow__GetClassID();
    }
}
