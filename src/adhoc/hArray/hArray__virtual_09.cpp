#include "gt4/hArray.h"
typedef int s32;

extern "C" int func_002ED768(void) throw();

extern "C" void hArray__virtual_09(struct hArray *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002ED768();
    }
}
