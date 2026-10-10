#include "gt4/hArray.h"
typedef int s32;

extern "C" int hArray__GetClassID(void) throw();

extern "C" void hArray__getClassID(struct hArray *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        hArray__GetClassID();
    }
}
