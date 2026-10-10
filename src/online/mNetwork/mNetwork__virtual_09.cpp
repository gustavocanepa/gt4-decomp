#include "gt4/mNetwork.h"
typedef int s32;

extern "C" int func_001DC7A0(void) throw();

extern "C" void mNetwork__virtual_09(struct mNetwork *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_001DC7A0();
    }
}
