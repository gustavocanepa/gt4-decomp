#include "types.h"
#include "gt4/MVectorReader.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char MVectorReader__vtable[];
s32 MVectorReader__structor_0(struct MVectorReader *arg0, s32 arg1) {
    arg0->unk4 = arg1;
    arg0->unk0 = (s32)MVectorReader__vtable;
}
