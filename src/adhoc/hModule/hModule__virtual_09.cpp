#include "gt4/hModule.h"
typedef int s32;

extern "C" int func_00304360(void) throw();

extern "C" void hModule__virtual_09(struct hModule *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00304360();
    }
}
