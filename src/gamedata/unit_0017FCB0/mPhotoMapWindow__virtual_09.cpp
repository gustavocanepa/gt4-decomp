#include "gt4/mPhotoMapWindow.h"
typedef int s32;

extern "C" int func_00192BA8(void) throw();

extern "C" void mPhotoMapWindow__virtual_09(struct mPhotoMapWindow *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00192BA8();
    }
}
