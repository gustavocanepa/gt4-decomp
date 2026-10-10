#include "gt4/mGameInputButton.h"
typedef int s32;

extern "C" int func_0029ACD8(void) throw();

extern "C" void mGameInputButton__virtual_09(struct mGameInputButton *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0029ACD8();
    }
}
