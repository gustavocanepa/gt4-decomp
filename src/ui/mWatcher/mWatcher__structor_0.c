#include "types.h"
#include "gt4/mWatcher.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char mWatcher__vtable[];
s32 hObject__structor_0(void *);
void mWatcher__structor_0(struct mWatcher *arg0) {
    hObject__structor_0(arg0);
    arg0->unk10 = 1;
    arg0->unk4 = (s32)mWatcher__vtable;
    arg0->unk14 = 0;
    arg0->unk18 = 0;
}
