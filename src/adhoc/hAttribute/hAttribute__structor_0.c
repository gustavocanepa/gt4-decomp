#include "types.h"
#include "gt4/hAttribute.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 hValue__structor_0();                            /* extern */

extern char hAttribute__vtable[];
s32 hAttribute__structor_0(struct hAttribute *arg0) {
    hValue__structor_0();
    arg0->unkC = -1;
    arg0->unk4 = (s32)hAttribute__vtable;
}
