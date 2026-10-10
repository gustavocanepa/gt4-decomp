#include "gt4/hString.h"
typedef int s32;

extern "C" int hString__GetClassID(void) throw();

extern "C" void hString__getClassID(struct hString *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        hString__GetClassID();
    }
}
