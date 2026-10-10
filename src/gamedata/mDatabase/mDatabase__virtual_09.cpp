#include "gt4/mDatabase.h"
typedef int s32;

extern "C" int func_001B4258(void) throw();

extern "C" void mDatabase__virtual_09(struct mDatabase *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_001B4258();
    }
}
