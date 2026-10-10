#include "gt4/hFloat.h"
typedef int s32;

extern "C" int hFloat__GetClassID(void) throw();

extern "C" void hFloat__getClassID(struct hFloat *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        hFloat__GetClassID();
    }
}
