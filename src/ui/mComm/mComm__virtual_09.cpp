#include "gt4/mComm.h"
typedef int s32;

extern "C" int func_00271070(void) throw();

extern "C" void mComm__virtual_09(struct mComm *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00271070();
    }
}
