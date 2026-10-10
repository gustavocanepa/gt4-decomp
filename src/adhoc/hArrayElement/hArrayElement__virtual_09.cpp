#include "gt4/hArrayElement.h"
typedef int s32;

extern "C" int func_002F0F60(void) throw();

extern "C" void hArrayElement__virtual_09(struct hArrayElement *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002F0F60();
    }
}
