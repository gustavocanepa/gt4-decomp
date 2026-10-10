#include "gt4/hString.h"
typedef int s32;

extern "C" int func_003124C0(void) throw();

extern "C" void hString__virtual_09(struct hString *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_003124C0();
    }
}
