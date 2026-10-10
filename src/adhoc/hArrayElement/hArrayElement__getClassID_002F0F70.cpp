#include "gt4/hArrayElement.h"
typedef int s32;

extern "C" int hArrayElement__GetClassID(void) throw();

extern "C" void hArrayElement__getClassID(struct hArrayElement *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        hArrayElement__GetClassID();
    }
}
