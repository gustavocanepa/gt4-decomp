#include "gt4/mPlayList.h"
typedef int s32;

extern "C" int func_0019E448(void) throw();

extern "C" void mPlayList__virtual_09(struct mPlayList *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0019E448();
    }
}
