#include "types.h"
#include "gt4/mScrollable.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char mScrollable__vtable[];
s32 mComposite__structor_0(void *);
void mScrollable__structor_0(struct mScrollable *arg0) {
    mComposite__structor_0(arg0);
    arg0->unk4 = (s32)mScrollable__vtable;
    arg0->unkB0 = 0;
    arg0->unkB4 = 0;
    arg0->unkB8 = 0;
}
