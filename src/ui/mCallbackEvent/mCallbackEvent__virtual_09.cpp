#include "gt4/mCallbackEvent.h"
typedef int s32;

extern "C" int func_00281CA8(void) throw();

extern "C" void mCallbackEvent__virtual_09(struct mCallbackEvent *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00281CA8();
    }
}
