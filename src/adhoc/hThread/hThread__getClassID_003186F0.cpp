#include "gt4/hThread.h"
typedef int s32;

extern "C" int hThread__GetClassID(void) throw();

extern "C" void hThread__getClassID(struct hThread *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        hThread__GetClassID();
    }
}
