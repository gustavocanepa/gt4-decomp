#include "gt4/mNetConf.h"
typedef int s32;

extern "C" int mNetConf__GetClassID(void) throw();

extern "C" void mNetConf__getClassID(struct mNetConf *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mNetConf__GetClassID();
    }
}
