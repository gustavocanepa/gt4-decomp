#include "gt4/hException.h"
typedef int s32;

extern "C" int func_002F5650(void) throw();

extern "C" void hException__virtual_09(struct hException *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002F5650();
    }
}
