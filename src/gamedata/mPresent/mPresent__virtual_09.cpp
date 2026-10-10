#include "gt4/mPresent.h"
typedef int s32;

extern "C" int func_0019FB58(void) throw();

extern "C" void mPresent__virtual_09(struct mPresent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0019FB58();
    }
}
