#include "gt4/hClass.h"
typedef int s32;

extern "C" int hClass__GetClassID(void) throw();

extern "C" void hClass__getClassID(struct hClass *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        hClass__GetClassID();
    }
}
