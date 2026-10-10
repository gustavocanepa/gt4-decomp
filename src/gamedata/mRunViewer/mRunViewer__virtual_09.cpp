#include "gt4/mRunViewer.h"
typedef int s32;

extern "C" int func_001A78D0(void) throw();

extern "C" void mRunViewer__virtual_09(struct mRunViewer *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_001A78D0();
    }
}
