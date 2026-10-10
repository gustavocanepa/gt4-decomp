#include "gt4/hVariable.h"
typedef int s32;

extern "C" int func_00324618(void) throw();

extern "C" void hVariable__virtual_09(struct hVariable *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00324618();
    }
}
