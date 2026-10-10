#include "gt4/hModule.h"
typedef int s32;

extern "C" int hModule__GetClassID(void) throw();

extern "C" void hModule__getClassID(struct hModule *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        hModule__GetClassID();
    }
}
