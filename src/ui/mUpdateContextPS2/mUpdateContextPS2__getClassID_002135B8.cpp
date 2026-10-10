#include "gt4/mUpdateContextPS2.h"
typedef int s32;

extern "C" int mUpdateContextPS2__GetClassID(void) throw();

extern "C" void mUpdateContextPS2__getClassID(struct mUpdateContextPS2 *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mUpdateContextPS2__GetClassID();
    }
}
