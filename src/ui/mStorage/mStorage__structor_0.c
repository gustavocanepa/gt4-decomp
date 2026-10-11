#include "types.h"
#include "gt4/mStorage.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 hObject__structor_0();                            /* extern */

extern char mStorage__vtable[];
s32 mStorage__structor_0(struct mStorage *arg0) {
    hObject__structor_0();
    arg0->unk10 = -1;
    arg0->unk4_s32 = (s32)mStorage__vtable;
}
