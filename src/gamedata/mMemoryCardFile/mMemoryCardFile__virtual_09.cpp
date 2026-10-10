#include "gt4/mMemoryCardFile.h"
typedef int s32;

extern "C" int func_00174298(void) throw();

extern "C" void mMemoryCardFile__virtual_09(struct mMemoryCardFile *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00174298();
    }
}
