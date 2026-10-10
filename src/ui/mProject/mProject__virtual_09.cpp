#include "gt4/mProject.h"
typedef int s32;

extern "C" int func_00229448(void) throw();

extern "C" void mProject__virtual_09(struct mProject *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00229448();
    }
}
