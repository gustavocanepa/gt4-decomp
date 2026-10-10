#include "gt4/hVariable.h"
typedef int s32;

extern "C" int hVariable__GetClassID(void) throw();

extern "C" void hVariable__getClassID(struct hVariable *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        hVariable__GetClassID();
    }
}
