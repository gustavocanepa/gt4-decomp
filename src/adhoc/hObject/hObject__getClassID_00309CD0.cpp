#include "gt4/hObject.h"
typedef int s32;

extern "C" int hObject__GetClassID(void) throw();

extern "C" void hObject__getClassID(struct hObject *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        hObject__GetClassID();
    }
}
