#include "gt4/mListBox.h"
typedef int s32;

extern "C" int func_002AE900(void) throw();

extern "C" void mListBox__virtual_09(struct mListBox *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002AE900();
    }
}
