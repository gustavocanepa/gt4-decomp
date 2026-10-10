#include "gt4/hException.h"
typedef int s32;

extern "C" int hException__GetClassID(void) throw();

extern "C" void hException__getClassID(struct hException *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        hException__GetClassID();
    }
}
