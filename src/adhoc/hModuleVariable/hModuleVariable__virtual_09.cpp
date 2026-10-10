#include "gt4/hModuleVariable.h"
typedef int s32;

extern "C" int func_003078D0(void) throw();

extern "C" void hModuleVariable__virtual_09(struct hModuleVariable *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_003078D0();
    }
}
