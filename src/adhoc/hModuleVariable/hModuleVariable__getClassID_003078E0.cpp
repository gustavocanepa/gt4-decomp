#include "gt4/hModuleVariable.h"
typedef int s32;

extern "C" int hModuleVariable__GetClassID(void) throw();

extern "C" void hModuleVariable__getClassID(struct hModuleVariable *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        hModuleVariable__GetClassID();
    }
}
