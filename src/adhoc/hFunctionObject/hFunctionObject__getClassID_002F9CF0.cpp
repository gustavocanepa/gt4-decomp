#include "gt4/hFunctionObject.h"
typedef int s32;

extern "C" int hFunctionObject__GetClassID(void) throw();

extern "C" void hFunctionObject__getClassID(struct hFunctionObject *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        hFunctionObject__GetClassID();
    }
}
