#include "types.h"
#include "gt4/hIO.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 hObject__structor_0();                            /* extern */

extern char hIO__vtable[];
void hIO__structor_0(struct hIO *arg0) {
    hObject__structor_0();
    arg0->unk10 = 0;
    arg0->unk4 = (s32)hIO__vtable;
}
