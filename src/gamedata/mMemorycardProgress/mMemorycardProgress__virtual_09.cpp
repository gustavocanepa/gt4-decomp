#include "gt4/mMemorycardProgress.h"
typedef int s32;

extern "C" int func_0017EF08(void) throw();

extern "C" void mMemorycardProgress__virtual_09(struct mMemorycardProgress *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0017EF08();
    }
}
