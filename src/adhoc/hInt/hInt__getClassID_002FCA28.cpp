#include "gt4/hInt.h"
typedef int s32;

extern "C" int hInt__GetClassID(void) throw();

extern "C" void hInt__getClassID(struct hInt *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        hInt__GetClassID();
    }
}
