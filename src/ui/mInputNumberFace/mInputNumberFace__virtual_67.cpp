#include "gt4/mInputNumberFace.h"
typedef int s32;

extern "C" void mTextFace__virtual_67(void);
extern "C" void mWidget__setActive(struct mInputNumberFace *arg0, s32 arg1);

extern "C" void mInputNumberFace__virtual_67(struct mInputNumberFace *arg0) {
    struct mInputNumberFace *s0 = arg0;

    mTextFace__virtual_67();
    mWidget__setActive(s0, 0);
    s0->unk11C = s0->unk108;
}
