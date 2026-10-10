#include "gt4/mMemoryCardManager.h"
typedef int s32;

extern "C" int func_00179428(void) throw();

extern "C" void mMemoryCardManager__virtual_09(struct mMemoryCardManager *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00179428();
    }
}
