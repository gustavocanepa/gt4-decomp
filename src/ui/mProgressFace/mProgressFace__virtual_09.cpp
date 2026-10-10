#include "gt4/mProgressFace.h"
typedef int s32;

extern "C" int func_002CA8A0(void) throw();

extern "C" void mProgressFace__virtual_09(struct mProgressFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002CA8A0();
    }
}
