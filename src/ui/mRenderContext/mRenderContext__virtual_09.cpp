#include "gt4/mRenderContext.h"
typedef int s32;

extern "C" int func_0022AC60(void) throw();

extern "C" void mRenderContext__virtual_09(struct mRenderContext *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0022AC60();
    }
}
