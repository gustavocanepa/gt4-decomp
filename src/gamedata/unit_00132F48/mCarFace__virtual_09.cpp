#include "gt4/mCarFace.h"
typedef int s32;

extern "C" int func_00137F08(void) throw();

extern "C" void mCarFace__virtual_09(struct mCarFace *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00137F08();
    }
}
