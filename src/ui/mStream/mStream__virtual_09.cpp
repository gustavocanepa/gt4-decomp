#include "gt4/mStream.h"
typedef int s32;

extern "C" int func_001FC550(void) throw();

extern "C" void mStream__virtual_09(struct mStream *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_001FC550();
    }
}
