#include "gt4/mProject.h"
typedef int s32;

extern "C" int mProject__GetClassID(void) throw();

extern "C" void mProject__getClassID(struct mProject *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mProject__GetClassID();
    }
}
