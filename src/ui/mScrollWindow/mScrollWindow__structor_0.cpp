#include "gt4/mScrollWindow.h"
typedef int s32;

extern void *mScrollWindow__vtable;
extern "C" void *mComposite__structor_0(void *);
extern "C" void *func_002D1B38(void *, s32, void *);

extern "C" void mScrollWindow__structor_0(void *arg0) {
    mComposite__structor_0(arg0);
    ((struct mScrollWindow *)arg0)->unk4 = &mScrollWindow__vtable;
    ((struct mScrollWindow *)arg0)->unkB4 = 0.299999989569f;
    ((struct mScrollWindow *)arg0)->unkB0 = (void *)(0x1);
    ((struct mScrollWindow *)arg0)->unkB8 = 0x0;
    ((struct mScrollWindow *)arg0)->unkBC = 0x0;
    ((struct mScrollWindow *)arg0)->unkC0 = 0x0;
    func_002D1B38((char *)arg0 + 0xc4, 0x1, (char *)arg0 + 0xfc);
    func_002D1B38((char *)arg0 + 0xfc, 0x0, (char *)arg0 + 0xc4); return;
}
