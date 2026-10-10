#include "gt4/mRenderContextPS2.h"
typedef int s32;

extern "C" int func_002157E8(void) throw();

extern "C" void mRenderContextPS2__virtual_09(struct mRenderContextPS2 *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002157E8();
    }
}
