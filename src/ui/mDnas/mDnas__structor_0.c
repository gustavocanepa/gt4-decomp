#include "types.h"
#include "gt4/mDnas.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 hObject__structor_0();                            /* extern */

extern char mDnas__vtable[];
void mDnas__structor_0(struct mDnas *arg0) {
    hObject__structor_0();
    arg0->unk34 = 0;
    arg0->unk10 = 0;
    arg0->unk4 = (s32)mDnas__vtable;
}
