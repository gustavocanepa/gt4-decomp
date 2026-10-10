#include "gt4/mTextFace.h"
typedef int s32;

extern void *mTextFace__vtable;
extern "C" void *mWidget__structor_0(void *);
extern "C" void *func_00246F58(void *);
extern "C" void *func_002B70B8(void *);
extern "C" void *func_0025B4C8(void *, float, float);

extern "C" void mTextFace__structor_0(void *arg0) {
    mWidget__structor_0(arg0);
    ((struct mTextFace *)arg0)->unk4 = &mTextFace__vtable;
    func_00246F58((char *)arg0 + 0xa0);
    func_002B70B8((char *)arg0 + 0x104);
    ((struct mTextFace *)arg0)->unk108 = 0x0;
    ((struct mTextFace *)arg0)->unk114_pvoid = 0x0;
    ((struct mTextFace *)arg0)->unk10C = (void *)(-0x1);
    ((struct mTextFace *)arg0)->unk110 = (void *)(-0x1);
    ((struct mTextFace *)arg0)->unk118_pvoid = 0x0;
    ((struct mTextFace *)arg0)->unk11C_pvoid = 0x0;
    func_0025B4C8(arg0, 256.000007629f, 24.0000004768f); return;
}
