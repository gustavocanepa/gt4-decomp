#include "gt4/mBox.h"
typedef int s32;

extern "C" int mBox__GetClassID(void) throw();

extern "C" void mBox__getClassID(struct mBox *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mBox__GetClassID();
    }
}
