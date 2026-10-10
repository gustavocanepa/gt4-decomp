#include "gt4/mNetConf.h"
typedef int s32;

extern "C" int func_00221C78(void) throw();

extern "C" void mNetConf__virtual_09(struct mNetConf *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00221C78();
    }
}
