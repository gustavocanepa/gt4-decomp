#include "gt4/hFileIO.h"
typedef int s32;

extern "C" int func_002F66E0(void) throw();

extern "C" void hFileIO__virtual_09(struct hFileIO *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002F66E0();
    }
}
