#include "gt4/mListBox.h"
typedef int s32;

extern "C" int mListBox__GetClassID(void) throw();

extern "C" void mListBox__getClassID(struct mListBox *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        mListBox__GetClassID();
    }
}
