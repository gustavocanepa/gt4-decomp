#include "types.h"
#include "gt4/mMBox.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char mMBox__vtable[];
s32 mBox__structor_0(void *);
void mMBox__structor_0(struct mMBox *arg0) {
    mBox__structor_0(arg0);
    arg0->unk4 = (s32)mMBox__vtable;
    arg0->unkC0 = 2;
    arg0->unkC4 = 0;
    arg0->unkC8 = 0;
}
