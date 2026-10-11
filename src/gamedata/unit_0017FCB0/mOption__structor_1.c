#include "types.h"
#include "gt4/mOption.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char mOption__vtable[];
s32 hObject__structor_0(void *);
void func_00436278(void *);
void mOption__structor_1(void *arg0, s32 arg1) {
    hObject__structor_0(arg0);
    ((struct mOption *)arg0)->unk4 = (s32)mOption__vtable;
    ((struct mOption *)arg0)->unk10 = arg1;
    func_00436278((s8 *)arg0 + 0x18);
}
