#include "types.h"
#include "gt4/mGame.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 hObject__structor_0();                            /* extern */

extern char mGame__vtable[];
s32 mGame__structor_1(struct mGame *arg0, s32 arg1, s32 arg2) {
    hObject__structor_0();
    arg0->unk14 = arg2;
    arg0->unk10 = arg1;
    arg0->unk4 = (s32)mGame__vtable;
}
