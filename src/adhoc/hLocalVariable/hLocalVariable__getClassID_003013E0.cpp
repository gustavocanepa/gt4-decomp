#include "gt4/hLocalVariable.h"
typedef int s32;

extern "C" int hLocalVariable__GetClassID(void) throw();

extern "C" void hLocalVariable__getClassID(struct hLocalVariable *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        hLocalVariable__GetClassID();
    }
}
