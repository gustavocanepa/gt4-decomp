#include "gt4/mKeyboardBox.h"
typedef int s32;

extern "C" int func_002AC170(void) throw();

extern "C" void mKeyboardBox__virtual_09(struct mKeyboardBox *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002AC170();
    }
}
