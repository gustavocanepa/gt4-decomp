#include "gt4/mOptionMenu.h"
typedef int s32;

extern "C" int func_002C7460(void) throw();

extern "C" void mOptionMenu__virtual_09(struct mOptionMenu *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002C7460();
    }
}
