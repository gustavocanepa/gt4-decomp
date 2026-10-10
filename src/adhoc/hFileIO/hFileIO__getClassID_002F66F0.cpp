#include "gt4/hFileIO.h"
typedef int s32;

extern "C" int hFileIO__GetClassID(void) throw();

extern "C" void hFileIO__getClassID(struct hFileIO *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        hFileIO__GetClassID();
    }
}
