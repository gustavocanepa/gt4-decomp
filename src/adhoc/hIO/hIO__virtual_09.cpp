#include "gt4/hIO.h"
typedef int s32;

extern "C" int func_002FEC58(void) throw();

extern "C" void hIO__virtual_09(struct hIO *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002FEC58();
    }
}
