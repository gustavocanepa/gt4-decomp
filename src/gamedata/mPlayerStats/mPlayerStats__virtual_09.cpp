#include "gt4/mPlayerStats.h"
typedef int s32;

extern "C" int func_0019C328(void) throw();

extern "C" void mPlayerStats__virtual_09(struct mPlayerStats *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0019C328();
    }
}
