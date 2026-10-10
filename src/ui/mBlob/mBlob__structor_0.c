#include "types.h"
#include "gt4/mBlob.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 hObject__structor_0();                            /* extern */

extern char mBlob__vtable[];
s32 mBlob__structor_0(struct mBlob *arg0, s32 arg1, s32 arg2) {
    hObject__structor_0();
    arg0->unk14 = arg2;
    arg0->unk10 = arg1;
    arg0->unk4 = (s32)mBlob__vtable;
}
