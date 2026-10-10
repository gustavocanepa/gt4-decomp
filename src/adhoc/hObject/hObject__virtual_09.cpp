#include "gt4/hObject.h"
typedef int s32;

extern "C" int func_00309CC0(void) throw();

extern "C" void hObject__virtual_09(struct hObject *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00309CC0();
    }
}
