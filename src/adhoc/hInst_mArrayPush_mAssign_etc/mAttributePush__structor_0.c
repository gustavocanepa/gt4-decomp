#include "types.h"
#include "gt4/mAttributePush.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 RefCounter__structor_0();                            /* extern */

extern char mAttributePush__vtable[];
s32 mAttributePush__structor_0(struct mAttributePush *arg0, s32 *arg1) {
    RefCounter__structor_0();
    arg0->unk4 = (s32)mAttributePush__vtable;
    arg0->unk8 = (s32) *arg1;
}
