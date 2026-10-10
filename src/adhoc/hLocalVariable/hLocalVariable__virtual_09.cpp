#include "gt4/hLocalVariable.h"
typedef int s32;

extern "C" int func_003013D0(void) throw();

extern "C" void hLocalVariable__virtual_09(struct hLocalVariable *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_003013D0();
    }
}
