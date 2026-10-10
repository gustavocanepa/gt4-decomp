#include "gt4/hMethodObject.h"
typedef int s32;

extern "C" int hMethodObject__GetClassID(void) throw();

extern "C" void hMethodObject__getClassID(struct hMethodObject *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        hMethodObject__GetClassID();
    }
}
