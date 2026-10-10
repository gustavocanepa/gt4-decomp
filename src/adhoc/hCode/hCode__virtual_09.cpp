#include "gt4/hCode.h"
typedef int s32;

extern "C" int func_002F43B8(void) throw();

extern "C" void hCode__virtual_09(struct hCode *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002F43B8();
    }
}
