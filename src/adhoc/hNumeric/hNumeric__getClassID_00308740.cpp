#include "gt4/hNumeric.h"
typedef int s32;

extern "C" int hNumeric__GetClassID(void) throw();

extern "C" void hNumeric__getClassID(struct hNumeric *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        hNumeric__GetClassID();
    }
}
