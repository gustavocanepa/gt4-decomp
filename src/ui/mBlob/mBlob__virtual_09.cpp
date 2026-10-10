#include "gt4/mBlob.h"
typedef int s32;

extern "C" int func_001FFEC8(void) throw();

extern "C" void mBlob__virtual_09(struct mBlob *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_001FFEC8();
    }
}
