#include "gt4/hCode.h"
typedef int s32;

extern "C" int hCode__GetClassID(void) throw();

extern "C" void hCode__getClassID(struct hCode *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        hCode__GetClassID();
    }
}
