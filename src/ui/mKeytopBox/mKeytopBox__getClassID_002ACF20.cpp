#include "gt4/mKeytopBox.h"
typedef int s32;

extern "C" int mKeytopBox__GetClassID(void) throw();

extern "C" void mKeytopBox__getClassID(struct mKeytopBox *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mKeytopBox__GetClassID();
    }
}
