#include "gt4/hInt.h"
typedef int s32;

extern "C" int func_002FCA18(void) throw();

extern "C" void hInt__virtual_09(struct hInt *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002FCA18();
    }
}
