#include "gt4/hFloat.h"
typedef int s32;

extern "C" int func_002F7D10(void) throw();

extern "C" void hFloat__virtual_09(struct hFloat *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002F7D10();
    }
}
