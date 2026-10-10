#include "gt4/hFunctionObject.h"
typedef int s32;

extern "C" int func_002F9CE0(void) throw();

extern "C" void hFunctionObject__virtual_09(struct hFunctionObject *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002F9CE0();
    }
}
