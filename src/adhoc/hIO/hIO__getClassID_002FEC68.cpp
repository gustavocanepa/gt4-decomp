#include "gt4/hIO.h"
typedef int s32;

extern "C" int hIO__GetClassID(void) throw();

extern "C" void hIO__getClassID(struct hIO *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        hIO__GetClassID();
    }
}
