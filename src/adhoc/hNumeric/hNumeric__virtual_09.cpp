#include "gt4/hNumeric.h"
typedef int s32;

extern "C" int func_00308730(void) throw();

extern "C" void hNumeric__virtual_09(struct hNumeric *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00308730();
    }
}
