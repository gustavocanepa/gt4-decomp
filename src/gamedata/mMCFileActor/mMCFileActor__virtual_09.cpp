#include "gt4/mMCFileActor.h"
typedef int s32;

extern "C" int func_001733F8(void) throw();

extern "C" void mMCFileActor__virtual_09(struct mMCFileActor *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_001733F8();
    }
}
