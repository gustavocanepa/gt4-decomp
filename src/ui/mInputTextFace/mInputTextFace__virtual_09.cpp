#include "gt4/mInputTextFace.h"
typedef int s32;

extern "C" int func_002A5F68(void) throw();

extern "C" void mInputTextFace__virtual_09(struct mInputTextFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002A5F68();
    }
}
