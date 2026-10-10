#include "gt4/hThread.h"
typedef int s32;

extern "C" int func_003186E0(void) throw();

extern "C" void hThread__virtual_09(struct hThread *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_003186E0();
    }
}
