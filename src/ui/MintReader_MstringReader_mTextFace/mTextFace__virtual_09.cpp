#include "gt4/mTextFace.h"
typedef int s32;

extern "C" int func_00243618(void) throw();

extern "C" void mTextFace__virtual_09(struct mTextFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00243618();
    }
}
