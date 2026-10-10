#include "gt4/hClass.h"
typedef int s32;

extern "C" int func_002F2BB0(void) throw();

extern "C" void hClass__virtual_09(struct hClass *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002F2BB0();
    }
}
