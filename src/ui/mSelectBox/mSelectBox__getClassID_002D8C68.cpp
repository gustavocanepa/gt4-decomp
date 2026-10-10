#include "gt4/mSelectBox.h"
typedef int s32;

extern "C" int mSelectBox__GetClassID(void) throw();

extern "C" void mSelectBox__getClassID(struct mSelectBox *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mSelectBox__GetClassID();
    }
}
