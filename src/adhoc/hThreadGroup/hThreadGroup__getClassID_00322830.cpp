#include "gt4/hThreadGroup.h"
typedef int s32;

extern "C" int hThreadGroup__GetClassID(void) throw();

extern "C" void hThreadGroup__getClassID(struct hThreadGroup *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        hThreadGroup__GetClassID();
    }
}
