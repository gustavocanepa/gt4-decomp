#include "types.h"
#include "gt4/hVariable.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 hObject__structor_0();                            /* extern */

extern char hVariable__vtable[];
s32 hVariable__structor_0(struct hVariable *arg0, s32 *arg1) {
    hObject__structor_0();
    arg0->unk4 = (s32)hVariable__vtable;
    arg0->unk10 = (s32) *arg1;
}
